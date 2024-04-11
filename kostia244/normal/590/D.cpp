#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 155, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int dp[2][maxn][maxn*maxn], a[maxn], n, k, s;
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k >> s;
	for(int i = 0; i < n; i++) cin >> a[i];
	memset(dp, 0x3f, sizeof dp);
	dp[0][0][0] = 0;
	for(int I = 0; I < n; I++) {
		int i = I&1;
		for(int t = 0; t <= k; t++) {
			for(int s = 0; s <= n*n; s++) {
				dp[i^1][t][s] = min(dp[i][t][s], dp[i^1][t][s]);
				dp[i^1][t+1][s + I-t] = min(dp[i^1][t+1][s + I-t], dp[i][t][s] + a[I]);
			}
		}
	}
	int ans = 1<<30;
	for(int i = 0; i <= min(s, n*n); i++) ans = min(ans, dp[n&1][k][i]);
	cout << ans << endl;
}