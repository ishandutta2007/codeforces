#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int a;
     int b;
     int c;
} position;

int cmp(const void *a, const void *b)
{
     if (((position *)a)->a != ((position *)b)->a) {
	  return ((position *)a)->a - ((position *)b)->a;
     } else {
	  return ((position *)a)->b - ((position *)b)->b;
     }
}

int cmp2(const void *a, const void *b)
{
     if (((position *)a)->b != ((position *)b)->b) {
	  return ((position *)a)->b - ((position *)b)->b;
     } else {
	  return ((position *)a)->a - ((position *)b)->a;
     }
}

int cmp3(const void *a, const void *b)
{
     if (((position *)a)->a + ((position *)a)->b != ((position *)b)->a + ((position *)b)->b) {
	  return ((position *)a)->a + ((position *)a)->b - ((position *)b)->a - ((position *)b)->b;
     } else {
	  return ((position *)a)->a - ((position *)b)->a;
     }
}

int cmp4(const void *a, const void *b)
{
     if (((position *)a)->a - ((position *)a)->b != ((position *)b)->a - ((position *)b)->b) {
	  return ((position *)a)->a - ((position *)a)->b - ((position *)b)->a + ((position *)b)->b;
     } else {
	  return ((position *)a)->a - ((position *)b)->a;
     }
}

int main()
{
     int n, m, i, j;
     position p[100000];
     int t[9] = {0};

     scanf("%d %d", &n, &m);

     for (i = 0; i < m; i++) {
	  scanf("%d %d", &p[i].a, &p[i].b);

	  p[i].c = 0;
     }

     qsort(p, m, sizeof(position), cmp);

     for (i = 0; i < m; i++) {
	  for (j = i; j < m; j++) {
	       if (p[i].a != p[j].a) break;
	  }

	  if (i != j - 1) {
	       p[i].c++;
	       p[j - 1].c++;

	       for (i++; i < j - 1; i++) p[i].c += 2;
	  }
     }

     qsort(p, m, sizeof(position), cmp2);

     for (i = 0; i < m; i++) {
	  for (j = i; j < m; j++) {
	       if (p[i].b != p[j].b) break;
	  }

	  if (i != j - 1) {
	       p[i].c++;
	       p[j - 1].c++;

	       for (i++; i < j - 1; i++) p[i].c += 2;
	  }
     }

     qsort(p, m, sizeof(position), cmp3);

     for (i = 0; i < m; i++) {
	  for (j = i; j < m; j++) {
	       if (p[i].a + p[i].b != p[j].a + p[j].b) break;
	  }

	  if (i != j - 1) {
	       p[i].c++;
	       p[j - 1].c++;

	       for (i++; i < j - 1; i++) p[i].c += 2;
	  }
     }

     qsort(p, m, sizeof(position), cmp4);

     for (i = 0; i < m; i++) {
	  for (j = i; j < m; j++) {
	       if (p[i].a - p[i].b != p[j].a - p[j].b) break;
	  }

	  if (i != j - 1) {
	       p[i].c++;
	       p[j - 1].c++;

	       for (i++; i < j - 1; i++) p[i].c += 2;
	  }
     }

     for (i = 0; i < m; i++) t[p[i].c]++;

     for (i = 0; i < 9; i++) {
	  if (i > 0) putchar(' ');

	  printf("%d", t[i]);
     }

     puts("");

     return 0;
}