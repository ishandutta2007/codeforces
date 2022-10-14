#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<17, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, k;
vector<int> f, sz, g[maxn];
int S, vis[maxn];
void dfs(int v) {
	vis[v] = 1; S++;
	for(auto i : g[v]) if(!vis[i]) dfs(i);
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> k;
	f.resize(k);
	for(auto &i : f) cin >> i;
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	for(auto &i : f) {
		S = 0;
		dfs(i);
		sz.push_back(S);
	}
	sort(all(sz));
	for(int i = 1; i <= n; i++) if(!vis[i]) {
		S = 0; dfs(i);
		sz.back() += S;
	}
	ll ans = 0;
	for(auto &i : sz) ans += i*1ll*(i-1)/2;
	ans -= m;
	cout << ans << endl;
}