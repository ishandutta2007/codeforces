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

char s[404][404];

void Hollwo_Pelw() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	int x1 = -1, x2 = -1, y1 = -1, y2 = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) if (s[i][j] == '*') {
			if (x1 == -1)
				x1 = i, y1 = j;
			else
				x2 = i, y2 = j;
		}
	if (x1 == x2)
		x2 = x1 == 0 ? 1 : 0;
	if (y1 == y2)
		y2 = y1 == 0 ? 1 : 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i == x1 || i == x2) && (j == y1 || j == y2))
				cout << '*';
			else
				cout << '.';
		}
		cout << '\n';
	}
}