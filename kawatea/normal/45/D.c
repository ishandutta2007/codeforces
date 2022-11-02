#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int l;
     int r;
     int i;
     int f;
} event;

int cmp(const void *a, const void *b)
{
     return ((event *)a)->l - ((event *)b)->l;
}

int main()
{
     int n, m1 = 1e9, m2 = 0, i, j;
     event e[100];
     int a[100];

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%d %d", &e[i].l, &e[i].r);

	  e[i].i = i;
	  e[i].f = 0;

	  if (e[i].l < m1) m1 = e[i].l;
	  if (e[i].r > m2) m2 = e[i].r;
     }

     qsort(e, n, sizeof(event), cmp);

     for (i = m1; i <= m2; i++) {
	  int num = -1, p = 1e9;

	  for (j = 0; j < n; j++) {
	       if (e[j].l > i) break;

	       if (e[j].r >= i && e[j].f == 0) {
		    if (e[j].r < p) {
			 num = j;
			 p = e[j].r;
		    }
	       }
	  }

	  if (num == -1) {
	       for (j = 0; j < n; j++) {
		    if (e[j].f == 0) break;
	       }

	       if (j == n) break;

	       i = e[j].l - 1;
	  } else {
	       a[e[num].i] = i;

	       e[num].f = 1;
	  }
     }

     for (i = 0; i < n; i++) {
	  if (i > 0) putchar(' ');

	  printf("%d", a[i]);
     }
     puts("");

     return 0;
}