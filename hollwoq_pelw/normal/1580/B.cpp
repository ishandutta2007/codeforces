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

int n, m, k, mod, fac[N], C[N][N], dp[N][N][N];

inline int add(int a, int b) {
	return a + b >= mod ? a + b - mod : a + b;
}

inline int mul(int a, int b) {
	return 1ll * a * b % mod;
}

// dp[size][dep][cnt]

void Hollwo_Pelw() {
	cin >> n >> m >> k >> mod;
	C[0][0] = fac[0] = 1;
	for (int i = 1; i < N; i++) {
		fac[i] = mul(fac[i - 1], i);
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
	}

	for (int i = 1; i <= m; i++)
		dp[0][i][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int l = 0, r = i - 1; l < i; l++, r--) {
			for (int j = 0; j < m; j++) {
#define cur dp[i][j + 1]
#define lef dp[l][j]
#define rig dp[r][j]
				for (int cl = 0; cl <= l; cl++) if (lef[cl]) {
					for (int cr = 0; cr <= r; cr++) if (rig[cr])
						cur[cl + cr] = add(cur[cl + cr], mul(mul(lef[cl], rig[cr]), C[i - 1][l]));
				}
			}
		}
		dp[i][1][1] = add(dp[i][1][1], fac[i]);
	}

	cout << dp[n][m][k] << '\n';
}