#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500001],dp[5001][5001];
int main() {
	int n,k,i,j,l,h,v;
	scanf("%d%d", &n,&k);
	for (i = 1; i <= n; i++)scanf("%lld", a + i);
	sort(a+1, a + n+1);
	int ba = n / k;
	memset(dp, 0x3f,sizeof(dp));
	dp[0][0] = 0;
	for (i = 1; i <= k; i++) {
		for (j = 0; j <= i; j++) {
			l = j, h = i - j,v=l*ba+h*(ba+1);
			if (l != 0)dp[l][h] = min(dp[l][h], dp[l - 1][h] + a[v] - a[v - ba + 1]);
			if (h != 0)dp[l][h] = min(dp[l][h], dp[l][h-1] + a[v] - a[v - ba ]);
		}
	}
	printf("%lld", dp[k-(n%k)][n%k]);
	getchar(); getchar();
}