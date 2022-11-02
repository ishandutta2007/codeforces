#include <stdio.h>

int a[1000][1000][2];
int dp[1000][1000][2];
char c[1000][1000][2];

int min(int a, int b)
{
     if (a < b) {
	  return a;
     } else {
	  return b;
     }
}

int main()
{
     int n, p, q, f = 0, i, j;
     char s[2000];

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  for (j = 0; j < n; j++) {
	       int x;
	       scanf("%d", &x);

	       if (x == 0) {
		    p = i; q = j; f = 1;

		    a[i][j][0] = a[i][j][1] = -1;

		    continue;
	       }

	       while (x % 2 == 0) {
		    a[i][j][0]++;

		    x /= 2;
	       }

	       while (x % 5 == 0) {
		    a[i][j][1]++;

		    x /= 5;
	       }
	  }
     }

     dp[0][0][0] = a[0][0][0]; dp[0][0][1] = a[0][0][1];

     for (i = 1; i < n; i++) {
	  if (a[0][i][0] >= 0) {
	       dp[0][i][0] = dp[0][i - 1][0] + a[0][i][0];
	       dp[0][i][1] = dp[0][i - 1][1] + a[0][i][1];
	  } else {
	       dp[0][i][0] = dp[0][i][1] = 1e9;
	  }

	  if (a[i][0][0] >= 0) {
	       dp[i][0][0] = dp[i - 1][0][0] + a[i][0][0];
	       dp[i][0][1] = dp[i - 1][0][1] + a[i][0][1];
	  } else {
	       dp[i][0][0] = dp[i][0][1] = 1e9;
	  }

	  c[0][i][0] = c[0][i][1] = 'R';
	  c[i][0][0] = c[i][0][1] = 'D';
     }

     for (i = 1; i < n; i++) {
	  for (j = 1; j < n; j++) {
	       if (a[i][j][0] >= 0) {
		    dp[i][j][0] = min(dp[i][j - 1][0], dp[i - 1][j][0]) + a[i][j][0];
		    dp[i][j][1] = min(dp[i][j - 1][1], dp[i - 1][j][1]) + a[i][j][1];
	       } else {
		    dp[i][j][0] = dp[i][j][1] = 1e9;
	       }

	       if (dp[i][j - 1][0] < dp[i - 1][j][0]) {
		    c[i][j][0] = 'R';
	       } else {
		    c[i][j][0] = 'D';
	       }

	       if (dp[i][j - 1][1] < dp[i - 1][j][1]) {
		    c[i][j][1] = 'R';
	       } else {
		    c[i][j][1] = 'D';
	       }
	  }
     }

     if (f == 1 && dp[n - 1][n - 1][0] >= 1 && dp[n - 1][n - 1][1] >= 1) {
	  puts("1");
	  for (i = 0; i < p; i++) putchar('D');
	  for (j = 0; j < q; j++) putchar('R');
	  for (; i < n - 1; i++) putchar('D');
	  for (; j < n - 1; j++) putchar('R');
	  puts("");

	  return 0;
     }

     p = q = n - 1;

     if (dp[p][q][0] > dp[p][q][1]) {
	  f = 1;
     } else {
	  f = 0;
     }

     for (i = 0; i < 2 * n - 2; i++) {
	  s[i] = c[p][q][f];

	  if (c[p][q][f] == 'R') {
	       q--;
	  } else {
	       p--;
	  }
     }

     printf("%d\n", dp[n - 1][n - 1][f]);

     for (i = 0; i < 2 * n - 2; i++) printf("%c", s[2 * n - i - 3]);
     puts("");

     return 0;
}