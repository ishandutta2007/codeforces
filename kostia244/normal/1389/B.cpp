#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse4,popcnt,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<17, mod = 1e9 + 7;
map<array<int, 3>, ll> dp;
vector<int> a;
ll n, k, z;
ll dfs(int s, int p, int l) {
	if(dp.count({s, p, l})) return dp[{s, p, l}];
	if(s == k) return 0;
	ll ans = 0;
	if(p+1 < n) ans = a[p+1] + dfs(s+1, p+1, 0);
	if(p && !l && (s-p)/2 < z) ans = max(ans, dfs(s+1, p-1, 1) + a[p-1]);
	return dp[{s, p, l}] = ans;
}
void solve() {
	dp.clear();
	cin >> n >> k >> z;
	a = vector<int>(n);
	for(auto &i : a) cin >> i;
	cout << dfs(0, 0, 0)+a[0] << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
}