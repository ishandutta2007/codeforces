#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int N = 200005;
int h[N], ne[N<<1], to[N<<1];
int tot;
inline void add(int x,int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}
int n, q, t;

template <typename T> 
void read(T &x) {
    x = 0; int f = 1;char c = getchar();
    while (!isdigit(c)) { if (c == '-') f = -1; c = getchar();}
    while (isdigit(c)) { x = (x << 3)+(x << 1) + c-'0'; c = getchar();}
    x *= f;
}

int siz[N], fa[N];
int son[N], dep[N];
int top[N];
void dfs1(int x,int f) {
	siz[x] = 1, fa[x] = f, dep[x] = dep[f] + 1;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == f) continue;
		dfs1(y, x); siz[x] += siz[y];
		if (siz[y] > siz[son[x]]) son[x] = y;
	}
}

void dfs2(int x,int topf) {
	top[x] = topf;
	if (!son[x]) return;
	dfs2(son[x], topf);
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa[x] || y == son[x]) continue;
		dfs2(y, y);
	}
}

int lca(int x,int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	if (dep[x] < dep[y]) swap(x, y);
	return y;
}

int get_dis(int x, int y) {
	return dep[x] + dep[y] - dep[lca(x, y)] * 2;
}

inline bool work(ll a, ll b, ll k) {
	if (a <= k && (a & 1) == (k & 1)) return true;
	if (b <= k && (b & 1) == (k & 1)) return true;
	return false;
}

int main() {
	read(n);
	for (int i = 1;i < n; i++) {
		int x, y; read(x), read(y); 
		add(x, y), add(y, x);
	} dfs1(1, 0), dfs2(1, 1);
	read(q);
	while (q--) {
		int x, y, a, b, k;
		read(a), read(b), read(x), read(y), read(k);
		ll ra = get_dis(x, y), 
			rb = min(get_dis(x, a) + 1 + get_dis(b, y), get_dis(x, b) + 1 + get_dis(y, a));
		if (work(ra, rb, k)) printf ("YES\n");
		else printf ("NO\n");
	}
	return 0;
}

/*

7
1 2
2 3
2 4
4 5
5 6
1 7
5
1 2 1 7 5
3 5 4 2 6
1 7 5 6 0
2 3 4 5 6 
2 4 5 7 6

*/