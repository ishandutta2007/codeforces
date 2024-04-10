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

const int N = 2e5 + 5;

int n, k, a[N];

void Hollwo_Pelw() {
	cin >> n >> k;
	vector<pair<int, int>> a(n / 2);
	for (int i = 0; i < n / 2; i++)
		a[i] = {i, n - 1 - i};
	if (k != n - 1) {
		if (k < n / 2)
			swap(a[0].first, a[k].first);
		else
			swap(a[0].first, a[n - k - 1].second);
		for (auto [x, y] : a)
			cout << x << ' ' << y << '\n';
		return ;
	}
	if (n == 4)
		return cout << "-1\n", (void) 0;
	swap(a[0].first, a[2].second);
	swap(a[0].first, a[1].second);
	for (auto [x, y] : a)
		cout << x << ' ' << y << '\n';
}