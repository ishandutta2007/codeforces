#include <stdio.h>

int n, p;
long long m1 = 1e18, m2 = 0;
int d[100][2];

void dfs(int f, long long x, long long y, long long z)
{
     if (f == p) {
	  long long tmp;

	  tmp = (x + 1) * (y + 2) * (z + 2) - n;

	  if (tmp < m1) m1 = tmp;

	  if (tmp > m2) m2 = tmp;

	  tmp = (x + 2) * (y + 1) * (z + 2) - n;

	  if (tmp < m1) m1 = tmp;

	  if (tmp > m2) m2 = tmp;

	  tmp = (x + 2) * (y + 2) * (z + 1) - n;

	  if (tmp < m1) m1 = tmp;

	  if (tmp > m2) m2 = tmp;
     } else {
	  int i, j, k;

	  for (i = 0; i <= d[f][1]; i++) {
	       for (j = i; j <= d[f][1]; j++) {
		    long long a = 1, b = 1, c = 1;

		    for (k = 0; k < i; k++) a *= d[f][0];

		    for (k = i; k < j; k++) b *= d[f][0];

		    for (k = j; k < d[f][1]; k++) c *= d[f][0];

		    dfs(f + 1, x * a, y * b, z * c);
	       }
	  }
     }
}

int main()
{
     int m, i;

     scanf("%d", &n);

     m = n;

     for (i = 2; i * i <= m; i++) {
	  if (m % i == 0) {
	       d[p][0] = i;

	       while (m % i == 0) {
		    d[p][1]++;

		    m /= i;
	       }

	       p++;
	  }
     }

     if (m > 1) {
	  d[p][0] = m;
	  d[p++][1] = 1;
     }

     dfs(0, 1, 1, 1);

     printf("%I64d %I64d\n", m1, m2);

     return 0;
}