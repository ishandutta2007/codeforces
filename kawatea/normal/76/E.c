#include <stdio.h>

int main()
{
     int n, i;
     long long sum = 0, p = 0, q = 0;
     int x[100000], y[100000];

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);

     for (i = 0; i < n; i++) {
	  p += x[i];
	  q += y[i];

	  sum += (long long)(n - 1) * x[i] * x[i];
	  sum += (long long)(n - 1) * y[i] * y[i];
     }

     for (i = 0; i < n; i++) {
	  sum -= (p - x[i]) * x[i];
	  sum -= (q - y[i]) * y[i];
     }

     printf("%I64d\n", sum);

     return 0;
}