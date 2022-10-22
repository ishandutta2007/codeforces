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
	FAST_IO(".inp", ".out");
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

int n, m, dp[111][111][3][3], vis[111][2];

int solve(int l, int r, int tl, int tr) {
	if (l > r) return 0;
	if (dp[l][r][tl][tr] != -1)
		return dp[l][r][tl][tr];
	
	set<int> g;
	for (int i = l; i <= r; i++) {
		for (int j = 0; j < 2; j++) {
			if (vis[i][j]) continue ;
			if (i == l && tl && (tl & (1 << j)) == 0) continue ;
			if (i == r && tr && (tr & (1 << j)) == 0) continue ;

			// cout << i << ' ' << j << endl;

			g.insert(solve(l, i - 1, tl, 1 << j)
				^ solve(i + 1, r, 1 << j, tr));
		}
	}

	int res = 0;
	while (g.count(res)) 
		++ res;
	// cout << "solve " << l << ' ' << r << ' ' << tl << ' ' << tr << endl;
	// for (auto v : g) cout << v << ' '; cout << '\n';
	return dp[l][r][tl][tr] = res;
}

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 0, r, c; i < m; i++) {
		cin >> r >> c, -- c;
		vis[r][c] = vis[r][c ^ 1] = vis[r + 1][c ^ 1] = vis[r - 1][c ^ 1] = 1;
	}
	memset(dp, -1, sizeof dp);
	cout << (solve(1, n, 0, 0) ? "WIN\n" : "LOSE\n");
}