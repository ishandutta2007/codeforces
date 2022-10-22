#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n, m, cnt, fa[maxn], sum[maxn], dep[maxn], top[maxn], son[maxn], size[maxn], tid[maxn << 1], head[maxn], nxt[maxn << 1], to[maxn << 1];

void addline(int u, int v) {
	nxt[++cnt] = head[u], head[u] = cnt, to[cnt] = v;
}

int dfs1(int u, int f) {
	size[u] = 1, fa[u] = f, dep[u] = dep[f] + 1;
	for (int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		if (v != f) {
			tid[i] = v, size[u] += dfs1(v, u);
			if (size[v] > size[son[u]]) son[u] = v;
		}
	}
	return size[u];
}

void dfs2(int u, int tp) {
	top[u] = tp;
	if (son[u]) dfs2(son[u], tp);
	for (int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		if (v != fa[u] && v != son[u]) dfs2(v, v);
	}
}

int get_sum(int u) {
	for (int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		if (v != fa[u]) sum[u] += get_sum(v);
	}
	return sum[u];
}

int lca(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) {
			u = fa[top[u]];
		} else {
			v = fa[top[v]];
		}
	}
	return dep[u] > dep[v] ? v : u;
}

int main() {
	int u, v;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &u, &v);
		addline(u, v), addline(v, u);
	}
	dfs1(1, 0), dfs2(1, 1);
	scanf("%d", &m);
	while (m--) {
		scanf("%d %d", &u, &v);
		sum[u]++, sum[v]++, sum[lca(u, v)] -= 2;
	}
	get_sum(1);
	for (int i = 1; i <= cnt; i++) {
		if (tid[i]) printf("%d ", sum[tid[i]]);
	}
	return 0;
}