#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
     return *((int *)b) - *((int *)a);
}

int main()
{
     int k, i;
     int a[12];

     scanf("%d", &k);

     for (i = 0; i < 12; i++) scanf("%d", &a[i]);

     qsort(a, 12, sizeof(int), cmp);

     for (i = 0; i < 12; i++) {
	  if (k <= 0) {
	       printf("%d\n", i);

	       return 0;
	  }

	  k -= a[i];
     }

     if (k <= 0) {
	  puts("12");
     } else {
	  puts("-1");
     }

     return 0;
}