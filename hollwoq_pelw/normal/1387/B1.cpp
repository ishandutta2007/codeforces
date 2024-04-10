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

const int N = 1e5 + 5;

int n, ok[N], res[N], ans;
vector<int> adj[N];

void doswap(int u, int v) {
	swap(res[u], res[v]), ans += 2, ok[u] = ok[v] = 1;
}

void dfs(int u, int p) {
	for (auto v : adj[u]) if (v != p) {
		dfs(v, u);
		if (!ok[v])
			doswap(u, v);
	}
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++) res[i] = i;
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	dfs(1, 1); 

	if (!ok[1])
		doswap(1, adj[1][0]);

	cout << ans << '\n';
	for (int i = 1; i <= n; i++)
		cout << res[i] << ' ';
}