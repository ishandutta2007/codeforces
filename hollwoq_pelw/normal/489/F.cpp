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

const int N = 505;

int n, m, mod, a[N], dp[N][N];
char s[N];

inline void sadd(int &a, int b) {
	if ((a += b) >= mod) a -= mod;
}

inline int mul(int a, int b) {
	return 1ll * a * b % mod;
}

void Hollwo_Pelw() {
	cin >> n >> m >> mod;
	fill(a + 1, a + n + 1, 2);
	for (int i = 1; i <= m; i++) {
		cin >> (s + 1);
		for (int j = 1; j <= n; j++) 
			a[j] -= s[j] - '0';
	}
	int p = n - m, c2 = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] == 2) c2 ++;
	dp[p][c2] = 1;
	for (int i = p; i; i--) {
		for (int j = i; ~j; j--) {
			int k = i - j << 1;
			if (j >= 0) sadd(dp[i - 1][j - 0], mul(dp[i][j], k * (k - 1) / 2));
			if (j >= 1) sadd(dp[i - 1][j - 1], mul(dp[i][j], k * j));
			if (j >= 2) sadd(dp[i - 1][j - 2], mul(dp[i][j], j * (j - 1) / 2));
		}
	}
	cout << dp[0][0] << '\n';
}