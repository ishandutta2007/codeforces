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

int dp[105][105][2];
// i even, j odd, can make 0,1

inline int get(int i, int j, int k) {
	// cout << "get " << i << ' ' << j << ' ' << k << " -> ";
	// cout << ((i >= 1 ? dp[i - 1][j][k] : 1) & (j >= 1 ? dp[i][j - 1][k] : 1)) << endl;
	return (i >= 1 ? dp[i - 1][j][k] : 1) & (j >= 1 ? dp[i][j - 1][k] : 1);
}

void Hollwo_Pelw(){
	for (int i = 0; i <= 100; i++) {
		dp[i][0][0] = 1;
		dp[0][i][((i + 1) / 2) & 1] = 1;
	}
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			dp[i][j][0] |= get(i - 1, j, 0);
			dp[i][j][0] |= get(i, j - 1, 1);

			// if (dp[i][j][0])
			// 	cout << i << " " << j << " " << 0 << "\n";
	
			dp[i][j][1] |= get(i - 1, j, 1);
			dp[i][j][1] |= get(i, j - 1, 0);

			// if (dp[i][j][1])
			// 	cout << i << " " << j << " " << 1 << "\n";
		}
	}

	int t; cin >> t;
	for (int n; t --; ) {
		cin >> n;
		vector<int> c(2);
		for (int a; n --; )
			cin >> a, c[abs(a) & 1] ++;
		cout << (dp[c[0]][c[1]][0] ? "Alice\n" : "Bob\n");
	}
}