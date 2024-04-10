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

int n, m, k, a[101][101], ans = 1e9;

void print(int x) {
	cout << (x > k ? -1 : x);
}

void bruteforces() {
	for (int mask = 0; mask < 1 << m; mask++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			int tmp = 0;
			for (int k = 0; k < m; k++) {
				tmp += a[j][k] == (mask >> k & 1);
			}
			cnt += min(tmp, m - tmp);
		}
		ans = min(ans, cnt);
	}
	print(ans);
}

void Hollwo_Pelw() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	if (m <= k)
		return bruteforces();
	for (int i = 0; i < m; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			int tmp = 0;
			for (int k = 0; k < n; k++) {
				tmp += a[k][i] == a[k][j];
			}
			cnt += min(tmp, n - tmp);
		}
		ans = min(ans, cnt);
	}
	print(ans);
}