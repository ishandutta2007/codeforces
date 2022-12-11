#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read(void) {
	int x = 0; bool f = 0;
	char c = getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
	for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	return f ? -x : x;
}

const int N = 100050;
int n, m;
int vis1[N], vis2[N];
int top[N], f[N], dis[N];
int son[N], dep[N], siz[N];

int x[N], y[N], d[N];
int w[N], tot, cnt;
int h[N], ne[N], to[N];
inline void add(int x,int y,int z) {
	ne[++tot] = h[x], to[tot] = y;
	w[tot] = z, h[x] = tot;
}

void dfs1(int x,int fa) {
	vis1[x] = siz[x] = 1, 
	dep[x] = dep[f[x] = fa] + 1;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		dfs1(y, x); siz[x] += siz[y];
		if (siz[son[x]] < siz[y]) son[x] = y;
	}
}

void dfs2(int x,int topf) {
	top[x] = topf; if (!son[x]) return;
	dfs2(son[x], topf);
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i];
		if (y == f[x] || y == son[x]) continue;
		dfs2(y, y);
	}
}

int lca(int x,int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = f[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}

int fa[N], ans[N];
int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int num, all;

void dfs(int x,int f) {
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == f) continue;
		dfs(y, x); d[x] += d[y];
	}
}

int main() {
	n = read(), m = read();
	for (int i = 1;i <= n; i++) fa[i] = i;
	for (int i = 1;i <= m; i++) {
		x[i] = read(), y[i] = read();
		if (find(x[i]) == find(y[i])) continue;
		vis2[i] = 1; fa[fa[x[i]]] = fa[y[i]];
		add(x[i], y[i], i);
		add(y[i], x[i], i);
	}
	for (int i = 1;i <= n; i++) 
		if (!vis1[i]) {
			dfs1(i, 0), dfs2(i, i);
			vis1[i] = 0;
		}
	for (int i = 1;i <= m; i++) {
		if (vis2[i]) continue;
		int anc = lca(x[i], y[i]), deta = 1;
		if ((dep[x[i]] + dep[y[i]] - dep[anc] * 2) & 1) deta = -1;
		else num = i, cnt++;
		d[x[i]] += deta, d[y[i]] += deta;
		d[anc] -= 2 * deta;
	}
	for (int i = 1;i <= n; i++) 
		if (!vis1[i]) dfs(i, 0);
	if (!cnt) {
		printf ("%d\n", m);
		for (int i = 1;i <= m; i++) printf ("%d ", i);
		return 0;
	}
	if (cnt == 1) ans[++all] = num;
	for (int i = 1;i <= n; i++) 
		for (int j = h[i]; j; j = ne[j]) 
			if (f[to[j]] == i && d[to[j]] == cnt) 
				ans[++all] = w[j];
	sort(ans + 1, ans + all + 1);
	cout << all << endl;
	for (int i = 1;i <= all; i++) printf ("%d ", ans[i]);
	return 0;
}