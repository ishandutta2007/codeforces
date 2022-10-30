#include <stdio.h>

int main()
{
     int n, d, m, l, i;
     long long sum = 0;

     scanf("%d %d %d %d", &n, &d, &m, &l);

     for (i = 0; i < n; i++) {
	  if ((sum + m - 1) / d * d > sum + l) {
	       printf("%I64d\n", ((sum + l) / d + 1) * d);

	       return 0;
	  }

	  sum += m;
     }

     printf("%I64d\n", ((sum - m + l) / d + 1) * d);

     return 0;
}