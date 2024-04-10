#include <stdio.h>
#include <stdlib.h>

int main()
{
     int n, m, v, p, i, j;

     scanf("%d %d %d", &n, &m, &v);

     if (m < n - 1 || m > (long long)n * (n - 1) / 2 - n + 2) {
	  puts("-1");

	  return 0;
     }

     if (v == n) {
	  p = n - 1;
     } else {
	  p = n;
     }

     printf("%d %d\n", v, p);

     m--;

     for (i = 1; i <= n; i++) {
	  for (j = i + 1; j <= n; j++) {
	       if (m == 0) return 0;

	       if (i == p || j == p) continue;

	       printf("%d %d\n", i, j);

	       m--;
	  }
     }

     return 0;
}