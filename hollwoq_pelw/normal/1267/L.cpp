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
	FAST_IO("1267L.inp", "1267L.out");
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

const int N = 1010;

int n, l, k, cnt[26], cc;
char s[N][N], t[N * N];

inline char getchr() {
	while (!cnt[cc]) cc ++; return cnt[cc] --, 'a' + cc;
}

void Hollwo_Pelw() {
	cin >> n >> l >> k >> t;
	for (int i = 0; i < n * l; i++)
		cnt[t[i] - 'a'] ++;
	int c = 1;
	for (int i = 0; i < l; i++) {
		for (int j = c; j <= k; j++)
			s[j][i] = getchr();
		while (s[c][i] != s[k][i]) c ++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < l; j++) {
			if (!s[i][j]) s[i][j] = getchr();
			cout << s[i][j];
		}
		cout << '\n';
	}
}