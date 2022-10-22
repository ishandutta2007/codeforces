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

#define min __min__
#define max __max__

inline int max(int a, int b) {
	return a > b ? a : b;
}

inline int min(int a, int b) {
	return a < b ? a : b;
}

int n, lx[N], rx[N], ly[N], ry[N];
int plx[N], prx[N], slx[N], srx[N];
int ply[N], pry[N], sly[N], sry[N];

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> lx[i] >> ly[i] >> rx[i] >> ry[i];
	plx[0] = ply[0] = slx[n + 1] = sly[n + 1] = -1e9;
	prx[0] = pry[0] = srx[n + 1] = sry[n + 1] = +1e9;
	for (int i = 1; i <= n; i++) {
		plx[i] = max(lx[i], plx[i - 1]);
		ply[i] = max(ly[i], ply[i - 1]);
		prx[i] = min(rx[i], prx[i - 1]);
		pry[i] = min(ry[i], pry[i - 1]);
	}
	for (int i = n; i >= 1; i--) {
		slx[i] = max(lx[i], slx[i + 1]);
		sly[i] = max(ly[i], sly[i + 1]);
		srx[i] = min(rx[i], srx[i + 1]);
		sry[i] = min(ry[i], sry[i + 1]);
	}
	for (int i = 1; i <= n; i++) {
		int mlx = max(plx[i - 1], slx[i + 1]);
		int mly = max(ply[i - 1], sly[i + 1]);
		int mrx = min(prx[i - 1], srx[i + 1]);
		int mry = min(pry[i - 1], sry[i + 1]);
		if (mlx <= mrx && mly <= mry)
			return cout << mlx << ' ' << mly, (void) 0;
	}
}