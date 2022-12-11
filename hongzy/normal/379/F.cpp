#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e6 + 10;

int n = 4, ans = 2, l, r, d[N], bel[N], f[N][23];

int lca(int u, int v) {
	if(d[u] < d[v]) swap(u, v);
	int c = d[u] - d[v];
	for(int i = 22; i >= 0; i --)
		if(c >> i & 1) u = f[u][i];
	if(u == v) return u;
	for(int i = 22; i >= 0; i --) {
		if(f[u][i] != f[v][i]) {
			u = f[u][i]; v = f[v][i];
		}
	}
	return f[u][0];
}

int qry(int x, int y) {
	return d[x] + d[y] - (d[lca(x, y)] << 1);
}

void create(int x) {
	int u = n + 1, v = n + 2;
	f[u][0] = f[v][0] = x;
	d[u] = d[v] = d[x] + 1;
	for(int i = 1; i < 23; i ++) {
		f[u][i] = f[f[u][i - 1]][i - 1];
		if(!f[u][i]) break ;
		f[v][i] = f[u][i];
	}
	int q1 = qry(l, u);
	if(q1 > ans) ans = q1, r = u;
	else {
		int q2 = qry(r, u);
		if(q2 > ans) ans = q2, l = u;
	}
	n += 2;
}

int main() {
	int q; scanf("%d", &q);
	d[1] = 0; d[2] = d[3] = d[4] = 1;
	f[2][0] = f[3][0] = f[4][0] = 1; l = 2; r = 3;
	while(q --) {
		int x; scanf("%d", &x); create(x);
		printf("%d\n", ans);
	}
	return 0;
}