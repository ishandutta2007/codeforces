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

	void add_edge(int u, int v, T cap, T rev = T()) {
		g.push_back({start[u], v, cap, T()});
		start[u] = g.size() - 1;
		g.push_back({start[v], u, rev, T()});
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

int n;
int a[3005], b[3005];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	for (int i=0; i<n; i++) {
		cin >> b[i];
	}

	max_flow mf(n+2, n, n+1);
	int pos=0, neg=0;

	for (int i=0; i<n; i++) {
		for (int x=a[i]; x<=100; x+=a[i]) {
			int j = find(a+i+1, a+n, x) - a;
			if (j < n) {
				mf.add_edge(i, j, 1e9);
			}
		}

		if (b[i] > 0) {
			mf.add_edge(i, n+1, b[i]);
			pos += b[i];
		} else if (b[i] < 0) {
			mf.add_edge(n, i, -b[i]);
			neg += -b[i];
		}
	}

	int f = mf();
	cerr << "f = " << f << '\n';
	cerr << "pos = " << pos << '\n';
	cerr << "neg = " << neg << '\n';

	cout << pos - f << '\n';
}