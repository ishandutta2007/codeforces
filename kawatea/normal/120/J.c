#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int x;
     int y;
     int f1;
     int f2;
     int i;
} point;

point p[100000];

int cmp(const void *a, const void *b)
{
     return ((point *)a)->x - ((point *)b)->x;
}

int dist(int x, int y)
{
     return x * x + y * y;
}

int main()
{
     int n, x = 0, y = 1, z = 2, m, d = 1, i, j;
     int s[100000] = {0, 1};
     FILE *fp1, *fp2;

     fp1 = fopen("input.txt", "r");
     fp2 = fopen("output.txt", "w");

     fscanf(fp1, "%d", &n);

     for (i = 0; i < n; i++) {
	  fscanf(fp1, "%d %d", &p[i].x, &p[i].y);

	  if (p[i].x >= 0) {
	       p[i].f1 = 0;
	  } else {
	       p[i].x *= -1;
	       p[i].f1 = 1;
	  }

	  if (p[i].y >= 0) {
	       p[i].f2 = 0;
	  } else {
	       p[i].y *= -1;
	       p[i].f2 = 1;
	  }

	  p[i].i = i + 1;
     }

     qsort(p, n, sizeof(point), cmp);

     m = dist(p[0].x - p[1].x, p[0].y - p[1].y);

     for (i = 2; i < n; s[z++] = i++) {
	  for (j = 0; j < z; j++) {
	       if (dist(p[s[j]].x - p[i].x, p[s[j]].y - p[i].y) < m) {
		    m = dist(p[s[j]].x - p[i].x, p[s[j]].y - p[i].y);

		    x = s[j];
		    y = i;
	       }

	       if (p[s[j]].x < p[i].x - m) s[j--] = s[--z];
	  }
     }

     if (p[x].f1 == p[y].f1) d++;
     if (p[x].f2 == p[y].f2) d += 2;

     fprintf(fp2, "%d %d %d %d\n", p[x].i, 1, p[y].i, d);

     fclose(fp1);
     fclose(fp2);

     return 0;
}