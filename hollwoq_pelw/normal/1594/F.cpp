/*
// is short or still long ???
hollwo_pelw's template(short)
// Note - -Dhollwo_pelw_local
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
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

#define int long long

int s, n, k, ok;

int solve(int p, int v) {
	if (v)
		ok &= p > 2;
	return (p + 1) / 2;
}

void Hollwo_Pelw() {
	cin >> s >> n >> k;
	int p = s / k; ok = 1;
	// s % k + 1 -> k - 1 (free)
	int res = (k - 1 - (s % k)) * solve(p, 0);
	if (s % k == 0) {
		res += solve(p + 1, 1);
	} else {
		res += solve(p + 1, 0) * ((s % k) + 1);
	}
	cout << (res > n && ok ? "NO\n" : "YES\n");
}