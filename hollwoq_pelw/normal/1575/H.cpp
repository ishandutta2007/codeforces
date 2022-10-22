#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

void Hollwo_Pelw();

signed main(){
#ifndef hollwo_pelw_local
	if (fopen("hollwo_pelw.inp", "r"))
		assert(freopen("hollwo_pelw.inp", "r", stdin)), assert(freopen("hollwo_pelw.out", "w", stdout));
#else
	auto start = chrono::steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
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
}

const int N = 505;

int n, m, fail[N], nxt[N][2], dp[N][N][N];
char a[N], b[N];

inline void chkmin(int &a, int b) { a = a < b ? a : b; }

void Hollwo_Pelw(){
	cin >> n >> m >> (a + 1) >> (b + 1);
	
	for (int i = 2, j = 0; i <= m; i++) {
		while (j && b[j + 1] != b[i])
			j = fail[j];
		fail[i] = (j += b[j + 1] == b[i]);
	}

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j < 2; j++)
			nxt[i][j] = (i < m && b[i + 1] == '0' + j) ? i + 1 : nxt[fail[i]][j];
	}

	memset(dp, 0x3f, sizeof dp);

	dp[0][0][0] = 0;

	for (int i = 0; i < n; i++) for (int j = 0; j <= m; j++) {
		for (int k = 0; k <= i; k++) if (dp[i][j][k] <= 1e9) {
			for (int c = 0; c < 2; c ++)
				chkmin(dp[i + 1][nxt[j][c]][k + (nxt[j][c] == m)], dp[i][j][k] + (a[i + 1] == c + '0' ? 0 : 1));
		}
	}

	for (int i = 0; i <= n - m + 1; i++) {
		int res = 1e9;
		for (int j = 0; j <= m; j++)
			res = min(res, dp[n][j][i]);
		cout << (res == 1e9 ? -1 : res) << ' ';
	}

}