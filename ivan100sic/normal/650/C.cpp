#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int r[1000005], c[1000005];
vector<vector<int>> a;
map<int, vector<pair<int, int>>> mp;

struct dsu {
	vector<int> p, v;

	dsu(int n) : p(n), v(n, 0) {
		iota(p.begin(), p.end(), 0);
	}

	int e(int x) {
		if (x == p[x])
			return p[x];
		return p[x] = e(p[x]);
	}

	void add(int x, int y) {
		x = e(x);
		v[x] = max(v[x], y);
	}

	void spoji(int x, int y) {
		x = e(x);
		y = e(y);
		if (x == y)
			return;
		p[x] = y;
		v[y] = max(v[y], v[x]);
	}

	int daj(int x) {
		return v[e(x)];
	}
};

int ex[1000005], ey[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	a.resize(n, vector<int>(m, 0));
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			int x;
			cin >> x;
			mp[x].emplace_back(i, j);
		}
	}

	memset(ex, 0xff, sizeof ex);
	memset(ey, 0xff, sizeof ey);

	dsu d(n*m);

	for (auto& [_, v] : mp) {
		for (auto [x, y] : v) {
			int z = max(r[x], c[y]) + 1;
			d.add(x+n*y, z);

			if (ex[x] != -1)
				d.spoji(x+n*y, ex[x]);
			if (ey[y] != -1)
				d.spoji(x+n*y, ey[y]);

			ex[x] = x+n*y;
			ey[y] = x+n*y;
		}

		for (auto [x, y] : v) {
			a[x][y] = d.daj(x+n*y);
			r[x] = max(r[x], a[x][y]);
			c[y] = max(c[y], a[x][y]);
		}

		for (auto [x, y] : v) {
			ex[x] = -1;
			ey[y] = -1;
			d.p[x+n*y] = x+n*y;
			d.v[x+n*y] = 0;
		}
	}

	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cout << a[i][j] << " \n"[j == m-1];
}