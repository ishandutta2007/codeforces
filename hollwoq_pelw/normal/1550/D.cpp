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
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 2e5 + 5, mod = 1e9 + 7;

inline int mul(int a, int b) { return 1ll * a * b % mod; }
inline int mul(int a, int b, int c) { return mul(a, mul(b, c)); }
inline void sadd(int &a, int b) { if((a += b) >= mod) a -= mod; }

int n, l, r, k, fac[N], ifac[N];

struct __init__ {
	__init__() {
		fac[0] = ifac[0] = fac[1] = ifac[1] = 1;
		for (int i = 2; i < N; i++)
			ifac[i] = mod - mul(mod / i, ifac[mod % i]);
		for (int i = 2; i < N; i++)
			fac[i] = mul(fac[i - 1], i), ifac[i] = mul(ifac[i - 1], ifac[i]);
	}
} __init__;

inline int C(int n, int k) {
	return k > n || k < 0 ? 0 : mul(fac[n], ifac[k], ifac[n - k]);
}

void Hollwo_Pelw() {
	cin >> n >> l >> r;
	int res = n & 1 ^ 1 ? C(n, n / 2) : 
				2ll * C(n, n / 2) % mod;
	res = mul(res, k = min(1 - l, r - n));
	while (1) {
		int x = min(n - l - k, n), y = min(r - k - 1, n);
		if (x < 0 || y < 0) break ; ++ k;
		sadd(res, C(x + y - n, n / 2 - n + y));
		if (n & 1) sadd(res, C(x + y - n, n / 2 - n + x));
	}
	cout << res << '\n';
}