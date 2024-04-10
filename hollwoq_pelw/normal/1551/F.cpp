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
	cin >> testcases;
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

const int N = 101, mod = 1e9 + 7;

int n, k, res, cnt[N], C[N][N];
vector<int> adj[N];

struct __init__ {
	__init__ () {
		C[0][0] = 1;
		for (int i = 1; i < N; i++) {
			C[i][0] = C[i][i] = 1;
			for (int j = 1; j < i; j++)
				C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		}
	}
} __init__;

void dfs(int u, int p, int d = 1) {
	cnt[d] ++;
	for (auto v : adj[u])
		if (v != p) dfs(v, u, d + 1);
}

int dp[N][N];

void solve(int r) {
	if (adj[r].size() < k) return ;
	memset(dp, 0, sizeof dp);
	for (int i = 1; i <= n; i++)
		dp[i][0] = 1;
	for (auto u : adj[r]) {
		for (int i = 1; i <= n; i++) 
			cnt[i] = 0;
		dfs(u, r);
		for (int i = 1; i <= n; i++)
			for (int j = k; j >= 1; j--)
				(dp[i][j] += 1ll * dp[i][j - 1] * cnt[i] % mod) %= mod;
	}
	for (int i = 1; i <= n; i++)
		(res += dp[i][k]) %= mod;
}

void Hollwo_Pelw() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) adj[i].clear();
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	if (k == 2) 
		return cout << n * (n - 1) / 2 << '\n', (void) 0;
	res = 0;
	for (int i = 1; i <= n; i++)
		solve(i);
	cout << res << '\n';
}