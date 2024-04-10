#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int a;
     int b;
} walrus;

int cmp(const void *a, const void *b)
{
     if (((walrus *)a)->a != ((walrus *)b)->a) {
	  return ((walrus *)a)->a - ((walrus *)b)->a;
     } else {
	  return ((walrus *)a)->b - ((walrus *)b)->b;
     }
}

int main()
{
     int n, m = -1, i;
     int a[100000];
     walrus w[100000];

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%d", &w[i].a);

	  w[i].b = i;
     }

     qsort(w, n, sizeof(walrus), cmp);

     for (i = 0; i < n; i++) {
	  if (w[i].b > m) m = w[i].b;

	  a[w[i].b] = m - w[i].b - 1;
     }

     for (i = 0; i < n; i++) {
	  if (i > 0) putchar(' ');

	  printf("%d", a[i]);
     }

     puts("");

     return 0;
}