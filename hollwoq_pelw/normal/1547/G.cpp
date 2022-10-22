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

const int N = 4e5 + 5;

vector<int> adj[N];
int n, m, res[N], vis[N];

void dfs(int u, int t) {
	if (t) 
		res[u] = -1;
	else if (res[u] < 2)
		res[u] ++;
	vis[u] = 1;
	for (auto v : adj[u]) if (res[v] != -1) {
		if (vis[v]) 
			dfs(v, 1);
		else if (res[v] < 2 || res[v] == 2 && t)
			dfs(v, t);
	}
	vis[u] = 0;
}

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		adj[i].clear(), vis[i] = res[i] = 0;
	for (int i = 1, u, v; i <= m; i++)
		cin >> u >> v, adj[u].push_back(v);
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		cout << res[i] << " \n"[i == n];
}