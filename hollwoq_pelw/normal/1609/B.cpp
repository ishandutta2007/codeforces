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

const int N = 20;

#define int long long

string s, t = "abc";
int n, q, cnt = 0;

inline bool check(int p) {
	if (p <= 0 || p + 2 > n) return 0;
	bool ok = 1;
	for (int j = 0; j < 3; j++)
		ok &= s[p + j] == t[j];
	return ok;
}

void Hollwo_Pelw() {
	cin >> n >> q >> s;
	s = " " + s;

	for (int i = 1; i <= n - 2; i++)
		cnt += check(i);

	for (int p; q --; ) {
		char c; cin >> p >> c;
		cnt -= check(p - 2);
		cnt -= check(p - 1);
		cnt -= check(p);
		s[p] = c;
		cnt += check(p - 2);
		cnt += check(p - 1);
		cnt += check(p);

		cout << cnt << '\n';
	}
}