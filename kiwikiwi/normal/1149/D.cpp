#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int n, m, a, b, g[77][77], mask[77], ans[77];
int x[210], y[210], w[210];
int dis[(1 << 17) + 10][77];
vector<pair<int, int> > e[77];

const int inf = 800000000;

int main() {
	scanf("%d%d%d%d", &n, &m, &a, &b);
	for (int i = 1; i <= n; i++)
		ans[i] = inf;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			g[i][j] = (i == j) ? 0 : inf;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &x[i], &y[i], &w[i]);
		if (w[i] == a) {
			g[x[i]][y[i]] = 1;
			g[y[i]][x[i]] = 1;
		}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	for (int i = 1; i <= n; i++) mask[i] = -2;
	int c = 0;
	for (int i = 1; i <= n; i++) if (mask[i] == -2) {
			int sz = 0;
			for (int j = 1; j <= n; j++) if (g[i][j] < inf) {
					sz++;
				}
			int id = -1;
			if (sz >= 4) {
				id = c;
				++c;
			}
			for (int j = 1; j <= n; j++) if (g[i][j] < inf)
					mask[j] = id;

		}
	for (int i = 0; i < m; i++) {
		if (g[x[i]][y[i]] < inf && w[i] == b && w[i] <= g[x[i]][y[i]]*a) continue;
		e[x[i]].push_back(make_pair(y[i], w[i]));
		e[y[i]].push_back(make_pair(x[i], w[i]));
	}
	for (int s = 0; s < (1 << c); s++)
		for (int i = 1; i <= n; i++)
			dis[s][i] = inf;
	if (mask[1] == -1) dis[0][1] = 0;
	else dis[(1 << mask[1])][1] = 0;
	for (int s = 0; s < (1 << c); s++) {
		priority_queue<pair<int, int> > q;
		for (int u = 1; u <= n; u++)
			q.push(make_pair(-dis[s][u], u));
		while (!q.empty()) {
			auto it = q.top(); q.pop();
			int u = it.second, d = -it.first;
			ans[u] = min(ans[u], d);
			if (dis[s][u] != d)
				continue;
			for (auto w : e[u]) {
				int v = w.first;
				if (mask[v] != -1 && mask[u] != mask[v] && (s & (1 << mask[v])))
					continue;
				int ns = s;
				if (mask[v] != -1) ns |= (1 << mask[v]);
				if (d + w.second >= dis[ns][v]) continue;
				dis[ns][v] = d + w.second;
				if (ns == s) {
					q.push(make_pair(-dis[ns][v], v));
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}