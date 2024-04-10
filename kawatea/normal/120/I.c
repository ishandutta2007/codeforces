#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
     int n, p = 0, i, j, k;
     int a[10][10] = {6, 2, 4, 4, 3, 4, 5, 3, 6, 5,
                      2, 2, 1, 2, 2, 1, 1, 2, 2, 2,
                      4, 1, 5, 4, 2, 3, 4, 2, 5, 4,
                      4, 2, 4, 5, 3, 4, 4, 3, 5, 5,
                      3, 2, 2, 3, 4, 3, 3, 2, 4, 4,
                      4, 1, 3, 4, 3, 5, 5, 2, 5, 5,
                      5, 1, 4, 4, 3, 5, 6, 2, 6, 5,
                      3, 2, 2, 3, 2, 2, 2, 3, 3, 3,
                      6, 2, 5, 5, 4, 5, 6, 3, 7, 6,
                      5, 2, 4, 5, 4, 5, 5, 3, 6, 6};
     char s[200001];
     FILE *fp1, *fp2;

     fp1 = fopen("input.txt", "r");
     fp2 = fopen("output.txt", "w");

     fscanf(fp1, "%s", s);

     n = strlen(s) / 2;

     for (i = 1; i <= n; i++) {
	  int x = s[n * 2 - i] - '0', m = a[s[n - i] - '0'][x];

	  for (j = x + 1; j < 10; j++) {
	       if (a[s[n - i] - '0'][j] + p > m) break;
	  }

	  if (j == 10) {
	       s[n * 2 - i] = '8';

	       p += a[s[n - i] - '0'][8] - m;
	  } else {
	       s[n * 2 - i] = j + '0';

	       p -= m - a[s[n - i] - '0'][j];

	       for (j = i - 1; j > 0; j--) {
		    m = a[s[n - j] - '0'][s[n * 2 - j] - '0'];

		    for (k = 0; k < 8; k++) {
			 if (a[s[n - j] - '0'][k] + p > m) break;
		    }

		    s[n * 2 - j] = k + '0';

		    p -= m - a[s[n - j] - '0'][k];
	       }

	       fprintf(fp2, "%s\n", s);

	       fclose(fp1);
	       fclose(fp2);

	       return 0;
	  }
     }

     for (i = 1; i <= n; i++) {
	  int x = s[n - i] - '0', m = a[x][s[n * 2 - i] - '0'];

	  for (j = x + 1; j < 10; j++) {
	       if (a[j][s[n * 2 - i] - '0'] + p > m) break;
	  }

	  if (j == 10) {
	       s[n - i] = '8';

	       p += a[8][s[n * 2 - i] - '0'] - m;
	  } else {
	       s[n - i] = j + '0';

	       p -= m - a[j][s[n * 2 - i] - '0'];

	       for (j = i - 1; j > 0; j--) {
		    m = a[s[n - j] - '0'][s[n * 2 - j] - '0'];

		    for (k = 0; k < 8; k++) {
			 if (a[k][s[n * 2 - j] - '0'] + p > m) break;
		    }

		    s[n - j] = k + '0';

		    p -= m - a[k][s[n * 2 - j] - '0'];
	       }

	       for (j = n; j > 0; j--) {
		    m = a[s[n - j] - '0'][s[n * 2 - j] - '0'];

		    for (k = 0; k < 8; k++) {
			 if (a[s[n - j] - '0'][k] + p > m) break;
		    }

		    s[n * 2 - j] = k + '0';

		    p -= m - a[s[n - j] - '0'][k];
	       }

	       fprintf(fp2, "%s\n", s);

	       fclose(fp1);
	       fclose(fp2);

	       return 0;
	  }
     }

     fprintf(fp2, "-1\n");

     fclose(fp1);
     fclose(fp2);

     return 0;
}