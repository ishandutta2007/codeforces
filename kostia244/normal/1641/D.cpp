// Problem: D.  
// Contest: Codeforces - Codeforces Round #773 (Div. 1)
// URL: https://codeforces.com/contest/1641/problem/D
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
const int N = 1<<17, C = 12;
int n, m, w[N], msk[N], dp[1<<C];
vector<int> c[N];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	vector<int> co;
	for(int i = 0; i < n; i++) {
		c[i].resize(m);
		for(auto &j : c[i]) cin >> j, co.push_back(j);
		cin >> w[i];
	}sort(all(co));
	co.erase(unique(all(co)), co.end());
	for(int i = 0; i < n; i++)
		for(auto &j : c[i]) 
			j = lower_bound(all(co), j) - co.begin();
	iota(all(co), 0);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	const int F = (1<<C)-1, inf = 1<<30;
	int ans = INT_MAX;
	for(int it = 0; it < 800; it++) {
		for(int i = 0; i < co.size(); i++)
			co[i] = rng()%C;
		fill(dp, dp+(1<<C), inf);
		for(int i = 0; i < n; i++) {
			msk[i] = 0;
			for(auto &j : c[i])
				msk[i] |= 1<<co[j];
			dp[msk[i]] = min(dp[msk[i]], w[i]);
		}
		for(int b = 1; b < 1<<C; b*=2)
			for(int i = 0; i < 1<<C; i++) if(i&b) {
				dp[i] = min(dp[i], dp[i - b]);
			}
		for(int i = 0; i < n; i++) {
			if(dp[F-msk[i]] < inf)
				ans = min(ans, w[i] + dp[F-msk[i]]);
		}
	}
	if(ans == INT_MAX) ans = -1;
	cout << ans << '\n';
}