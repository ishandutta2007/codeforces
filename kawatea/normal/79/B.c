#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int x;
     int y;
} point;

int cmp(const void *a, const void *b)
{
     if (((point *)a)->x == ((point *)b)->x) {
	  return ((point *)a)->y - ((point *)b)->y;
     } else {
	  return ((point *)a)->x - ((point *)b)->x;
     }
}

int main()
{
     int n, m, k, t, i, j;
     point p[1000];

     scanf("%d %d %d %d", &n, &m, &k, &t);

     for (i = 0; i < k; i++) scanf("%d %d", &p[i].x, &p[i].y);

     qsort(p, k, sizeof(point), cmp);

     for (i = 0; i < t; i++) {
	  int c, x, y, f = 0;

	  scanf("%d %d", &x, &y);

	  c = (x - 1) * m + y;

	  for (j = 0; j < k; j++) {
	       if (p[j].x == x && p[j].y == y) {
		    f = 1;
		    puts("Waste");
		    break;
	       }
	       if (p[j].x > x || (p[j].x == x && p[j].y > y)) break;
	  }

	  c -= j;

	  if (f == 0) {
	       if (c % 3 == 0) {
		    puts("Grapes");
	       } else if (c % 3 == 1) {
		    puts("Carrots");
	       } else {
		    puts("Kiwis");
	       }
	  }
     }

     return 0;
}