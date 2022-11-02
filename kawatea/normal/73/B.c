#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
     char s[21];
     int a;
} racer;

racer r[100000];

int cmp(const void *a, const void *b)
{
     return *((int *)a) - *((int *)b);
}

int cmp2(const void *a, const void *b)
{
     if (((racer *)a)->a != ((racer *)b)->a) {
	  return ((racer *)b)->a - ((racer *)a)->a;
     } else {
	  return strcmp(((racer *)a)->s, ((racer *)b)->s);
     }
}

int main()
{
     int n, m, c, x, y, p, q, i, j;
     int b[100000];
     char s[21];

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%s %d", r[i].s, &r[i].a);

     scanf("%d", &m);

     for (i = 0; i < m; i++) scanf("%d", &b[i]);
     for (; i < n; i++) b[i] = 0;

     scanf("%s", s);

     qsort(b, n, sizeof(int), cmp);

     for (i = 0; i < n; i++) {
	  if (strcmp(s, r[i].s) == 0) break;
     }

     r[i].a += b[0];

     qsort(r, n, sizeof(racer), cmp2);

     for (i = 0; i < n; i++) {
	  if (strcmp(s, r[i].s) == 0) break;
     }

     c = i;

     p = 0;
     q = n - 1;

     for (i = n - 1; i >= n - m && i > 0; i--) {
	  for (j = q; j > c; j--) {
	       if (r[j].a + b[i] > r[c].a) {
		    break;
	       } else if (r[j].a + b[i] == r[c].a && strcmp(s, r[j].s) > 0) {
		    break;
	       }
	  }

	  if (j > c) {
	       p++;

	       q = j - 1;
	  } else {
	       break;
	  }
     }

     y = c + p + 1;

     r[c].a += b[n - 1] - b[0];

     qsort(r, n, sizeof(racer), cmp2);

     for (i = 0; i < n; i++) {
	  if (strcmp(s, r[i].s) == 0) break;
     }

     c = i;
     x = 1;
     j = n - 2;

     for (i = n - 1; i >= 0; i--) {
	  if (i == c) continue;

	  for (; j >= 0; j--) {
	       if (r[i].a + b[j] < r[c].a) {
		    j--;

		    if (j == -1) x--;

		    break;
	       } else if (r[i].a + b[j] == r[c].a && strcmp(s, r[i].s) < 0) {
		    j--;

		    if (j == -1) x--;

		    break;
	       }
	  }

	  if (j == -1) x++;
     }

     printf("%d %d\n", x, y);

     return 0;
}