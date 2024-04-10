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


const int N = 505;

const int dx[4] = {0, +1, +1, 0};
const int dy[4] = {0, -1, 0, +1};

const int64_t inf = 1e18;

int n, m, k, chk[4];
// int64_t dp[N][N][2][N];
int64_t cost[N][N], can[2][N], dp[2][N][2][N];
vector<pair<int, int>> cann[N][N][2];

// dp[i][j][0/1][k]
// cur pos = (i, j), k last move is same (right / down)
// 1 -> down, 0 -> right

inline void chkmin(int64_t &a, int64_t b) { a = a < b ? a : b; }

void Hollwo_Pelw() {
	cin >> n >> m >> k;
	for (int x, y, d, t, e; k --; ) {
		cin >> x >> y >> d >> t >> e;
		for (int p = 0; p < 4; p++) {
			int nx = x + dx[p] * d, ny = y + dy[p] * d;
			chk[p] = (nx + ny) >= t + p && (nx + ny) % 4 == (t + p) % 4;
			if (chk[p]) cost[nx][ny] += e;
		}
		if (d % 4 == 3) {
			if (chk[0] && chk[3])
				cann[x][y + d][0].emplace_back(d, e);
		}
		if (d % 4 == 2) {
			if (chk[0] && chk[2])
				cann[x + d][y][1].emplace_back(d, e);
		}
		if (d % 4 == 1) {
			if (chk[1] && chk[2])
				cann[x + d][y][0].emplace_back(d, e);
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) {
				dp[0][0][0][0] = dp[0][0][1][0] = cost[0][0];
				continue;
			}
			
			for (int t = 0; t < 2; t++) {
				for (int k = 0; k <= (t ? i : j); k++)
					dp[i & 1][j][t][k] = inf;
			}

			for (int t = 0; t < 2; t++)
				for (auto [d, e] : cann[i][j][t])
					can[t][d] += e;

			if (i > 0){
				int64_t cur = cost[i][j];
				for (int k = 1; k <= i; k++) {
					cur -= can[1][k];
					// move down
					chkmin(dp[i & 1][j][1][k], dp[i - 1 & 1][j][1][k - 1] + cur);
					chkmin(dp[i & 1][j][0][0], dp[i - 1 & 1][j][1][k - 1] + cur);
				}
			}

			if (j > 0) {
				int64_t cur = cost[i][j];
				for (int k = 1; k <= j; k++) {
					cur -= can[0][k];
					// move right
					chkmin(dp[i & 1][j][0][k], dp[i & 1][j - 1][0][k - 1] + cur);
					chkmin(dp[i & 1][j][1][0], dp[i & 1][j - 1][0][k - 1] + cur);
				}
			}
			
			for (int t = 0; t < 2; t++)
				for (auto [d, e] : cann[i][j][t])
					can[t][d] -= e;
		}

	int64_t res = inf;
	for (int t = 0; t < 2; t++)
		for (int k = 0; k < (t ? n : m); k++)
			chkmin(res, dp[n - 1 & 1][m - 1][t][k]);

	cout << res;
}