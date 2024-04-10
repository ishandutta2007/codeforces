#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct edge {
	int y, w;
};

int n;
ll da[100005], db[100005], d[100005];
basic_string<edge> e[100005];
basic_string<int> f[100005];
int dub[100005];

void dfs1(int x, int p, ll* d) {
	for (auto [y, w] : e[x]) {
		if (y == p)
			continue;
		d[y] = d[x] + w;
		dfs1(y, x, d);
	}
}

void reroot(int x, int p) {
	for (auto [y, w] : e[x]) {
		if (y == p)
			continue;
		f[x] += y;
		dub[y] = dub[x] + 1;
		reroot(y, x);
	}
}

int p[100005], sz[100005], maxsz;

int ep(int x) {
	if (x == p[x])
		return x;
	return p[x] = ep(p[x]);
}

void dinit() {
	fill(sz+1, sz+n+1, 0);
	fill(p+1, p+n+1, 0);
	maxsz = 0;
}

void dadd(int x) {
	sz[x] = 1;
	p[x] = x;
	for (int y : f[x]) {
		if (!p[y])
			continue;
		p[y] = x;
		sz[x] += sz[y];
	}
	maxsz = max(maxsz, sz[x]);
}

void dremove(int x) {
	sz[ep(x)]--;
	p[x] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u] += {v, w};
		e[v] += {u, w};
	}

	da[1] = 0;
	dfs1(1, 1, da);
	int a = max_element(da+1, da+n+1) - da;
	da[a] = 0;
	dfs1(a, a, da);
	int b = max_element(da+1, da+n+1) - da;
	db[b] = 0;
	dfs1(b, b, db);
	for (int i=1; i<=n; i++)
		d[i] = max(da[i], db[i]);

	int centar = min_element(d+1, d+n+1) - d;
	reroot(centar, centar);

	vector<int> c(n);
	iota(c.begin(), c.end(), 1);
	sort(c.begin(), c.end(), [&](int x, int y) {
		if (d[x] != d[y])
			return d[x] > d[y];
		return dub[x] > dub[y];
	});

	int q;
	cin >> q;
	while (q--) {
		ll w;
		cin >> w;
		dinit();
		for (int l=0, r=0; l<n; l++) {
			while (r < n && d[c[l]] - d[c[r]] <= w) {
				dadd(c[r++]);
			}
			dremove(c[l]);
		}
		cout << maxsz << '\n';
	}
}