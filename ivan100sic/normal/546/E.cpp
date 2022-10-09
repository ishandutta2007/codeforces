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

int n, m;
bool e[105][105];
int a[105], b[105];
int sol[105][105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		cin >> b[i];
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		e[u][v] = 1;
		e[v][u] = 1;
	}

	MaxFlow eng(2*n+2);
	int source = 2*n;
	int sink = 2*n+1;

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++)
			if (e[i][j])
				eng.add_edge(i, n+j, 123123123);
		eng.add_edge(source, i, a[i]);
		eng.add_edge(n+i, sink, b[i]);
		eng.add_edge(i, n+i, 123123123);
	}

	int wa = accumulate(a, a+n, 0);
	int wb = accumulate(b, b+n, 0);

	int wf = eng.maxflow(source, sink);
	if (wf != wa || wf != wb) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	for (int i=0; i<n; i++) {
		for (int ei=eng.start[i]; ei!=-1; ei = eng.g[ei].next) {
			int j = eng.g[ei].v - n;
			if (j < 0 || j >= n)
				continue;
			sol[i][j] = eng.g[ei].flow;
		}
	}

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cout << sol[i][j] << " \n"[j == n-1];
}