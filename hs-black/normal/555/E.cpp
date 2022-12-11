
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

const int N = 300580;
int vis[N], dfn[N], low[N], st[N], d1[N], d2[N], bl[N], tp;
int dep[N], Top[N], col[N], f[N], son[N], siz[N], cnt;
int h[N], ne[N<<1], to[N<<1], tot = 1;

inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}

void dfs1(int x, int fa, int anc) {
	dep[x] = dep[f[x] = fa] + (siz[x] = 1);
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		dfs1(y, x, anc), siz[x] += siz[y]; 
		if (siz[y] > siz[son[x]]) son[x] = y;
	}
	bl[x] = anc;
}

void dfs2(int x, int topf) {
	Top[x] = topf; if (!son[x]) return;
	dfs2(son[x], topf);
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

int sc;
void tarjan(int x, int in) {
	st[++tp] = x, dfn[x] = low[x] = ++cnt;
	for (int i = h[x]; i ; i = ne[i]) {
		int y = to[i]; if (i == in) continue;
		if (!dfn[y]) tarjan(y, i ^ 1), Mn(low[x], low[y]);
		else Mn(low[x], dfn[y]);
	}
	if (dfn[x] == low[x]) {
		int z; 
		while (z = st[tp--]) {
			vis[z] = 0, col[z] = x;
			if (x == z) break;
		}
	}
}

int n, m, q;
void rebuild(void) {
	for (int i = 1;i <= n; i++) if (!dfn[i]) tarjan(i, 0);
	int res = tot; tot = 0; memset(h, 0, sizeof(h));
	for (int i = 2;i < res; i += 2) {
		int x = to[i], y = to[i + 1];
		if (col[x] == col[y]) continue;
		add(col[x], col[y]), add(col[y], col[x]);
	}
	for (int i = 1;i <= n; i++)
		if (!Top[col[i]] && col[i] == i) dfs1(i, 0, i), dfs2(i, i);
}

void work(int x, int fa) {
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		work(y, x), d1[x] += d1[y], d2[x] += d2[y];
	}
	if (d1[x] && d2[x]) {
		puts("No"); exit(0);
	}
}

int main() {
	read(n), read(m), read(q);
	for (int i = 1, x, y;i <= m; i++)
		read(x), read(y), add(x, y), add(y, x);
	rebuild();
	for (int i = 1, x, y;i <= q; i++) {
		read(x), read(y); x = col[x], y = col[y];
		if (bl[x] != bl[y]) return puts("No"), 0;
		d1[x]++, d2[y]++; int lca = Lca(x, y);
		d1[lca]--, d2[lca]--; 
	}
	work(1, 0);
	return puts("Yes"), 0;
}