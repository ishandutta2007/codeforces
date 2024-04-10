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

int n, zx, zy, t;
string a[10], b[10];
int dz[10][10], d[10][10];

void bfs(int x, int y, int zx, int zy) {
	basic_string<pair<int, int>> qz = {{zx, zy}};
	basic_string<pair<int, int>> q0 = {{x, y}};
	basic_string<pair<int, int>> tmpz;
	basic_string<pair<int, int>> tmp0;

	memset(dz, 255, 400);
	memset(d, 255, 400);
	dz[zx][zy] = 0;
	d[x][y] = 0;

	auto go1 = [&](int x, int y, int dd) {
		if (x < 0 || y < 0 || x >= n || y >= n)
			return;
		if (a[x][y] >= 'Y')
			return;
		if (d[x][y] != -1)
			return;
		if (dz[x][y] != -1)
			return;
		tmp0 += {x, y};
		d[x][y] = dd;
	};

	auto go2 = [&](int x, int y, int dd) {
		if (x < 0 || y < 0 || x >= n || y >= n)
			return;
		if (a[x][y] >= 'Y')
			return;
		if (dz[x][y] != -1)
			return;
		tmpz += {x, y};
		dz[x][y] = dd;
	};

	while (q0.size()) {
		tmp0 = {};
		for (auto [x, y] : q0) {
			if (dz[x][y] != -1)
				continue;
			int dd = d[x][y] + 1;
			go1(x+1, y, dd);
			go1(x-1, y, dd);
			go1(x, y-1, dd);
			go1(x, y+1, dd);
		}
		tmpz = {};
		for (auto [x, y] : qz) {
			int dd = d[x][y] + 1;
			go2(x+1, y, dd);
			go2(x-1, y, dd);
			go2(x, y-1, dd);
			go2(x, y+1, dd);
		}
		swap(tmp0, q0);
		swap(tmpz, qz);
	}
}

int h(int x) {
	return x == -1 ? 123123123 : x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> t;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		cin >> b[i];
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (a[i][j] == 'Z')
				zx = i, zy = j;

	MaxFlow mf(202);

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (isdigit(a[i][j])) {
				mf.add_edge(200, i+n*j, a[i][j] - '0');
				mf.add_edge(100+i+n*j, 201, b[i][j] - '0');
				bfs(i, j, zx, zy);
				for (int k=0; k<n; k++) {
					for (int l=0; l<n; l++) {
						if (d[k][l] != -1 && d[k][l] <= t) {
							mf.add_edge(i+n*j, 100+k+n*l, 123123);
						}
					}
				}
			}
		}
	}

	cout << mf.maxflow(200, 201) << '\n';
}