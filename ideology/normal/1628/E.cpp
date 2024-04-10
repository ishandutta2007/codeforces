#include <cmath>
#include <cstring>

#include <algorithm>
#include <chrono>
#include <stack>
#include <bitset>
#include <numeric>
#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

typedef unsigned long long ull;

using namespace std;

const int _ = 600005;

int prt[_][20], ch[_][2];
int f[_], wt[_], dep[_];
int dfn[_], ver[_];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

tuple<int, int, int> ed[_];

void dfs(int u) {
	static int t;
	if (!ch[u][0]) { ver[dfn[u] = ++t] = u; return; }
	dfs(ch[u][0]); dfs(ch[u][1]);
}

int mn[_ << 2], mx[_ << 2], Mn[_ << 2], Mx[_ << 2], tag[_ << 2];
void update(int o) {
	mn[o] = min(mn[o << 1], mn[o << 1 | 1]);
	mx[o] = max(mx[o << 1], mx[o << 1 | 1]);
}
void modify(int o, int x) {
	tag[o] = x;
	if (x == 0) { mn[o] = 1e9; mx[o] = 0; }
	else { mn[o] = Mn[o]; mx[o] = Mx[o]; }
}
void pd(int o) {
	if (tag[o] == -1) return;
	modify(o << 1, tag[o]); modify(o << 1 | 1, tag[o]);
	tag[o] = -1; update(o);
}
void build(int o, int l, int r) {
	if (l == r) {
		mn[o] = 1e9; mx[o] = 0;
		Mn[o] = Mx[o] = dfn[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(o << 1, l, mid);
	build(o << 1 | 1, mid + 1, r);
	Mn[o] = min(Mn[o << 1], Mn[o << 1 | 1]);
	Mx[o] = max(Mx[o << 1], Mx[o << 1 | 1]);
	update(o);
}
void modify(int o, int l, int r, int ql, int qr, int x) {
	if (l == ql && r == qr) return modify(o, x);
	pd(o);
	int mid = (l + r) >> 1;
	if (qr <= mid) modify(o << 1, l, mid, ql, qr, x);
	else if (ql > mid) modify(o << 1 | 1, mid + 1, r, ql, qr, x);
	else {
		modify(o << 1, l, mid, ql, mid, x);
		modify(o << 1 | 1, mid + 1, r, mid + 1, qr, x);
	}
	update(o);
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 19; i >= 0; --i)
		if (((dep[u] - dep[v]) >> i) & 1)
			u = prt[u][i];
	if (u == v) return u;
	for (int i = 19; i >= 0; --i)
		if (prt[u][i] != prt[v][i]) {
			u = prt[u][i];
			v = prt[v][i];
		}
	return prt[u][0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, Q; cin >> N >> Q;
	int M = N * 2 - 1; iota(f + 1, f + M + 1, 1);
	for (int i = 1; i < N; ++i) {
		int u, v, w; cin >> u >> v >> w;
		ed[i] = make_tuple(w, u, v);
	}
	sort(ed + 1, ed + N);
	for (int i = 1; i < N; ++i) {
		int u, v, w; tie(w, u, v) = ed[i];
		wt[N + i] = w;
		u = find(u); v = find(v);
		f[u] = f[v] = N + i;
		prt[u][0] = prt[v][0] = N + i;
		ch[N + i][0] = u; ch[N + i][1] = v;
	}
	for (int i = M; i; --i) {
		dep[i] = dep[prt[i][0]] + 1;
		for (int j = 1; j != 20; ++j)
			prt[i][j] = prt[prt[i][j - 1]][j - 1];
	}
	dfs(M);
	build(1, 1, N);
	while (Q--) {
		int opt, x, y;
		cin >> opt >> x;
		if (opt == 1) {
			cin >> y; modify(1, 1, N, x, y, 1);
		} else if (opt == 2) {
			cin >> y; modify(1, 1, N, x, y, 0);
		} else {
			int myn = min(mn[1], dfn[x]), mex = max(mx[1], dfn[x]);
			int ans = lca(ver[myn], ver[mex]);
			if (ans <= N) cout << "-1\n";
			else cout << wt[ans] << '\n';
		}
	}

	return 0;
}