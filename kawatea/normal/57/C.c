#include <stdio.h>

long long extgcd(long long a, long long b, long long *x, long long *y)
{
     long long d = a;

     if (b != 0) {
	  d = extgcd(b, a % b, y, x);

	  *y -= (a / b) * (*x);
     } else {
	  *x = 1;
	  *y = 0;
     }

     return d;
}

long long mod_inverse(long long a, long long m)
{
     long long x, y;

     extgcd(a, m, &x, &y);

     return (m + x % m) % m;
}

int main()
{
     int n, m = 1000000007, i;
     long long a1 = 1, a2 = 1, a3 = 1, c;

     scanf("%d", &n);

     for (i = 1; i <= 2 * n - 1; i++) {
	  a1 *= i;
	  a1 %= m;
     }

     for (i = 1; i <= n; i++) {
	  a2 *= i;
	  a2 %= m;
     }

     for (i = 1; i <= n - 1; i++) {
	  a3 *= i;
	  a3 %= m;
     }

     c = a1 * mod_inverse(a2 * a3 % m, m) % m;
     c *= 2;
     c -= n;
     c %= m;

     printf("%I64d\n", c);

     return 0;
}