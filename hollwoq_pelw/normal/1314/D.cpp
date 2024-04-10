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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 85, inf = 1e9 + 7;

int n, k, dp[N], d[N][N];
vector<int> part[2];

void Hollwo_Pelw() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> d[i][j];

	int res = inf;

	for (int itr = 0; itr <= 5000; itr++) {
		part[0].clear();
		part[1].clear();

		part[0].push_back(1);
		for (int i = 2; i <= n; i++)
			part[rng() % 2].push_back(i);

		if (part[1].empty()) continue ;

		for (int i = 1; i <= n; i++)
			dp[i] = inf;
		
		dp[1] = 0;
		for (int i = 1; i <= k; i++) {
			for (auto v : part[i & 1]) {
				dp[v] = inf;
				for (auto u : part[i - 1 & 1])
					dp[v] = min(dp[v], dp[u] + d[u][v]);
			}
		}

		res = min(res, dp[1]);

		if (dp[1] == 0) break ;
	}
	cout << res;
}