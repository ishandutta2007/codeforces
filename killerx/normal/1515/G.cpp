#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

typedef long long ll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int mxn = 2e5 + 5;

int n, m;
std::vector <std::pair <int, int> > adj[mxn], radj[mxn];
int cc[mxn], c;
std::vector <int> vscc[mxn];
bool vis[mxn];
ll dep[mxn];
ll g[mxn];

inline void add_edge(int u, int v, int l) {
	adj[u].push_back(std::make_pair(v, l));
	radj[v].push_back(std::make_pair(u, l));
}

namespace SCC {
	bool vis[mxn];
	std::vector <int> vec;

	void dfs(int u) {
		vis[u] = 1;
		rep(i, adj[u].size()) {
			int v = adj[u][i].first;
			if (!vis[v]) dfs(v);
		}
		vec.push_back(u);
	}

	void rdfs(int u) {
		cc[u] = c;
		rep(i, radj[u].size()) {
			int v = radj[u][i].first;
			if (!~cc[v]) rdfs(v);
		}
	}

	void solve() {
		rep(i, n) vis[i] = 0;
		vec.clear();
		rep(i, n) if (!vis[i]) dfs(i);
		rep(i, n) cc[i] = -1;
		c = 0;
		for (int i = n - 1; ~i; -- i) {
			int u = vec[i];
			if (!~cc[u]) rdfs(u), ++ c;
		}
		rep(i, n) vscc[cc[i]].push_back(i);
	}
}

int cid;

void dfs(int u) {
	vis[u] = 1;
	rep(i, adj[u].size()) {
		int v = adj[u][i].first;
		if (cc[v] != cid) continue;
		if (!vis[v]) {
			dep[v] = dep[u] + adj[u][i].second;
			dfs(v);
		} else {
			g[cid] = gcd(g[cid], dep[u] + adj[u][i].second - dep[v]);
		}
	}
}

void solve() {
	rep(i, vscc[cid].size()) vis[vscc[cid][i]] = 0;
	dep[vscc[cid][0]] = 0;
	dfs(vscc[cid][0]);
}

int main() {
	scanf("%d %d", &n, &m);
	rep(i, m) {
		int u, v, l;
		scanf("%d %d %d", &u, &v, &l);
		-- u, -- v;
		add_edge(u, v, l);
	}
	SCC::solve();
	rep(i, c) cid = i, solve();
	/*
	rep(i, c) {
		rep(j, vscc[i].size())
			eprintf("%d ", vscc[i][j] + 1);
		eprintf("\n");
	}
	*/
	int q;
	scanf("%d", &q);
	while (q --) {
		int u, s, t;
		scanf("%d %d %d", &u, &s, &t);
		-- u;
		if (s % gcd(g[cc[u]], t) == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}