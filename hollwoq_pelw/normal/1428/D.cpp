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
	FAST_IO("input.txt", "output.txt");
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

const int N = 1e5 + 5;

vector<pair<int, int>> res;
int n, row, last, a[N];

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) if (a[i] == 1)
		res.emplace_back(++ row, i), last = i; // can use in other
	for (int i = n, f = 1, c = row; i; i--) {
		if (a[i] == 3) {
			if (row == 0 || last < i) return cout << -1, (void) 0;
			c -= f, f = 0;
			res.emplace_back(++ row, i);
			res.emplace_back(row, last);
			last = i;
		}
		if (a[i] == 2) {
			if (c < 1 || res[c - 1].second < i) return cout << -1, (void) 0;
			res.emplace_back(c --, i);
			if (f) last = i, f = 0;
		}
	}
	cout << res.size() << '\n';
	for (auto xy : res)
		cout <<  n - xy.first + 1 << ' ' << xy.second << '\n';
}