#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int l;
     int i;
} rod;

typedef struct {
     int l;
     int i;
} nail;

int cmp(const void *a, const void *b)
{
     return ((rod *)a)->l - ((rod *)b)->l;
}

int cmp2(const void *a, const void *b)
{
     return ((nail *)a)->l - ((nail *)b)->l;
}

int diff(int x1, int y1, int x2, int y2)
{
     return abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
     int n, m, p = 0, q = 0, i, j;
     int x[500], y[500];
     rod r[500];
     nail a[250], b[250];
     int c[500];

     scanf("%d %d", &n, &m);

     for (i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);

     for (i = 0; i < m; i++) {
	  scanf("%d", &r[i].l);

	  r[i].i = i + 1;
     }

     for (i = 0; i < n; i++) {
	  if (i % 2 == 0) {
	       if (i == 0) {
		    a[i / 2].l = diff(x[i], y[i], x[n - 1], y[n - 1]) + diff(x[i], y[i], x[i + 1], y[i + 1]);
	       } else {
		    a[i / 2].l = diff(x[i], y[i], x[i - 1], y[i - 1]) + diff(x[i], y[i], x[i + 1], y[i + 1]);
	       }

	       a[i / 2].i = i;
	  } else {
	       if (i == n - 1) {
		    b[i / 2].l = diff(x[i], y[i], x[i - 1], y[i - 1]) + diff(x[i], y[i], x[0], y[0]);
	       } else {
		    b[i / 2].l = diff(x[i], y[i], x[i - 1], y[i - 1]) + diff(x[i], y[i], x[i + 1], y[i + 1]);
	       }

	       b[i / 2].i = i;
	  }
     }

     qsort(r, n, sizeof(rod), cmp);
     qsort(a, n / 2, sizeof(nail), cmp2);
     qsort(b, n / 2, sizeof(nail), cmp2);

     for (i = 0; i < n; i++) c[i] = -1;

     for (i = 0; i < n / 2; i++) {
	  for (; p < n; p++) {
	       if (a[i].l == r[p].l) break;
	  }

	  if (p == n) break;

	  c[a[i].i] = r[p++].i;
     }

     if (i >= n / 2) {
	  puts("YES");

	  for (i = 0; i < n; i++) {
	       if (i > 0) putchar(' ');
	       printf("%d", c[i]);
	  }
	  puts("");

	  return 0;
     }

     for (i = 0; i < n; i++) c[i] = -1;

     for (i = 0; i < n / 2; i++) {
	  for (; q < n; q++) {
	       if (b[i].l == r[q].l) break;
	  }

	  if (q == n) break;

	  c[b[i].i] = r[q++].i;
     }

     if (i >= n / 2) {
	  puts("YES");

	  for (i = 0; i < n; i++) {
	       if (i > 0) putchar(' ');
	       printf("%d", c[i]);
	  }
	  puts("");

	  return 0;
     }

     puts("NO");

     return 0;
}