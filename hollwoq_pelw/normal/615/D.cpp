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

#define int long long
const int N = 2e5 + 5, mod = 1e9 + 7;

int n = 1, m, res = 1, cnt[N];

int binpow(int a, int b) {
	int r = 1;
	while (b) {
		if (b&1) r = 1ll * r * a % mod;
		b >>= 1; a = 1ll * a * a % mod;
	}
	return r;
}

void Hollwo_Pelw() {
	cin >> m;
	for (int i = 0, p; i < m; i++)
		cin >> p, cnt[p] ++;
	for (int p = 2; p < N; p++) if (cnt[p]) {
		res = binpow(res, cnt[p] + 1) * binpow(binpow(p, cnt[p] * (cnt[p] + 1) / 2), n) % mod, n = n * (cnt[p] + 1) % (mod - 1);
	}
	cout << res;
}