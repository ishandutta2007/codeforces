#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct edge {
	int v, w;
};

int n;
basic_string<edge> e[5005];
ll sol = 8e18;
ll ec[5005];

int sz[5005];

ll dfs1(int x, int p, int tag) {
	sz[x] = 1;
	ll ecc = 0;
	for (auto [y, w] : e[x]) {
		if (y == p)
			continue;
		ll t = dfs1(y, x, tag);
		sz[x] += sz[y];
		ecc += t + sz[y] * 1ll * w;
	}
	return ecc;
}

int cs[2];
ll le[2];

void dfs2(int x, int p, int tag) {
	le[tag] = min(le[tag], ec[x]);
	for (auto [y, w] : e[x]) {
		if (y == p)
			continue;
		ec[y] = ec[x] + (cs[tag]-2ll*sz[y])*w;
		dfs2(y, x, tag);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u] += {v, w};
		e[v] += {u, w};
	}

	for (int u=1; u<=n; u++) {
		for (auto [v, w] : e[u]) {
			if (u > v)
				continue;

			ec[u] = dfs1(u, v, 0);
			ec[v] = dfs1(v, u, 1);
			cs[0] = sz[u];
			cs[1] = sz[v];
			le[0] = le[1] = 8e18;
			dfs2(u, v, 0);
			dfs2(v, u, 1);
			ll z = accumulate(ec+1, ec+n+1, 0ll);
			z += 2*(ll(w)*sz[u]*sz[v] + sz[u]*le[1] + sz[v]*le[0]);
			sol = min(sol, z);
		}
	}

	cout << sol/2 << '\n';
}