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

const int N = 2e5 + 5;

int par[N], siz[N], dis[N], flag;
vector<pair<int*, int>> trace;

inline pair<int, int> find(int u) {
	int d = 0;
	while (u != par[u]) {
		d ^= dis[u];
		u  = par[u];
	}
	return {u, d};
}

inline void rollback(int k) {
	for (; (int) trace.size() > k; trace.pop_back())
		* trace.back().first = trace.back().second;
}

inline void apply(int * a, int b) { trace.emplace_back(a, *a), *a = b;}

inline void merge(int u, int v) {
	auto pu = find(u), pv = find(v);
	int du = pu.second, dv = pv.second;

	if ((u = pu.first) == (v = pv.first)) {
		if (du == dv)
			apply(&flag, 1);
		return ;
	}

	if (siz[v] > siz[u]) swap(u, v);

	apply(siz + u, siz[v] + siz[u]);
	apply(par + v, u);
	apply(dis + v, du ^ dv ^ 1);
}

struct edge_t {
	int u, v;
} e[N];
int n, m, q, opt[N];

void solve(int l1, int r1, int l2, int r2) {
	if (l1 > r1) return ;
	if (l2 > r2) return ;
	if (l2 == r2) {
		for (int i = l1; i <= r1; i++)
			opt[i] = l2;
		return ;
	}
	int m1 = (l1 + r1) >> 1, m2 = 0, keep = trace.size();

	for (int i = l1; i < m1; i++) merge(e[i].u, e[i].v);
	for (int i = r2; i >= l2; i--) {
		merge(e[i].u, e[i].v);
		if (flag) {
			opt[m1] = m2 = i; break ; 
		}
	}

	if (!m2) opt[m1] = m2 = l2;
	rollback(keep);

	for (int i = r2; i > m2; i--)
		merge(e[i].u, e[i].v);
	solve(l1, m1 - 1, l2, m2);
	
	rollback(keep);

	for (int i = l1; i <= m1; i++)
		merge(e[i].u, e[i].v);
	solve(m1 + 1, r1, m2, r2);

	rollback(keep);
}

void solve_case() {
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++)
		cin >> e[i].u >> e[i].v;
	e[m + 1] = {0, 1};

	iota(par, par + n + 1, 0);
	fill(siz, siz + n + 1, 1);
	// merge(1, 0);

	solve(1, m, 1, m + 1);

	for (int i = 1, l, r; i <= q; i++) {
		cin >> l >> r;
		cout << (r < opt[l] ? "YES\n" : "NO\n");
	}
}