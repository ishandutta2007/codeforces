/*
    ___                         ______      __                  __
   /   |____  __  ___________ _/ ____/___ _/ /___  ____  ______/ /____
  / /| /_  / / / / / ___/ __ `/ /   / __ `/ __/ / / / / / / __  / ___/
 / ___ |/ /_/ /_/ (__  ) /_/ / /___/ /_/ / /_/ /_/ / /_/ / /_/ (__  )
/_/  |_/___/\__,_/____/\__,_/\____/\__,_/\__/\__, /\__, /\__,_/____/
                                            /____//____/

 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)


*/

#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n') {
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 1005000;
int h[N], ne[N], to[N], dfn[N], dep[N], pos[N], tot, len, q, n;
inline void add(int x, int y) { ne[++tot] = h[x], to[h[x] = tot] = y; }
namespace Azusa {
	int siz[N], Top[N], son[N], id[N], f[N], cnt;
	void dfs1(int x, int fa) {
		dep[x] = dep[f[x] = fa] + (siz[x] = 1);
		for (int i = h[x]; i; i = ne[i]) {
			int y = to[i]; if (y == fa) continue;
			dfs1(y, x), siz[x] += siz[y];
			if (siz[y] > siz[son[x]]) son[x] = y;
		}
	}
	void dfs2(int x, int topf) {
		Top[x] = topf, id[dfn[x] = ++cnt] = x;
		if (son[x]) dfs2(son[x], topf);
		for (int i = h[x], y; i; i = ne[i]) 
			if ((y = to[i]) != f[x] && y != son[x]) dfs2(y, y);
	}
	int Lca(int x, int y) {
		while (Top[x] != Top[y]) {
			if (dep[Top[x]] < dep[Top[y]]) swap(x, y);
			x = f[Top[x]];
		}
		return dep[x] < dep[y] ? x : y;
	}
	int getto(int x, int z) {
		int t = 0;
		while (Top[x] != Top[z]) t = Top[x], x = f[t];
		return x == z ? t : son[z];
	}
	bool in(int x, int y) { return dfn[x] <= dfn[y] && dfn[y] <= dfn[x] + siz[x] - 1; }
}

using Azusa::Lca;
using Azusa::getto;
namespace jzp {
	int st[20][N], lg[N];
	void main() {
		lg[0] = -1;
		for (int i = 1;i <= len; ++i) 
			st[0][i] = pos[i], lg[i] = lg[i >> 1] + 1;
		for (int i = 1;i <= 19; ++i) 
			for (int j = 1;j + (1 << i) - 1 <= len; ++j)
				st[i][j] = Lca(st[i-1][j], st[i-1][j + (1 << i - 1)]);
	}
	int query(int l, int r) {
		int t = lg[r - l + 1];
		return Lca(st[t][l], st[t][r - (1 << t) + 1]);
	}
}

namespace SegmentTree {
	#define ls p << 1
	#define rs ls | 1
	int mx[N<<2];
	void build(int p, int l, int r) {
		if (l == r) return mx[p] = Azusa::id[l], void();
		int mid = (l + r) >> 1;
		build(ls, l, mid), build(rs, mid + 1, r);
		mx[p] = max(mx[ls], mx[rs]);
	}
	int query(int p, int l, int r, int L, int R) {
		if (L <= l && r <= R) return mx[p];
		int mid = (l + r) >> 1, mmx = 0;
		if (L <= mid) Mx(mmx, query(ls, l, mid, L, R));
		if (R > mid) Mx(mmx, query(rs, mid + 1, r, L, R));
		return mmx;
	}
	void change(int p, int l, int r, int x, int t) {
		if (l == r) return mx[p] = t, void();
		int mid = (l + r) >> 1;
		x <= mid ? change(ls, l, mid, x, t) : change(rs, mid + 1, r, x, t);
		mx[p] = t;
	}
	#undef ls
	#undef rs
}
using SegmentTree::query;
namespace Bit {
	int d[N];
	void Add(int x, int c) { for (; x <= len; x += x & -x) d[x] += c; }
	int Sum(int x) { int res = 0; for (; x; x-= x & -x) res += d[x]; return res; }
}

namespace LCT {
	#define ls s[x][0]
	#define rs s[x][1]
	#define I inline 
	#define V void
	int s[N][2], siz[N], col[N], f[N];
	I bool chk(int x) { return s[f[x]][1] == x; }
	I bool nrt(int x) { return s[f[x]][chk(x)] == x; }
	I V rotate(int x) {
		int y = f[x], z = f[y], k = chk(x), w = s[x][!k];
		if (nrt(y)) s[z][chk(y)] = x; f[x] = z;
		if (w) f[w] = y; s[y][k] = w;
		s[x][!k] = y, f[y] = x;
	}
	I V spread(int x) { if (col[x]) col[ls] = col[rs] = col[x]; }
	I V pus(int x) { if (nrt(x)) pus(f[x]); spread(x); }
	I V splay(int x) {
		pus(x);
		for (int y; nrt(x); rotate(x))
			if (nrt(y = f[x])) rotate(chk(y)^chk(x) ? x : y);
	}
	I V access(int x, int t) {
		Bit::Add(t, dep[x]); int y;
		for (y = 0; x; x = f[y = x]) {
			splay(x), rs = y;
			if (col[x]) Bit::Add(col[x], -(dep[x] - dep[f[x]]));
		}
		splay(y), col[y] = t;
	}
}

int Query(int l, int r) {
	int t = jzp::query(l, r);
	return Bit::Sum(r) - Bit::Sum(l - 1) - dep[t] + 1;
}

int Dis(int x, int y) { return dep[x] + dep[y] - 2 * dep[Lca(x, y)]; }

int ans[N];
char op[N]; int X[N], inv[N], m;
int main() {
//	freopen ("magician.in","r",stdin);
//	freopen ("magician.out","w",stdout);
	read(n), read(m);
	for (int i = 1, x, y;i < n; ++i) 
		read(x), read(y), add(x, y), add(y, x);
	Azusa::dfs1(1, 0), Azusa::dfs2(1, 1);
	for (int i = 1;i <= n; ++i) LCT::f[i] = Azusa::f[i], pos[i] = inv[i] = i;
	len = n; int t = 0;
	for (int i = 1;i <= m; ++i) {
		char o[9]; int x;
		scanf ("%s", o), read(x);
		op[++t] = o[0], X[t] = x;
		if (o[0] == 'u') pos[++len] = X[t];
		if (o[0] == 'c') op[++t] = o[0], read(X[t]);
	}
	m = t, jzp::main(), SegmentTree::build(1, 1, n);
	int rt = n, nw = n;
	for (int i = 1;i <= n; ++i) LCT::access(i, i);
	for (int i = 1;i <= m; ++i) {
		if (op[i] == 'u') {
			LCT::access(rt = X[i], ++nw), inv[nw] = rt;
			SegmentTree::change(1, 1, n, dfn[X[i]], nw), ans[i] = -1;
		} else {
			if (X[i] == rt) { ans[i] = n; continue; }
			int t;
			if (Azusa::in(X[i], rt)) {
				int sn = getto(rt, X[i]);
				t = query(1, 1, n, 1, dfn[sn] - 1);
				if (dfn[sn] + Azusa::siz[sn] <= n) Mx(t, query(1, 1, n, dfn[sn] + Azusa::siz[sn], n));
			} else t = query(1, 1, n, dfn[X[i]], dfn[X[i]] + Azusa::siz[X[i]] - 1);
			ans[i] = n - (Query(t, nw) - Dis(X[i], inv[t]) - 1);
		}
	}
	for (int i = 1;i <= m; ++i) 
		if (op[i] == 'c') write(ans[i] < ans[i + 1] ? X[i] : X[i + 1]), ++i;
		else if (op[i] == 'w') write(ans[i]);
	return 0;
}