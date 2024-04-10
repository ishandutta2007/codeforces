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

const int N = 1e6 + 5, mod = 1e9 + 7;

int dp[N][22], p[N];

inline int add(int a, int b) {
	return a + b >= mod ? a + b - mod : a + b;
}

struct __initial__ {
	__initial__ () {
		// prime sieve
		for (int i = 1; i < N; i++) p[i] = i;
		for (int i = 2; i < N; i++) if (p[i] == i) {
			for (int j = i * 2; j < N; j += i) p[j] = i;
		} 
		// dp calc
		for (int i = 0; i < N ; i++) dp[i][0] = 1;
		for (int i = 1; i < 22; i++) dp[0][i] = 2;
		for (int i = 1; i < N; i++)
			for (int j = 1; j < 22; j++)
				dp[i][j] = add(dp[i - 1][j], dp[i][j - 1]);
	}
} __init__;

void solve(int r, int n) {
	int res = 1;
	while (n > 1) {
		int c = 0, v = p[n];
		while (n % v == 0)
			n /= v, c ++;
		res = 1ll * res * dp[r][c] % mod;
	}
	cout << res << '\n';
}

void Hollwo_Pelw() {
	int q; cin >> q;
	for (int i = 1, r, n; i <= q; i++)
		cin >> r >> n, solve(r, n);
}