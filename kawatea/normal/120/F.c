#include <stdio.h>
#include <stdlib.h>

int dfs(int x, int f, int a[100][100], int b[100], int p[100])
{
     int m1 = 0, m2 = 0, i;

     b[x] = 1;

     for (i = 0; i < p[x]; i++) {
	  if (b[a[x][i]] == 0) {
	       int m = dfs(a[x][i], 1, a, b, p) + 1;

	       if (m > m1) {
		    m2 = m1;
		    m1 = m;
	       } else if (m > m2) {
		    m2 = m;
	       }
	  }
     }

     if (f == 0) {
	  return m1 + m2;
     } else {
	  return m1;
     }
}

int main()
{
     int n, k, sum = 0, i, j;
     FILE *fp1, *fp2;

     fp1 = fopen("input.txt", "r");
     fp2 = fopen("output.txt", "w");

     fscanf(fp1, "%d", &n);

     for (i = 0; i < n; i++) {
	  int a[100][100];
	  int p[100] = {0};
	  int m = 0;

	  fscanf(fp1, "%d", &k);

	  for (j = 0; j < k - 1; j++) {
	       int x, y;

	       fscanf(fp1, "%d %d", &x, &y);

	       x--; y--;

	       a[x][p[x]++] = y;
	       a[y][p[y]++] = x;
	  }

	  for (j = 0; j < k; j++) {
	       int b[100] = {0};
	       int c = dfs(j, 0, a, b, p);

	       if (c > m) m = c;
	  }

	  sum += m;
     }

     fprintf(fp2, "%d\n", sum);

     fclose(fp1);
     fclose(fp2);

     return 0;
}