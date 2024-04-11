#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define apply fuckstl
#define int long long
using namespace std;
using ll = int64_t;
const int maxn = 1<<20, mod = 119<<23|1;
struct dsu
{
	int sz;
	vector<int> par, psz;

	void init(int n)
	{
		sz = n;
		par.assign(sz + 1, 0);
		psz.assign(sz + 1, 0);
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
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int t, n;
	string x, y;
	cin >> t;
	while(t--) {
		cin >> n >> x >> y;
		int ans = 0;
		dsu d;
		d.init(20);
		for(int i = 0; i < n; i++) {
			if(x[i] > y[i]) {ans = -1; break;}
			d.unite(x[i]-'a', y[i]-'a');
		}
		if(ans != -1) 
		for(int i = 0; i < 20; i++) if(d.root(i) == i) ans += d.psz[i]-1;
		cout << ans << '\n';
	}
}