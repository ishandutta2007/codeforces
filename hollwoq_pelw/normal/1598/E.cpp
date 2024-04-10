/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

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
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 1005;

int n, m, q, dp[N][N][2], res, cnt;
bool b[N][N];

inline void update(int i, int j) {
	if (!i || !j) return ;

	res -= dp[i][j][0] + dp[i][j][1];

	if (b[i][j]) {
		dp[i][j][0] = dp[i][j][1] = 0;
		return ;
	}
	dp[i][j][0] = dp[i][j + 1][1] + 1;
	dp[i][j][1] = dp[i + 1][j][0] + 1;

	res += dp[i][j][0] + dp[i][j][1];
}

void Hollwo_Pelw() {
	cin >> n >> m >> q;
	for (int i = n; i; i--)
		for (int j = m; j; j--)
			update(i, j);
	cnt = n * m;

	for (int x, y; q--; ) {
		cin >> x >> y;

		cnt += b[x][y];
		b[x][y] ^= 1;
		cnt -= b[x][y];

		for (int i = x, j = y; i && j; i--, j--) {
			update(i, j);
			update(i - 1, j);
			update(i, j - 1);
		}

		cout << res - cnt << '\n';
	}
}