#include <stdio.h>

int b[2001][1000];

int main()
{
     int n, max = 0, i, j;
     char s[5000][5];
     int a[5000], f[2001], p[2001] = {0};
     int c[1000] = {0};

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%s %d", s[i], &a[i]);

     for (i = 0; i <= 2000; i++) f[i] = -1;

     for (i = 0; i < n; i++) {
	  if (s[i][0] == 's') f[a[i]] = i;
     }

     for (i = 2000; i >= 0; i--) {
	  if (f[i] >= 0) {
	       for (j = f[i]; j >= 0; j--) {
		    if (s[j][0] == 'w' && a[j] == i) break;

		    if (a[j] == -1) break;
	       }

	       if (a[j] == -1) continue;

	       if (j >= 0) {
		    p[i] = 1;

		    for (; j < f[i]; j++) {
			 if (s[j][0] == 'w') a[j] = -1;
		    }
	       }
	  }
     }

     b[0][0] = 1;

     for (i = 1; i <= 2000; i++) {
	  int x = 0;

	  for (j = 0; j < 1000; j++) {
	       b[i][j] = b[i - 1][j] * 2 + x;

	       x = b[i][j] / 10;

	       b[i][j] %= 10;
	  }
     }

     for (i = 0; i <= 2000; i++) {
	  if (p[i] == 1) {
	       int x = 0;

	       for (j = 0; j < 1000; j++) {
		    c[j] += b[i][j] + x;

		    x = c[j] / 10;

		    c[j] %= 10;
	       }
	  }
     }

     for (j = 999; j > 0; j--) {
	  if (c[j] > 0) break;
     }

     for (; j >= 0; j--) printf("%d", c[j]);
     puts("");

     return 0;
}