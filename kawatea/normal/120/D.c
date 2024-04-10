#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
     return *((int *)a) - *((int *)b);
}

int main()
{
     int n, m, a, b, c, sum = 0, i, j, k;
     int d[50][50], e[50], f[50];
     FILE *fp1, *fp2;

     fp1 = fopen("input.txt", "r");
     fp2 = fopen("output.txt", "w");

     fscanf(fp1, "%d %d", &n, &m);

     for (i = 0; i < n; i++) {
	  for (j = 0; j < m; j++) {
	       fscanf(fp1, "%d", &d[i][j]);
	  }
     }

     fscanf(fp1, "%d %d %d", &a, &b, &c);

     for (i = 0; i < n; i++) {
	  int s = 0;

	  for (j = 0; j < m; j++) s += d[i][j];

	  e[i] = s;
     }

     for (i = 0; i < m; i++) {
	  int s = 0;

	  for (j = 0; j < n; j++) s += d[j][i];

	  f[i] = s;
     }

     if (a > b) {
	  int tmp = a; a = b; b = tmp;
     }

     if (a > c) {
	  int tmp = a; a = c; c = tmp;
     }

     if (b > c) {
	  int tmp = b; b = c; c = tmp;
     }

     for (i = 0; i < n - 2; i++) {
	  for (j = i + 1; j < n - 1; j++) {
	       int p[3] = {0};

	       for (k = 0; k < n; k++) {
		    if (k <= i) {
			 p[0] += e[k];
		    } else if (k <= j) {
			 p[1] += e[k];
		    } else {
			 p[2] += e[k];
		    }
	       }

	       qsort(p, 3, sizeof(int), cmp);

	       if (p[0] == a && p[1] == b && p[2] == c) sum++;
	  }
     }

     for (i = 0; i < m - 2; i++) {
	  for (j = i + 1; j < m - 1; j++) {
	       int p[3] = {0};

	       for (k = 0; k < m; k++) {
		    if (k <= i) {
			 p[0] += f[k];
		    } else if (k <= j) {
			 p[1] += f[k];
		    } else {
			 p[2] += f[k];
		    }
	       }

	       qsort(p, 3, sizeof(int), cmp);

	       if (p[0] == a && p[1] == b && p[2] == c) sum++;
	  }
     }

     fprintf(fp2, "%d\n", sum);

     fclose(fp1);
     fclose(fp2);

     return 0;
}