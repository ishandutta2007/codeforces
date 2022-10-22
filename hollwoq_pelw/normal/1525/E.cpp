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

const int N = 5e4 + 5, M = 22, mod = 998244353;

int a[N][M], n, m, fac, invfac;

inline int binpow(int a, int b) {
	int r = 1;
	while (b) {
		if (b&1) r = 1ll * r * a % mod;
		b >>= 1; a = 1ll * a * a % mod;
	}
	return r;
}

int solve(int *p) {
	sort(p + 1, p + n + 1);
	int res = 1;
	for (int i = n, j = n, cnt = 0; i; i--, cnt--) {
		while (j && p[j] >= i) j--, cnt++;
		if (cnt <= 0) return 0;
		res = 1ll * res * cnt % mod; 
	}
	return res;
}

void Hollwo_Pelw() {
	cin >> n >> m;
	
	fac = 1;
	for (int i = 1; i <= n; i++)
		fac = 1ll * fac * i % mod;
	invfac = binpow(fac, mod - 2);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[j][i], --a[j][i];
	long long ans = 1ll * m * fac;
	for (int i = 1; i <= m; i++) {
		ans -= solve(a[i]);
	}
	ans = (ans % mod + mod) * invfac % mod;
	cout << ans;
}