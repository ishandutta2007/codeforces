#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int l;
     int r;
} segment;

int cmp(const void *a, const void *b)
{
     return ((segment *)a)->l - ((segment *)b)->l;
}

int main()
{
     int n, c = 0, p = 0, i, j;
     segment s[1000];
     int a[1000], f[1000] = {0};

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  int x, y;

	  scanf("%d %d", &x, &y);

	  if (x < y) {
	       s[i].l = x;
	       s[i].r = y;
	  } else {
	       s[i].l = y;
	       s[i].r = x;
	  }
     }

     qsort(s, n, sizeof(segment), cmp);

     for (i = s[0].l; ; i++) {
	  int min = 1e9;

	  for (j = c; j < n; j++) {
	       if (s[j].l > i) break;

	       if (s[j].r < min) min = s[j].r;
	  }

	  if (min == i) {
	       for (j = c; j < n; j++) {
		    if (s[j].l > min) break;

		    f[j] = 1;
	       }

	       a[p++] = min;
	       c = j;

	       if (c == n) break;
	  }
     }

     printf("%d\n", p);

     for (i = 0; i < p; i++) {
	  if (i > 0) putchar(' ');
	  printf("%d", a[i]);
     }
     puts("");

     return 0;
}