#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define V 1234567
#define E 1234567
#define maxN 56
i64 inf = 1ll << 50;

int s, t, vtot;
struct edge {
	int v, ne;
	i64 f;
} e[E * 2];
int g[V], et;
void ae(int u, int v, i64 f) {
	e[et] = {v, g[u], f};
	g[u] = et++;
	e[et] = {u, g[v], 0};
	g[v] = et++;
}
int d[V], cu[V];
bool lb() {
	for (int i = 0; i < vtot; i++) {
		d[i] = 0;
		cu[i] = g[i];
	}
	static int qu[V];
	int p = 0, q = 0;
	qu[q++] = s;
	d[s] = 1;
	while (p != q) {
		int u = qu[p++];
		for (int i = g[u]; ~i; i = e[i].ne)
			if (e[i].f && !d[e[i].v]) {
				d[e[i].v] = d[u] + 1;
				if (e[i].v == t)return 1;
				qu[q++] = e[i].v;
			}
	}
	return 0;
}
i64 aug(int u, i64 m) {
	if (u == t)return m;
	i64 su = 0, f;
	for (int i = cu[u]; ~i; cu[u] = i = e[i].ne)
		if (e[i].f && d[e[i].v] == d[u] + 1) {
			f = aug(e[i].v, min(m, e[i].f));
			e[i].f -= f;
			e[i ^ 1].f += f;
			m -= f;
			su += f;
			if (!m) break;
		}
	if (!su) d[u] = -1;
	return su;
}
i64 dinic() {
	i64 su = 0;
	while (lb())
		su += aug(s, inf);
	return su;
}
void init() {
	for (int i = 0; i < vtot; i++) g[i] = -1;
	et = 0;
}

int n, h, m, id[maxN][maxN], constraint[maxN];
i64 ans;

int main() {
	scanf("%d%d%d", &n, &h, &m);
	s = vtot++;
	t = vtot++;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= h; j++)
			id[i][j] = vtot++;
	}
	for (int i = 0; i < m; i++) constraint[i] = vtot++;
	init();
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= h; j++) {
			ae(id[i][j], id[i][j - 1], inf);
		}
		for (int j = 1; j <= h; j++) {
			ae(s, id[i][j], 2 * j - 1);
			ans += 2 * j - 1;
		}
	}
	for (int i = 0; i < m; i++) {
		int l, r, x, c;
		scanf("%d%d%d%d", &l, &r, &x, &c);
		--l; --r;
		if (x >= h) continue;
		ae(constraint[i], t, c);
		for (int j = l; j <= r; j++) {
			ae(id[j][x + 1], constraint[i], inf);
		}
	}
	printf("%lld\n", ans - dinic());
}