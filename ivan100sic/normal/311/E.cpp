#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll HH = 1e18;

struct MaxFlow {

	struct edge {
		int next, v;
		ll cap, flow;
	};

	int n;
	vector<int> start, level, used;
	vector<edge> g;

	MaxFlow(int n) : start(n, -1), level(n, -1), used(n, -1) {}

	void add_edge(int u, int v, ll c) {
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

	ll dfs(int x, int t, ll f) {
		if (x == t)
			return f;
		for (int& i = used[x]; i != -1; i = g[i].next) {
			int v = g[i].v;
			if (level[v] == level[x] + 1 && g[i].flow < g[i].cap) {
				ll z = dfs(v, t, min(f, g[i].cap - g[i].flow));
				if (z > 0) {
					g[i].flow += z;
					g[i^1].flow -= z;
					return z;
				}
			}
		}
		return 0;
	}

	ll maxflow(int s, int t) {
		ll f = 0;
		while (bfs(s, t)) {
			used = start;
			while (1) {
				ll z = dfs(s, t, HH);
				f += z;
				if (!z) break;
			}
		}
		return f;
	}
};

int n, m, g;
int gender[10005], v[10005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> g;
	for (int i=1; i<=n; i++)
		cin >> gender[i];
	for (int i=1; i<=n; i++)
		cin >> v[i];

	int source = 0;
	int sink = 2*n+m+1;
	MaxFlow mf(sink + 1);

	ll sol = 0;

	const int TOGGLE = 1;

	for (int i=1; i<=m; i++) {
		int sx, w, k, gf;
		cin >> sx >> w >> k;
		while (k--) {
			int x;
			cin >> x;
			if (sx == TOGGLE) {
				mf.add_edge(2*n+i, 2*x-1, HH);
			} else {
				mf.add_edge(2*x, 2*n+i, HH);
			}
		}
		cin >> gf;
		if (gf) {
			sol -= g;
			w += g;
		}
		sol += w;

		if (sx == TOGGLE) {
			mf.add_edge(source, 2*n+i, w);
		} else {
			mf.add_edge(2*n+i, sink, w);
		}
	}

	for (int i=1; i<=n; i++) {
		mf.add_edge(source, 2*i, v[i]*gender[i]);
		mf.add_edge(2*i-1, sink, v[i]*(1-gender[i]));
		mf.add_edge(2*i-1, 2*i, HH);
	}

	ll f = mf.maxflow(0, sink);

	// cerr << "flow = " << f << '\n';
	sol -= f;

	cout << sol << '\n';
}