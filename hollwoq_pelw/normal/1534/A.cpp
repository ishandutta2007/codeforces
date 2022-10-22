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

int n, m, x, y;

char a[55][55], b[55][55];

void Hollwo_Pelw() {
	cin >> n >> m;
	x = 0, y = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
			if (a[i][j] != '.')
				x = i, y = j;
		}
	}
	if (!x && !y) {
		a[1][1] = 'R';
		x = 1, y = 1;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if ((i + j) % 2 == (x + y) % 2) 
				b[i][j] = a[x][y];
			else 
				b[i][j] = a[x][y] ^ 'R' ^ 'W';

			if (b[i][j] != a[i][j] && a[i][j] != '.')
				return cout << "NO\n", (void) 0;
		}
	}
	cout << "YES\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << b[i][j];
		}
		cout << "\n";
	}
}