
/*
 
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

const int N = 200500;
int m, n;
namespace Work {
	const int P = 1e9 + 7;
	int h[N], ne[N<<1], to[N<<1], tot;
	inline void add(int x, int y) {
		ne[++tot] = h[x], to[h[x] = tot] = y;
	}
	int dep[N], sum[N], siz[N], f[N], Top[N], son[N];
	void dfs1(int x, int fa) {
		dep[x] = dep[f[x] = fa] + (siz[x] = 1);
		sum[x] = sum[fa];
		for (int i = h[x]; i; i = ne[i]) {
			int y = to[i]; if (y == fa) continue;
			sum[x] += y > n;
		}
		for (int i = h[x]; i; i = ne[i]) {
			int y = to[i]; if (y == fa) continue;
			dfs1(y, x), siz[x] += siz[y];
			if (siz[y] > siz[son[x]]) son[x] = y;
		}
	}
	void dfs2(int x, int topf) {
		Top[x] = topf; if (son[x]) dfs2(son[x], topf);
		for (int i = h[x], y; i; i = ne[i])
			if ((y = to[i]) != son[x] && y != f[x]) dfs2(y, y);
	}
	int Lca(int x, int y) {
		while (Top[x] != Top[y]) {
			if (dep[Top[x]] < dep[Top[y]]) swap(x, y);
			x = f[Top[x]];
		}
		return dep[x] < dep[y] ? x : y;
	}
	int mi[N], q;
	void main() {
		dfs1(1, 0), dfs2(1, 1), read(q); mi[0] = 1;
		for (int i = 1;i <= n; i++) mi[i] = mi[i-1] * 2 % P;
		for (int i = 1, x, y;i <= q; i++) {
			read(x), read(y); int lca = Lca(x, y);
			write(mi[sum[x] + sum[y] - sum[lca] - sum[f[lca]] + (f[lca] > n) + (lca > n)]);
		}
	}
}

namespace Prework {
	int dfn[N], low[N], cnt, sz;
	int h[N], ne[N<<1], to[N<<1], deg[N], tot;
	inline void add(int x, int y) {
		ne[++tot] = h[x], to[h[x] = tot] = y;
	}
	void init(void) {
		read(n), read(m);
		for (int i = 1, x, y;i <= m; i++)
			read(x), read(y), add(x, y), add(y, x);
	}
	int cut[N], vis[N], f[N], ncnt;
	void adde(int x, int y) { Work::add(x, y), Work::add(y, x); }
	void solve(int x, int y) {
		++ncnt; adde(x, ncnt);
		while (y != x) adde(y, ncnt), y = f[y];
	}
	void tarjan(int x, int fa) {
		dfn[x] = low[x] = ++cnt;
		for (int i = h[x]; i; i = ne[i]) {
			int y = to[i]; if (y == fa) continue;
			if (dfn[y]) Mn(low[x], dfn[y]);
			else f[y] = x, tarjan(y, x), Mn(low[x], low[y]);
			if (low[y] > dfn[x]) adde(x, y);
		}
		for (int i = h[x], y; i; i = ne[i]) 
			if (f[y = to[i]] != x && dfn[y] > dfn[x]) solve(x, y);
	}
	void main() { init(), ncnt = n, tarjan(1, 0); }
}

int main() { return Prework::main(), Work::main(), 0; }


/*

10 11
1 2
2 3
3 4
1 4
3 5
5 6
8 6
8 7
7 6
7 9
9 10
1
9 2

*/