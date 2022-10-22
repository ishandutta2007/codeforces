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
	FAST_IO(".inp", ".out");
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

const int N = 1e5 + 5, mod = 998244353;

inline int mul(int a, int b) {
	return 1ll * a * b % mod;
}

int n, inv[N];

struct __initial__ {
	__initial__ () {
		inv[0] = inv[1] = 1;
		for (int i = 2; i < N; i++)
			inv[i] = mod - mul(mod / i, inv[mod % i]);
	}
} __init__;

string s;

void Hollwo_Pelw() {
	cin >> n >> s;
	int p = 0, m = n;
	for (int i = 0, c = 0; i < n; i++) {
		if (s[i] == '1') c ++;
		if (s[i] == '0' || i == n - 1) {
			p += c / 2, m -= c % 2, c = 0;
		}
	}
	m -= p;
	int ans = 1;
	for (int i = 1; i <= p; i ++) {
		ans = mul(ans, mul(inv[i], m - i + 1));
	}
	cout << ans << '\n';
}