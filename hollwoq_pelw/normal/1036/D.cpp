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

#define int long long
const int N = 3e5 + 5;

int n, m, a[N], b[N], tot;

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], tot += a[i];
	cin >> m;
	for (int i = 1; i <= m; i++)
		cin >> b[i], tot -= b[i];
	if (tot)
		return cout << -1, (void) 0;
	int i = 0, j = 0, ca = 0, cb = 0, ans = -1;
	while (i <= n && j <= m) {
		if (ca < cb) { ca += a[++ i]; continue; }
		if (ca > cb) { cb += b[++ j]; continue; }
		ca = a[++ i], cb = b[++ j], ++ ans; 
	}
	cout << ans;
}