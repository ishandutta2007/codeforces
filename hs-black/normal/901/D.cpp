
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

const int N = 205000;
ll c[N], val[N], res[N];
int h[N], ne[N<<1], to[N<<1], tot = 1, m, n;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}

int dep[N], son[N], f[N], siz[N], Top[N], vis[N];
void dfs1(int x, int fa) {
	dep[x] = dep[f[x] = fa] + (siz[x] = vis[x] = 1), res[x] = c[x];
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (vis[y]) continue;
		dfs1(y, x), siz[x] += siz[y];
		if (siz[son[x]] < siz[y]) son[x] = y;
		val[i >> 1] = res[y], res[x] -= res[y];
	}
}

void dfs2(int x, int topf) {
	Top[x] = topf, vis[x] = 1, son[x] && (dfs2(son[x], topf), 0);
	for (int i = h[x], y; i; i = ne[i]) !vis[y = to[i]] && (dfs2(y, y), 0);
}

int Lca(int x, int y) {
	while (Top[x] != Top[y]) {
		if (dep[Top[x]] < dep[Top[y]]) swap(x, y);
		x = f[Top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}

inline void nope(void) { puts("NO"); exit(0); }
inline void ojbk(void) {
	puts("YES");
	for (int i = 1;i <= m; i++) write(val[i]);
	exit(0);
}

int main() {
	read(n), read(m);
	for (int i = 1;i <= n; i++) read(c[i]); 
	for (int i = 1, x, y;i <= m; i++)
		read(x), read(y), add(x, y), add(y, x);
	dfs1(1, 0), memset(vis, 0, sizeof(vis)), dfs2(1, 1);
	(res[1] & 1) ? nope(), 0 : !res[1] && (ojbk(), 0);
	for (int i = 1;i <= m; i++) {
		int x = to[i * 2], y = to[(i * 2) ^ 1];
		if ((dep[x] + dep[y]) & 1) continue;
		int t = (dep[x] & 1) ? 2 : -2, tmp = res[1] / t;
		val[i] = tmp, memset(vis, 0, sizeof(vis));
		c[x] -= tmp, c[y] -= tmp, dfs1(1, 0), ojbk();
	}
	nope();
	return 0;
}