#include <bits/stdc++.h>
using namespace std;

#define N 524288
#define ull unsigned long long

int n, m, c[N];
int dfn[N], tme, siz[N];
ull col[N + N], lazy[N + N];
int head[N], nex[N + N], to[N + N], tot;

void add(int u, int v) {
	to[tot] = v;
	nex[tot] = head[u];
	head[u] = tot ++;
}

void dfs(int u, int p) {
	dfn[u] = tme ++, siz[u] = 1;
	for (int e = head[u]; ~e; e = nex[e]) {
		int v = to[e];
		if (v == p) continue;
		dfs(v, u);
		siz[u] += siz[v];
	}
}

void pd(int i) {
	if (~lazy[i]) {
		col[i] = lazy[i];
		if (i < N) {
			lazy[i + i] = lazy[i];
			lazy[i + i + 1] = lazy[i];
		}
		lazy[i] = -1;
	}
}

void upd(int i, int a, int b, int l, int r, int v) {
	if (l <= a && b <= r) {lazy[i] = 1ull << v; pd(i); return;}
	pd(i); if (r <= a || b <= l) return;
	int m = (a + b) >> 1;
	upd(i + i, a, m, l, r, v);
	upd(i + i + 1, m, b, l, r, v);
	col[i] = col[i + i] | col[i + i + 1];
}

ull qry(int i, int a, int b, int l, int r) {
	pd(i);
	if (l <= a && b <= r) return col[i];
	if (r <= a || b <= l) return 0;
	int m = (a + b) >> 1;
	ull L = qry(i + i, a, m, l, r);
	ull R = qry(i + i + 1, m, b, l, r);
	return L | R;
}

int count_bits(ull x) {
	int cnt = 0;
	while (x) {
		x -= x & -x;
		++ cnt;
	}
	return cnt;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++ i) scanf("%d", &c[i]), -- c[i];
	for (int i = 0; i < n; ++ i) head[i] = -1;
	for (int i = 1; i < n; ++ i) {
		int u, v; scanf("%d%d", &u, &v); -- u, -- v;
		add(u, v); add(v, u);
	}
	dfs(0, -1);
	for (int i = 0; i < n; ++ i) {
		upd(1, 0, N, dfn[i], dfn[i] + 1, c[i]);
	}
	while (m --) {
		int t, v; scanf("%d%d", &t, &v); -- v;
		if (t == 1) {
			int c; scanf("%d", &c); -- c;
			upd(1, 0, N, dfn[v], dfn[v] + siz[v], c);
		} else {
			printf("%d\n", count_bits(qry(1, 0, N, dfn[v], dfn[v] + siz[v])));
		}
	}
	return 0;
}