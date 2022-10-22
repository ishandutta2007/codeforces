#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 3e5 + 5;
const int mxnd = mxn * 20 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;

struct SEG {
	int stk[mxnd], top, tot;

	ll tag[mxnd], mn[mxnd];
	int ls[mxnd], rs[mxnd];

	int nd() {
		int x = top ? stk[-- top] : ++ tot;
		tag[x] = 0;
		mn[x] = inf;
		ls[x] = rs[x] = 0;
		return x;
	}

	void del(int x) {
		stk[top ++] = x;
	}

	void push(int x, ll v) {
		tag[x] += v;
		tag[x] = min(tag[x], inf);
		mn[x] += v;
		mn[x] = min(mn[x], inf);
	}

	void pushdown(int x) {
		if (tag[x]) {
			if (ls[x])
				push(ls[x], tag[x]);
			if (rs[x])
				push(rs[x], tag[x]);
			tag[x] = 0;
		}
	}

	void pushup(int x) {
		mn[x] = inf;
		if (ls[x])
			mn[x] = min(mn[x], mn[ls[x]]);
		if (rs[x])
			mn[x] = min(mn[x], mn[rs[x]]);
	}

	int merge(int x, int y,
			int a = 0, int b = mxn, ll mnx = inf, ll mny = inf) {
		if (!x && !y)
			return 0;
		else if (!x) {
			push(y, mnx);
			return y;
		}
		else if (!y) {
			push(x, mny);
			return x;
		}
		else if (a + 1 == b) {
			mn[x] = min(mn[x] + mn[y], min(mn[x] + mny, mn[y] + mnx));
			mn[x] = min(mn[x], inf);
			del(y);
			return x;
		}
		pushdown(x);
		pushdown(y);
		int m = (a + b) >> 1;
		ll nmnx = min(mnx, rs[x] ? mn[rs[x]] : inf);
		ll nmny = min(mny, rs[y] ? mn[rs[y]] : inf);
		ls[x] = merge(ls[x], ls[y], a, m, nmnx, nmny);
		rs[x] = merge(rs[x], rs[y], m, b, mnx, mny);
		del(y);
		pushup(x);
		return x;
	}

	void upd(int &x, int p, ll v, int a = 0, int b = mxn) {
		if (!x)
			x = nd();
		if (a + 1 == b) {
			mn[x] = v;
			if (mn[x] >= inf) {
				del(x);
				x = 0;
			}
			return ;
		}
		pushdown(x);
		int m = (a + b) >> 1;
		if (p < m)
			upd(ls[x], p, v, a, m);
		else
			upd(rs[x], p, v, m, b);
		pushup(x);
		if (mn[x] >= inf) {
			del(x);
			x = 0;
		}
	}

	void debug(int x, int a = 0, int b = mxn) {
		if (!x)
			return ;
		if (a + 1 == b) {
			if (mn[x] < inf)
				printf("(%d, %lld)", a + 1, mn[x]);
			return ;
		}
		pushdown(x);
		int m = (a + b) >> 1;
		debug(ls[x], a, m);
		debug(rs[x], m, b);
	}
} seg;

int n, m;
vector <int> g[mxn];
map <int, int> fx[mxn];
int dfn[mxn], on[mxn];
int rt[mxn];

void dfs(int u, int p) {
	static int tme = 0;
	on[tme] = u;
	dfn[u] = tme ++;
	rep(i, g[u].size()) {
		int v = g[u][i];
		if (v == p)
			continue;
		dfs(v, u);
	}
}

void solve(int u, int p) {
	seg.upd(rt[u], dfn[u], 0);
	rep(i, g[u].size()) {
		int v = g[u][i];
		if (v == p)
			continue;
		solve(v, u);
		seg.upd(rt[v], dfn[v], inf);
		rt[u] = seg.merge(rt[u], rt[v]);
	}
//	cerr << u + 1 << ": "; seg.debug(rt[u]); cerr << endl;
	int temp = 0;
	map <int, int>::iterator it;
	for (it = fx[u].begin(); it != fx[u].end(); ++ it)
		seg.upd(temp, dfn[it->first], it->second);
	seg.upd(temp, dfn[u], 0);
	rt[u] = seg.merge(rt[u], temp);
//	cerr << u + 1 << ": "; seg.debug(rt[u]); cerr << endl;
}

int main() {
	scanf("%d %d", &n, &m);
	rep(i, n - 1) {
		int u, v;
		scanf("%d %d", &u, &v);
		-- u, -- v;
		g[u].pb(v), g[v].pb(u);
	}
	dfs(0, -1);
	rep(i, m) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		-- u, -- v;
		if (u == v) continue;
		if (fx[u].find(v) == fx[u].end())
			fx[u][v] = 0x3f3f3f3f;
		fx[u][v] = min(fx[u][v], w);
	}
	solve(0, -1);
	ll ans = rt[0] ? seg.mn[rt[0]] : inf;
	if (ans >= inf)
		printf("-1\n");
	else
		printf("%lld\n", ans);
	return 0;
}