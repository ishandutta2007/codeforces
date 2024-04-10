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

     if (a[n - 1] == 1) {
	  for (i = 0; i < n - 1; i++) {
	       if (i > 0) putchar(' ');

	       putchar('1');
	  }

	  if (i > 0) putchar(' ');

	  puts("2");
     } else {
	  putchar('1');

	  for (i = 0; i < n - 1; i++) {
	       printf(" %d", a[i]);
	  }

	  puts("");
     }

     return 0;
}