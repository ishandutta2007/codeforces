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

const int N = 505, M = N * N;

int n, m, d[N][N], eu[M], ev[M], ew[M];

void Hollwo_Pelw(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			d[i][j] = (i == j ? 0 : 1e9);
	for (int i = 1; i <= m; i++) {
		cin >> eu[i] >> ev[i] >> ew[i];
		d[eu[i]][ev[i]] = d[ev[i]][eu[i]] = 1;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);


	long long res = 1e18;

	for (int i = 1; i <= m; i++) {
		for (int x = 1; x <= n; x++) {
			res = min(res, 1ll * (d[1][x] + d[n][x] + d[eu[i]][x] + 2) * ew[i]);
			res = min(res, 1ll * (d[1][x] + d[n][x] + d[ev[i]][x] + 2) * ew[i]);
		}
		res = min(res, 1ll * (d[1][eu[i]] + d[n][ev[i]] + 1) * ew[i]);
		res = min(res, 1ll * (d[1][ev[i]] + d[n][eu[i]] + 1) * ew[i]);
	}

	cout << res << '\n';
}