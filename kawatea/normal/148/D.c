#include <stdio.h>

double dp[1001][1001];

int main()
{
     int w, b, i, j;
     double sum = 0;

     scanf("%d %d", &w, &b);

     if (w == 0) {
	  puts("0");

	  return 0;
     }

     dp[w][b] = 1;

     for (i = w; i > 0; i--) {
	  for (j = b; j >= 0; j--) {
	       int x = (w + b - i - j) % 3;

	       if (dp[i][j] == 0) continue;

	       if (x == 0) {
		    sum += dp[i][j] * i / (i + j);

		    if (j > 0) dp[i][j - 1] += dp[i][j] * j / (i + j);
	       } else if (x == 1) {
		    if (j > 0) dp[i][j - 1] += dp[i][j] * j / (i + j);
	       } else {
		    dp[i - 1][j] += dp[i][j] * i / (i + j);

		    if (j > 0) dp[i][j - 1] += dp[i][j] * j / (i + j);
	       }
	  }
     }

     printf("%.10lf\n", sum);

     return 0;
}