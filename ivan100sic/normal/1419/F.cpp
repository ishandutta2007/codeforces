// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct union_find_rollback {
	struct elem { int p, s; };
	vector<elem> a;
	vector<pair<int*, int>> u;

	int root(int x) {
		while (x != a[x].p) x = a[x].p;
		return x;
	}

	void flag() { u.emplace_back(nullptr, 0); }
	void mark(int& x) { u.emplace_back(&x, x); }

	union_find_rollback(int n) : a(n) {
		for (int i=0; i<n; i++) a[i] = {i, 1};
	}

	void join(int x, int y) {
		x = root(x); y = root(y);
		if (x == y) return;
		if (a[x].s > a[y].s) {
			swap(x, y);
		}
		mark(a[x].p); mark(a[y].s);
		a[x].p = y;
		a[y].s += a[x].s;
	}

	void rollback() {
		while (1) {
			auto [p, v] = u.back(); u.pop_back();
			if (p) {
				*p = v;
			} else {
				return;
			}
		}
	}

	//
	int sz(int x) {
		return a[root(x)].s;
	}

};

map<int, vector<pair<int, int>>> ex, ey;
int n;
int x[1005], y[1005];

int up(int p, int q) {
	auto it = ex.find(p);
	if (it == ex.end()) return -1;

	auto jt = lower_bound(begin(it->second), end(it->second), make_pair(q, -1));
	if (jt == end(it->second)) return -1;
	return jt->second;
}

int dn(int p, int q) {
	auto it = ex.find(p);
	if (it == ex.end()) return -1;

	auto jt = lower_bound(begin(it->second), end(it->second), make_pair(q, -1));
	if (jt == begin(it->second)) return -1;
	return prev(jt)->second;
}

int rt(int p, int q) {
	auto it = ey.find(q);
	if (it == ey.end()) return -1;

	auto jt = lower_bound(begin(it->second), end(it->second), make_pair(p, -1));
	if (jt == end(it->second)) return -1;
	return jt->second;
}

int lf(int p, int q) {
	auto it = ey.find(q);
	if (it == ey.end()) return -1;

	auto jt = lower_bound(begin(it->second), end(it->second), make_pair(p, -1));
	if (jt == begin(it->second)) return -1;
	return prev(jt)->second;
}

int bsc[4][1005][1005];
int xxc[1005][1005];
int yyc[1005][1005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x[i] >> y[i];
		ex[x[i]].emplace_back(y[i], i);
		ey[y[i]].emplace_back(x[i], i);
	}

	for (auto& [k, v] : ex) sort(begin(v), end(v));
	for (auto& [k, v] : ey) sort(begin(v), end(v));

	// make bsc
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {

			auto q = [&](int xx, int yy) {
				xxc[i][j] = xx;
				yyc[i][j] = yy;
				int c = 0;
				for (auto f : {up, dn, lf, rt}) {
					int k = f(xx, yy);
					bsc[c++][i][j] = k;
				}
			};

			// razlicito
			if (x[i] != x[j] && y[i] != y[j]) {
				q(x[i], y[j]);
			} else if (x[i] == x[j] && y[i] - y[j] >= 2) {
				q(x[i], (y[i] + 0ll + y[j]) / 2);
			} else if (x[i] - x[j] >= 2 && y[i] == y[j]) {
				q((x[i] + 0ll + x[j]) / 2, y[i]);
			}
		}
	}

	ll l=0, r=2.01e9, o=-1;
	while (l <= r) {
		int m = (l+r) / 2;
		union_find_rollback ufr(n+1);

		for (auto ee : {&ex, &ey}) {
			for (auto& [k, v] : *ee) {
				for (int i=0; i<(int)v.size()-1; i++) {
					if (v[i+1].first - v[i].first <= m) {
						ufr.join(v[i].second, v[i+1].second);
					}
				}
			}
		}

		bool ok = 0;
		if (ufr.sz(0) == n) {
			ok = 1;
		} else {
			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					ufr.flag();

					for (int d=0; d<4; d++) {
						int k = bsc[d][i][j];
						if (k != -1 && abs(xxc[i][j] - x[k]) + abs(yyc[i][j] - y[k]) <= m) {
							ufr.join(n, k);
						}
					}

					if (ufr.sz(0) == n+1) {
						ok = 1;
						i = j = n;
					}

					ufr.rollback();
				}
			}
		}

		if (ok) {
			o = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}

	cout << o << '\n';
}