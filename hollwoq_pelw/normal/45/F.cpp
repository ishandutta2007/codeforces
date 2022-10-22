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

int n, m;

void Hollwo_Pelw() {
	cin >> m >> n;
	if (n == 1)
		return cout << -1, (void) 0;
	if (n == m)
		return cout << 5, (void) 0;
	if (n > m && n < 2 * m)
		return cout << 3, (void) 0;
	if (n >= 2 * m)
		return cout << 1, (void) 0;
	if (n == 2)
		return cout << (m == 3 ? 11 : -1), (void) 0;
	if (n == 3) 
		return cout << (m <= 5 ? m * 2 + 1 : -1), (void) 0;
	int ans = 4; m -= n - 2;
	while (1) {
		if (n >= 2 * m)
			return cout << ans + 1, (void) 0;
		if (n >= m)
			return cout << ans + 3 + 2 * (n == m), (void) 0;
		m -= n / 2 - 1, ans += 2;
	}
	cout << ans;
}