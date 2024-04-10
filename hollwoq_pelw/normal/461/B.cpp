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
		FAST_IO("DISENTR.inp", "DISENTR.out");
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

const int N = 1e5 + 5, mod = 1e9 + 7;

#define int long long

int n, c[N], dp[N][2];
vector<int> adj[N];

void dfs(int u){
	dp[u][0] = 1;
	for (auto v : adj[u]) {
		dfs(v);
		dp[u][1] = (dp[u][0] * dp[v][1] + dp[u][1] * (dp[v][0] + dp[v][1])) % mod;
		dp[u][0] = dp[u][0] * (dp[v][0] + dp[v][1]) % mod;
	}
	if (c[u])
		dp[u][1] = dp[u][0], dp[u][0] = 0;
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, p; i < n; i++)
		cin >> p, adj[p].push_back(i);
	for (int i = 0; i < n; i++) 
		cin >> c[i];
	dfs(0);
	cout << dp[0][1];
}