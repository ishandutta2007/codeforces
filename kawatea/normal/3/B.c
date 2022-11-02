#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int p;
     int i;
} vehicle;

int cmp(const void *a, const void *b)
{
     return ((vehicle *)b)->p - ((vehicle *)a)->p;
}

int main()
{
     int n, v, sum = 0, x = 0, y = 0, i, j;
     vehicle a[100000], b[100000];
     int c[100000] = {0};

     scanf("%d %d", &n, &v);

     for (i = 0; i < n; i++) {
	  int t, p;

	  scanf("%d %d", &t, &p);

	  if (t == 1) {
	       a[x].p = p;
	       a[x++].i = i;
	  } else {
	       b[y].p = p;
	       b[y++].i = i;
	  }
     }

     qsort(a, x, sizeof(vehicle), cmp);
     qsort(b, y, sizeof(vehicle), cmp);

     i = 0; j = 0;

     while (v) {
	  if (i == x && j == y) break;

	  if (i == x) {
	       if (v == 1) break;

	       sum += b[j].p;

	       c[b[j++].i] = 1;

	       v -= 2;

	       continue;
	  }

	  if (j == y) {
	       sum += a[i].p;

	       c[a[i++].i] = 1;

	       v--;

	       continue;
	  }

	  if (v >= 2) {
	       if (i == x - 1) {
		    if (a[i].p > b[j].p) {
			 sum += a[i].p;

			 c[a[i++].i] = 1;

			 v--;
		    } else {
			 sum += b[j].p;

			 c[b[j++].i] = 1;

			 v -= 2;
		    }
	       } else {
		    if (a[i].p + a[i + 1].p > b[j].p) {
			 sum += a[i].p;

			 c[a[i++].i] = 1;

			 v--;
		    } else {
			 sum += b[j].p;

			 c[b[j++].i] = 1;

			 v -= 2;
		    }
	       }
	  } else {
	       sum += a[i].p;

	       c[a[i].i] = 1;

	       break;
	  }
     }

     printf("%d\n", sum);

     for (i = 0; i < n; i++) {
	  if (c[i] == 1) {
	       printf("%d ", i + 1);
	  }
     }
     puts("");

     return 0;
}