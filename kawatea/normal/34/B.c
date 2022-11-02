#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
     return *((int *)a) - *((int *)b);
}

int main()
{
     int n, m, sum = 0, i;
     int a[100];

     scanf("%d %d", &n, &m);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     qsort(a, n, sizeof(int), cmp);

     for (i = 0; i < m; i++) {
	  if (a[i] < 0) {
	       sum += -a[i];
	  } else {
	       break;
	  }
     }

     printf("%d\n", sum);

     return 0;
}