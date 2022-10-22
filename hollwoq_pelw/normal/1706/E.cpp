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
	cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = steady_clock::now();
	cout << "\nExecution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int N = 2e5 + 5;

int n, m, q, nnode, st[N], par[18][N], h[N], fa[N], val[N];

inline int find(int u) {
	return fa[u] == u ? u : fa[u] = find(fa[u]);
}

inline int lca(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	for (int i = 18; i --; )
		if ((h[v] - h[u]) >> i & 1)
			v = par[i][v];
	if (u == v) return u;
	for (int i = 18; i --; )
		if (par[i][u] ^ par[i][v])
			u = par[i][u], v = par[i][v];
	return par[0][u];
}

void Hollwo_Pelw(){
	cin >> n >> m >> q, nnode = n;
	iota(fa + 1, fa + (n << 1), 1);
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		if ((u = find(u)) != (v = find(v)))
			val[fa[u] = fa[v] = par[0][u] = par[0][v] = ++ nnode] = i;
	}

	for (int i = nnode; i; i--)
		h[i] = h[par[0][i]] + 1;
	for (int i = 1; i < 18; i++) {
		for (int j = 1; j <= nnode; j++)
			par[i][j] = par[i - 1][par[i - 1][j]];
	}

	for (int i = 1; i < n; i++)
		st[i + n] = val[lca(i, i + 1)];
	for (int p = n - 1; p; p--)
		st[p] = max(st[p << 1], st[p << 1 | 1]);

	for (int l, r; q --; ) {
		cin >> l >> r;
		int res = 0;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) res = max(res, st[l ++]);
			if (r & 1) res = max(res, st[-- r]);
		}
		cout << res << ' ';
	}
	cout << '\n';
}