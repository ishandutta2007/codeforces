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

const int N = 5e5 + 5, SZ = 400;

int q, a[N], lazy[SZ][SZ];

void Hollwo_Pelw() {
	cin >> q;
	for (int _ = 0, t, x, y; _ < q; _++) {
		cin >> t >> x >> y;
		if (t == 1) {
			a[x] += y;
			for (int i = 1; i < SZ; i++)
				lazy[i][x % i] += y;
		} else {
			if (x < SZ) {
				cout << lazy[x][y] << '\n';
			} else {
				int tot = 0;
				for (int i = y; i < N; i += x) 
					tot += a[i];
				cout << tot << '\n';
			}
		}
	}
}