#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct LCT {
	static const int mxn = 6e5 + 5;
	int rev[mxn], fa[mxn], ch[2][mxn], sz[mxn], virt[mxn];
	int val[mxn], mn[mxn], tot;

	LCT() { mn[0] = 0x3f3f3f3f; }

	#define ls ch[0]
	#define rs ch[1]
	#define nroot(x) (ls[fa[x]] == x || rs[fa[x]] == x)

	inline int nd(int v) {
		int x = ++ tot;
		rev[x] = 0;
		fa[x] = 0;
		ls[x] = rs[x] = 0;
		sz[x] = 1;
		virt[x] = 0;
		val[x] = mn[x] = v;
		return x;
	}

	inline void push(int x) {
		rev[x] ^= 1;
		swap(ls[x], rs[x]);
	}

	inline void pushdown(int x) {
		if (rev[x]) {
			if (ls[x]) push(ls[x]);
			if (rs[x]) push(rs[x]);
			rev[x] = 0;
		}
	}

	inline void pushup(int x) {
		sz[x] = sz[ls[x]] + 1 + sz[rs[x]] + virt[x];
		mn[x] = min(mn[ls[x]], min(val[x], mn[rs[x]]));
	}

	void rot(int x) {
		int y = fa[x];
		int d = x == rs[y];
		int z = fa[y];
		if (nroot(y)) ch[y == rs[z]][z] = x;
		fa[x] = z; fa[y] = x; fa[ch[d ^ 1][x]] = y;
		ch[d][y] = ch[d ^ 1][x]; ch[d ^ 1][x] = y;
		pushup(y); pushup(x);
	}

	void upd(int x) {
		if (nroot(x)) upd(fa[x]);
		pushdown(x);
	}

	void splay(int x) {
		upd(x);
		while (nroot(x)) {
			int y = fa[x], z = fa[y];
			if (nroot(y)) rot(((rs[z] == y) ^ (rs[y] == x)) ? x : y);
			rot(x);
		}
	}

	void access(int x) {
		for (int lst = 0; x; x = fa[x]) {
			splay(x);
			virt[x] += sz[rs[x]];
			rs[x] = lst;
			virt[x] -= sz[rs[x]];
			pushup(x);
			lst = x;
		}
	}

	void makeroot(int x) {
		access(x);
		splay(x);
		push(x);
	}

	int findroot(int x) {
		access(x);
		splay(x);
		int y = x;
		pushdown(y);
		while (ls[y]) y = ls[y], pushdown(y);
		splay(y);
		return y;
	}

	void link(int x, int y) {
		makeroot(x);
		access(y);
		splay(y);
		rs[y] = x;
		fa[x] = y;
		pushup(y);
	}

	void cut(int x, int y) {
		makeroot(x);
		access(y);
		splay(y);
		ls[y] = 0;
		fa[x] = 0;
		pushup(y);
	}
} lct;

const int mxn = 5e5 + 5;
int n, q, k;
int nd[mxn], ed[mxn];
vector <pair <int, pair <int, int> > > E;

void LINK(int e) {
	int u = E[e].second.first;
	int v = E[e].second.second;
	lct.makeroot(nd[u]);
	if (lct.findroot(nd[v]) == nd[u]) {
		lct.access(nd[v]);
		lct.splay(nd[v]);
		int ne = lct.mn[nd[v]];
		lct.cut(nd[E[ne].second.first], ed[ne]);
		lct.cut(nd[E[ne].second.second], ed[ne]);
	}
	lct.link(nd[u], ed[e]);
	lct.link(nd[v], ed[e]);
}

void CUT(int e) {
	int u = E[e].second.first;
	int v = E[e].second.second;
	lct.makeroot(nd[u]);
	if (lct.findroot(nd[v]) == nd[u]) {
		lct.cut(nd[u], ed[e]);
		lct.cut(nd[v], ed[e]);
	}
}

int main() {
	scanf("%d %d %d", &n, &q, &k);
	rep(i, n) nd[i] = lct.nd(0x3f3f3f3f);
	int d = 0, j = 0;
	while (q --) {
		int t; scanf("%d", &t);
		if (t == 1) {
			int u, v;
			scanf("%d %d", &u, &v);
			-- u; -- v;
			ed[E.size()] = lct.nd(E.size());
			E.pb(mp(d, mp(u, v)));
			LINK(E.size() - 1);
		} else if (t == 2) {
			int u;
			scanf("%d", &u);
			-- u;
			lct.access(nd[u]);
			lct.splay(nd[u]);
			printf("%d\n", (lct.sz[nd[u]] + 1) >> 1);
		} else if (t == 3) {
			++ d;
			while (j < (int) E.size() && E[j].first <= d - k) {
				CUT(j);
				++ j;
			}
		}
	}
	return 0;
}