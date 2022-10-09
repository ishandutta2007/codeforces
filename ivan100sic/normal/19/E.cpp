#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct dsu {
	vector<int> p, sz, c;
	int valid;

	dsu(int n) : p(n), sz(n, 1), c(n, 0), valid(1) {
		iota(p.begin(), p.end(), 0);
	}

	vector<pair<int*, int>> changes;

	void put_flag() {
		changes.emplace_back(nullptr, 0);
	}

	void save(int& x) {
		changes.emplace_back(&x, x);
	}

	pair<int, int> e(int x) {
		int z = 0;
		while (x != p[x]) {
			z ^= c[x];
			x = p[x];
		}
		return {x, z};
	}

	void bipart_spoji(int x, int y) {
		auto [xr, xc] = e(x);
		auto [yr, yc] = e(y);

		if (xr != yr) {
			if (sz[xr] > sz[yr])
				swap(xr, yr);

			save(p[xr]);
			save(c[xr]);
			save(sz[yr]);

			p[xr] = yr;
			c[xr] = 1 ^ xc ^ yc;
			sz[yr] += sz[xr];
		} else {
			if (xc == yc) {
				save(valid);
				valid = 0;
			}
		}
	}

	void roll_back() {
		while (1) {
			auto [x, y] = changes.back();
			changes.pop_back();
			if (!x) return;
			*x = y;
		}
	}
};

int n, m;
int u[10005], v[10005];
vector<int> sol;

void solve(int l, int r, dsu& d) {
	if (l == r) {
		if (d.valid) {
			sol.push_back(l);
		}
	} else {
		int m = (l+r) >> 1;

		d.put_flag();
		for (int i=m+1; i<=r; i++) {
			d.bipart_spoji(u[i], v[i]);
		}
		solve(l, m, d);
		d.roll_back();

		d.put_flag();
		for (int i=l; i<=m; i++) {
			d.bipart_spoji(u[i], v[i]);
		}
		solve(m+1, r, d);
		d.roll_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=m; i++)
		cin >> u[i] >> v[i];
	dsu d(n+1);
	if (m) solve(1, m, d);
	cout << sol.size() << '\n';
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}