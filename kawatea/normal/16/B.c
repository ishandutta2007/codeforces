#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int a;
     int b;
} match;

int cmp(const void *a, const void *b)
{
     return ((match *)b)->b - ((match *)a)->b;
}

int main()
{
     int n, m, sum = 0, i;
     match a[20];

     scanf("%d %d", &n, &m);

     for (i = 0; i < m; i++) scanf("%d %d", &a[i].a, &a[i].b);

     qsort(a, m, sizeof(match), cmp);

     for (i = 0; i < m; i++) {
	  if (n >= a[i].a) {
	       sum += a[i].a * a[i].b;

	       n -= a[i].a;
	  } else {
	       sum += n * a[i].b;

	       n = 0;
	  }
     }

     printf("%d\n", sum);

     return 0;
}