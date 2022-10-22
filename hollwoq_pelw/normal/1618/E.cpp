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

#define int long long

const int N = 4e4 + 5;

int n, b[N], a[N], tot;

void Hollwo_Pelw() {
	cin >> n, tot = 0;
	for (int i = 1; i <= n; i++) 
		cin >> b[i], tot += b[i];
	int num = n * (n + 1) / 2;

	if (tot % num != 0)
		return cout << "NO\n", (void) 0;

	b[0] = b[n], tot /= num;

	for (int i = 1; i <= n; i++) {
		int v = tot - (b[i] - b[i - 1]);
		if (v % n != 0 || v <= 0)
			return cout << "NO\n", (void) 0;
		a[i] = v / n;
	}
	cout << "YES\n";
	for (int i = 1; i <= n; i++)
		cout << a[i] << " \n"[i == n];
}