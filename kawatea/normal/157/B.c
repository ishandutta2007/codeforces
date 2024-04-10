#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void *a, const void *b)
{
     return *((int *)b) - *((int *)a);
}

int main()
{
     int n, i;
     double sum = 0, pi = acos(-1);
     int a[100];

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     qsort(a, n, sizeof(int), cmp);

     for (i = 0; i < n; i++) {
	  if (i % 2 == 0) {
	       sum += a[i] * a[i] * pi;
	  } else {
	       sum -= a[i] * a[i] * pi;
	  }
     }

     printf("%.10lf\n", sum);

     return 0;
}