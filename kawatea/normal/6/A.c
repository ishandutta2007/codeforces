#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
     return *((int *)a) - *((int *)b);
}

int main()
{
     int a[4];
     int i;

     for (i = 0; i < 4; i++) scanf("%d", &a[i]);

     qsort(a, 4, sizeof(int), cmp);

     for (i = 0; i < 2; i++) {
	  if (a[i] + a[i + 1] > a[i + 2]) {
	       puts("TRIANGLE");

	       return 0;
	  }
     }

     for (i = 0; i < 2; i++) {
	  if (a[i] + a[i + 1] == a[i + 2]) {
	       puts("SEGMENT");

	       return 0;
	  }
     }

     puts("IMPOSSIBLE");

     return 0;
}