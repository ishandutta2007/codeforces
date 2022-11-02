#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int x;
     int r;
     int f;
     int i;
} circle;

int diff(int x1, int y1, int x2, int y2)
{
     return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int cmp(const void *a, const void *b)
{
     return ((circle *)a)->x - ((circle *)b)->x;
}

int cmp2(const void *a, const void *b)
{
     return ((circle *)a)->i - ((circle *)b)->i;
}

int main()
{
     int n, m, num = 0, i;
     circle c[10000];

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%d %d", &c[i].x, &c[i].r);

	  c[i].f = -1;
	  c[i].i = i;
     }

     qsort(c, n, sizeof(circle), cmp);

     scanf("%d", &m);

     for (i = 0; i < m; i++) {
	  int x, y, l = -1, r = n, u = (l + r) / 2;

	  scanf("%d %d", &x, &y);

	  while (r - l > 1) {
	       if (c[u].x >= x) {
		    r = u;
		    u = (l + r) / 2;
	       } else {
		    l = u;
		    u = (l + r) / 2;
	       }
	  }

	  if (r < n && c[r].f == -1 && diff(c[r].x, 0, x, y) <= c[r].r * c[r].r) {
	       c[r].f = i + 1;

	       num++;
	  }

	  if (r > 0 && c[r - 1].f == -1 && diff(c[r - 1].x, 0, x, y) <= c[r - 1].r * c[r - 1].r) {
	       c[r - 1].f = i + 1;

	       num++;
	  }
     }

     qsort(c, n, sizeof(circle), cmp2);

     printf("%d\n", num);

     for (i = 0; i < n; i++) {
	  if (i > 0) putchar(' ');

	  printf("%d", c[i].f);
     }

     puts("");

     return 0;
}