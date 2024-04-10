#include <stdio.h>

long long dp[2000][7000];

long long min(long long a, long long b)
{
     if (a < b) {
	  return a;
     } else {
	  return b;
     }
}

int main()
{
     int n, i, j;
     int t[2000], c[2000];
     long long m = 1e18;

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d %d", &t[i], &c[i]);

     for (i = 0; i < n; i++) {
	  for (j = 0; j < 7000; j++) {
	       dp[i][j] = 1e18;
	  }
     }

     dp[0][2000 + t[0]] = c[0];
     dp[0][1999] = 0;

     for (i = 1; i < n; i++) {
	  for (j = 1; j < 7000; j++) {
	       dp[i][j - 1] = min(dp[i][j - 1], dp[i - 1][j]);
	       if (j + t[i] < 7000) dp[i][j + t[i]] = min(dp[i][j + t[i]], dp[i - 1][j] + c[i]);
	  }
     }

     for (i = 2000; i < 7000; i++) m = min(m, dp[n - 1][i]);

     printf("%I64d\n", m);

     return 0;
}