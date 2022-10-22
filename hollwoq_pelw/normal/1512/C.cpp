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
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}


int n, a, b;
string s;

void Hollwo_Pelw() {
	cin >> a >> b >> s, n = a + b;
	for (int i = 0; i < n - i - 1; i++) {
		if (s[i] != s[n - i - 1]) {
			if (s[i] != '?' && s[n - i - 1] != '?')
				return cout << "-1\n", (void) 0;
			if (s[i] == '0' || s[n - i - 1] == '0')
				s[i] = s[n - i - 1] = '0', a -= 2;
			if (s[i] == '1' || s[n - i - 1] == '1')
				s[i] = s[n - i - 1] = '1', b -= 2;
		} else if (s[i] != '?') {
			if (s[i] == '0') a -= 2;
			if (s[i] == '1') b -= 2;
		}
	}
	for (int i = 0; i < n - i - 1; i++) {
		if (s[i] == '?') {
			s[i] = s[n - i - 1] = "01"[a < 2];
			if (s[i] == '0') a -= 2;
			if (s[i] == '1') b -= 2;
		}
	}
	if (n % 2 == 1) {
		if (s[n / 2] == '?') 
			s[n / 2] = "01"[a < 1];
		if (s[n / 2] == '0') a --;
		if (s[n / 2] == '1') b --;
	}
	if (a == 0 && b == 0)
		cout << s << '\n';
	else
		cout << "-1\n";
}