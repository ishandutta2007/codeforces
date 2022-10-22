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
	FAST_IO("1442D.inp", "1442D.out");
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

const int N = 3005;

#define int long long

int n, k, pref[N][N], sz[N], dp[N << 2][N], res;

#define ldp dp[id << 1]
#define rdp dp[id << 1 | 1]

void solve(int id, int tl, int tr) {
	if (tl == tr) {
		for (int j = 0; j <= k; j++) if (sz[tl] >= k - j)
			res = max(res, dp[id][j] + pref[tl][k - j]);
		return ;
	}
	int tm = tl + tr >> 1;
	for (int j = 0; j <= k; j++)
		ldp[j] = rdp[j] = dp[id][j];

	for (int x = tm + 1; x <= tr; x++)
		for (int j = k; j >= sz[x]; j--)
			ldp[j] = max(ldp[j], ldp[j - sz[x]] + pref[x][sz[x]]);

	for (int x = tl; x <= tm; x++)
		for (int j = k; j >= sz[x]; j--)
			rdp[j] = max(rdp[j], rdp[j - sz[x]] + pref[x][sz[x]]);

	solve(id << 1, tl, tm), solve(id << 1 | 1, tm + 1, tr);
}

void Hollwo_Pelw() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> sz[i];
		for (int j = 1, a; j <= sz[i]; j++) {
			cin >> a;
			if (j <= k) pref[i][j] = pref[i][j - 1] + a;
		}
	}
	solve(1, 1, n);
	cout << res << '\n';
}