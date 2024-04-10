#include <stdio.h>
#include <string.h>

int main()
{
     char s[51];
     int n, i, j;
     long long sum = 0;
     long long dp[50][10] = {0};

     scanf("%s", s);

     n = strlen(s);

     for (i = 0; i < 10; i++) dp[0][i] = 1;

     for (i = 0; i < n - 1; i++) {
	  for (j = 0; j < 10; j++) {
	       int x = s[i + 1] - '0' + j;

	       dp[i + 1][x / 2] += dp[i][j];

	       if (x % 2 == 1) dp[i + 1][(x + 1) / 2] += dp[i][j];
	  }
     }

     for (i = 0; i < 10; i++) sum += dp[n - 1][i];

     for (i = 1; i < n; i++) {
	  int x = s[i] + s[i - 1] - 2 * '0';

	  if (s[i] - '0' != x / 2 && s[i] - '0' != (x + 1) / 2) break;
     }

     if (i == n) sum--;

     printf("%I64d\n", sum);

     return 0;
}