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

const int N = 23, S = 2e4 + 5, mod = 998244353;

int n, cnt[1 << N][26], dp[1 << N];

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (auto c : s) 
			cnt[1 << i][c - 'a'] ++;
	}
	
	fill(cnt[0], cnt[0] + 26, S);
	
	for (int mask = 1; mask < 1 << n; mask++) {
		int f = mask & - mask, o = mask ^ f;
		for (int i = 0; i < 26; i++)
			cnt[mask][i] = min(cnt[o][i], cnt[f][i]);
	}

	for (int mask = 0; mask < 1 << n; mask++) {
		dp[mask] = 1;
		for (int i = 0; i < 26; i++)
			dp[mask] = 1ll * dp[mask] * (cnt[mask][i] + 1) % mod;
	}

	for (int i = 0; i < n; i++) {
		for (int mask = 0; mask < 1 << n; mask++) if (mask >> i & 1) {
			if ((dp[mask ^ 1 << i] -= dp[mask]) < 0)
				dp[mask ^ 1 << i] += mod;

		}
	}

	for (int i = 0; i < n; i++) {
		for (int mask = 0; mask < 1 << n; mask++) if (mask >> i & 1) {
			if ((dp[mask] += dp[mask ^ 1 << i]) >= mod)
				dp[mask] -= mod;
		}
	}

	int full = (1 << n) - 1;

	long long res = 0;

	for (int mask = 0; mask < 1 << n; mask++) {
		int v = dp[full] - dp[full ^ mask], s = 0, k = 0;
		if (v < 0) v += mod;

		for (int i = 0; i < n; i++)
			if (mask >> i & 1)
				k ++, s += i + 1;

		res ^= 1ll * v * s * k;
	}

	cout << res;
}