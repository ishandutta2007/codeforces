// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct matching {
	const int n, m;
	static const int inf = 2100000000;
	vector<vector<int>> e;
	vector<int> pu, pv, d;
	matching(int n, int m) : n(n), m(m), e(n+1) {}
	void add_edge(int u, int v) { e[u+1].push_back(v+1); }
	bool bfs() {
		vector<int> q(n+1);
		int qs=0, qe=0;
		for (int u=1; u<=n; u++) {
			if (pu[u] == 0) {
				d[u] = 0;
				q[qe++] = u;
			} else {
				d[u] = inf;
			}
		}
		d[0] = inf;
		while (qs != qe) {
			int u = q[qs++];
			if (d[u] < d[0]) {
				for (int v : e[u]) {
					if (d[pv[v]] == inf) {
						d[pv[v]] = d[u] + 1;
						q[qe++] = pv[v];
					}
				}
			}
		}
		return d[0] != inf;
	}
	bool dfs(int u) {
		if (u == 0) {
			return true;
		}
		for (int v : e[u]) {
			if (d[pv[v]] == d[u] + 1) {
				if (dfs(pv[v])) {
					pv[v] = u;
					pu[u] = v;
					return true;
				}
			}
		}
		d[u] = inf;
		return false;
	}
	int run() {
		int sz = 0;
		pu.resize(n+1, 0);
		pv.resize(m+1, 0);
		d.resize(n+1);
		while (bfs()) {
			for (int u=1; u<=n; u++) {
				if (pu[u] == 0) {
					if (dfs(u)) {
						sz++;
					}
				}
			}
		}
		return sz;
	}
	auto vertex_cover() {
		run();
		vector<int> q(n+1), drhs(m+1, inf);
		int qs=0, qe=0;
		for (int u=1; u<=n; u++) {
			if (pu[u] == 0) {
				d[u] = 0;
				q[qe++] = u;
			} else {
				d[u] = inf;
			}
		}
		d[0] = inf;
		while (qs != qe) {
			int u = q[qs++];
			if (d[u] < d[0]) {
				for (int v : e[u]) {
					drhs[v] = 0;
					if (d[pv[v]] == inf) {
						d[pv[v]] = d[u] + 1;
						q[qe++] = pv[v];
					}
				}
			}
		}
		pair<vector<int>, vector<int>> s;
		for (int i=1; i<=n; i++)
			if (pu[i] > 0 && d[i] == inf)
				s.first.push_back(i-1);
		for (int j=1; j<=m; j++)
			if (drhs[j] == 0)
				s.second.push_back(j-1);
		return s;
	}
};

int n, m;
string a[205];

struct edge {
	int a, b, c, d;

	edge(int a, int b, int c, int d) {
		if (tie(a, b) > tie(c, d)) {
			swap(a, c);
			swap(b, d);
		}
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}

	bool operator< (const edge& o) const {
		return tie(a, b, c, d) < tie(o.a, o.b, o.c, o.d);
	}

	bool operator== (const edge& o) const {
		return tie(a, b, c, d) == tie(o.a, o.b, o.c, o.d);
	}
};

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

vector<edge> g;

bool u(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (u(i+1, j) && a[i][j] == '#' && a[i+1][j] == '#') {
				g.emplace_back(i, j, i+1, j);
			}
			if (u(i, j+1) && a[i][j] == '#' && a[i][j+1] == '#') {
				g.emplace_back(i, j, i, j+1);
			}
		}
	}

	sort(begin(g), end(g));
	g.erase(unique(begin(g), end(g)), end(g));
	int k = g.size(), v = 0;
	matching mat(k+2, k+2);

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (a[i][j] == '#') {
				v++;
			}
			for (int d=0; d<4; d++) {
				int x1 = i + dx[d];
				int y1 = j + dy[d];
				int x2 = i + dx[(d+1)&3];
				int y2 = j + dy[(d+1)&3];
				if (u(x1, y1) && u(x2, y2) && a[x1][y1] == '#' && a[x2][y2] == '#' && a[i][j] == '#') {
					auto it1 = lower_bound(begin(g), end(g), edge(i, j, x1, y1)) - begin(g);
					auto it2 = lower_bound(begin(g), end(g), edge(i, j, x2, y2)) - begin(g);
					if (d % 2) swap(it1, it2);
					mat.add_edge(it1, it2);
				}
			}
		}
	}

	int ms = mat.run();
	cout << v - k + ms << '\n';
}