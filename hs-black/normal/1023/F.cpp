
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

const int N = 1005000;
struct node {
	int x, y; ll z;
	bool operator < (const node &i) const {
		return z < i.z;
	}
}ed[N];

ll w[N<<1], val[N];
int ne[N<<1], to[N<<1], h[N], f[N], tot; 
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
inline void add(int x, int y, ll z) {
	ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z;
}
inline void adde(int x, int y, ll z) {
	add(x, y, z), add(y, x, z);
}

int fat[N], dep[N], siz[N], son[N], Top[N];
void dfs(int x, int fa) {
	dep[x] = dep[fat[x] = fa] + (siz[x] = 1);
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		val[y] = w[i], dfs(to[i], x), siz[x] += siz[y];
		if (siz[son[x]] < siz[y]) son[x] = y;
	}
}

void dfs2(int x, int topf) {
	Top[x] = topf; if (son[x]) dfs2(son[x], topf);
	for (int i = h[x], y; i; i = ne[i])
		if ((y = to[i]) != fat[x] && y != son[x]) dfs2(y, y);
}

int Lca(int x, int y) {
	while (Top[x] != Top[y]) {
		if (dep[Top[x]] < dep[Top[y]]) swap(x, y);
		x = fat[Top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}

const ll inf = 0x3f3f3f3f3f3f3f;
int cnt, tp, n, k, m;
int main() {
	read(n), read(k), read(m);
	for (int i = 1;i <= k; i++)
		cnt++, read(ed[cnt].x), read(ed[cnt].y);
	for (int i = 1;i <= m; i++) 
		cnt++, read(ed[cnt].x), read(ed[cnt].y), read(ed[cnt].z);
	sort(ed + 1, ed + cnt + 1);
	for (int i = 1;i <= n; i++) f[i] = i;
	for (int i = 1;i <= cnt; i++) {
		int x = find(ed[i].x), y = find(ed[i].y);
		if (x == y) { ed[++tp] = ed[i]; continue; }
		adde(ed[i].x, ed[i].y, ed[i].z ? 0 : inf), f[x] = y;
	}
	for (int i = 1;i <= n; i++) 
		f[i] = i, !fat[i] && (dfs(i, 0), dfs2(i, i), 0);
	for (int i = 1;i <= tp; i++) {
		int lca = Lca(ed[i].x, ed[i].y);
		for (int t = find(ed[i].x); dep[t] > dep[lca]; t = find(t))
			Mn(val[t], ed[i].z), f[t] = fat[t];
		for (int t = find(ed[i].y); dep[t] > dep[lca]; t = find(t))
			Mn(val[t], ed[i].z), f[t] = fat[t];
	}
	ll ans = 0;
	for (int i = 1;i <= n; i++) 
		ans += val[i], Mn(ans, inf);
	ans < inf ? write(ans) : write(-1);
	return 0;
}