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

const int mod = 1e9 + 7;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline void sadd(int &a, int b) { a = a + b >= mod ? a + b - mod : a + b; }

inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline void ssub(int &a, int b) { a = a - b < 0 ? a - b + mod : a - b; }

inline int mul(int a, int b) { return 1ll * a * b % mod; }
inline void smul(int &a, int b) { a = 1ll * a * b % mod; }

inline int mul(int a, int b, int c) { return mul(a, mul(b, c)); }

inline int binpow(int a, int b) {
	int r = 1;
	while (b) {
		if (b&1) r = mul(r, a);
		b >>= 1; a = mul(a, a);
	}
	return r;
}

inline int inv(int a) {
	return binpow(a, mod - 2);
}

int n, a[20], dp[1 << 14], p[20][20];

// dp[mask] = prob that any bit in mask win the other

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			p[i][j] = mul(a[i], inv(a[i] + a[j]));
	int res = 0;
	for (int msk = 1; msk < 1 << n; msk++) {
		dp[msk] = 1;
		// cout << "solve mask = " << msk << " :\n";
		for (int sub = msk & msk - 1; sub; sub = sub - 1 & msk) {
			int oth = msk ^ sub, prob = dp[sub];
			for (int i = 0; i < n; i++) if (sub >> i & 1) 
				for (int j = 0; j < n; j++) if (oth >> j & 1)
					smul(prob, p[i][j]);
			ssub(dp[msk], prob);
		}

		int prob = dp[msk];
		for (int i = 0; i < n; i++) if (msk >> i & 1)
			for (int j = 0; j < n; j++) if (!(msk >> j & 1))
				smul(prob, p[i][j]);
		sadd(res, mul(prob, __builtin_popcount(msk)));
	}
	cout << res;
}