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

#define int long long

int W, H, w, h, sx, sy, ex, ey;

void Hollwo_Pelw() {
	cin >> W >> H >> sx >> sy >> ex >> ey >> w >> h;
	int res = 1e9;
	if (ex - sx + w <= W) {
		res = min(res, max(w - sx, 0ll));
		res = min(res, max(w - W + ex, 0ll));
	} 
	if (ey - sy + h <= H) {
		res = min(res, max(h - sy, 0ll));
		res = min(res, max(h - H + ey, 0ll));
	}
	if (res == 1e9)
		cout << -1 << '\n';
	else
		cout << fixed << setprecision(6) << (double) res << '\n';
}