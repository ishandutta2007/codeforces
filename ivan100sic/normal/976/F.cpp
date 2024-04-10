#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <complex>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct edge {
	int v, cap, flow, next, id;
};

struct flow {
	int n, s, t;
	vector<int> start, level, used;
	vector<edge> g;

	flow(int n, int s, int t) : n(n), s(s), t(t),
		start(n, -1) {}

	void add_edge(int u, int v, int cap, int id) {
		g.push_back({ v, cap, 0, start[u], id });
		start[u] = (int)g.size() - 1;
		g.push_back({ u, 0, 0, start[v], id });
		start[v] = (int)g.size() - 1;
	}

	bool bfs() {
		level.assign(n, -1);
		queue<int> q;
		level[s] = 0;
		q.push(s);

		while (q.size()) {
			int x = q.front(); q.pop();
			for (int i = start[x]; i != -1; i = g[i].next) {
				int y = g[i].v;
				if (level[y] == -1 && g[i].flow < g[i].cap) {
					level[y] = level[x] + 1;
					q.push(y);
				}
			}
		}

		return level[t] != -1;
	}

	int dfs(int x, int f = 123123123) {
		if (x == t) {
			return f;
		}

		for (int& i = used[x]; i != -1; i = g[i].next) {
			int y = g[i].v;
			if (level[y] == level[x] + 1 && g[i].flow < g[i].cap) {
				int z = dfs(y, min(f, g[i].cap - g[i].flow));
				if (z > 0) {
					g[i].flow += z;
					g[i ^ 1].flow -= z;
					return z;
				}
			}
		}

		return 0;
	}

	int run() {
		int f = 0;
		while (bfs()) {
			while (1) {
				used = start;
				int z = dfs(s);
				if (!z) {
					break;
				}
				f += z;
			}
		}
		return f;
	}

	vector<int> find_flow_edges(int l, int r, int p, int q) {
		vector<int> sol;
		for (int x = l; x < r; x++) {
			for (int i = start[x]; i != -1; i = g[i].next) {
				int y = g[i].v;
				if (y < p || y >= q) {
					continue;
				}
				if (g[i].flow > 0) {
					sol.push_back(g[i].id);
				}
			}
		}
		return sol;
	}
};

int a, b, m;
int da[2005], db[2005];
int u[2005], v[2005];
int minDeg;

set<int> resenje[2005];

void solve() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> a >> b >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		u[i] = x;
		v[i] = y;
		da[x]++;
		db[y]++;
	}

	minDeg = 123123;

	for (int i = 0; i < a; i++) {
		minDeg = min(minDeg, da[i]);
	}

	for (int i = 0; i < b; i++) {
		minDeg = min(minDeg, db[i]);
	}

	int source = a + b;
	int sink = source + 1;

	flow e(sink + 1, source, sink);

	for (int i = 0; i < a; i++) {
		e.add_edge(source, i, da[i] - minDeg, -1);
	}

	for (int i = 0; i < b; i++) {
		e.add_edge(i + a, sink, db[i] - minDeg, -1);
	}

	for (int i = 0; i < m; i++) {
		e.add_edge(u[i], a + v[i], 1, i);
	}

	cerr << "minDeg: " << minDeg << '\n';

	// postavi
	for (int i = minDeg; i >= 0; i--) {
		// pokreni
		e.run();
		auto v = e.find_flow_edges(0, a, a, a + b);
		for (int x : v) {
			resenje[i].insert(x);
		}
		// bampuj kapacitete
		for (int j = 0; j < a + b; j++) {
			e.g[2 * j].cap += 1;
		}
		// lepotan
	}

	for (int i = 0; i <= minDeg; i++) {
		cout << m - resenje[i].size() << '\n';
		for (int j = 0; j < m; j++) {
			if (resenje[i].count(j) == 0) {
				cout << j + 1 << ' ';
			}
		}
		cout << '\n';
	}
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}