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
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

void Hollwo_Pelw() {
	int n, m, q;
	cin >> n >> m;
	vector<string> a(n);
	for (auto &s : a)
		cin >> s;
	vector<int> die(m);
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (a[i - 1][j] == 'X' && a[i][j - 1] == 'X')
				die[j] = 1;
		}
	}
	for (int i = 1; i < m; i++)
		die[i] += die[i - 1];

	cin >> q;
	for (int l, r; q --; ) {
		cin >> l >> r;
		int c = die[r - 1] - die[l - 1];
		cout << (c ? "NO\n" : "YES\n");
	}
}