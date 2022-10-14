#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<20, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, m, k, a[maxn], vis[maxn], p2[maxn], ans = 0;
vector<int> g[maxn], xors;
vector<array<int, 2>> edges, xe[maxn];

int unvis;
void dfs(int v) {
	vis[v] = 1;
	unvis--;
	//cout << "Visiting " << v << endl;
	for(auto &i : g[v]) if(!vis[i]) {
		dfs(i);
	}
}
void solve(vector<array<int, 2>> e) {
	//cout << e.size() << " " << (a[e[0][0]]^a[e[0][1]]) << endl;
	unvis = n;
	ans = (mod + ans - p2[n])%mod;
	for(auto &[x, y] : e) {
		g[x].push_back(y);
		g[y].push_back(x);
		//cout << x << " " << y << endl;
	}
	ll cur = 1;
	for(auto &[x, y] : e) {
		if(!vis[x]) {
			//cout << "Starting from " << x << endl;
			dfs(x);
			cur = (cur*2ll)%mod;
		}
	}
	//cout << cur*1ll*p2[unvis] << endl;
	ans = (ans + cur*1ll*p2[unvis])%mod;
	for(auto &[x, y] : e) {
		g[x].clear(), g[y].clear();
		vis[x] = vis[y] = 0;
	}
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> k;
	p2[0] = 1;
	for(int i = 1; i < maxn; i++) p2[i] = (p2[i-1] + p2[i-1])%mod;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		edges.push_back({f, t});
		xors.push_back(a[f]^a[t]);
	}
	ans = p2[n]*1ll*p2[k]%mod;
	sort(all(xors));
	for(auto [f, t] : edges) {
		int p = lower_bound(all(xors), a[f]^a[t])-xors.begin();
		xe[p].push_back({f, t});
	}
	for(int i = 0; i < xors.size(); i++) {
		if(xe[i].size()) solve(xe[i]);
	}
	cout << ans << endl;
}