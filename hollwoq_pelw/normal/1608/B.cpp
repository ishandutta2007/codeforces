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

int n, a, b;

void Hollwo_Pelw() {
	cin >> n >> a >> b;
	if (abs(a - b) > 1 || a + b > n - 2)
		return cout << "-1\n", (void) 0;
	int l = 1, r = n;

	if (a < b) {
		for (int i = 1; i <= a + b + 1; i++) {
			if (i & 1)
				cout << (r --) << ' ';
			else
				cout << (l ++) << ' ';
		}
		while (l <= r)
			cout << (l ++) << ' ';
		cout << '\n';
		return ;
	}
	if (b < a) {
		for (int i = 1; i <= a + b + 1; i++) {
			if (i & 1)
				cout << (l ++) << ' ';
			else
				cout << (r --) << ' ';
		}
		while (l <= r)
			cout << (r --) << ' ';
		cout << '\n';
		return ;
	}
	for (int i = 1; i <= a + b + 1; i++) {
		if (i & 1)
			cout << (l ++) << ' ';
		else
			cout << (r --) << ' ';
	}
	while (l <= r)
		cout << (l ++) << ' ';
	cout << '\n';
}