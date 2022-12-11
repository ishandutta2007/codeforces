#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
const int N = 2e6 + 5, M = 302;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m, c, q, ans[N], qc[N], qd[N], col[M][M], f[M * M], qx[N], qy[N];
int id(int x, int y) {
	return (x - 1) * m + y;
}
int find(int u) {
	return u == f[u] ? u : f[u] = find(f[u]);
}
bool merge(int u, int v) {
	u = find(u); v = find(v);
	if(u == v) return 0;
	f[u] = v; return 1;
}
struct node { int x, y, t; };
vector< vector<node> > a, b;
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= q; i ++) {
		scanf("%d%d%d", qx + i, qy + i, qc + i);
		qd[i] = col[qx[i]][qy[i]];
		col[qx[i]][qy[i]] = qc[i];
		c = max(c, qc[i]);
	}
	a.resize(c + 1); b.resize(c + 1);
	for(int i = 0; i <= c; i ++) {
		a[i].clear(); b[i].clear();
	}
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			a[0].push_back({i, j, 0});
	for(int i = 1; i <= q; i ++) {
		a[qc[i]].push_back({qx[i], qy[i], i});
		b[qd[i]].push_back({qx[i], qy[i], i});
	}
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			b[col[i][j]].push_back({i, j, q + 1});
	
	for(int i = 0; i <= c; i ++)
		reverse(b[i].begin(), b[i].end());
	for(int i = 0; i <= c; i ++) {
		for(auto u : a[i]) {
			if(!f[id(u.x, u.y)]) {
				f[id(u.x, u.y)] = id(u.x, u.y);
				ans[u.t] ++;
			}
			for(int k = 0; k < 4; k ++) {
				int nx = u.x + dx[k], ny = u.y + dy[k];
				if(nx < 1 || nx > n || ny < 1 || ny > m) continue ;
				if(f[id(nx, ny)]) {
					if(merge(id(nx, ny), id(u.x, u.y))) {
						ans[u.t] --;
					}
				}
			}
		}
		for(auto u : a[i]) {
			f[id(u.x, u.y)] = 0;
		}
	}
	for(int i = 0; i <= c; i ++) {
		for(auto u : b[i]) {
			if(!f[id(u.x, u.y)]) {
				f[id(u.x, u.y)] = id(u.x, u.y);
				ans[u.t] --;
			}
			for(int k = 0; k < 4; k ++) {
				int nx = u.x + dx[k], ny = u.y + dy[k];
				if(nx < 1 || nx > n || ny < 1 || ny > m) continue ;
				if(f[id(nx, ny)]) {
					if(merge(id(nx, ny), id(u.x, u.y))) {
						ans[u.t] ++;
					}
				}
			}
		}
		for(auto u : b[i]) {
			f[id(u.x, u.y)] = 0;
		}
	}
	for(int i = 1; i <= q; i ++) {
		printf("%d\n", ans[i] += ans[i - 1]);
	}
	return 0;
}