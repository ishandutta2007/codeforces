#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct MaxFlow {

	struct edge {
		ll next, v, cap, flow;
	};

	int n;
	vector<ll> start, level, used;
	vector<edge> g;

	MaxFlow(ll n) : start(n, -1), level(n, -1), used(n, -1) {}

	void add_edge(ll u, ll v, ll c) {
		g.push_back({start[u], v, c, 0});
		start[u] = g.size() - 1;
		g.push_back({start[v], u, 0, 0});
		start[v] = g.size() - 1;
	}

	bool bfs(ll s, ll t) {
		queue<int> q;
		fill(level.begin(), level.end(), -1);
		q.push(s);
		level[s] = 0;
		while (q.size()) {
			ll x = q.front(); q.pop();
			for (ll i = start[x]; i != -1; i = g[i].next) {
				if (g[i].flow < g[i].cap && level[g[i].v] == -1) {
					level[g[i].v] = level[x] + 1;
					q.push(g[i].v);
				}
			}
		}
		return level[t] != -1;
	}

	ll dfs(ll x, ll t, ll f) {
		if (x == t)
			return f;
		for (ll& i = used[x]; i != -1; i = g[i].next) {
			ll v = g[i].v;
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

	ll maxflow(ll s, ll t) {
		ll f = 0;
		while (bfs(s, t)) {
			used = start;
			while (1) {
				ll z = dfs(s, t, 8123123123123123123ll);
				f += z;
				if (!z) break;
			}
		}
		return f;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;

	MaxFlow e(n+m+2);
	int source = n+m;
	int sink = n+m+1;

	ll sol = 0;

	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		e.add_edge(source, i, x);
	}

	for (int i=0; i<m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--,v--;
		e.add_edge(u, n+i, 8123123123123123123ll);
		e.add_edge(v, n+i, 8123123123123123123ll);
		e.add_edge(n+i, sink, w);
		sol += w;
	}

	cout << sol - e.maxflow(source, sink) << '\n';
}