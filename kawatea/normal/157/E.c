#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long dp[101][2601];
int m = 1000000007;

long long dfs(int n, int x)
{
     int i;
     long long sum = 0;

     if (x < 0) return 0;

     if (dp[n][x] >= 0) return dp[n][x];

     if (n == 0) {
	  if (x == 0) {
	       return dp[n][x] = 1;
	  } else {
	       return dp[n][x] = 0;
	  }
     }

     for (i = 0; i < 26; i++) {
	  sum = (sum + dfs(n - 1, x - i)) % m;
     }

     return dp[n][x] = sum;
}

int main()
{
     int t, n, i, j;
     char s[101];

     for (i = 0; i <= 100; i++) {
	  for (j = 0; j <= 2600; j++) {
	       dp[i][j] = -1;
	  }
     }

     scanf("%d", &t);

     for (i = 0; i < t; i++) {
	  int sum = 0;

	  scanf("%s", s);

	  n = strlen(s);

	  if (n == 1) {
	       puts("0");

	       continue;
	  }

	  for (j = 0; j < n; j++) sum += s[j] - 'a';

	  sum = dfs(n, sum);

	  sum = (sum + m - 1) % m;

	  printf("%d\n", (int)sum);
     }

     return 0;
}