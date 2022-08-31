// stop creating problems

#include <bits/stdc++.h>
using namespace std;

const int maxN = 223456;

int cnt, l[maxN], r[maxN], dep[maxN], n, q, u, v;
int par[maxN][22];
vector<int> e[maxN];
set<pair<int, int>> extraEdge;

void dfs(int u, int f) {
	cnt++;
	l[u] = cnt;
	par[u][0] = f;
	dep[u] = dep[f] + 1;
	for (auto v : e[u]) {
		if (v == f) continue;
		dfs(v, u);
	}
	r[u] = cnt;
}

int lca(int u, int v) {
	if (dep[u] > dep[v])
		swap(u, v);
	int w = dep[v] - dep[u];
	for (int j = 19; j >= 0; j--)
		if ((w >> j) & 1)
			v = par[v][j];
	if (u == v) return u;
	for (int j = 19; j >= 0; j--)
		if (par[u][j] != par[v][j])	 {
			u = par[u][j];
			v = par[v][j];
		}
	return par[u][0];
}

struct segmentTree {
	int offset, val, cnt;
} tree[maxN << 2];
void push_down(int index) {
	int &w = tree[index].offset;
	tree[index * 2].offset += w;
	tree[index * 2].val += w;
	tree[index * 2 + 1].offset += w;
	tree[index * 2 + 1].val += w;
	w = 0;
}
void push_up(int index) {
	tree[index].val = max(tree[index * 2].val, tree[index * 2 + 1].val);
	tree[index].cnt = 0;
	if (tree[index * 2].val == tree[index].val)
		tree[index].cnt += tree[index * 2].cnt;
	if (tree[index * 2 + 1].val == tree[index].val)
		tree[index].cnt += tree[index * 2 + 1].cnt;
}

void build(int index = 1, int segl = 1, int segr = n) {
	tree[index].cnt = segr - segl + 1;
	if (segl == segr) return;
	int mid = (segl + segr) >> 1;
	build(index * 2, segl, mid);
	build(index * 2 + 1, mid + 1, segr);
}

void add(int l, int r, int v, int index = 1, int segl = 1, int segr = n) {
	if (segr < l || segl > r) return;
	if (l <= segl && segr <= r) {
		tree[index].offset += v;
		tree[index].val += v;
	} else {
		push_down(index);
		int mid = (segl + segr) >> 1;
		add(l, r, v, index * 2, segl, mid);
		add(l, r, v, index * 2 + 1, mid + 1, segr);
		push_up(index);
	}
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	build(1, 1, n);
	for (int j = 1; j <= 20; j++)
		for (int u = 1; u <= n; u++)
			par[u][j] = par[par[u][j - 1]][j - 1];
	cnt = 0;
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &u, &v);
		if (l[u] > l[v]) swap(u, v);
		int w = 0;
		if (extraEdge.count(make_pair(u, v))) {
			w = -1;
			extraEdge.erase(make_pair(u, v));
		} else {
			w = 1;
			extraEdge.insert(make_pair(u, v));
		}
		cnt += w;
		if (l[u] <= l[v] && r[u] >= r[v]) {
			add(1, n, w);
			int z = v;
			for (int j = 19; j >= 0; j--)
				if (dep[par[z][j]] > dep[u])
					z = par[z][j];
			add(l[z], r[z], -w);
			add(l[v], r[v], w);
		} else {
			add(l[u], r[u], w);
			add(l[v], r[v], w);
		}
		if (tree[1].val == cnt) {
			printf("%d\n", tree[1].cnt);
		} else {
			printf("0\n");
		}
	}
}