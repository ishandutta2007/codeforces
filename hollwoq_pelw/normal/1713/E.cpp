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

const int N = 1005;

int n, par[N], a[N][N];

inline int find(int u) { return u < 0 ? -find(-u) : (u == par[u] ? u : par[u] = find(par[u])); }

inline void merge(int u, int v) {
	if (abs(u = find(u)) != abs(v = find(v)))
		(u > 0 ? par[u] = v : par[-u] = -v);
}

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	iota(par + 1, par + n + 1, 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] < a[j][i]) merge(+i, +j);
			if (a[i][j] > a[j][i]) merge(+i, -j);
		}
	}
	for (int i = 1; i <= n; i++) if (find(i) > 0) {
		for (int j = 1; j <= n; j++)
			swap(a[i][j], a[j][i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << a[i][j] << " \n"[j == n];
	}
}