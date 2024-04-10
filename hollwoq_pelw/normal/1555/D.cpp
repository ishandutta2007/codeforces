/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include<bits/stdc++.h>
using namespace std;

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

const int N = 2e5 + 5;

int n, m, a[N], per[3];

int f[6][N], cnt;
// 0 => 0, 1, 2
// 1 => 0, 2, 1
// 2 => 1, 0, 2
// ...

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char c; cin >> c, a[i] = c - 'a';
	}
	per[0] = 0, per[1] = 1, per[2] = 2;
	do {
		for (int i = 1; i <= n; i++)
			f[cnt][i] = f[cnt][i - 1] + (per[i % 3] != a[i]);
		++ cnt;
	} while (next_permutation(per, per + 3));
	for (int i = 1, l, r; i <= m; i++) {
		cin >> l >> r;
		int res = 1e9;
		for (int j = 0; j < 6; j++) {
			res = min(res, f[j][r] - f[j][l - 1]);
		}
		cout << res << '\n';
	}
}