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

struct edge {
	int u, v, w;
};

int n, m;
edge a[300005];
int b[300005], rnk[300005], sol[300005];

/*
	za x = 0..m-1
	sol[x] = najmanji rank R (0..m-1) takav da su grane
	cija je pozicija <= x i rank <= R "sunny"

	sol je generalno opadajuca funkcija
*/

typedef union_find_rollback ufr;

void up(ufr& e, int& x, int& y) {
	y++;
	if (b[y] <= x) {
		auto [u, v, w] = a[b[y]];
		e.join(u, v);
	}
}

void right(ufr& e, int& x, int& y) {
	x++;
	if (rnk[x] <= y) {
		auto [u, v, w] = a[x];
		e.join(u, v);
	}
}

void up(ufr& e, int& x, int& y, int w) {
	while (w--) up(e, x, y);
}

void right(ufr& e, int& x, int& y, int w) {
	while (w--) right(e, x, y);
}

void solve(ufr& e, int l, int r, int& x, int& y) {
	if (l > r) return;
	int mid = (l+r) / 2;

	e.flag(); e.mark(x); e.mark(y);
	right(e, x, y, mid - x);

	e.flag(); e.mark(x); e.mark(y);

	int steps = 0;
	while (y+1 < m) {
		if (!e.o) break;
		up(e, x, y);
		steps++;
	}

	sol[mid] = e.o ? m : y;
	e.rollback();

	solve(e, mid+1, r, x, y);

	e.rollback();

	e.flag(); e.mark(x); e.mark(y);

	up(e, x, y, steps);
	solve(e, l, mid-1, x, y);

	e.rollback();
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		a[i] = {u, v, w};
		b[i] = i;
		sol[i] = m;
	}

	sort(b, b+m, [&](int x, int y) { return a[x].w < a[y].w; });
	for (int i=0; i<m; i++) {
		rnk[b[i]] = i;
	}

	ufr e(n);

	int x=-1, y=-1;
	solve(e, 0, m-1, x, y);

	for (int i=0; i<m; i++) {
		if (sol[i] < m) {
			cout << a[b[sol[i]]].w << '\n';
		} else {
			cout << "-1\n";
		}
	}
}