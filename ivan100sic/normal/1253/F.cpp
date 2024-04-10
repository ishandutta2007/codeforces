#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll inf = 1e18;

int n, m, k, q;
vector<pair<int, int>> e[100005];
vector<pair<int, ll>> g[100005];
ll dist[100005];
int root[100005];

void dijk() {
	set<pair<ll, int>> pq;
	for (int i=1; i<=k; i++)
		dist[i] = 0, root[i] = i, pq.insert({dist[i], i});
	for (int i=k+1; i<=n; i++)
		dist[i] = inf;
	while (pq.size()) {
		auto [dx, x] = *pq.begin();
		pq.erase(pq.begin());
		for (auto [y, w] : e[x]) {
			if (dist[y] > dx + w) {
				pq.erase({dist[y], y});
				dist[y] = dx + w;
				root[y] = root[x];
				pq.insert({dist[y], y});
			}
		}
	}
}

struct dsu {
	vector<int> p;

	dsu(int n) : p(n) {
		iota(p.begin(), p.end(), 0);
	}

	int e(int x) {
		if (x == p[x])
			return x;
		return p[x] = e(p[x]);
	}

	bool spoji(int x, int y) {
		x = e(x);
		y = e(y);
		if (x == y)
			return false;
		p[x] = y;
		return true;
	}
};

int dub[100005];
int p[100005][18];
ll h[100005][18];

void dfs(int x, int par, ll w) {
	p[x][0] = par;
	h[x][0] = w;
	for (int i=1; i<18; i++) {
		p[x][i] = p[p[x][i-1]][i-1];
		h[x][i] = max(h[x][i-1], h[p[x][i-1]][i-1]);
	}
	for (auto [y, wy] : g[x]) {
		if (y == par)
			continue;
		dub[y] = dub[x] + 1;
		dfs(y, x, wy);
	}
}

ll dizi(int& x, int k) {
	ll z = 0;
	for (int i=0; i<18; i++) {
		if (k & (1 << i)) {
			z = max(z, h[x][i]);
			x = p[x][i];
		}
	}
	return z;
}

ll solve(int x, int y) {
	if (dub[x] > dub[y])
		swap(x, y);
	ll z = dizi(y, dub[y] - dub[x]);
	if (x == y)
		return z;
	for (int i=17; i>=0; i--) {
		if (p[x][i] != p[y][i]) {
			z = max({z, h[x][i], h[y][i]});
			x = p[x][i];
			y = p[y][i];
		}
	}
	return max({z, h[x][0], h[y][0]});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k >> q;
	for (int i=0; i<m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].emplace_back(v, w);
		e[v].emplace_back(u, w);
	}

	dijk();
	vector<tuple<ll, int, int>> f;
	for (int i=1; i<=n; i++) {
		for (auto [j, w] : e[i]) {
			if (root[i] != root[j]) {
				f.emplace_back(dist[i] + dist[j] + w, root[i], root[j]);
			}
		}
	}
	sort(f.begin(), f.end());
	dsu ds(k+1);
	for (auto [w, u, v] : f) {
		if (ds.spoji(u, v)) {
			g[u].emplace_back(v, w);
			g[v].emplace_back(u, w);
		}
	}
	dfs(1, 1, 0);
	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << solve(u, v) << '\n';
	}
}