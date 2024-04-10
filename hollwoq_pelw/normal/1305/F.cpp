/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5 + 5;

int n, res;
long long a[N];

void solve(long long v) {
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		long long x = v - a[i] % v;
		if (a[i] >= v && v - x < x)
			x = v - x;
		if (x > res) return ;
		cur += x;
		if (cur > res) return ;
	}
	res = cur;
}

void decomp(long long v) {
	if (v <= 1) return ;
	while (!(v & 1))
		v >>= 1;
	for (int i = 3; 1ll * i * i <= v; i += 2)
		if (v % i == 0) {
			solve(i);
			while (v % i == 0)
				v /= i;
		}
	if (v > 1)
		solve(v);
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], res += a[i] & 1;
	for (int _ = 0; _ < 20; _++) {
		int v = rng() % n + 1;
		for (int x = -1; x <= 1; x++)
			decomp(a[v] + x);
	}
	cout << res;
}