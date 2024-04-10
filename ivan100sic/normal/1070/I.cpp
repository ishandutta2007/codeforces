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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;

		int source = n+m;
		int sink = source + 1;
		MaxFlow mf(sink+1);

		vector<int> deg(n, 0);

		for (int i=0; i<m; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			deg[u]++;
			deg[v]++;
			mf.add_edge(u, n+i, 1);
			mf.add_edge(v, n+i, 1);
		}

		for (int i=0; i<m; i++)
			mf.add_edge(n+i, sink, 1);

		for (int i=0; i<n; i++) {
			int c = deg[i] - k;
			if (c > 0) {
				mf.add_edge(source, i, 2*c);
			}
		}

		mf.maxflow(source, sink);

		bool ok = true;
		for (int j = mf.start[source]; j != -1; j = mf.g[j].next) {
			if (mf.g[j].cap != mf.g[j].flow) {
				ok = false;
				break;
			}
		}

		vector<int> sol(m, 0);
		int idx = 0;

		if (ok) {
			for (int x=0; x<n; x++) {
				vector<int> van;
				for (int j = mf.start[x]; j != -1; j = mf.g[j].next) {
					if (mf.g[j].flow == 1) {
						van.push_back(mf.g[j].v - n);
					}
				}
				if (van.size() % 2)
					van.pop_back();
				for (int i=0; i<(int)van.size(); i+=2)
					sol[van[i]] = sol[van[i + 1]] = ++idx;
			}
			for (int& x : sol)
				if (!x)
					x = ++idx;
		}

		for (int x : sol)
			cout << x << ' ';
		cout << '\n';
	}
}