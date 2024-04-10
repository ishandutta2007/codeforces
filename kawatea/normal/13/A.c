#include <stdio.h>

int gcd(int a, int b)
{
     if (a < b) return gcd(b, a);

     if (a % b == 0) return b;

     return gcd(b, a % b);
}

int main()
{
     int n, x = 0, y = 0, g, i;

     scanf("%d", &n);

     for (i = 2; i < n; i++) {
	  int m = n;

	  while (m) {
	       x += m % i;
	       m /= i;
	  }

	  y++;
     }

     g = gcd(x, y);
     x /= g;
     y /= g;

     printf("%d/%d\n", x, y);

     return 0;
}