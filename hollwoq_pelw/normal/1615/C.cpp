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

const int inf = 2e9;

int n;
string s, t;

inline int solve(int tp) {
	int cnt0 = 0, cnt1 = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			if (t[i] == '1') cnt1 ++;
			if (t[i] == '0') cnt0 ++;
		}
	}
	if ((cnt0 + cnt1) % 2 == tp) {
		if (tp == 0) {
			if (cnt0 != cnt1)
				return inf;
		} else {
			if (cnt1 != cnt0 + 1)
				return inf;
		}
		return cnt0 + cnt1;
	}
	return inf;
}

void Hollwo_Pelw() {
	cin >> n >> s >> t;
	int res = solve(0);
	for (auto &c : s)
		c = c == '0' ? '1' : '0';
	res = min(res, solve(1));

	cout << (res == inf ? -1 : res) << '\n';
}