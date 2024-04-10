#include <stdio.h>

int main()
{
     int n, k, x = 1, y, i, j, l, p, q;
     char c[3][4];
     char s[243][243];
     FILE *fp1, *fp2;

     fp1 = fopen("input.txt", "r");
     fp2 = fopen("output.txt", "w");

     fscanf(fp1, "%d %d", &n, &k);

     for (i = 0; i < k - 1; i++) x *= n;
     y = x * n;

     for (i = 0; i < y; i++) {
	  for (j = 0; j < y; j++) {
	       s[i][j] = '.';
	  }
     }

     for (i = 0; i < n; i++) fscanf(fp1, "%s", c[i]);

     for (i = 0; i < k; i++) {
	  for (j = 0; j < n; j++) {
	       for (l = 0; l < n; l++) {
		    if (c[j][l] == '*') {
			 for (p = 0; p < y; p++) {
			      for (q = 0; q < y; q++) {
				   if (j % n == p / x % n && l % n == q / x % n) {
					s[p][q] = '*';
				   }
			      }
			 }
		    }
	       }
	  }

	  x /= n;
     }

     for (i = 0; i < y; i++) {
	  for (j = 0; j < y; j++) {
	       fprintf(fp2, "%c", s[i][j]);
	  }
	  fprintf(fp2, "\n");
     }

     fclose(fp1);
     fclose(fp2);

     return 0;
}