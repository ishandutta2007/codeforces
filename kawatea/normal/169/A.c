#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
     return *((int *)a) - *((int *)b);
}

int main()
{
     int n, a, b, i, j;
     int c[2000];

     scanf("%d %d %d", &n, &a, &b);

     for (i = 0; i < n; i++) scanf("%d", &c[i]);

     qsort(c, n, sizeof(int), cmp);

     for (i = 0; i < n; i++) {
	  for (j = i; j < n; j++) {
	       if (c[i] != c[j]) break;
	  }

	  if (j == b) {
	       printf("%d\n", c[j] - c[j - 1]);

	       return 0;
	  }

	  i = j - 1;
     }

     puts("0");

     return 0;
}