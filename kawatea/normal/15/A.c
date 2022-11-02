#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int x;
     int a;
} house;

int cmp(const void *a, const void *b)
{
     return ((house *)a)->x - ((house *)b)->x;
}

int main()
{
     int n, t, sum = 2, i;
     house h[1000];

     scanf("%d %d", &n, &t);

     for (i = 0; i < n; i++) scanf("%d %d", &h[i].x, &h[i].a);

     qsort(h, n, sizeof(house), cmp);

     for (i = 0; i < n - 1; i++) {
	  int f = 0;

	  if (h[i].x + h[i].a / 2.0 + t <= h[i + 1].x - h[i + 1].a / 2.0) {
	       sum++; f++;
	  }

	  if (h[i + 1].x - h[i + 1].a / 2.0 - t >= h[i].x + h[i].a / 2.0) {
			 sum++; f++;
	  }

	  if (f == 2) {
	       if (h[i].x + h[i].a / 2.0 + t == h[i + 1].x - h[i + 1].a / 2.0) {
		    sum--;
	       }
	  }
     }

     printf("%d\n", sum);

     return 0;
}