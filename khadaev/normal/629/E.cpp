#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif
const ld eps = 1e-8;

vector<vector<int>> e;
map<pair<int, int>, ll> size, sum;

ll getSize(int u, int v) {
	if (size.count({u, v})) return size[{u, v}];
	ll ans = 1;
	for (int to : e[v]) {
		if (to == u) continue;
		ans += getSize(v, to);
	}
	size[{u, v}] = ans;
	//cout << "SIZE: " << u << ' ' << v << ' ' << ans << '\n';
	return ans;
}

ll getSum(int u, int v) {
	if (sum.count({u, v})) return sum[{u, v}];
	ll ans = 0;
	for (int to : e[v]) {
		if (to == u) continue;
		ans += getSize(v, to);
		ans += getSum(v, to);
	}
	sum[{u, v}] = ans;
	//cout << "SUM: " << u << ' ' << v << ' ' << ans << '\n';
	return ans;
}

vector<int> heis;

void dfs(int n, int h) {
	if (heis[n] != -1) return;
	heis[n] = h;
	for (int to : e[n]) dfs(to, h + 1);
}

vector<int> spt[18];

int up(int u, int n) {
	for(int i = 17; i >= 0; --i) {
		if (n >= (1 << i)) {
			n -= (1 << i);
			u = spt[i][u];
		}
	}
	return u;
}

int lca(int u, int v) {
	if (heis[u] < heis[v])swap(u, v);
	u = up(u, heis[u] - heis[v]);
	if (u == v) return u;
	for(int i = 17; i >= 0; --i) {
		if (spt[i][u] != spt[i][v]) {
			u = spt[i][u];
			v = spt[i][v];
		}
	}
	return spt[0][u];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	e.resize(n);
	heis.resize(n);
	fill(heis.begin(), heis.end(), -1);
	forn(i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(0, 0);
	forn(i, 0, 18) spt[i].resize(n);
	spt[0][0] = 0;
	forn(i, 1, n) {
		for (int to : e[i])
			if (heis[to] < heis[i])
				spt[0][i] = to;
	}
	forn(i, 1, 18)
		forn(j, 0, n)
			spt[i][j] = spt[i - 1][spt[i - 1][j]];
	forn(i, 0, m) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		if (heis[u] < heis[v]) swap(u, v);
		int anc = lca(u, v);
		int preU, preV;
		if (anc == v) {
			preU = spt[0][u];
			preV = up(u, heis[u] - heis[v] - 1);
		} else {
			preU = spt[0][u];
			preV = spt[0][v];
		}
		ld exp = (ld)getSum(preU, u) / getSize(preU, u) + (ld)getSum(preV,
		v) / getSize(preV, v);
		//cout << u << ' ' << v << ' ' << preU << ' ' << preV << '\n';
		cout << fixed << setprecision(10) << exp + (1 + heis[u] + heis[v] - 2 * heis[anc]) << '\n';
		//cout << '\n';
	}
	return 0;
}