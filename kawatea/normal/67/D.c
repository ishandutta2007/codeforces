#include <stdio.h>

int a[1000000], b[1000000], c[1000000];
int dp[1000000];

int main()
{
     int n, l, r, m, i;

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);
     for (i = 0; i < n; i++) scanf("%d", &b[n - i - 1]);

     for (i = 0; i < n; i++) c[b[i]] = i;

     for (i = 0; i < n; i++) dp[i] = 1e9;

     for (i = 0; i < n; i++) {
	  l = -1, r = n, m = (l + r) / 2;

	  while (r - l > 1) {
	       if (dp[m] >= c[a[i]]) {
		    r = m;
		    m = (l + r) / 2;
	       } else {
		    l = m;
		    m = (l + r) / 2;
	       }
	  }

	  dp[r] = c[a[i]];
     }

     l = -1, r = n, m = (l + r) / 2;

     while (r - l > 1) {
	  if (dp[m] >= 1e9) {
	       r = m;
	       m = (l + r) / 2;
	  } else {
	       l = m;
	       m = (l + r) / 2;
	  }
     }

     printf("%d\n", r);

     return 0;
}