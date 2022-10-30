#include <stdio.h>

int main()
{
     int n, m, s;
     long long x, y;

     scanf("%d %d %d", &n, &m, &s);

     if (n % s == 0) {
	  x = n;
     } else {
	  x = (long long)n % s * (n / s + 1);
     }

     if (m % s == 0) {
	  y = m;
     } else {
	  y = (long long)m % s * (m / s + 1);
     }

     printf("%I64d\n", x * y);

     return 0;
}