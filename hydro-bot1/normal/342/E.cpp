// Hydro submission #633e8e9fba4ac7a74c187f2d@1665044127517
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int LOGN = 17;
int n, m;
int f[MAXN][LOGN], depth[MAXN];
int tmpdis[MAXN];
vector<int> g[MAXN];
void dfs(int cur, int father) {
	depth[cur] = depth[father] +1;
	f[cur][0] = father;
	for (int i = 1; i < LOGN; i++)
		f[cur][i] = f[f[cur][i-1]][i-1];
	for (int i = 0; i < g[cur].size(); i++) {
		if (g[cur][i] == father) continue;
		dfs(g[cur][i], cur);
	}
}
int lca(int u, int v) {
	if (depth[u] > depth[v]) swap(u, v);
	for (int i = LOGN-1; i >= 0; i--) {
		if (depth[f[v][i]] >= depth[u]) v = f[v][i];
	}
	for (int i = LOGN-1; i >= 0; i--) {
		int s = f[u][i], t = f[v][i];
		if (s != t) {
			u = s;
			v = t;
		}
	}
	if (u != v)
		return f[u][0];
	return u;
}
int dist(int u, int v) {
	int l = lca(u, v);
	return depth[u]+depth[v] - 2*depth[l];
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n-1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 1);
	int b = sqrt(m);
	vector<int> buf;
	memset(tmpdis, 0x3f, sizeof tmpdis);
	buf.push_back(1);
	for (int i = 0; i < m; i++) {
		int type, v;
		scanf("%d%d", &type, &v);
		if (type == 1) {
			buf.push_back(v);
		} else {
			int ans = tmpdis[v];
			for (int i = 0; i < buf.size(); i++)
				ans = min(ans, dist(v, buf[i]));
			printf("%d\n", ans);
		}
		if (i%b == 0) {
			queue<int> q;
			for (int i = 0; i < buf.size(); i++) {
				q.push(buf[i]);
				tmpdis[buf[i]] = 0;
			}
			buf.clear();
			while (!q.empty()) {
				int f = q.front();
				q.pop();
				for (int i = 0; i < g[f].size(); i++) {
					if (tmpdis[g[f][i]] > tmpdis[f]+1) {
						tmpdis[g[f][i]] = tmpdis[f]+1;
						q.push(g[f][i]);
					}
				}
			}
		}
	}
	return 0;
}