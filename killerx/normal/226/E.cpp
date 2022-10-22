#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct SEG {
	static const int maxn = 1e7 + 1e6 + 5;
	int ls[maxn], rs[maxn], s[maxn], tot;
	int nd() { int x = ++ tot; ls[x] = rs[x] = s[x] = 0; return x; }
	int cl(int o) { int x = ++ tot; ls[x] = ls[o]; rs[x] = rs[o]; s[x] = s[o]; return x; }
	void upd(int &o, int a, int b, int x, int v) {
		if (!o) o = nd(); else o = cl(o);
		s[o] += v; if (a + 1 == b) return ;
		int m = (a + b) >> 1;
		if (x < m) upd(ls[o], a, m, x, v);
		else upd(rs[o], m, b, x, v);
	}
	int qry(int &p, int &q, int a, int b, int l, int r) {
		if (!p && !q) return 0;
		if (l <= a && b <= r) return s[p] - s[q];
		int m = (a + b) >> 1, ans = 0;
		if (l < m) ans += qry(ls[p], ls[q], a, m, l, r);
		if (r > m) ans += qry(rs[p], rs[q], m, b, l, r);
		return ans;
	}
} seg;

const int maxn = 1e5 + 5;
int n;
vector <int> g[maxn];
int dfn[maxn], ed[maxn], tme;
int rt[maxn], cnt;
int tt[maxn];
int r;
int fa[maxn][20], dep[maxn];

void dfs(int u = r) {
	dfn[u] = tme ++;
	rep(i, g[u].size()) dep[g[u][i]] = dep[u] + 1, fa[g[u][i]][0] = u, dfs(g[u][i]);
	ed[u] = tme;
}

int lca(int u, int v) {
	if (dep[u] > dep[v]) swap(u, v);
	rep(i, 20) if ((dep[v] - dep[u]) >> i & 1) v = fa[v][i];
	if (u == v) return u;
	for (int i = 20 - 1; ~i; -- i) if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}

int qry(int u, int v, int y) {
	int xx = seg.qry(rt[cnt], rt[y], 0, n, 0, dfn[u] + 1);
	if (v != r) xx -= seg.qry(rt[cnt], rt[y], 0, n, 0, dfn[fa[v][0]] + 1);
	return dep[u] - dep[v] + 1 - xx;
}

int kth(int u, int k) {
	rep(i, 20) if (k >> i & 1) u = fa[u][i];
	return u;
}

int fnd(int u, int k, int y) {
	int lb = 0, rb = dep[u];
	while (lb < rb) {
		int md = (lb + rb) >> 1;
		if (qry(u, kth(u, md), y) >= k) rb = md;
		else lb = md + 1;
	}
	return kth(u, lb);
}

int main() {
	scanf("%d", &n);
	rep(i, n) {
		int fa; scanf("%d", &fa); -- fa;
		if (!~fa) r = i; else g[fa].pb(i);
	}
	dfs();
	fa[r][0] = r;
	rep(j, 20) if (j) rep(i, n) fa[i][j] = fa[fa[i][j - 1]][j - 1];
	int q; scanf("%d", &q);
	while (q --) {
		int tp; scanf("%d", &tp);
		rt[cnt + 1] = rt[cnt]; ++ cnt;
		if (tp == 1) {
			int u; scanf("%d", &u); -- u;
			tt[u] = cnt;
			seg.upd(rt[cnt], 0, n, dfn[u], +1);
			if (ed[u] < n) seg.upd(rt[cnt], 0, n, ed[u], -1);
		} else {
			int u, v, k, y; scanf("%d %d %d %d", &u, &v, &k, &y); -- u; -- v;
			int l = lca(u, v), tu = qry(u, l, y), tv = qry(v, l ,y);
			bool iu = tt[u] <= y, iv = tt[v] <= y, il = tt[l] <= y;
			int tot = tu + tv - il; k += iu;
			if (tot - iv < k) puts("-1");
			else {
				if (k <= tu) printf("%d\n", fnd(u, k, y) + 1);
				else printf("%d\n", fnd(v, tot - k + 1, y) + 1);
			}
		}
	}
	return 0;
}