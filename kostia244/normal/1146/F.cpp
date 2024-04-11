#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<18, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
vector<int> g[maxn];
//{0, 1, 2+}
array<int, 2> dfs(int v) {
	if(g[v].empty()) return {1, 1};
	array<int, 3> dp {1, 0, 0};
	for(auto i : g[v]) {
		auto ch = dfs(i);
		array<int, 3> ndp;
		ndp[0] = dp[0]*1ll*ch[0]%mod;
		ndp[1] = (dp[1]*1ll*ch[0] + dp[0]*1ll*ch[1])%mod;
		ndp[2] = (dp[2]*1ll*(ch[0] + ch[1]) + dp[1]*1ll*ch[1])%mod;
		dp = ndp; 
	}
	dp[0] = (dp[0]+dp[2])%mod;
	dp[1] = (dp[1] + dp[2])%mod;
	return {dp[0], dp[1]};
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int t, i = 2; i <= n; i++) cin >> t, g[t].push_back(i);
	auto dp = dfs(1);
	cout << dp[0] << '\n';
}