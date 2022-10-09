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

vector<int> xu, yu;
int a[55], b[55], c[55], d[55];
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	xu = yu = {1, n+1};
	for (int i=0; i<m; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		xu.push_back(a[i]);
		xu.push_back(c[i]+1);
		yu.push_back(b[i]);
		yu.push_back(d[i]+1);
	}
	sort(xu.begin(), xu.end());
	xu.resize(unique(xu.begin(), xu.end()) - xu.begin());
	sort(yu.begin(), yu.end());
	yu.resize(unique(yu.begin(), yu.end()) - yu.begin());

	MaxFlow mf(1000);
	int source = 999, sink = 998;

	for (int i=0; i<m; i++) {
		int p = lower_bound(xu.begin(), xu.end(), a[i])   - xu.begin();
		int q = lower_bound(yu.begin(), yu.end(), b[i])   - yu.begin();
		int r = lower_bound(xu.begin(), xu.end(), c[i]+1) - xu.begin();
		int s = lower_bound(yu.begin(), yu.end(), d[i]+1) - yu.begin();

		for (int x=p; x<r; x++) {
			for (int y=q; y<s; y++) {
				mf.add_edge(x, y+500, n);
			}
		}
	}

	for (int x=0; x<(int)xu.size()-1; x++) {
		mf.add_edge(source, x, xu[x+1] - xu[x]);
	}

	for (int y=0; y<(int)yu.size()-1; y++) {
		mf.add_edge(y+500, sink, yu[y+1] - yu[y]);
	}

	int f = mf.maxflow(source, sink);

	cout << f << '\n';
}