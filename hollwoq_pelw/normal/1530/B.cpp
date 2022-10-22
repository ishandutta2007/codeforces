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

const int N = 1e5 + 5;

int n, m, res[22][22];

void Hollwo_Pelw(){
	cin >> n >> m;
	memset(res, 0, sizeof res);
	for (int i = 1; i <= n; i += 2)
		res[i][1] = 1;
	for (int i = 1; i <= m; i += 2)
		res[1][i] = 1;
	for (int i = 3; i < n - 1; i += 2)
		res[i][m] = 1;
	for (int i = 3; i < m - 1; i += 2)
		res[n][i] = 1;
	res[n][m] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << res[i][j];
		cout << '\n';
	}
}