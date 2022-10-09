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

struct edge {
	int u, v, w;

	template<class T>
	auto operator< (const T& b) const {
		return w < b.w;
	}
};

int n, m;
edge a[100005];

bool moze(int l) {
	max_flow<int> mf(2*n+2, 2*n, 2*n+1);

	for (int i=0; i<n; i++) {
		mf.add_edge(2*n, i, 1);
	}

	for (int i=0; i<n; i++) {
		mf.add_edge(i+n, 2*n+1, 1);
	}

	for (int i=0; i<=l; i++) {
		mf.add_edge(a[i].u, a[i].v+n, 1);
	}

	int f = mf();
	// cerr << "count = " << l << ", flow = " << f << '\n';
	return f == n;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		a[i] = {u, v, w};
	}

	sort(a, a+m);
	int l = 0, r = m-1, o = -1;
	while (l <= r) {
		int mid = (l+r) / 2;
		if (moze(mid)) {
			o = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	if (o == -1) {
		cout << "-1\n";
	} else {
		cout << a[o].w << '\n';
	}
}