#include <stdio.h>
#include <string.h>

int dp[100][26][101];

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
     int k, n, res = -1e9, i, j, l, p;
     char s[105];
     int c[26][26] = {0};

     scanf("%s %d", s, &k);

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  char s1[2], s2[2];
	  int x;

	  scanf("%s %s %d", s1, s2, &x);

	  c[s1[0] - 'a'][s2[0] - 'a'] = x;
     }

     for (i = 0; i < strlen(s); i++) {
	  for (j = 0; j < 26; j++) {
	       for (l = 0; l <= k; l++) {
		    dp[i][j][l] = -1e9;
	       }
	  }
     }

     for (i = 0; i < 26; i++) {
	  if (i == s[0] - 'a') {
	       dp[0][i][k] = 0;
	  } else if (k > 0) {
	       dp[0][i][k - 1] = 0;
	  }
     }

     for (i = 1; i < strlen(s); i++) {
	  for (j = 0; j < 26; j++) {
	       for (l = 0; l <= k; l++) {
		    for (p = 0; p < 26; p++) {
			 if (j == s[i] - 'a') {
			      dp[i][j][l] = max(dp[i][j][l], dp[i - 1][p][l] + c[p][j]);
			 } else if (l > 0) {
			      dp[i][j][l - 1] = max(dp[i][j][l - 1], dp[i - 1][p][l] + c[p][j]);
			 }
		    }
	       }
	  }
     }

     for (i = 0; i < 26; i++) {
	  for (j = 0; j <= k; j++) {
	       res = max(res, dp[strlen(s) - 1][i][j]);
	  }
     }

     printf("%d\n", res);

     return 0;
}