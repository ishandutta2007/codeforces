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

int n, h, m;
int l[55], r[55], x[55], c[55];

int source() {
	return n*(h+1) + m;
}

int sink() {
	return source() + 1;
}

int polje(int i, int j) {
	return i+n*j;
}

int kazna(int i) {
	return n*(h+1) + i;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> h >> m;
	for (int i=0; i<m; i++) {
		cin >> l[i] >> r[i] >> x[i] >> c[i];
		l[i]--, r[i]--;
	}

	MaxFlow mf(n*(h+1) + m + 2);
	for (int i=0; i<n; i++) {
		for (int j=0; j<=h; j++) {
			mf.add_edge(source(), polje(i, j), j ? 2*j-1 : 0);
		}
	}
	for (int i=0; i<m; i++) {
		mf.add_edge(kazna(i), sink(), c[i]);
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<=h; j++) {
			for (int k=0; k<m; k++) {
				if (l[k] <= i && i <= r[k] && j > x[k]) {
					mf.add_edge(polje(i, j), kazna(k), 123123123);
				}
			}
		}
	}

	int f = mf.maxflow(source(), sink());
	cerr << f << '\n';
	cout << n*h*h - f << '\n';
}