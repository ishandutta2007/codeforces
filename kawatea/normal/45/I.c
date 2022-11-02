#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
     return *((int *)b)- *((int *)a);
}

int main()
{
     int n, p = 0, f = 0, i;
     int a[100];

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     qsort(a, n, sizeof(int), cmp);

     for (i = 0; i < n; i++) {
	  if (a[i] > 0) {
	       printf("%d ", a[i]);
	       f = 1;
	  } else {
	       break;
	  }
     }

     for (i = n - 1; i >= 0; i--) {
	  if (a[i] < 0) {
	       p++;

	       if (p == 2) {
		    printf("%d %d ", a[i], a[i + 1]);

		    f = 1;

		    p = 0;
	       }
	  }
     }

     if (f == 0) printf("%d", a[0]);

     puts("");

     return 0;
}