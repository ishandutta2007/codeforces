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
	auto start = chrono::steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << "\nExecution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 55;

int n, k, f[N], d[N], w[N][N], x[N], y[N], cur, res, par[N];

inline int find(int u) { return par[u] == u ? u : par[u] = find(par[u]); }
inline void merge(int u, int v) { par[find(u)] = find(v); }

void Hollwo_Pelw(){
	cin >> n >> k;
	fill(f + 1, f + n + 1, n);
	for (int i = 1; i <= k; i++)
		cin >> f[i];

	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int x; cin >> x;
			w[i][j] = w[j][i] = x;
		}
	}

	uniform_int_distribution<> rnd_e(1, n - 1), rnd_v(1, n);
	uniform_real_distribution<> rnd(0.0, 1.0);

	for (int i = 1; i < n; i++)
		x[i] = n, y[i] = i, cur += w[x[i]][y[i]];
	fill(d + 1, d + n, 1), d[n] = n - 1;

	res = cur;

	for (double T = 1e6; T > 1e-5; T *= 0.99999) {
		iota(par + 1, par + n + 1, 1);

		int p = rnd_e(rng), nxt = cur - w[x[p]][y[p]];

		d[x[p]] --, d[y[p]] --;

		for (int i = 1; i < n; i++)
			if (p != i) merge(x[i], y[i]);

		int u = rnd_v(rng), v = rnd_v(rng);
		while (d[u] == f[u] || d[v] == f[v] || find(u) == find(v))
			u = rnd_v(rng), v = rnd_v(rng);

		merge(u, v);

		nxt += w[u][v];

		if (nxt < cur || rnd(rng) < exp((cur - nxt) / T)) {
			x[p] = u, y[p] = v;
			res = min(res, (cur = nxt));
		}

		d[x[p]] ++, d[y[p]] ++;
	}

	cout << res << '\n';
}