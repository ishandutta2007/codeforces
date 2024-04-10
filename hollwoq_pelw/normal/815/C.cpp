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

const int N = 5005, inf = 1e9 + 9;

int n, b, dp[N][2][N], res, sz[N], par[N];

void Hollwo_Pelw() {
	cin >> n >> b;
	for (int i = 1, c, d; i <= n; i++) {
		cin >> c >> d;
		if (i > 1)
			cin >> par[i];

		sz[i] = 1;
		dp[i][0][0] = 0;
		dp[i][0][1] = c;
		dp[i][1][0] = inf;
		dp[i][1][1] = c-d;
		
		fill(dp[i][0] + 2, dp[i][0] + n + 1, inf);
		fill(dp[i][1] + 2, dp[i][1] + n + 1, inf);
	}

	for (int v = n; v; v--) {
		int u = par[v];

		for (int i = 0; i <= sz[v]; i++)
			dp[v][1][i] = min(dp[v][0][i], dp[v][1][i]);

		if (!u) break ;

		for (int i = sz[u]; ~i; i--) {
			for (int j = sz[v]; ~j; j--) {
				for (int k = 0; k < 2; k++)
					dp[u][k][i + j] = min(dp[u][k][i + j], dp[u][k][i] + dp[v][k][j]);
			}
		}

		sz[u] += sz[v];
	}
	while (res < sz[1] && dp[1][1][res + 1] <= b)
		res ++;
	cout << res;
}