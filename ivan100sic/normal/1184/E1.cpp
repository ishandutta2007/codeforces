#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct edge {
	int u, v, w, id;

	bool operator< (const edge& b) const {
		return tie(w, id) < tie(b.w, b.id);
	}
};

struct dsu {
	vector<int> p;

	dsu(int n) : p(n) {
		iota(p.begin(), p.end(), 0);
	}

	int e(int x) {
		if (x == p[x])
			return x;
		return p[x] = e(p[x]);
	}

	bool spoji(int x, int y) {
		x = e(x);
		y = e(y);
		if (x == y)
			return false;
		p[x] = y;
		return true;
	}
};

int n, m;
edge f[1000005];
edge g[1000005];

bool moze(int e) {
	g[0] = f[0];
	g[0].w = e;
	copy(f+1, f+m, g+1);
	sort(g, g+m);
	dsu d(n+1);
	for (int i=0; i<m; i++)
		if (d.spoji(g[i].u, g[i].v) && g[i].id == 0)
			return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> f[i].u >> f[i].v >> f[i].w;
		f[i].id = i;
	}
	int l = 0, r = 1e9, o = -1;
	while (l <= r) {
		int m = (l+r) >> 1;
		if (moze(m)) {
			o = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	cout << o << '\n';
}