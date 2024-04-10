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
	FAST_IO("1612B.inp", "1612B.out");
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

// min left = a
// max right = b

int n, a, b;

void Hollwo_Pelw() {
	cin >> n >> a >> b;
	if (a > n / 2 + 1 || b < n / 2)
		return cout << "-1\n", (void) 0;
	if (a > n / 2 && b > n / 2)
		return cout << "-1\n", (void) 0;
	if (a <= n / 2 && b <= n / 2)
		return cout << "-1\n", (void) 0;

	for (int i = n; i > n / 2; i--) {
		if (i == b)
			cout << a << ' ';
		else
			cout << i << ' ';
	}
	for (int i = n / 2; i > 0; i--) {
		if (i == a)
			cout << b << ' ';
		else
			cout << i << ' ';
	}
	cout << '\n';
}