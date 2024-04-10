#include <stdio.h>
#include <stdlib.h>

long long dp[3000][3000];

typedef struct {
     int x;
     int c;
} marble;

int cmp(const void *a, const void *b)
{
     return ((marble *)a)->x - ((marble *)b)->x;
}

long long minimum(long long a, long long b)
{
     if (a < b) {
	  return a;
     } else {
	  return b;
     }
}

int main()
{
     int n, p = 0, i, j;
     marble m[3000];
     long long x = 1e18;

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  for (j = 0; j < n; j++) {
	       dp[i][j] = 1e18;
	  }
     }

     for (i = 0; i < n; i++) scanf("%d %d", &m[i].x, &m[i].c);

     qsort(m, n, sizeof(marble), cmp);

     dp[0][0] = m[0].c;

     for (i = 1; i < n; i++) {
	  for (j = 0; j < i; j++) {
	       dp[i][j] = dp[i - 1][j] + m[i].x - m[j].x;
	  }

	  for (j = 0; j < i; j++) {
	       dp[i][i] = minimum(dp[i][i], dp[i - 1][j] + m[i].c);
	  }
     }

     for (i = 0; i < n; i++) x = minimum(x, dp[n - 1][i]);

     printf("%I64d\n", x);

     return 0;
}