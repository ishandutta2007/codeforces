#include <bits/stdc++.h>
using namespace std;

void solve_case();

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);

	// int test; for (cin >> test; test --; )
	{
		solve_case();
	}
}

struct node_t {
	using val_t = int64_t;
	struct line_t {
		val_t a, b;
		line_t (val_t _a = 0, val_t _b = 0) : a(_a), b(_b) {}
		val_t eval(val_t x) { return a * x + b; }
	} ln;

	node_t *l = 0, *r = 0;
	val_t tl, tr;

	node_t(val_t _tl = 0, val_t _tr = 0) : tl(_tl), tr(_tr) { ln = line_t(0, 4e18); }

	inline void clear() { if (l) l -> clear(); if (r) r -> clear(); free(this); }

	void add(val_t a, val_t b) { add(line_t(a, b)); }
	void add(line_t new_ln) {
		val_t tm = (tl + tr) >> 1;
		bool md = new_ln.eval(tm) < ln.eval(tm),
			 lf = new_ln.eval(tl) < ln.eval(tl);

		if (md) swap(new_ln, ln);

		if (tl == tr || new_ln.eval(0) == 4e18) return ;

		if (md != lf) {
			if (!l) l = new node_t(tl, tm);
			l -> add(new_ln);
		} else {
			if (!r) r = new node_t(tm + 1, tr);
			r -> add(new_ln);
		}
	}

	val_t query(val_t x) {
		val_t tm = (tl + tr) >> 1, res = ln.eval(x);
		if (x <= tm) {
			if (l) res = min(l -> query(x), res);
		} else {
			if (r) res = min(r -> query(x), res);
		}
		return res;
	} 
} * root = new node_t(-1e9, 1e9); // range of queries

const int N = 1e5 + 5;

int n, a[N], b[N];
int64_t dp[N];

void solve_case() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];

	root -> add(b[1], dp[1]);
	for (int i = 2; i <= n; i++) {
		dp[i] = root -> query(a[i]);
		root -> add(b[i], dp[i]);
	}

	cout << dp[n];
}