#include <bits/stdc++.h>
using namespace std;

#define get(x, y) ((x - 1) * m + y)
typedef pair <int, int> pii;
const int maxn = 1e6 + 10;
int n, m, tot, a[maxn], f[maxn], par[maxn];
struct node {
	int x, y;
	bool operator < (const node& o) const {
		return a[get(x, y)] < a[get(o.x, o.y)];
	}
} dat[maxn];
vector <int> g[maxn];

int find(int x) {
	return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y) {
	par[find(x)] = find(y);
}

int dfs(int u) {
	if (~f[u]) return f[u]; f[u] = 0;
	for (int v : g[u]) f[u] = max(f[u], dfs(v));
	return ++f[u];
}

int main() {
	scanf("%d %d", &n, &m), tot = n * m;
	for (int i = 1; i <= tot; i++) {
		scanf("%d", a + i), par[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dat[j] = node{i, j};
		}
		sort(dat + 1, dat + m + 1);
		for (int j = 1; j < m; j++) {
			int u = get(dat[j].x, dat[j].y);
			int v = get(dat[j + 1].x, dat[j + 1].y);
			if (a[u] == a[v]) unite(u, v);
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			dat[i] = node{i, j};
		}
		sort(dat + 1, dat + n + 1);
		for (int i = 1; i < n; i++) {
			int u = get(dat[i].x, dat[i].y);
			int v = get(dat[i + 1].x, dat[i + 1].y);
			if (a[u] == a[v]) unite(u, v);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dat[j] = node{i, j};
		}
		sort(dat + 1, dat + m + 1);
		for (int j = 1; j < m; j++) {
			int u = get(dat[j].x, dat[j].y);
			int v = get(dat[j + 1].x, dat[j + 1].y);
			if ((u = find(u)) != (v = find(v))) g[v].push_back(u);
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			dat[i] = node{i, j};
		}
		sort(dat + 1, dat + n + 1);
		for (int i = 1; i < n; i++) {
			int u = get(dat[i].x, dat[i].y);
			int v = get(dat[i + 1].x, dat[i + 1].y);
			if ((u = find(u)) != (v = find(v))) g[v].push_back(u);
		}
	}
	memset(f, -1, sizeof f);
	for (int i = 1; i <= tot; i++) {
		if (find(i) == i) dfs(i);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d ", f[find(get(i, j))]);
		}
		putchar(10);
	}
	return 0;
}