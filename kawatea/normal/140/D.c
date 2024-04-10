#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
     return *((int *)a) - *((int *)b);
}

int main()
{
     int n, num = 0, sum = 10, p = 0, i;
     int a[100];

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     qsort(a, n, sizeof(int), cmp);

     for (i = 0; i < n; i++) {
	  if (a[i] + sum > 720) break;

	  sum += a[i];
	  num++;
     }

     sum = 10;

     for (i = 0; i < num; i++) {
	  sum += a[i];

	  if (sum > 360) p += sum - 360;
     }

     printf("%d %d\n", num, p);

     return 0;
}