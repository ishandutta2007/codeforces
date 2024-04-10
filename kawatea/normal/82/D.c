#include <stdio.h>

int dp[500][1000];
int p[500][1000][3];

int max(int a, int b)
{
     if (a > b) {
	  return a;
     } else {
	  return b;
     }
}

int main()
{
     int n, m = 1e9, num = 0, x = 0, y = 0, c = 0, i, j;
     int a[1000];
     int b[500][2];

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     for (i = 0; i < (n + 1) / 2; i++) {
	  for (j = 0; j < n; j++) {
	       dp[i][j] = 1e9;
	  }
     }

     dp[0][0] = 0;

     for (i = 0; i < n / 2; i++) {
	  for (j = 0; j <= i * 2; j++) {
	       if (n - i * 2 >= 3) {
		    if (dp[i + 1][j] > dp[i][j] + max(a[i * 2 + 1], a[i * 2 + 2])) {
			 dp[i + 1][j] = dp[i][j] + max(a[i * 2 + 1], a[i * 2 + 2]);
			 p[i + 1][j][0] = i * 2 + 2;
			 p[i + 1][j][1] = i * 2 + 3;
			 p[i + 1][j][2] = j;
		    }

		    if (dp[i + 1][i * 2 + 1] > dp[i][j] + max(a[j], a[i * 2 + 2])) {
			 dp[i + 1][i * 2 + 1] = dp[i][j] + max(a[j], a[i * 2 + 2]);
			 p[i + 1][i * 2 + 1][0] = j + 1;
			 p[i + 1][i * 2 + 1][1] = i * 2 + 3;
			 p[i + 1][i * 2 + 1][2] = j;
		    }

		    if (dp[i + 1][i * 2 + 2] > dp[i][j] + max(a[j], a[i * 2 + 1])) {
			 dp[i + 1][i * 2 + 2] = dp[i][j] + max(a[j], a[i * 2 + 1]);
			 p[i + 1][i * 2 + 2][0] = j + 1;
			 p[i + 1][i * 2 + 2][1] = i * 2 + 2;
			 p[i + 1][i * 2 + 2][2] = j;
		    }
	       } else  {
		    if (m > dp[i][j] + max(a[j], a[i * 2 + 1])) {
			 m = dp[i][j] + max(a[j], a[i * 2 + 1]);
			 num = j;
			 x = j + 1;
			 y = i * 2 + 2;
		    }
	       }
	  }
     }

     if (n % 2 == 1) {
	  for (i = 0; i < n; i++) {
	       if (m > dp[n / 2][i] + a[i]) {
		    m = dp[n / 2][i] + a[i];
		    num = i;
		    x = i + 1;
	       }
	  }
     }

     for (i = 0; i < (n + 1) / 2; i++) {
	  b[c][0] = x;
	  b[c++][1] = y;

	  x = p[(n + 1) / 2 - i - 1][num][0];
	  y = p[(n + 1) / 2 - i - 1][num][1];
	  num = p[(n + 1) / 2 - i - 1][num][2];
     }

     printf("%d\n", m);

     for (i = c - 1; i >= 0; i--) {
	  if (b[i][1] == 0) {
	       printf("%d\n", b[i][0]);
	  } else {
	       printf("%d %d\n", b[i][0], b[i][1]);
	  }
     }

     return 0;
}