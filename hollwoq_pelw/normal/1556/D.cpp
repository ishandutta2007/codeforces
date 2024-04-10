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

const int N = 1e4 + 5;

int n, k, a[N];

inline int query(string s, int i, int j) {
	cout << s << ' ' << i << ' ' << j << endl;
	int res; cin >> res; return res;
}

inline int getsum(int i, int j) {
	return query("and", i, j) + query("or", i, j);
}

void Hollwo_Pelw() {
	cin >> n >> k;
	int x = getsum(1, 2), y = getsum(2, 3), z = getsum(1, 3);
	a[1] = (x + z - y) / 2;
	a[2] = x - a[1];
	a[3] = y - a[2];
	for (int i = 4; i <= n; i++)
		a[i] = getsum(1, i) - a[1];
	sort(a + 1, a + n + 1);
	cout << "finish " << a[k] << endl;
}