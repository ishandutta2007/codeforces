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
	int o;

	int root(int x) {
		while (x != a[x].p) x = a[x].p;
		return x;
	}

	void flag() { u.emplace_back(nullptr, 0); }
	void mark(int& x) { u.emplace_back(&x, x); }

	union_find_rollback(int n) : a(n) {
		for (int i=0; i<n; i++) a[i] = {i, 1};
		o = n;
	}

	void join(int x, int y) {
		x = root(x); y = root(y);
		if (x == y) return;
		mark(o);
		o -= (a[x].s & a[y].s & 1) * 2;
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
};

typedef union_find_rollback ufr;

struct edge {
	int x, y;
};

const int maxn = 524288;
vector<edge> e[2 * maxn];
vector<pair<int, int>> u[maxn];
int ans[500005];

int n, k, q;

void ad(edge g, int l, int r, int x=1, int xl=0, int xr=maxn) {
	if (r <= xl || xr <= l) return;
	if (l <= xl && xr <= r) {
		e[x].emplace_back(g);
		return;
	}

	int xm = (xl+xr) >> 1;
	ad(g, l, r, 2*x, xl, xm);
	ad(g, l, r, 2*x+1, xm, xr);
}

void rek(ufr& uf, int x, int xl, int xr) {
	uf.flag();
	for (auto [u, v] : e[x]) {
		uf.join(u, v);
	}

	if (xr-xl == 1) {
		for (auto [v, id] : u[xl]) {
			ans[id] = uf.a[uf.root(v)].s;
		}
	} else {
		int xm = (xl+xr) >> 1;
		rek(uf, 2*x, xl, xm);
		rek(uf, 2*x+1, xm, xr);
	}

	uf.rollback();
}

struct pivo {
	edge e;
	int day, i;
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	vector<pivo> dod;

	cin >> n >> q >> k;

	int day = 0, qid = 0;
	int ai = 0;
	for (int i=0; i<q; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, y;
			cin >> x >> y;
			x--, y--;
			dod.push_back({edge{x, y}, day, i});
		} else if (t == 2) {
			int x;
			cin >> x;
			u[i].emplace_back(x-1, qid++);
		} else {
			day++;
			while (ai < (int)dod.size() && dod[ai].day == day - k) {
				ad(dod[ai].e, dod[ai].i, i);
				ai++;
			}
		}
	}

	while (ai < (int)dod.size()) {
		ad(dod[ai].e, dod[ai].i, q);
		ai++;
	}

	ufr uf(n);
	rek(uf, 1, 0, maxn);

	for (int i=0; i<qid; i++) {
		cout << ans[i] << '\n';
	}
}