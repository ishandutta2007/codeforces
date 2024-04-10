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
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 5005, mod = 998244353;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline void sadd(int &a, int b) { a = a + b >= mod ? a + b - mod : a + b; }
inline int mul(int a, int b) { return 1ll * a * b % mod; }

int n, k, dp[N][N], ndp[N], sz[N];
vector<int> adj[N];

void dfs(int u, int p){
	dp[u][0] = sz[u] = 1;
	for (auto v : adj[u]) if (v != p) {
		dfs(v, u);
		for (int i = 0; i <= sz[u] + sz[v]; i++) ndp[i] = 0;
		for (int i = 0; i <= sz[u]; i++)
			for (int j = 0; j <= sz[v]; j++) {
				if (i + j + 1 <= k)
					sadd(ndp[max(i, j + 1)], mul(dp[u][i], dp[v][j]));
				sadd(ndp[i], mul(dp[u][i], dp[v][j]));
			}
		sz[u] += sz[v];
		for (int i = 0; i <= sz[u]; i++) dp[u][i] = ndp[i];
	}
}

void Hollwo_Pelw() {
	cin >> n >> k;
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	dfs(1, 1);
	int ans = 0;
	for (int i = 0; i <= n; i++)
		sadd(ans, dp[1][i]);
	cout << ans;
}