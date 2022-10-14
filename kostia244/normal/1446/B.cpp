#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4.1,sse4.2,popcnt")
#include<bits/extc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 5050, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int dp[maxn][maxn];
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, 0, sizeof dp);
	int n, m;
	string s, t;
	cin >> n >> m >> s >> t;
	int ans = 0;
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			if(i < n && j < m && s[i] == t[j]) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 2);
			if(i < n) dp[i+1][j] = max(dp[i+1][j], dp[i][j] - 1);
			if(j < m) dp[i][j+1] = max(dp[i][j+1], dp[i][j] - 1);
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << '\n';
}