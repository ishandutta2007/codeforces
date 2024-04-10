#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

void Hollwo_Pelw();

signed main(){
#ifndef hollwo_pelw_local
	if (fopen(".inp", "r"))
		assert(freopen(".inp", "r", stdin)), assert(freopen(".out", "w", stdout));
#else
	using namespace chrono;
	auto start = steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = steady_clock::now();
	cout << "\nExecution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int N = 2.5e5 + 5;

int n, h[N], par[18][N], fa[N];
vector<int> g1[N], g2[N];

void pre_dfs(int u, int p) {
	h[u] = h[par[0][u] = p] + 1;
	for (int i = 1; i < 18; i++)
		par[i][u] = par[i - 1][par[i - 1][u]];
	for (int v : g1[u]) if (v != p)
		pre_dfs(v, u);
}

inline int lca(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	for (int i = 18; i --; )
		if ((h[v] - h[u]) >> i & 1)
			v = par[i][v];
	if (u == v)
		return u;
	for (int i = 18; i --; )
		if (par[i][u] ^ par[i][v])
			u = par[i][u], v = par[i][v];
	return par[0][u];
}

inline int find(int u) { return fa[u] == u ? u : fa[u] = find(fa[u]); }
inline void merge(int v, int u) {
	int fv = find(v), fu = find(u), w = find(lca(u, v));
	// assert(fv != fu && "WTF is this");

	if (find(fv) != w) {
		fa[fv] = par[0][fv];
		cout << fv << ' ' << fa[fv] << ' ' << v << ' ' << u << '\n';
	} else {

		for (int i = 18; i --; )
			if (h[find(par[i][fu])] > h[w])
				fu = par[i][fu];

		fa[fu] = par[0][fu];
		cout << fu << ' ' << fa[fu] << ' ' << v << ' ' << u << '\n';
	}
}

void solve(int u, int p) {
	for (int v : g2[u]) if (v != p) {
		solve(v, u);
		merge(v, u);
	}
}

void Hollwo_Pelw(){
	cin >> n;
	iota(fa + 1, fa + n + 1, 1);
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		g1[u].push_back(v);
		g1[v].push_back(u);
	}
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		g2[u].push_back(v);
		g2[v].push_back(u);
	}
	pre_dfs(1, 0);

	cout << n - 1 << '\n';
	solve(1, 0);
}