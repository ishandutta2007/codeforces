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
	FAST_IO("1498F.inp", "1498F.out");
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

const int N = 1e5 + 5, K = 22;

int n, k, dp[N][K << 1], res[N], a[N]; // dp[i][j] -> xor in subtree i, j = (x * k + y) with (x -> odd-even pos of depth y)
vector<int> adj[N];

inline int nxt(int a) { if (++ a >= 2 * k) a = 0; return a; }

void pre_dfs(int u, int p) {
	dp[u][0] = a[u];
	for (auto v : adj[u]) if (v != p) {
		pre_dfs(v, u);
		for (int j = 0; j < 2 * k; j++)
			dp[u][nxt(j)] ^= dp[v][j];
	}
}

inline void reroot(int u, int v) {
	for (int i = 0; i < 2 * k; i++)
		dp[v][nxt(i)] ^= dp[u][i];
	for (int i = 0; i < 2 * k; i++)
		dp[u][nxt(i)] ^= dp[v][i];
}

void dfs(int u, int p) {
	for (int i = k; i < 2 * k; i++)
		res[u] ^= dp[u][i];
	// cout << u << ' ' << res[u] << "\n";
	for (auto v : adj[u]) if (v != p) {
		reroot(v, u);
		dfs(v, u);
		reroot(u, v);
	}
}

void Hollwo_Pelw() {
	cin >> n >> k;
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	for (int i = 1; i <= n; i++) cin >> a[i];
	pre_dfs(1, 1), dfs(1, 1);
	for (int i = 1; i <= n; i++)
		cout << (bool) res[i] << ' ';
}