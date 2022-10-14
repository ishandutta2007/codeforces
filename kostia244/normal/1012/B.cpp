#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,sse2,sse,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC comment("/STACK:26666666")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int mod = 1e9 + 7;
struct dsu {
	int sz;
	vi r, p;
	void init(int n) {
		r.resize(n);
		p.resize(n);
		sz = n;
		for(int i = 0; i < n; i++) p[i] = i;
	}
	int par(int v) {
		if(v==p[v]) return v;
		return p[v] = par(p[v]);
	}
	void unite(int i, int j) {
		i = par(i), j = par(j);
		if(i == j) return;
		if(r[i] < r[j]) swap(i, j);
		p[j] = i;
		r[i] += r[i]==r[j];
		--sz;
	}
};
int n, m, q, x, y;
dsu d;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> q;
	d.init(n+m);
	while(q--) {
		cin >> x >> y, x--, y--;
		d.unite(x, n+y);
	}
	cout << d.sz-1;
}