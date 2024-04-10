#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1 << 18;
int n;
int v[mxn];
int fa[mxn];
vector <int> g[mxn];
int dfn[mxn], ed[mxn];
int eu[mxn * 2], fst[mxn], lst[mxn], cnt, lg[mxn * 2], mn[mxn * 2][19];

void dfs(int u) {
	static int tme = 0;
	dfn[u] = tme ++;
	fst[u] = lst[u] = cnt; eu[cnt ++] = u;
	rep(i, g[u].size()) {
		int v = g[u][i];
		dfs(v);
		lst[u] = cnt; eu[cnt ++] = u;
	}
	ed[u] = tme ++;
}

void init() {
	for (int i = 2; i <= cnt; ++ i)
		lg[i] = lg[i >> 1] + 1;
	rep(j, 19) rep(i, cnt) {
		if (j)
			mn[i][j] = (dfn[mn[i][j - 1]] < dfn[mn[i + (1 << (j - 1))][j - 1]] ? mn[i][j - 1] : mn[i + (1 << (j - 1))][j - 1]);
		else
			mn[i][j] = eu[i];
	}
}

int lca(int u, int v) {
	if (fst[u] > fst[v])
		swap(u, v);
	int l = fst[u], r = lst[v], k = lg[r - l + 1];
	return dfn[mn[l][k]] < dfn[mn[r - (1 << k) + 1][k]] ? mn[l][k] : mn[r - (1 << k) + 1][k];
}

bool on(int u, int v, int w) {
	int l = lca(u, v);
	if (!(dfn[l] <= dfn[w] && ed[w] <= ed[l])) return 0;
	if (dfn[w] <= dfn[u] && ed[u] <= ed[w]) return 1;
	if (dfn[w] <= dfn[v] && ed[v] <= ed[w]) return 1;
	return 0;
}

struct SEG {
	struct S {
		bool is;
		int u, v;

		S() {
			is = 1;
			u = -1;
			v = -1;
		}

		S operator + (const S &o) const {
			S an;
			if (!is || !o.is) {
				an.is = 0;
				an.u = -1;
				an.v = -1;
				return an;
			}
			if (u == -1)
				return o;
			if (o.u == -1)
				return *this;
			int ids[] = {u, v, o.u, o.v};
			rep(a, 4) rep(b, a) {
				rep(c, 4) rep(d, c) {
					if (a == c || b == c || d == a || d == b)
						continue;
					if (on(ids[a], ids[b], ids[c]) && on(ids[a], ids[b], ids[d])) {
						an.is = 1;
						an.u = ids[a];
						an.v = ids[b];
						return an;
					}
				}
			}
			an.is = 0;
			an.u = -1;
			an.v = -1;
			return an;
		}
	} s[mxn << 1];

	void upd(int x, int v, int i, int a, int b) {
		if (a + 1 == b) {
			s[i].is = 1;
			s[i].u = s[i].v = v;
			return ;
		}
		int m = (a + b) >> 1;
		if (x < m)
			upd(x, v, i << 1, a, m);
		else
			upd(x, v, i << 1 | 1, m, b);
		s[i] = s[i << 1] + s[i << 1 | 1];
	}

	int qry(int i, int a, int b, S x) {
		if ((x + s[i]).is)
			return b;
		if (a + 1 == b)
			return a;
		int m = (a + b) >> 1;
		S y = x + s[i << 1];
		if (y.is)
			return qry(i << 1 | 1, m, b, y);
		else
			return qry(i << 1, a, m, x);
	}
} seg;

int main() {
	scanf("%d", &n);
	rep(i, n)
		scanf("%d", &v[i]);
	rep(i, n) if (i)
		scanf("%d", &fa[i]), -- fa[i], g[fa[i]].pb(i);
	dfs(0);
	init();
	rep(i, n)
		seg.upd(v[i], i, 1, 0, n);
	int q;
	scanf("%d", &q);
	while (q --) {
		int tp;
		scanf("%d", &tp);
		if (tp == 1) {
			int i, j;
			scanf("%d %d", &i, &j);
			-- i, -- j;
			swap(v[i], v[j]);
			seg.upd(v[i], i, 1, 0, n);
			seg.upd(v[j], j, 1, 0, n);
		} else {
			printf("%d\n", seg.qry(1, 0, n, SEG::S()));
		}
	}
	return 0;
}