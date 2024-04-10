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
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 2e5 + 5;

int n, mod;

inline void sadd(int &a, int b) {
	if ((a += b) >= mod) a -= mod;
}

inline void ssub(int &a, int b) {
	if ((a -= b) < 0) a += mod;
}

int dp[N], pre, lz[N];

void Hollwo_Pelw() {
	cin >> n >> mod;
	pre = 0, dp[1] = 1;
	for (int i = 1; i <= n; i++) {
		sadd(lz[i], lz[i - 1]);
		sadd(dp[i], lz[i]);
		sadd(dp[i], pre);
		sadd(pre, dp[i]);
		for (int j = 2; i * j <= n; j ++) {
			sadd(lz[i * j], dp[i]);
			if (i * j + j <= n)
				ssub(lz[i * j + j], dp[i]);
			// cout << i * j << ' ' << i * j + j << '\n';
		}
		// cout << lz[i] << ' ' << dp[i] << '\n';
	}
	cout << dp[n];
}