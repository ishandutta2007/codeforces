#include <stdio.h>

int main()
{
     int n, l, max = 0, i, j;
     int a[100];

     scanf("%d %d", &n, &l);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     for (i = l; i <= 100; i++) {
	  int sum = 0;

	  for (j = 0; j < n; j++) sum += a[j] / i;

	  if (sum * i > max) max = sum * i;
     }

     printf("%d\n", max);

     return 0;
}