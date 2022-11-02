#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int p;
     int t;
} team;

int cmp(const void *a, const void *b)
{
     if (((team *)a)->p != ((team *)b)->p) {
	  return ((team *)b)->p - ((team *)a)->p;
     } else {
	  return ((team *)a)->t - ((team *)b)->t;
     }
}

int main()
{
     int n, k, sum = 1, i;
     team t[50];

     scanf("%d %d", &n, &k);

     for (i = 0; i < n; i++) scanf("%d %d", &t[i].p, &t[i].t);

     qsort(t, n, sizeof(team), cmp);

     k--;

     for (i = k - 1; i >= 0; i--) {
	  if (t[i].p == t[k].p && t[i].t == t[k].t) {
	       sum++;
	  } else {
	       break;
	  }
     }

     for (i = k + 1; i < n; i++) {
	  if (t[i].p == t[k].p && t[i].t == t[k].t) {
	       sum++;
	  } else {
	       break;
	  }
     }

     printf("%d\n", sum);

     return 0;
}