#include <stdio.h>

int dp[100][100][1000][2];

int main()
{
     int n, m, k, max = -1, num, i, j, l;
     int a[100][100], b[100];

     scanf("%d %d %d", &n, &m, &k);

     k++;

     for (i = 0; i < n; i++) {
	  for (j = 0; j < m; j++) {
	       scanf("%1d", &a[i][j]);
	  }
     }

     for (i = 0; i < m; i++) dp[0][i][a[n - 1][i]][0] = 1;

     for (i = 1; i < n; i++) {
	  for (j = 0; j < m; j++) {
	       for (l = a[n - i - 1][j]; l < 1000; l++) {
		    if (j > 0 && dp[i - 1][j - 1][l - a[n - i - 1][j]][0] == 1) {
			 dp[i][j][l][0] = 1;
			 dp[i][j][l][1] = 0;
		    }
		    if (j < m - 1 && dp[i - 1][j + 1][l - a[n - i - 1][j]][0] == 1) {
			 dp[i][j][l][0] = 1;
			 dp[i][j][l][1] = 1;
		    }
	       }
	  }
     }

     for (i = 0; i < m; i++) {
	  for (j = 0; k * j < 1000; j++) {
	       if (dp[n - 1][i][k * j][0] == 1 && k * j > max) {
		    max = k * j;
		    num = i;
	       }
	  }
     }

     if (max == -1) {
	  puts("-1");
     } else {
	  printf("%d\n", max);

	  for (i = 0; i < n - 1; i++) {
	       if (dp[n - i - 1][num][max][1] == 0) {
		    b[i] = 0;

		    max -= a[i][num];
		    num--;
	       } else {
		    b[i] = 1;

		    max -= a[i][num];
		    num++;
	       }
	  }

	  printf("%d\n", num + 1);

	  for (i = n - 2; i >= 0; i--) {
	       if (b[i] == 0) {
		    putchar('R');
	       } else {
		    putchar('L');
	       }
	  }
	  puts("");
     }

     return 0;
}