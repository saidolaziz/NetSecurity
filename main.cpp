/* This program calculates the Key for two persons
using the Diffie-Hellman Key exchange algorithm */
#include<stdio.h>
#include<math.h>
#include <stdlib.h>

// Power function to return value of a ^ b mod P
long long int power(long long int a, long long int b,
									long long int P)
{
	if (b == 1)
		return a;

	else
		return (((long long int)pow(a, b)) % P);
}

//Driver program
int main()
{
	long long int P, G, x, a, y, b, ka, kb,g;

	// Both the persons will be agreed upon the
		// public keys G and P
	P = 97; // A prime number P is taken
	printf("The value of P : %lld\n", P);


    for(int i = 0; i<100; i++) {
          g=rand()%100;
      if(g<P){
        break;
      }
    }

  G= g;


	//G = 9; // A primitve root for P, G is taken
	printf("The value of G : %lld\n\n", G);

	// Alice will choose the private key a
	a = 4; // a is the chosen private key
	printf("The private key a for Alice : %lld\n", a);
	x = power(G, a, P); // gets the generated key

	// Bob will choose the private key b
	b = 3; // b is the chosen private key
	printf("The private key b for Bob : %lld\n\n", b);
	y = power(G, b, P); // gets the generated key

	// Generating the secret key after the exchange
		// of keys
	ka = power(y, a, P); // Secret key for Alice
	kb = power(x, b, P); // Secret key for Bob

	printf("Secret key for the Alice is : %lld\n", ka);
	printf("Secret Key for the Bob is : %lld\n", kb);

	return 0;
}
