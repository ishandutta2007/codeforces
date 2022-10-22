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

const int N = 1e5 + 5;

int n, x[N], y[N];

double calc(double cx) {
	double cy = 0;
	// dist(cx, cy, x, y) <= cy
	// (cx - x) ^ 2 + (cy - y) ^ 2 			<= cy ^ 2
	//     C        - 2 * cy * y + y ^ 2 	<= 0
	//     C / y + y 						<= 2 * cy
	for (int i = 1; i <= n; i++)
		cy = max(cy, (cx - x[i]) * (cx- x[i]) / y[i] + y[i]);
	return cy / 2.0;
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	for (int i = 1; i < n; i++)
		if ((y[i] > 0) ^ (y[i + 1] > 0))
			return cout << -1, (void) 0;
	if (y[1] < 0) 
		for (int i = 1; i <= n; i++)
			y[i] = -y[i];
	double l = -2e9, r = +2e9, ml, mr;
	for (int _ = 0; _ < 100; _++) {
		ml = l + (r - l) / 3;
		mr = r - (r - l) / 3;
		(calc(ml) < calc(mr) ? r = mr : l = ml);
	}
	cout << fixed << setprecision(6) << calc(l);
}