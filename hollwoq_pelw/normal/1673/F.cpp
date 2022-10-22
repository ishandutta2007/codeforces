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
	if (fopen("hollwo_pelw.inp", "r"))
		assert(freopen("hollwo_pelw.inp", "r", stdin)), assert(freopen("hollwo_pelw.out", "w", stdout));
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
	cout << "\nExcution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int N = 1 << 5;

int n, q, h[N][N], v[N][N], f[N][N];
pair<int, int> res[1 << 20];

inline int p(int i) { return 1 << __builtin_ctz(i); }

void Hollwo_Pelw(){
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++)
			cout << (h[i][j - 1] = 1 * p(j) * p(j)) << ' ';
		cout << endl;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << (v[i - 1][j] = 2 * p(i) * p(i)) << ' ';
		cout << endl;
	}
	for (int j = 1; j < n; j++)
		f[0][j] = f[0][j - 1] ^ h[0][j - 1];
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n; j++)
			f[i][j] = f[i - 1][j] ^ v[i - 1][j];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			res[f[i][j]] = {i, j};

	for (int x, y = 0; q --; ) {
		cin >> x; auto [px, py] = res[y ^= x];
		cout << px + 1 << ' ' << py + 1 << endl;
	}
}