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
	FAST_IO("1593E.inp", "1593E.out");
#endif
	int testcases = 1;
	cin >> testcases;
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

const int N = 4e5 + 5;

int deg[N], n, k, vis[N];
vector<int> adj[N];

void Hollwo_Pelw() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		adj[i].clear(), vis[i] = 0;
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	for (int i = 1; i <= n; i++)
		deg[i] = adj[i].size();
	vector<int> q;
	for (int i = 1; i <= n; i++)
		if (deg[i] <= 1) q.push_back(i), vis[i] = 1;

	while (k --) {
		vector<int> nq;
		for (auto v : q) {
			vis[v] = 2;
			for (auto u : adj[v]) {
				if ((-- deg[u]) <= 1) {
					if (!vis[u]) 
						nq.push_back(u), vis[u] = 1;
				}
			}
		}
		q = nq;
		if (q.empty()) break ;
	}

	int res = 0;
	for (int i = 1; i <= n; i++)
		if (vis[i] < 2) ++ res;
	cout << res << '\n';
}