#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int l;
     int r;
     int i;
} group;

int cmp(const void *a, const void *b)
{
     return ((group *)a)->l - ((group *)b)->l;
}

int cmp2(const void *a, const void *b)
{
     return *((int *)a) - *((int *)b);
}

int main()
{
     int n, p = 0, i, j;
     group g[5001];
     int a[5000];

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%d %d", &g[i].l, &g[i].r);

	  g[i].i = i + 1;
     }

     g[n].l = 1e9;

     qsort(g, n, sizeof(group), cmp);

     for (i = 0; i < n; i++) {
	  for (j = 0; j < n - 1; j++) {
	       int c = j + 1;

	       if (i == j) continue;

	       if (j + 1 == i) c++;

	       if (g[j].r > g[c].l) break;
	  }

	  if (j >= n - 1) a[p++] = g[i].i;
     }

     qsort(a, p, sizeof(int), cmp);

     printf("%d\n", p);

     for (i = 0; i < p; i++) {
	  if (i > 0) putchar(' ');
	  printf("%d", a[i]);
     }
     puts("");

     return 0;
}