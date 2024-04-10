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

const int N = 105000;
const int P = 1e9 + 7;
int h[N], ne[N<<1], to[N<<1], tot;
inline void add(int x, int y) { ne[++tot] = h[x], to[h[x] = tot] = y; }
int dep[N], f[N], siz[N], son[N], Top[N], dfn[N], vis[N], cnt, nw;
void dfs1(int x, int fa) {
	dep[x] = dep[f[x] = fa] + (siz[x] = 1);
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		dfs1(y, x), siz[x] += siz[y];
		if (siz[son[x]] < siz[y]) son[x] = y;
	}
}
void dfs2(int x, int topf) {
	Top[x] = topf, dfn[x] = ++cnt;
	if (son[x]) dfs2(son[x], topf);
	for (int i = h[x], y; i; i = ne[i])
		if (!dfn[y = to[i]]) dfs2(y, y);
}

inline int Lca(int x, int y) {
	while (Top[x] != Top[y]) {
		if (dep[Top[x]] < dep[Top[y]]) swap(x, y);
		x = f[Top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}

int dp[N][301], a[N], st[N], tp, m, n, q, k, r;
vector<int> vec[N];
inline int mod(int x) { return x >= P ? x - P : x; }
inline void adde(int x, int y) { vec[x].push_back(y), vec[y].push_back(x); }
void Dp(int x, int fa) {
	if (vis[x]) {
		++cnt;
		for (int i = 1;i <= m; ++i)
			dp[cnt][i] = (dp[cnt-1][i-1] + 1ll * dp[cnt-1][i] * max(0, i - nw)) % P;
		nw += vis[x];
	}
	for (auto t: vec[x]) if (t != fa) Dp(t, x);
	nw -= vis[x], vis[x] = 0, vec[x].clear();
}

int main() {
	read(n), read(q);
	for (int i = 1, x, y;i < n; ++i)
		read(x), read(y), add(x, y), add(y, x);
	dfs1(1, 0), dfs2(1, 1), dp[0][0] = 1;
	for (int i = 1;i <= q; ++i) {
		read(k), read(m), read(r);
		for (int j = 1;j <= k; ++j) read(a[j]), vis[a[j]] = 1;
		if (!vis[1]) a[++k] = 1;
		if (!vis[r] && r != 1) a[++k] = r;
		sort(a + 1, a + k + 1, [&](int x, int y) { return dfn[x] < dfn[y]; });
		st[tp = 1] = 1;
		for (int j = 2;j <= k; ++j) {
			int lca = Lca(a[j], st[tp]);
			while (tp > 1 && dfn[st[tp-1]] >= dfn[lca]) adde(st[tp-1], st[tp]), --tp;
			if (lca != st[tp]) adde(lca, st[tp]), st[tp] = lca;
			st[++tp] = a[j];
		}
		while (tp > 1) adde(st[tp - 1], st[tp]), --tp;
		cnt = 0, Dp(r, 0);
		int ans = 0;
		for (int j = 1;j <= m; ++j) ans = mod(ans + dp[cnt][j]);
		write(ans);
	}
	return 0;
}

/*

10 1
2 1
3 2
4 2
5 1
6 4
7 5
8 6
9 3
10 7
4 3 1 9 4 8 7



*/