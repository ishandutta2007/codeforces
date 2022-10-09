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


const int SITO_MAX = 100000;

int f[SITO_MAX+1];
vector<int> prosti;

struct sito {
	sito() {
		for (int i=2; i<=SITO_MAX; i++) {
			if (f[i] == 0) {
				f[i] = i;
				prosti.push_back(i);
			}
			int j = 0;
			while (j < (int)prosti.size()) {
				if (prosti[j] > f[i]) {
					break;
				}
				int x = i * prosti[j];
				if (x > SITO_MAX) {
					break;
				}
				f[x] = prosti[j];
				j++;
			}
		}
	}
} sito_obj_983431;

vector<pair<int, int>> factor_small(int x) {
	vector<pair<int, int>> v;
	while (x > 1) {
		int p = f[x];
		int c = 0;
		while (x % p == 0) {
			x /= p;
			c++;
		}
		v.push_back({p, c});
	}
	return v;
}

vector<pair<int, int>> factor(int x) {
	vector<pair<int, int>> v;
	for (int p : prosti) {
		if (x % p == 0) {
			int c = 0;
			while (x % p == 0) {
				x /= p;
				c++;
			}
			v.push_back({p, c});
		}			
	}

	if (x > 1) {
		v.push_back({x, 1});
	}
	return v;
}


int n;
int a[205];
basic_string<int> ee[205];
int v[205];

void dfs(int x, basic_string<int>& w) {
	w += x;
	v[x] = 1;
	for (int y : ee[x]) {
		if (!v[y]) {
			dfs(y, w);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	MaxFlow e(n+2);
	int source = n;
	int sink = n+1;

	for (int i=0; i<n; i++) {
		if (a[i] % 2 == 0) {
			e.add_edge(source, i, 2);
		} else {
			e.add_edge(i, sink, 2);
			continue;
		}
		for (int j=0; j<n; j++) {
			if (a[j] % 2 == 1 && f[a[i] + a[j]] == a[i] + a[j]) {
				e.add_edge(i, j, 1);
			}
		}
	}

	int f = e.maxflow(source, sink);
	if (f != n) {
		cout << "Impossible\n";
		return 0;
	}

	for (int x=0; x<n; x++) {
		for (int j = e.start[x]; j != -1; j = e.g[j].next) {
			if (e.g[j].flow != 1)
				continue;
			int y = e.g[j].v;
			ee[x] += y;
			ee[y] += x;
		}
	}

	vector<basic_string<int>> sol;

	for (int i=0; i<n; i++) {
		if (!v[i]) {
			basic_string<int> w;
			dfs(i, w);
			sol.push_back(w);
		}
	}

	cout << sol.size() << '\n';
	for (auto w : sol) {
		cout << w.size();
		for (int x : w)
			cout << ' ' << x+1;
		cout << '\n';
	}
}