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

#define int long long

const int mod = 1e9 + 7;

inline int binpow(int a, int b) {
	int r = 1;
	while (b) {
		if (b&1) r = r * a % mod;
		b >>= 1; a = a * a % mod;
	}
	return r;
}

inline int sumpow(int a, int b) {
	if (b == 1) return 1;
	if (b & 1)
		return (sumpow(a, b - 1) + binpow(a, b - 1)) % mod;
	int r = sumpow(a, b >> 1);
	return r * (binpow(a, b >> 1) + 1) % mod;
}

int a, b, n, x;

void Hollwo_Pelw() {
	cin >> a >> b >> n >> x;
	cout << (binpow(a, n) * x % mod + sumpow(a, n) * b % mod) % mod;
}