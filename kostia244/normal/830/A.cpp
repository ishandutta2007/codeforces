#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define pcnt(x) __builtin_popcount(x)
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 2e3 + 3, mod = 1e9 + 7;
ll n, m, p, dp[maxn][maxn];
vi a, b;
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> p;
	a.resize(n);
	for(auto &i : a) cin >> i;
	b.resize(m);
	for(auto &i : b) cin >> i;
	sort(all(a));
	sort(all(b));
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++) {
			if(i<n&&j<m)
			dp[i+1][j+1] = min(dp[i+1][j+1], max(dp[i][j], abs(a[i]-b[j]) + abs(b[j]-p)));
			dp[i][j+1] = min(dp[i][j+1], dp[i][j]);
		}
	cout << dp[n][m];
}