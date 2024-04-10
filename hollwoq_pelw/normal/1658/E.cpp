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
	if (fopen("hollwo_pelw.inp", "r")){
		freopen("hollwo_pelw.inp", "r", stdin);
		freopen("hollwo_pelw.out", "w", stdout);
	}
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
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int N = 2005;

int n, k, X[N * N], Y[N * N];
char c[N][N];

void Hollwo_Pelw(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1, v; j <= n; j++)
			cin >> v, X[v] = i, Y[v] = j;

	int xl = 1e9, xr = -1e9, yl = 1e9, yr = -1e9;
	for (int i = n * n; i; i--) {
		int x = X[i], y = Y[i];
		if ((x + y) - xl > k || xr - (x + y) > k
		 || (x - y) - yl > k || yr - (x - y) > k) {
			c[x][y] = 'G';
		} else {
			c[x][y] = 'M';
			xl = min(xl, x + y), xr = max(xr, x + y);
			yl = min(yl, x - y), yr = max(yr, x - y);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << c[i][j];
		cout << '\n';
	}

}