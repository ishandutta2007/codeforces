#include <stdio.h>
#include <string.h>

int dp[101][51][201][2];

int main()
{
     int n, c = 0, len, i, j, k, l;
     char s[101];

     scanf("%s", s);
     scanf("%d", &n);

     len = strlen(s);

     for (i = 0; i < len; i++) {
	  if (s[i] == 'T') c++;
     }
     if (c <= n) {
	  n -= c;

	  len -= n % 2;

	  printf("%d\n", len);
     } else {
	  if (s[0] == 'T') {
	       for (i = 0; i <= n; i += 2) dp[1][i][100][1] = 1;
	       for (i = 1; i <= n; i += 2) dp[1][i][101][0] = 1;
	  } else {
	       for (i = 0; i <= n; i += 2) dp[1][i][101][0] = 1;
	       for (i = 1; i <= n; i += 2) dp[1][i][100][1] = 1;
	  }

	  for (i = 1; i < len; i++) {
	       for (j = 0; j <= n; j++) {
		    for (k = 0; k <= 200; k++) {
			 if (dp[i][j][k][0] == 1) {
			      if (s[i] == 'T') {
				   for (l = j; l <= n; l += 2) dp[i + 1][l][k][1] = 1;
				   for (l = j + 1; l <= n; l += 2) dp[i + 1][l][k + 1][0] = 1;
			      } else {
				   for (l = j; l <= n; l += 2) dp[i + 1][l][k + 1][0] = 1;
				   for (l = j + 1; l <= n; l += 2) dp[i + 1][l][k][1] = 1;
			      }
			 }

			 if (dp[i][j][k][1] == 1) {
			      if (s[i] == 'T') {
				   for (l = j; l <= n; l += 2) dp[i + 1][l][k][0] = 1;
				   for (l = j + 1; l <= n; l += 2) dp[i + 1][l][k - 1][1] = 1;
			      } else {
				   for (l = j; l <= n; l += 2) dp[i + 1][l][k - 1][1] = 1;
				   for (l = j + 1; l <= n; l += 2) dp[i + 1][l][k][0] = 1;
			      }
			 }
		    }
	       }
	  }

	  c = 0;

	  for (i = 0; i <= 100; i++) {
	       if (dp[len][n][100 + i][0] == 1) c = i;

	       if (dp[len][n][100 - i][0] == 1) c = i;

	       if (dp[len][n][100 + i][1] == 1) c = i;

	       if (dp[len][n][100 - i][1] == 1) c = i;
	  }

	  printf("%d\n", c);
     }

     return 0;
}