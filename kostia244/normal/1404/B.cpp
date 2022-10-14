#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 3e5 + 33, maxk = 1<<11, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> g[maxn];
array<int, 2> dfs(int v, int p = -1) {
	array<int, 2> ans = {0, v};
	for(auto &i : g[v]) if(i != p) {
		auto t = dfs(i, v);t[0]++;
		ans = max(ans, t);
	}
	return ans;
}
int D = -1;
void find(int v, int b, int p = -1, int d = 0) {
	if(v == b) D = d;
	for(auto &i : g[v]) if(i != p) {
		find(i, b, v, d+1);
	}
}
void solve() {
	int n, a, b, da, db;
	cin >> n >> a >> b >> da >> db;
	for(int i = 0; i <= n; i++) g[i].clear();
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	int v = dfs(1)[1];
	int diam = dfs(v)[0];
	D = -1;find(a, b);
	if(db <= 2*da || diam <= 2*da || D <= da) cout << "Alice\n";
	else cout << "Bob\n";
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
	
}