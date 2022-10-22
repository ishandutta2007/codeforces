#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> g[5001];
int dp[5001][501],c[5001],f[501],h[11];
int cd[100001], fd[100001];
int main() {
	int n, k, i, j,l;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n*k; i++)scanf("%d", c + i);
	for (i = 0; i < n; i++)scanf("%d",f+i);
	for (i = 1; i <= k; i++)scanf("%d", h + i);
	for (i = 1; i <= n * k; i++) {
		for (j = 1; j <= n; j++) {
			for (l = 1; l <= min(k,i); l++) {
				dp[i][j] = max(dp[i][j], dp[i - l][j - 1]+h[l]);
			}
		}
	}
	for (i = 0; i <= n * k; i++) {
		for (j = 1; j <= n; j++)dp[i][j] = max(dp[i][j], dp[i][j - 1]);
	}
	for (i = 0; i < n*k; i++)cd[c[i]]++;
	for (i = 0; i < n; i++)fd[f[i]]++;
	int ans = 0;
	for (i = 0; i <= 100000; i++)ans += dp[cd[i]][fd[i]];
	printf("%d", ans);
}