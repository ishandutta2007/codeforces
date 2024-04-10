#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct edge {
	int u, v, w, id;

	bool operator< (const edge& b) const {
		return w < b.w;
	}
} a[200005];

struct dsu {
	vector<int> p;

	dsu(int n) : p(n) {
		iota(p.begin(), p.end(), 0);
	}

	int ep(int x) {
		if (x == p[x])
			return x;
		return p[x] = ep(p[x]);
	}

	bool spoji(int x, int y) {
		x = ep(x);
		y = ep(y);
		if (x == y)
			return false;
		p[x] = y;
		return true;
	}
};

int n, m;

basic_string<pair<int, int>> e[200005];
int p[200005][18], v[200005][18];
int dub[200005];
ll ans[200005];

void dfs(int x, int par, int pw) {
	p[x][0] = par;
	v[x][0] = pw;
	for (int i=1; i<18; i++) {
		int y = p[x][i-1];
		p[x][i] = p[y][i-1];
		v[x][i] = max(v[x][i-1], v[y][i-1]);
	}
	for (auto ee : e[x]) {
		int y = ee.first;
		int w = ee.second;
		if (y == par)
			continue;
		dub[y] = dub[x] + 1;
		dfs(y, x, w);
	}
}

int dizi(int& x, int k) {
	int z = 0;
	for (int i=0; i<18; i++) {
		if (k & (1 << i)) {
			z = max(z, v[x][i]);
			x = p[x][i];
		}
	}
	return z;
}

int resi(int x, int y) {
	int z = 0;
	if (dub[x] > dub[y]) {
		z = max(z, dizi(x, dub[x] - dub[y]));
	} else if (dub[y] > dub[x]) {
		z = max(z, dizi(y, dub[y] - dub[x]));
	}

	if (x == y)
		return z;

	for (int i=17; i>=0; i--) {
		int xx = p[x][i];
		int yy = p[y][i];
		if (xx != yy) {
			z = max({z, v[x][i], v[y][i]});
			x = xx;
			y = yy;
		}
	}

	return max({z, v[x][0], v[y][0]});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		a[i] = {u, v, w, i};
	}
	sort(a, a+m);
	dsu d(n+1);
	ll mstw = 0;
	for (int i=0; i<m; i++) {
		if (d.spoji(a[i].u, a[i].v)) {
			e[a[i].u] += {a[i].v, a[i].w};
			e[a[i].v] += {a[i].u, a[i].w};
			mstw += a[i].w;
		}
	}
	// cerr << "mstw " << mstw << '\n';
	dfs(1, 1, 0);
	for (int i=0; i<m; i++) {
		int w = resi(a[i].u, a[i].v);
		// cerr << a[i].u << ' ' << a[i].v << ' ' << a[i].w << ' ' << w << '\n';
		ans[a[i].id] = mstw + a[i].w - w;
	}

	for (int i=0; i<m; i++)
		cout << ans[i] << '\n';
}