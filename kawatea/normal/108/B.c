#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
     return *((int *)a) - *((int *)b);
}

int main()
{
     int n, i;
     int a[100000];

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     qsort(a, n, sizeof(int), cmp);

     for (i = 0; i < n - 1; i++) {
	  if (a[i] == a[i + 1]) continue;

	  if (a[i] * 2 > a[i + 1]) {
	       puts("YES");

	       return 0;
	  }
     }

     puts("NO");

     return 0;
}