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

const int N = 1010;

int n, a[N];

int solve(int l, int r) {
	int cur = 0, mn = 0;
	for (int i = l + 1; i < r; i++)
		mn = min(mn, cur = i & 1 ? cur + a[i] : cur - a[i]);
	// cout << "solve " << l << ' ' << r << " : " << cur << ' ' << mn << '\n';
	// a - b + cur = 0;
	// a + mn >= 0
	// a in [-mn, l]
	// b = a + cur
	int cl = max(-mn + cur, 1ll), cr = min(a[l] + cur, a[r]); 
	return max(cr - cl + 1, 0ll);
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int res = 0;
	for (int i = 1; i <= n; i += 2) {
		for (int j = i + 1; j <= n; j += 2) {
			res += solve(i, j);
		}
	}
	cout << res << '\n';
}