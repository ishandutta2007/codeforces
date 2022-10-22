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

const int N = 505, mod = 998244353;

#define cur dp[j & 1]
#define lst dp[j & 1 ^ 1]

inline void sadd(int &a, int b) {
	if ((a += b) >= mod) a -= mod;
}

int n, a[N], dp[2][505], res; char c;

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c; if (c == '+') cin >> a[i];
	}
	for (int i = 1; i <= n; i++) if (a[i]) {
		memset(dp, 0, sizeof dp), dp[0][0] = 1;
		for (int j = 1; j <= n; j++) {
			memcpy(cur, lst, sizeof cur);
			if (j ^ i) for (int k = 0; k < j; k++) {
				if (a[i] < a[j] || (a[i] == a[j] && i < j))
					sadd(cur[k], lst[k]);
				else if (a[j])
					sadd(cur[k + 1], lst[k]);
				else if (k || i > j)
					sadd(cur[k ? k - 1 : 0], lst[k]);
			}
		}
		for (int j = 0; j <= n; j++)
			res = (res + 1ll * dp[n & 1][j] * a[i]) % mod;
	}
	cout << res;
}