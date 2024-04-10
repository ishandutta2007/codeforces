#include <stdio.h>
#include <stdlib.h>

int a[100000], b[50000], c[100000];
int dp[100001];

int cmp(const void *a, const void *b)
{
     return *((int *)a) - *((int *)b);
}

int lucky(int n)
{
     while (n) {
	  if (n % 10 != 4 && n % 10 != 7) {
	       return 0;
	  }

	  n /= 10;
     }

     return 1;
}

int extgcd(int a, int b, int *x, int *y)
{
     int d = a;

     if (b != 0) {
	  d = extgcd(b, a % b, y, x);

	  *y -= (a / b) * (*x);
     } else {
	  *x = 1;
	  *y = 0;
     }

     return d;
}

int mod_inverse(int a, int m)
{
     int x, y;

     extgcd(a, m, &x, &y);

     return (m + x % m) % m;
}

int main()
{
     int n, k, p = 0, q = 0, m = 1000000007, i, j;
     long long sum = 0, a1 = 1, a2 = 1, a3 = 1;

     scanf("%d %d", &n, &k);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     qsort(a, n, sizeof(int), cmp);

     for (i = 0; i < n; i++) {
	  if (lucky(a[i]) == 1) {
	       for (j = i; j < n; j++) {
		    if (a[j] != a[i]) break;
	       }

	       if (j - i > 1) b[q++] = j - i;

	       i = j - 1;
	  }

	  p++;
     }

     if (p < k) {
	  puts("0");

	  return 0;
     }

     for (i = 1; i <= p - q; i++) {
	  a1 = a1 * i % m;
	  a3 = a3 * i % m;

	  c[i] = (int)a3;
     }

     c[0] = 1;

     for (i = 0; i <= k; i++) {
	  if (i > p - q) break;

	  dp[i] = a1 * mod_inverse((int)(a2 * a3 % m), m) % m;

	  a2 = a2 * (i + 1) % m;
	  a3 = c[p - q - i - 1];
     }

     for (i = 0; i < q; i++) {
	  for (j = k - 1; j >= 0; j--) {
	       dp[j + 1] = ((long long)dp[j] * b[i] + dp[j + 1]) % m;
	  }
     }

     printf("%d\n", dp[k]);

     return 0;
}