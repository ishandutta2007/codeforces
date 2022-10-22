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

// n x m
// a (1 x 2)
// b (2 x 1)
// c (2 x 2)

int n, m, a, b, c;
char res[101][101];

void Hollwo_Pelw() {
	cin >> n >> m >> a >> b >> c;
	if (n % 2 && m % 2) {
		cout << "IMPOSSIBLE";
	} else {
		if (n & 1) for (int i = 1; i <= m; i += 2)
			res[n][i] = res[n][i + 1] = "yz"[i >> 1 & 1], -- a;
		if (m & 1) for (int i = 1; i <= n; i += 2)
			res[i][m] = res[i + 1][m] = "yz"[i >> 1 & 1], -- b;

		if ((n / 2) * (m / 2) > c + a / 2 + b / 2 || a < 0 || b < 0) {
			cout << "IMPOSSIBLE";
		} else {
			for (int i = 1; i < n; i += 2)
				for (int j = 1; j < m; j += 2) {
					if (a >= 2) {
						res[i][j] = res[i][j + 1] = "ab"[j >> 1 & 1], -- a;
						res[i + 1][j] = res[i + 1][j + 1] = "ba"[j >> 1 & 1], -- a;
					} else if (b >= 2) {
						res[i][j] = res[i + 1][j] = "cd"[i >> 1 & 1], -- b;
						res[i][j + 1] = res[i + 1][j + 1] = "dc"[i >> 1 & 1], -- b;
					} else {
						res[i][j] = res[i][j + 1] = res[i + 1][j] = res[i + 1][j + 1] = "ef"[(i ^ j) >> 1 & 1], -- c;
					}
				}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++)
					cout << res[i][j];
				cout << '\n';
			} 
		}
	}
}