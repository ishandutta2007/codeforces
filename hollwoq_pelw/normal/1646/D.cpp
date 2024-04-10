/*-------------------------------/ 
      hollwo_pelw's template     
/-------------------------------*/

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

void FAST_IO(string filein = "", string fileout = ""){
	if (fopen(filein.c_str(), "r")){
		freopen(filein.c_str(), "r", stdin);
		freopen(fileout.c_str(), "w", stdout);
	}
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
#ifdef hollwo_pelw_local
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
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

const int N = 2e5 + 5;

vector<int> adj[N];
struct node_t {
	int cnt, sum;
	bool operator < (const node_t &o) const {
		return cnt < o.cnt || (cnt == o.cnt && sum > o.sum);
	}
} dp[N][2];

int n, w[N], b[N];

void solve(int u, int p) {
	dp[u][0] = {0, 1};
	dp[u][1] = {1, (int) adj[u].size()};

	for (int v : adj[u]) if (v != p) {
		solve(v, u);
		
		dp[u][1].cnt += dp[v][0].cnt;
		dp[u][1].sum += dp[v][0].sum;

		dp[u][0].cnt += dp[v][b[v]].cnt;
		dp[u][0].sum += dp[v][b[v]].sum;
	}
	b[u] = dp[u][0] < dp[u][1];
}

void trace(int u, int p, int t) {
	w[u] = t ? adj[u].size() : 1;
	for (int v : adj[u]) if (v != p)
		trace(v, u, t ? 0 : b[v]);
}

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	if (n == 2)
		return cout << "2 2\n1 1\n", (void) 0;

	solve(1, 0);

	cout << dp[1][b[1]].cnt << ' ' << dp[1][b[1]].sum << '\n';

	trace(1, 0, b[1]);
	for (int i = 1; i <= n; i++)
		cout << w[i] << " \n"[i == n];

}