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

const int N = 4005;

int n, m, a[N], sz[N], lf[N], rt[N];
long long dp[N][N];

void dfs(int u) {
	sz[u] = 1;
	for (auto v : {lf[u], rt[u]}) if (v) {
		int w = a[v] - a[u];
		dfs(v);
		for (int i = min(m, sz[u]); i >= 0; i--)
			for (int j = min(m, sz[v]); j >= 0; j--)
				dp[u][i + j] = max(dp[u][i + j], 
					dp[u][i] + dp[v][j] + 1ll * j * (m - j) * w);
		sz[u] += sz[v];
	}
}

void Hollwo_Pelw() {
	static int st[N], top;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int cur = top;
		while (cur && a[i] < a[st[cur]]) cur --;
		
		if (cur > 0)
			lf[st[cur + 0]] = i;
		if (cur < top)
			rt[i] = st[cur + 1];

		st[++ cur] = i, top = cur;
	}

	dfs(st[1]);
	cout << dp[st[1]][m];
}