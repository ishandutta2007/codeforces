#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse4,popcnt,tune=native")
#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
const int maxn = 1<<20, mod = 1e9 + 7;
struct dsu
{
	int sz;
	vector<int> par, psz, mh;

	void init(int n)
	{
		sz = n;
		par.assign(sz + 1, 0);
		psz.assign(sz + 1, 0);
		mh.assign(sz + 1, 1<<30);
		for(int i = 0; i <= sz; i++)
			par[i] = i, psz[i] = 1;
	}

	int root(int u) { return par[u] = ((u == par[u]) ? u : root(par[u])); }
	
	bool connected(int x, int y) { return root(x) == root(y); }

	void unite(int x, int y)
	{
		x = root(x), y = root(y);
		if(x == y) return;
		if(psz[x] > psz[y]) swap(x, y);
		par[x] = y, psz[y] += psz[x]; 
	}
};

vector<int> g[maxn];
int n, a[maxn], b[maxn], h[maxn];
ll ans = 0;
dsu d;
ll dfs(ll v, ll p) {
	ll res = a[v];
	for(auto i : g[v]) if(i != p) {
		h[i] = h[v] + 1;
		ll t =  dfs(i, v);
		res += t;
		if(t > 0) d.unite(i, v);
	}
	ans += res;
	return max(res, 0ll);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	d.init(n);
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int t, i = 1; i <= n; i++) {
		cin >> t;
		b[i] = t;
		if(t != -1)
			g[t].push_back(i);
	}
	for(int i = 1; i <= n; i++) if(b[i] == -1) dfs(i, i);
	cout << ans << '\n';
	vector<array<int, 3>> ans;
	for(int i = 1; i <= n; i++) d.mh[d.root(i)] = min(d.mh[d.root(i)], h[i]);
	for(int i = 1; i <= n; i++) 
		ans.push_back({d.mh[d.root(i)], -h[i], i});
	sort(all(ans));
	for(auto i : ans) cout << i[2] << " "; cout << '\n';
}