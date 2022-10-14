//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 1e9 + 7;
struct dsu
{
	int sz;
	vector<int> par, psz, l, r;

	void init(int n)
	{
		sz = n;
		par.assign(sz + 1, 0);
		psz.assign(sz + 1, 0);
		l.assign(sz + 1, 0);
		r.assign(sz + 1, 0);
		for(int i = 0; i <= sz; i++)
			par[i] = i, psz[i] = 1, l[i] = i, r[i] = i;
	}

	int root(int u) { return par[u] = ((u == par[u]) ? u : root(par[u])); }

	bool connected(int x, int y) { return root(x) == root(y); }

	void unite(int x, int y)
	{
		x = root(x), y = root(y);
		if(x == y) return;
		if(psz[x] > psz[y]) swap(x, y);
		par[x] = y, psz[y] += psz[x];
		l[y] = min(l[y], l[x]);
		r[y] = max(r[y], r[x]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	dsu d;
	d.init(n+1);
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		d.unite(f, t);
	}
	ll x = 1, ans = 0;
	while(x <= n) {
		int t = d.root(x), c;
		int r = d.r[t];
		while(x < r) {
			x++;
			c = d.root(x);
			if(c!=t) {
				d.unite(c, t);
				t = d.root(t);
				ans++;
				r = d.r[t];
			}
		}
		x++;
	}
	cout << ans;
}