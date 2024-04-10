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

const int N = 5e5 + 5;
 
int n, nnode, rev[N], vis[N];
map<int, int> mp;
map<pair<int, int>, vector<pair<int, int>>> edge;
string res[N];
 
set<tuple<int, int, int>> adj[N];
vector<int> ans;
 
void dfs(int u) {
	vis[u] = 1;
	while (adj[u].size()) {
		auto [v, i, j] = *adj[u].begin();
		adj[u].erase(adj[u].begin());
		adj[v].erase({u, i, j});
		dfs(v);
	}
	ans.push_back(u);
}
 
void Hollwo_Pelw() {
	cin >> n, nnode = n;
 
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		res[i] = string(k, '.');
		for (int j = 0, a; j < k; j++) {
			cin >> a;
			if (!mp.count(a)) {
				mp[a] = ++ nnode;
				rev[nnode] = a;
			}
			adj[mp[a]].emplace(i, i, j);
			adj[i].emplace(mp[a], i, j);
			edge[{mp[a], i}].emplace_back(i, j);
			edge[{i, mp[a]}].emplace_back(i, j);
		}
	}
 
	for (int i = 1; i <= nnode; i++)
		if (adj[i].size() & 1)
			return cout << "NO\n", (void) 0;
 
	for (int i = 1; i <= nnode; i++)
		if (!vis[i]) {
			dfs(i);
			for (int j = 1; j < ans.size(); j++) {
				auto [x, y] = edge[{ans[j], ans[j - 1]}].back();
				edge[{ans[j], ans[j - 1]}].pop_back();
				edge[{ans[j - 1], ans[j]}].pop_back();
				
				if (ans[j] <= n)
					res[x][y] = 'L';
				else
					res[x][y] = 'R';
 
				// cout << (ans[j] <= n ? ans[j] : rev[ans[j]]) << " ";
			}
			// cout << "\n";
			ans.clear();
		}
	cout << "YES\n";
	for (int i = 1; i <= n; i++)
		cout << res[i] << '\n';
}