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

const int N = 405, M = 2.5e5 + 5;

int n, m, a[N], dp[N][N][N];

inline int cost(int f, int l, int r, int m) {
	return max(dp[f - 1][l][m], a[r] - a[m]);
}

void Hollwo_Pelw(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			dp[0][i][j] = a[j] - a[i];
	for (int f = 1; f <= n; f++) {
		for (int i = 1; i <= n; i++)
			for (int j = i, k = i; j <= n; j ++) {
				while (k < j && cost(f, i, j, k) > cost(f, i, j, k + 1))
					k ++;
				dp[f][i][j] = cost(f, i, j, k);
			}
	}
	long long res = 0;
	for (int s, f, c, r; m --; ) {
		cin >> s >> f >> c >> r;
		res = max(res, 1ll * dp[r][s][f] * c);
	}
	cout << res;
}