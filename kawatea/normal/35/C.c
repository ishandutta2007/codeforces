#include <stdio.h>
#include <stdlib.h>

int main()
{
     int n, m, k, max = 0, p = 1, q = 1, i, j, l;
     int x[10], y[10];
     FILE *fp1, *fp2;

     fp1 = fopen("input.txt", "r");
     fp2 = fopen("output.txt", "w");

     fscanf(fp1, "%d %d", &n, &m);
     fscanf(fp1, "%d", &k);

     for (i = 0; i < k; i++) fscanf(fp1, "%d %d", &x[i], &y[i]);

     for (i = 1; i <= n; i++) {
	  for (j = 1; j <= m; j++) {
	       int c = 10000;

	       for (l = 0; l < k; l++) {
		    if (abs(i - x[l]) + abs(j - y[l]) < c) {
			 c = abs(i - x[l]) + abs(j - y[l]);
		    }
	       }

	       if (c > max) {
		    max = c;
		    p = i;
		    q = j;
	       }
	  }
     }

     fprintf(fp2, "%d %d\n", p, q);

     fclose(fp1);
     fclose(fp2);

     return 0;
}