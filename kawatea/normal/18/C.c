#include <stdio.h>

int main()
{
     int n, res = 0, sum1 = 0, sum2 = 0, i;
     int a[100000];

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%d", &a[i]);

	  sum2 += a[i];
     }

     for (i = 0; i < n - 1; i++) {
	  sum1 += a[i];
	  sum2 -= a[i];

	  if (sum1 == sum2) res++;
     }

     printf("%d\n", res);

     return 0;
}