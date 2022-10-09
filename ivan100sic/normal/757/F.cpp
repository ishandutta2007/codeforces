#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct dominators {
	// indexi su od 1
	// vraca p[x] = x za nedostizne cvorove i root, za ostale
	// vraca idom(x)
	vector<basic_string<int>> g, rg, bucket;
	vector<int> arr, par, rev, sdom, dom, dsu, label;
	int n, T;

	dominators(int n) : g(n+1), rg(n+1), bucket(n+1), arr(n+1),
		par(n+1), rev(n+1), sdom(n+1), dom(n+1), dsu(n+1), label(n+1),
		n(n), T(0) {}

	void add_edge(int u, int v) {
		g[u] += v;
	}

	void dfs(int u) {
		T++;
		arr[u] = T;
		rev[T] = u;
		label[T] = sdom[T] = dsu[T] = T;
		for (int w : g[u]) {
			if (!arr[w]) {
				dfs(w);
				par[arr[w]] = arr[u];
			}
			rg[arr[w]] += arr[u];
		}
	}

	int find(int u, int x=0) {
		if (u == dsu[u])
			return x ? -1 : u;
		int v = find(dsu[u], x+1);
		if (v < 0)
			return u;
		if (sdom[label[dsu[u]]] < sdom[label[u]])
			label[u] = label[dsu[u]];
		dsu[u] = v;
		return x ? v : label[u];
	}

	void link(int u, int v) {
		dsu[v] = u;
	}

	vector<int> run(int root) {
		dfs(root);
		iota(dom.begin(), dom.end(), 0);
		for (int i=T; i>=1; i--) {
			for (int w : rg[i])
				sdom[i] = min(sdom[i], sdom[find(w)]);
			if (i > 1)
				bucket[sdom[i]] += i;
			for (int w : bucket[i]) {
				int v = find(w);
				if (sdom[v] == sdom[w])
					dom[w] = sdom[w];
				else
					dom[w] = v;
			}
			if (i > 1)
				link(par[i], i);
		}
		for (int i=2; i<=T; i++) {
			if (dom[i] != sdom[i])
				dom[i] = dom[dom[i]];
		}
		vector<int> outside_dom(n+1);
		iota(outside_dom.begin(), outside_dom.end(), 0);
		for (int i=1; i<=T; i++)
			outside_dom[rev[i]] = rev[dom[i]];
		return outside_dom;
	}
};


struct edge {
	int v, w;
};

basic_string<edge> e[200005];
basic_string<int> f[200005];
int sz[200005];
int n, m, s;

ll d[200005];

void dijk(int x) {
	set<pair<ll, int>> pq;
	memset(d, 63, sizeof(d));
	d[x] = 0;
	pq.insert({0, x});
	while (pq.size()) {
		auto [dx, x] = *pq.begin();
		pq.erase(pq.begin());
		for (auto [y, w] : e[x]) {
			if (d[y] > dx + w) {
				pq.erase({d[y], y});
				d[y] = dx + w;
				pq.insert({d[y], y});
			}
		}
	}
}

void dfss(int x) {
	sz[x] = 1;
	for (int y : f[x]) {
		dfss(y);
		sz[x] += sz[y];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> s;
	for (int i=0; i<m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u] += {v, w};
		e[v] += {u, w};
	}

	dijk(s);
	dominators dom(n);
	for (int i=1; i<=n; i++) {
		for (auto [j, w] : e[i]) {
			if (d[j] == d[i] + w) {
				dom.add_edge(i, j);
			}
		}
	}
	auto p = dom.run(s);
	for (int i=1; i<=n; i++)
		if (p[i] != i)
			f[p[i]] += i;
	dfss(s);
	int sol = 0 ;
	for (int i=1; i<=n; i++)
		if (i != s)
			sol = max(sol, sz[i]);
	cout << sol << '\n';
}