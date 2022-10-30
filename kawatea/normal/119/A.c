#include <stdio.h>

int gcd(int a, int b)
{
     if (a < b) return gcd(b, a);

     if (a % b == 0) return b;

     return gcd(b, a % b);
}

int main()
{
     int a, b, n;

     scanf("%d %d %d", &a, &b, &n);

     while (1) {
	  if (n == 0) {
	       puts("1");

	       return 0;
	  }

	  n -= gcd(a, n);

	  if (n == 0) {
	       puts("0");

	       return 0;
	  }

	  n -= gcd(b, n);
     }

     return 0;
}