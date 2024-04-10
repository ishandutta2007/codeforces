#include <bits/stdc++.h>
using namespace std;

void FAST_IO(string filein = "", string fileout = ""){
	if (fopen(filein.c_str(), "r")){
		freopen(filein.c_str(), "r", stdin);
		freopen(fileout.c_str(), "w", stdout);
	}
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Why_Are_You_So_Orz();

signed main(){
#ifndef ONLINE_JUDGE
	FAST_IO("input.inp", "output.out");
	auto start = chrono::steady_clock::now();
#else
	FAST_IO("mike4235orz.inp", "mike4235orz.out");
#endif
	int testcases = 1;
	cin >> testcases;
	for (int test = 1; test <= testcases; test++)
		Why_Are_You_So_Orz();
#ifndef ONLINE_JUDGE
	auto end = chrono::steady_clock::now();
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

#define int long long

const int N = 2e5 + 5, mod = 1e9 + 7;

int fac[N], inv[N];

struct __init__ {
	__init__ () {
		fac[0] = inv[0] = fac[1] = inv[1] = 1;
		for (int i = 2; i < N; i++) fac[i] = fac[i - 1] * i % mod;
		for (int i = 2; i < N; i++) inv[i] = mod - (mod / i) * inv[mod % i] % mod;
		for (int i = 2; i < N; i++) inv[i] = inv[i - 1] * inv[i] % mod;
	}
} __init__;

inline int C(int n, int k) {
	if (k > n || k < 0) return 0;
	return fac[n] * inv[n - k] % mod * inv[k] % mod;
}

inline int binpow(int a, int x) {
	int r = 1;
	while (x) {
		if (x&1) r = r * a % mod;
		x >>= 1; a = a * a % mod;
	}
	return r;
}

void Why_Are_You_So_Orz() {
	// &a >= ^b 
	// x 0, y 1 => y even => 
	int n, k; cin >> n >> k;
	int eq = 0, tot = binpow(2, n);
	{
		for (int c1 = 0; c1 < n; c1 += 2) {
			eq = (eq + C(n, c1)) % mod;
		}
		eq += n & 1;
	}
	int res = 0, cur = 1;
	for (int i = 0; i < k; i++) {
		if (n & 1 ^ 1)
			res = (res + cur * binpow(tot, k - i - 1)) % mod;
		cur = cur * eq % mod;
	}
	cout << (cur + res) % mod << '\n';
}