#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
int n, m, q;
int fa[N], sz[N], d[N], son[N], top[N], dfn[N], pos[N], idx;
vector<int> G[N];
void dfs1(int u) {
	sz[u] = 1; son[u] = 0;
	for(int v : G[u]) if(v != fa[u]) {
		fa[v] = u; d[v] = d[u] + 1; dfs1(v); sz[u] += sz[v];
		if(sz[v] > sz[son[u]]) son[u] = v;
	}
}
void dfs2(int u, int t) {
	top[u] = t; dfn[u] = ++ idx; pos[idx] = u;
	if(son[u]) {
		dfs2(son[u], t);
		for(int v : G[u]) if(!dfn[v]) dfs2(v, v);
	}
}
struct Node {
	int x[10];
	void init() { fill(x, x + 10, N); }
	Node operator + (const Node &b) {
		int u = 0, v = 0; Node ans;
		for(int i = 0; i < 10; i ++) {
			ans.x[i] = x[u] < b.x[v] ? x[u ++] : b.x[v ++];
		}
		return ans;
	}
} val[N << 2], now;
priority_queue<int> pq[N];
void build(int u, int l, int r) {
	if(l == r) {
		l = pos[l]; int s = pq[l].size();
		for(int i = 9; i >= s; i --) val[u].x[i] = N;
		for(int i = s - 1; i >= 0; i --) {
			val[u].x[i] = pq[l].top(); pq[l].pop();
		}
		return ;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	val[u] = val[u << 1] + val[u << 1 | 1];
}
void query(int u, int l, int r, int ql, int qr) {
	if(l == ql && r == qr) { now = now + val[u]; return ; }
	int mid = (l + r) >> 1;
	if(qr <= mid) query(u << 1, l, mid, ql, qr);
	else if(ql > mid) query(u << 1 | 1, mid + 1, r, ql, qr);
	else {
		query(u << 1, l, mid, ql, mid);
		query(u << 1 | 1, mid + 1, r, mid + 1, qr);
	}
}
Node tquery(int u, int v) {
	now.init();
	while(top[u] ^ top[v]) {
		if(d[top[u]] < d[top[v]]) swap(u, v);
		query(1, 1, n, dfn[top[u]], dfn[u]);
		u = fa[top[u]];
	}
	if(dfn[u] > dfn[v]) swap(u, v);
	query(1, 1, n, dfn[u], dfn[v]);
	return now;
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for(int u, v, i = 1; i < n; i ++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int x, i = 1; i <= m; i ++) {
		scanf("%d", &x);
		if(pq[x].size() < 10) pq[x].push(i);
		else if(pq[x].top() > i) {
			pq[x].pop(); pq[x].push(i);
		}
	}
	dfs1(1); dfs2(1, 1); build(1, 1, n);
	for(int u, v, a, i = 1; i <= q; i ++) {
		scanf("%d%d%d", &u, &v, &a);
		Node ans = tquery(u, v); int sz = 0;
		for(int j = 0; j < 10; j ++) sz += ans.x[j] != N;
		printf("%d", sz = min(sz, a));
		for(int j = 0; j < sz; j ++) printf(" %d", ans.x[j]);
		putchar('\n');
	}
	return 0;
}