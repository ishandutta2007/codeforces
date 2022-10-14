#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<20, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, m, care[maxn], vis[maxn];
vector<int> g[maxn];
void dfs(int v) {
	vis[v] = 1;
	for(auto i : g[v]) if(!vis[i]) {
		dfs(i);
	}
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	ll uni = 0;
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		if(f == t) uni++;
		else {
			g[f].push_back(t);
			g[t].push_back(f);
		}
		care[f] = care[t] = 1;
	}
	int c = 0;
	for(int i = 1; i <= n; i++) if(care[i]) {
		if(!vis[i]) {
			dfs(i), c++;
		}
	}
	if(c > 1) return cout << 0, 0;
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += g[i].size()*1ll*(g[i].size()-1)/2;
	}
	ans += uni*(uni-1)/2;
	ans += (m-uni)*uni;
	cout << ans << endl;
}