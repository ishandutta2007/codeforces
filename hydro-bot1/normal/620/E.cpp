// Hydro submission #6204af17969d4a99c6a555ba@1644474135557
#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0, f = 0; char c = 0;
	while (!isdigit(c)) f |= c == '-', c = getchar();
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
	return f ? -x : x;
}

#define N 400010
#define pb push_back

int n, m, c[N], L[N], R[N], dfn[N], cnt = 0;
vector<int> e[N];

#define lid (id << 1)
#define rid (id << 1 | 1)
struct Segment {
	int l, r, tg;
	long long st;
}tr[N * 4];
void Build(int id, int l, int r) {
	tr[id].l = l, tr[id].r = r;
	if (tr[id].l == tr[id].r) {
		tr[id].st = 1ll << c[dfn[tr[id].l]];
		return;
	}
	int mid = (tr[id].l + tr[id].r) >> 1;
	Build(lid, l, mid), Build(rid, mid + 1, r);
	tr[id].st = tr[lid].st | tr[rid].st;
}
void Down(int id) {
	if (tr[id].l == tr[id].r || tr[id].tg == 0) return;
	tr[lid].st = tr[rid].st = 1ll << tr[id].tg;
	tr[lid].tg = tr[rid].tg = tr[id].tg;
	tr[id].tg = 0;
}
void Add(int id, int l, int r, int c) {
	Down(id);
	if (l <= tr[id].l && tr[id].r <= r) {
		tr[id].st = 1ll << c, tr[id].tg = c;
		return;
	}
	int mid = (tr[id].l + tr[id].r) >> 1;
	if (l <= mid) Add(lid, l, r, c);
	if (r > mid) Add(rid, l, r, c);
	tr[id].st = tr[lid].st | tr[rid].st;
}
long long Ask(int id, int l, int r) {
	Down(id);
	if (l <= tr[id].l && tr[id].r <= r) {
		return tr[id].st;
	}
	int mid = (tr[id].l + tr[id].r) >> 1;
	long long res = 0;
	if (l <= mid) res |= Ask(lid, l, r);
	if (r > mid) res |= Ask(rid, l, r);
	return res;
}

void dfs(int x, int fa) {
	L[x] = ++cnt, dfn[cnt] = x;
	for (auto y : e[x]) {
		if (y != fa) dfs(y, x);
	}
	R[x] = cnt;
}

int F(long long x, int s = 0) {
	while (x) {
		s ++, x -= x & -x;
	}
	return s;
}

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i ++) c[i] = read();
	for (int i = 1; i < n; i ++) {
		int x = read(), y = read();
		e[x].pb(y), e[y].pb(x);
	}

	dfs(1, 0);
	Build(1, 1, n);

	while (m --) {
		int op = read(), x = read();
		if (op == 1) {
			Add(1, L[x], R[x], read());
		} else {
			printf("%d\n", F(Ask(1, L[x], R[x])));
		}
	}
	return 0;
}