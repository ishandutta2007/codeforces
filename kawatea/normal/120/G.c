#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
     int a1;
     int b1;
     int a2;
     int b2;
     int d[100];
     int p;
     char s[100][21];
} team;

int main()
{
     int n, t, m, x = 0, y = 0, z = 0, i, j;
     team a[100];
     int c[100], f[100] = {0};
     char s[100][21];
     FILE *fp1, *fp2;

     fp1 = fopen("input.txt", "r");
     fp2 = fopen("output.txt", "w");

     fscanf(fp1, "%d %d", &n, &t);

     for (i = 0; i < n; i++) {
	  fscanf(fp1, "%d %d %d %d", &a[i].a1, &a[i].b1, &a[i].a2, &a[i].b2);

	  for (j = 0; j < 100; j++) a[i].d[j] = 0;

	  a[i].p = 0;
     }

     fscanf(fp1, "%d", &m);

     for (i = 0; i < m; i++) fscanf(fp1, "%s %d", s[i], &c[i]);

     while (1) {
	  int r = t, e = 0;

	  while (r > 0) {
	       int p;

	       if (z == 0) {
		    p = c[y] - a[x].a1 - a[x].b2 - a[x].d[y];
	       } else {
		    p = c[y] - a[x].a2 - a[x].b1 - a[x].d[y];
	       }

	       if (p < 1) p = 1;

	       if (p <= r) {
		    r -= p;

		    strcpy(a[x].s[a[x].p++], s[y]);

		    f[y] = 1;
	       } else {
		    a[x].d[y] += r;

		    r = 0;
	       }

	       for (i = y + 1; i < m; i++) {
		    if (f[i] == 0) break;
	       }

	       if (i == m) {
		    for (i = 0; i < y; i++) {
			 if (f[i] == 0) break;
		    }
	       }

	       if (i == y && f[i] == 1) {
		    e = 1;

		    break;
	       }

	       y = i;
	  }

	  if (e == 1) break;

	  x++;

	  if (x == n) {
	       x = 0;
	       z = (z + 1) % 2;
	  }
     }

     for (i = 0; i < n; i++) {
	  fprintf(fp2, "%d", a[i].p);

	  for (j = 0; j < a[i].p; j++) fprintf(fp2, " %s", a[i].s[j]);

	  fprintf(fp2, "\n");
     }

     fclose(fp1);
     fclose(fp2);

     return 0;
}