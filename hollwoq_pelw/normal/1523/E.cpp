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

const int N = 1e5 + 5, mod = 1e9 + 7;

inline int mul(int a, int b) {
	return 1ll * a * b % mod;
}

inline int mul(int a, int b, int c) {
	return mul(a, mul(b, c));
}

inline int add(int a, int b) {
	return a + b >= mod ? a + b - mod : a + b;
}

int inv[N], fac[N], ifac[N];

struct __init__ {
	__init__() {
		for (int i = 0; i < 2; i++)
			inv[i] = fac[i] = ifac[i] = 1;
		for (int i = 2; i < N; i++)
			inv[i] = mod - mul(mod / i, inv[mod % i]);
		for (int i = 2; i < N; i++)
			fac[i] = mul(fac[i - 1], i), ifac[i] = mul(ifac[i - 1], inv[i]);
	}
} __init__;

inline int C(int n, int k) {
	return k < 0 || k > n ? 0 : mul(fac[n], ifac[k], ifac[n - k]);
}

void Hollwo_Pelw() {
	int n, k, res = 1; cin >> n >> k;
	for (int i = 1, p = 1; (i - 1) * (k - 1) < n; i++)
		p = mul(p, i, inv[n - i + 1]), res = add(res, mul(p, C(n - (i - 1) * (k - 1), i)));
	cout << res << '\n';
}