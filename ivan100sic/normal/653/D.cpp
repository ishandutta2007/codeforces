#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct MaxFlow {

	struct edge {
		int next, v, cap, flow;
	};

	int n;
	vector<int> start, level, used;
	vector<edge> g;

	MaxFlow(int n) : start(n, -1), level(n, -1), used(n, -1) {}

	void add_edge(int u, int v, int c) {
		g.push_back({start[u], v, c, 0});
		start[u] = g.size() - 1;
		g.push_back({start[v], u, 0, 0});
		start[v] = g.size() - 1;
	}

	bool bfs(int s, int t) {
		queue<int> q;
		fill(level.begin(), level.end(), -1);
		q.push(s);
		level[s] = 0;
		while (q.size()) {
			int x = q.front(); q.pop();
			for (int i = start[x]; i != -1; i = g[i].next) {
				if (g[i].flow < g[i].cap && level[g[i].v] == -1) {
					level[g[i].v] = level[x] + 1;
					q.push(g[i].v);
				}
			}
		}
		return level[t] != -1;
	}

	int dfs(int x, int t, int f) {
		if (x == t)
			return f;
		for (int& i = used[x]; i != -1; i = g[i].next) {
			int v = g[i].v;
			if (level[v] == level[x] + 1 && g[i].flow < g[i].cap) {
				int z = dfs(v, t, min(f, g[i].cap - g[i].flow));
				if (z > 0) {
					g[i].flow += z;
					g[i^1].flow -= z;
					return z;
				}
			}
		}
		return 0;
	}

	int maxflow(int s, int t) {
		int f = 0;
		while (bfs(s, t)) {
			used = start;
			while (1) {
				int z = dfs(s, t, 1123123123);
				f += z;
				if (!z) break;
			}
		}
		return f;
	}
};

int n, m, mede;
int u[505], v[505], c[505];

bool probaj(ld w) {
	MaxFlow mf(n);
	for (int i=0; i<m; i++) {
		int cap = min((ld)1e9, floor(c[i] / (w / mede)));
		mf.add_edge(u[i], v[i], cap);
	}
	return mf.maxflow(0, n-1) >= mede;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> mede;
	for (int i=0; i<m; i++) {
		cin >> u[i] >> v[i] >> c[i];
		u[i]--;
		v[i]--;
	}

	ld l = 0, r = 6e8;
	for (int iter=0; iter<52; iter++) {
		ld m = (l+r) / 2;
		if (probaj(m)) {
			l = m;
		} else {
			r = m;
		}
	}
	cout << setprecision(20) << fixed << l << '\n';
}