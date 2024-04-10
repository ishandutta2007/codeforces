#include <stdio.h>
#include <string.h>

int main()
{
     int n, m, k, i, j, l;
     int a[30][30] = {0};
     char s[30][30][11];
     FILE *fp1, *fp2;

     fp1 = fopen("input.txt", "r");
     fp2 = fopen("output.txt", "w");

     fscanf(fp1, "%d %d %d", &n, &m, &k);

     for (i = 0; i < k; i++) {
	  char c[5];

	  fscanf(fp1, "%s", c);

	  if (c[0] == '+') {
	       int x, y;
	       char d[11];

	       fscanf(fp1, "%d %d %s", &x, &y, d);

	       x--; y--;

	       for (j = x; j < n; j++) {
		    for (l = y; l < m; l++) {
			 if (a[j][l] == 0) {
			      a[j][l] = 1;
			      strcpy(s[j][l], d);

			      j = n;

			      break;
			 }
		    }

		    y = 0;
	       }
	  } else {
	       int f = 0;
	       char d[11];

	       fscanf(fp1, "%s", d);

	       for (j = 0; j < n; j++) {
		    for (l = 0; l < m; l++) {
			 if (a[j][l] == 1 && strcmp(s[j][l], d) == 0) {
			      fprintf(fp2, "%d %d\n", j + 1, l + 1);

			      a[j][l] = 0;

			      f = 1;
			      j = n;

			      break;
			 }
		    }
	       }

	       if (f == 0) fprintf(fp2, "-1 -1\n");
	  }
     }

     fclose(fp1);
     fclose(fp2);

     return 0;
}