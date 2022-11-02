#include <stdio.h>

int min(int a, int b)
{
     if (a < b) {
	  return a;
     } else {
	  return b;
     }
}

int gcd(int a, int b)
{
     if (a < b) return gcd(b, a);

     if (a % b == 0) return b;

     return gcd(b, a % b);
}

int main()
{
     int a, b, x, y, g;

     scanf("%d %d %d %d", &a, &b, &x, &y);

     g = gcd(x, y);

     x /= g; y /= g;

     a /= x; b /= y;

     printf("%d %d\n", min(a, b) * x, min(a, b) * y);

     return 0;
}