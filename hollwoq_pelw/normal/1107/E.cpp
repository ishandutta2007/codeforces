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
	// cin >> testcases;
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

const int N = 105;

int n, a[N];

int64_t dp[N][N][N];
char s[N];

void Hollwo_Pelw() {
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int d = 1; d <= n; d++) {
		for (int i = 0, j = d; j <= n; i++, j++) {
			for (int k = 1; k <= i + 1; k++) {
				dp[i][j][k] = dp[i + 1][j][1] + a[k];
				for (int l = i + 1; l < j; l++)
					if (s[i] == s[l])
						dp[i][j][k] = max(dp[i][j][k], dp[i + 1][l][1] + dp[l][j][k + 1]);
			}
		}
	}
	cout << dp[0][n][1];
}