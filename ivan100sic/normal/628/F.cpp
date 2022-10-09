// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T = int>
struct max_flow {
	struct edge {
		int next, v;
		T cap, flow;
	};

	int s, t;
	vector<int> start, level, used, q;
	vector<edge> g;

	max_flow(int n, int s, int t) : s(s), t(t), start(n, -1), level(n, -1), used(n, -1), q(n) {}

	void add_edge(int u, int v, T c) {
		g.push_back({start[u], v, c, T()});
		start[u] = g.size() - 1;
		g.push_back({start[v], u, T(), T()});
		start[v] = g.size() - 1;
	}

	bool bfs(int s, int t) {
		size_t qs = 0, qe = 1;
		fill(level.begin(), level.end(), -1);
		q[0] = s;
		level[s] = 0;
		while (qs != qe) {
			int x = q[qs++];
			for (int i = start[x]; i != -1; i = g[i].next) {
				if (g[i].flow < g[i].cap && level[g[i].v] == -1) {
					level[g[i].v] = level[x] + 1;
					q[qe++] = g[i].v;
				}
			}
		}
		return level[t] != -1;
	}

	T dfs(int x, int t, T f) {
		if (x == t)
			return f;
		for (int& i = used[x]; i != -1; i = g[i].next) {
			int v = g[i].v;
			if (level[v] == level[x] + 1 && g[i].flow < g[i].cap) {
				T z = dfs(v, t, min(f, g[i].cap - g[i].flow));
				if (z > 0) {
					g[i].flow += z;
					g[i^1].flow -= z;
					return z;
				}
			}
		}
		return T();
	}

	T operator() () {
		T f = T();
		while (bfs(s, t)) {
			used = start;
			while (1) {
				T z = dfs(s, t, numeric_limits<T>::max());
				f += z;
				if (!z) break;
			}
		}
		return f;
	}
};

void no() {
	cout << "unfair\n";
	exit(0);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n, b, q;
	cin >> n >> b >> q;
	vector<pair<int, int>> a;
	for (int i=0; i<q; i++) {
		int u, v;
		cin >> u >> v;
		a.emplace_back(u, v);
	}
	a.emplace_back(b, n);
	a.emplace_back(0, 0);
	sort(begin(a), end(a));
	a.erase(unique(begin(a), end(a)), end(a));
	q = a.size();

	int source = 20023, sink = source + 1, sz = sink + 1;
	max_flow mf(sz, source, sink);
	int pe = 10001;
	int qe = 20015;

	for (int i=1; i<q; i++) {
		int c = a[i].second - a[i-1].second;
		if (c < 0)
			no();
		mf.add_edge(source, pe, c);
		for (int j=a[i-1].first+1; j<=a[i].first; j++)
			mf.add_edge(pe, j, 1);
		pe++;
	}

	// sabiraci
	for (int r=1; r<=5; r++) {
		for (int i=r; i<=b; i+=5) {
			mf.add_edge(i, qe, 1);
		}
		mf.add_edge(qe, sink, n/5);
		qe++;
	}

	if (mf() < n)
		no();
	cout << "fair\n";
}