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

const int N = 5e4 + 5, B = 255;

int n, q, dp[N][1 << 8], par[N], anc[N], dep[N], a[N];
vector<int> adj[N];

inline bool chkmax(int &a, int b) {
	return a < b ? a = b, 1 : 0;
}

void dfs(int u, int d = 1) {
	dep[u] = d;
	for (auto v : adj[u]) if (v != par[u]) {
		par[v] = u;
		dfs(v, d + 1);
	}
	if (d > B) {
		for (int mask = 0, x = u, v; mask < 1 << 8; mask++) {
			v = mask ^ a[x], anc[u] = (x = par[x]);
			chkmax(dp[u][(v >> 8) ^ B], (B << 8) | v);
		}
		for (int i = 0; i < 8; i++) 
			for (int mask = 0; mask < 1 << 8; mask ++)
				chkmax(dp[u][mask], dp[u][mask ^ 1 << i] - (1 << 8 + i));
	}
}

void Hollwo_Pelw() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	dfs(1);
	for (int _ = 0, u, v, d; _ < q; _++) {
		cin >> u >> v, d = dep[v] - dep[u] + 1;
		int ans = 0;
		for (int i = 0; i < d >> 8; i++)
			chkmax(ans, dp[v][i]), v = anc[v];
		for (int i = d >> 8 << 8; i < d; i++)
			chkmax(ans, i ^ a[v]), v = par[v];
		cout << ans << '\n';
	}
}