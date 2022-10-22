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

const int N = 1e3 + 5;

int n, k, b[N], c[N], dp[N << 1], f[N * 12];

struct __init__ {
	__init__() {
		memset(dp, 0x3f, sizeof dp);
		dp[1] = 0;
		for (int i = 1; i < N; i++) {
			for (int j = 1; j <= i; j++)
				dp[i + i / j] = min(dp[i + i / j], dp[i] + 1);
		}
	}
} __init__;

void Hollwo_Pelw() {
	cin >> n >> k, k = min(k, n * 12);
	for (int i = 1; i <= n; i++)
		cin >> b[i], b[i] = dp[b[i]];
	
	fill(f, f + k + 5, 0);

	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		for (int j = k; j >= b[i]; j--)
			f[j] = max(f[j], f[j - b[i]] + c[i]);
	}

	cout << f[k] << '\n';
}