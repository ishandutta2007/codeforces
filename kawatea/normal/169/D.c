#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int m;
     int v;
     int i;
} lemmings;

int cmp(const void *a, const void *b)
{
     if (((lemmings *)a)->m != ((lemmings *)b)->m) {
	  return ((lemmings *)a)->m - ((lemmings *)b)->m;
     } else {
	  return ((lemmings *)a)->v - ((lemmings *)b)->v;
     }
}

int main()
{
     int n, k, h, i, j;
     double l, r, m;
     lemmings a[100000];
     int b[100000], c[100000];

     scanf("%d %d %d", &n, &k, &h);

     for (i = 0; i < n; i++) scanf("%d", &a[i].m);
     for (i = 0; i < n; i++) scanf("%d", &a[i].v);

     for (i = 0; i < n; i++) a[i].i = i + 1;

     qsort(a, n, sizeof(lemmings), cmp);

     l = 0, r = 1e18, m = (l + r) / 2;

     for (i = 0; i < 500; i++) {
	  int p = 0;

	  for (j = 0; j < n && p < k; j++) {
	       if ((double)(p + 1) * h / a[j].v <= m) {
		    b[p++] = a[j].i;
	       }
	  }

	  if (p >= k) {
	       r = m;
	       m = (l + r) / 2;

	       for (j = 0; j < k; j++) c[j] = b[j];
	  } else {
	       l = m;
	       m = (l + r) / 2;
	  }
     }

     for (i = 0; i < k; i++) {
	  if (i > 0) putchar(' ');

	  printf("%d", c[i]);
     }

     puts("");

     return 0;
}