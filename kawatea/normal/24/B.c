#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
     char s[51];
     int point;
     int a[50];
} driver;

int cmp1(const void *a, const void *b)
{
     if (((driver *)a)->point != ((driver *)b)->point) {
	  return ((driver *)b)->point - ((driver *)a)->point;
     } else {
	  int i;

	  for (i = 0; i < 50; i++) {
	       if (((driver *)a)->a[i] != ((driver *)b)->a[i]) {
		    return ((driver *)b)->a[i] - ((driver *)a)->a[i];
	       }
	  }

	  return 0;
     }
}

int cmp2(const void *a, const void *b)
{
     if (((driver *)a)->a[0] != ((driver *)b)->a[0]) {
	  return ((driver *)b)->a[0] - ((driver *)a)->a[0];
     } else if (((driver *)a)->point != ((driver *)b)->point) {
	  return ((driver *)b)->point - ((driver *)a)->point;
     } else {
	  int i;

	  for (i = 1; i < 50; i++) {
	       if (((driver *)a)->a[i] != ((driver *)b)->a[i]) {
		    return ((driver *)b)->a[i] - ((driver *)a)->a[i];
	       }
	  }

	  return 0;
     }
}

int main()
{
     int t, n, p = 0, i, j, k, l;
     driver d[1000];
     char s[51];
     int score[50] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1, 0};

     scanf("%d", &t);

     for (i = 0; i < t; i++) {
	  scanf("%d", &n);

	  for (j = 0; j < n; j++) {
	       scanf("%s", s);

	       for (k = 0; k < p; k++) {
		    if (strcmp(d[k].s, s) == 0) break;
	       }

	       if (k == p) {
		    strcpy(d[k].s, s);
		    d[k].point = 0;

		    for (l = 0; l < 50; l++) d[k].a[l] = 0;

		    p++;
	       }

	       d[k].point += score[j];
	       d[k].a[j]++;
	  }
     }

     qsort(d, p, sizeof(driver), cmp1);

     printf("%s\n", d[0].s);

     qsort(d, p, sizeof(driver), cmp2);

     printf("%s\n", d[0].s);

     return 0;
}