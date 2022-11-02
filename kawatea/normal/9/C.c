#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
     return *((int *)a) - *((int *)b);
}

int main()
{
     int n, x = 1, p = 0, q = 1, i, j;
     int a[2000] = {1};

     scanf("%d", &n);

     for (i = 0; i < 9; i++) {
	  for (j = p; j < q; j++) {
	       a[x++] = a[j] * 10;
	       a[x++] = a[j] * 10 + 1;
	  }

	  p = q; q = x;
     }

     for (i = 0; i < x; i++) {
	  if (a[i] > n) break;
     }

     printf("%d\n", i);

     return 0;
}