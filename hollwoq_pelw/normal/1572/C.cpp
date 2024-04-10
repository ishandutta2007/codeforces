/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
	if (fopen(filein.c_str(), "r")){
		freopen(filein.c_str(), "r", stdin);
		freopen(fileout.c_str(), "w", stdout);
#ifdef hollwo_pelw_local
		freopen(fileerr.c_str(), "w", stderr);
#endif
	}
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
#ifdef hollwo_pelw_local
	FAST_IO("input.inp", "output.out", "error.err");
	auto start = chrono::steady_clock::now();
#else
	FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
#endif
	int testcases = 1;
	cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 3e3 + 5, inf = 2e9;

int n, prv[N], b[N], dp[N][N];

void Hollwo_Pelw() {
	cin >> n;
	fill(b + 1, b + n + 1, 0);
	for (int i = 1, a; i <= n; i++)
		cin >> a, prv[i] = b[a], b[a] = i;
	
	for (int i = 1; i <= n; i++)
		dp[i][i] = 0;

	for (int len = 2; len <= n; len ++) {
		for (int l = 1, r = len; r <= n; l ++, r ++) {
			dp[l][r] = min(dp[l][r - 1], dp[l + 1][r]) + 1;
			for (int j = prv[r]; j >= l; j = prv[j])
				dp[l][r] = min(dp[l][r], dp[l][j] + dp[j + 1][r]);
		}
	}

	cout << dp[1][n] << '\n';
}