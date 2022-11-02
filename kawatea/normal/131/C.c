#include <stdio.h>

long long c[31][31];

long long conb(int n, int m)
{
     if (c[n][m] >= 0) return c[n][m];

     if (n == m) return c[n][m] = 1;

     if (m == 0) return c[n][m] = 1;

     if (m == 1) return c[n][m] = n;

     return c[n][m] = conb(n - 1, m) + conb(n - 1, m - 1);
}

int main()
{
     int n, m, t, i, j;
     long long sum = 0;

     scanf("%d %d %d", &n, &m, &t);

     for (i = 0; i <= 30; i++) {
	  for (j = 0; j <= 30; j++) {
	       c[i][j] = -1;
	  }
     }

     for (i = 4; i <= n; i++) {
	  if (t - i < 1) break;

	  if (t - i > m) continue;

	  sum += conb(n, i) * conb(m, t - i);
     }

     printf("%I64d\n", sum);

     return 0;
}