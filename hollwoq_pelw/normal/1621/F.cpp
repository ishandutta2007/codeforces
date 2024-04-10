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

int n, a, b, c;
string s;

void Hollwo_Pelw() {
	cin >> n >> a >> b >> c >> s;
	int c0 = 0, c1 = 0, out = 0, del = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] == '0' && s[i - 1] == '0') c0 ++;
		if (s[i] == '1' && s[i - 1] == '1') c1 ++;
	}
	vector<int> seg;
	for (int i = 0, j = 0; i < n; i = j) {
		while (j < n && s[j] == s[i]) j ++;
		if (s[i] == '0') {
			if (i > 0 && j < n)
				seg.push_back(j - i - 1);
			else
				out ++;
		}
	}
	sort(seg.begin(), seg.end());
	int turn = min(c0, c1), res = turn * (a + b);
	c0 -= turn, c1 -= turn;

	// cout << turn << '\n';

	for (auto v : seg) {
		if (turn >= v)
			turn -= v, del ++;
	}
	
	if (c0) res += a, c0 --;
	if (c1) res += b, c1 --;

	// cout << "not del " << res << '\n';

	if (c < b) { // delete better
		res += (b - c) * (del + min(out, c1));
	}
	cout << res << '\n';
}