/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include<bits/stdc++.h>
using namespace std;

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

const int N = 2e5 + 5, mod = 998244353;

#define int long long 

inline int binpow(int a, int b){
	int r = 1;
	while (b){
		if (b&1) r = r * a % mod;
		b >>= 1; a = a * a % mod;
	}
	return r;
}

inline int inv(int a) {
	return binpow(a, mod - 2);
}

int n, q, p[N], prod[N], pref[N], res;
set<int> pos;

int solve(int l, int r) {
	int a, b;
	if (l > 1) {
		a = (pref[r - 1] - pref[l - 2] + mod) % mod * inv(prod[l - 1]) % mod;
	} else {
		a = (pref[r - 1] + 1) % mod;
	}
	b = prod[r] * inv(prod[l - 1]) % mod;
	return a * inv(b) % mod;
}

void Hollwo_Pelw() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> p[i], p[i] = p[i] * inv(100) % mod;
	prod[0] = 1;
	for (int i = 1; i <= n; i++)
		prod[i] = prod[i - 1] * p[i] % mod, pref[i] = (pref[i - 1] + prod[i]) % mod;
	pos.insert(1), pos.insert(n + 1);
	res = solve(1, n);
	for (int i = 1, x, l, r; i <= q; i++) {
		cin >> x;
		auto it = pos.lower_bound(x);
		if (*it != x) {
			it = pos.insert(x).first;
			l = *prev(it), r = *next(it);
			res -= solve(l, r - 1);
			res += solve(l, x - 1);
			res += solve(x, r - 1);
		} else {
			l = *prev(it), r = *next(it);
			res += solve(l, r - 1);
			res -= solve(l, x - 1);
			res -= solve(x, r - 1);
			pos.erase(x);
		}
		cout << (res = (res % mod + mod) % mod) << '\n';
	}
}