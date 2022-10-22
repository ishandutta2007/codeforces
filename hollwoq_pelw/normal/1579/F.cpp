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

const int N = 1e6 + 5;

int n, d, vis[N], a[N];

void Hollwo_Pelw() {
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		char c; cin >> c, a[i] = c - '0', vis[i] = 0;
	}
	int res = 0;
	for (int i = 0; i < n; i++) if (!vis[i]) {
		int have0 = -1;
		for (int j = i; !vis[j]; j = (j + d) % n) {
			vis[j] = 1;
			if (a[j] == 0) have0 = j;
		}
		if (have0 < 0)
			return cout << "-1\n", (void) 0;
		for (int j = have0, c = 0; vis[j] < 2; j = (j + d) % n) {
			vis[j] = 2;
			if (a[j] == 1)  ++ c;
			if (a[j] == 0) c = 0;
			res = max(res, c);
		}
	}
	cout << res << '\n';
}