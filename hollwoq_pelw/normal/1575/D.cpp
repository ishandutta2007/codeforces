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

const int N = 2e5 + 5;

inline int solve(string s, string t) {
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	for (int i = 0; i < 2; i++) {
		if (s[i] == '_') s[i] = t[i];
		if (s[i] != t[i]) return 0;
	}
	if (s.back() == '0') return 0;
	int res = 1;
	for (int i = s.size() - 1; i >= 2; i--) {
		if (s[i] == '_')
			res *= i == s.size() - 1 ? 9 : 10;
	}
	return res;
}

void Hollwo_Pelw() {
	string s; cin >> s;

	if (s.size() == 1) {
		cout << (s[0] == '0' || s[0] == 'X' || s[0] == '_' ? 1 : 0);
		return ;
	}

	int rt = 0;

	if (s.find('X') == string::npos) {
		rt += solve(s, "00")
			+ solve(s, "25")
			+ solve(s, "50")
			+ solve(s, "75");
	} else {
		for (int i = 0; i <= 9; i++) {
			string t = s;
			for (auto &c : t) if (c == 'X') 
				c = (char) ('0' + i);
			rt += solve(t, "00")
				+ solve(t, "25")
				+ solve(t, "50")
				+ solve(t, "75");
		}
	}

	cout << rt;
}