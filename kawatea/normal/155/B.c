#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
     return *((int *)b) - *((int *)a);
}

int main()
{
     int n, sum = 0, p = 0, q = 1, i;
     int a[1000];

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  int x, y;

	  scanf("%d %d", &x, &y);

	  if (y == 0) {
	       a[p++] = x;
	  } else {
	       sum += x;

	       q += y - 1;
	  }
     }

     qsort(a, p, sizeof(int), cmp);

     for (i = 0; i < p && i < q; i++) sum += a[i];

     printf("%d\n", sum);

     return 0;
}