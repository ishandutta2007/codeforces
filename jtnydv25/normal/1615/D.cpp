#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...) // remove in interactive
#define endl '\n'
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<vector<pii>> adj(n);
		vector<pii> edges(n - 1);
		vector<int> cols(n, -1);
		vector<int> orig(n);
		for(int i = 0; i + 1 < n; i++){
			cin >> edges[i].first >> edges[i].second;
			int v; cin >> v;
			edges[i].first--; edges[i].second--;
			orig[i] = v;
			if(v >= 0){
				int p  = __builtin_popcount(v) % 2;
				adj[edges[i].first].push_back({edges[i].second, p});
				adj[edges[i].second].push_back({edges[i].first, p});
			}
		}

		for(int i = 0; i < m; i++){
			int u, v, p;
			cin >> u >> v >> p;
			u--; v--;
			adj[u].push_back({v, p});
			adj[v].push_back({u, p});
		}
		bool error = false;
		function<void(int, int)> dfs = [&](int s, int col){
			cols[s] = col;
			for(auto it: adj[s]){
				int v = it.first, _col = col ^ it.second;
				if(cols[v] != -1){
					if(cols[v] != _col) error = true;
					continue;
				}
				dfs(v, _col);
			}
		};
		for(int v = 0; v < n; v++) if(cols[v] == -1) dfs(v, 1);

		if(error){
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		for(int i = 0; i + 1 < n; i++){
			int u = edges[i].first, v = edges[i].second;
			cout << u + 1 << " " << v + 1 << " ";
			cout << (orig[i] != -1 ? orig[i] : (cols[u] ^ cols[v])) << endl;
		}
	}
}