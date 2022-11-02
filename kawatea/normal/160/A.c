#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
     return *((int *)b) - *((int *)a);
}

int main()
{
     int n, sum = 0, p = 0, i;
     int a[100];

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%d", &a[i]);

	  sum += a[i];
     }

     qsort(a, n, sizeof(int), cmp);

     for (i = 0; i < n; i++) {
	  p += a[i];

	  if (p * 2 > sum) {
	       printf("%d\n", i + 1);

	       return 0;
	  }
     }

     return 0;
}