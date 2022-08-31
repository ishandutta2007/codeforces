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
		int n; cin >> n;
		vector<vector<int>> adj(n+1);
		// vector<vector<int>> msb(20);
		vector<int> MSB(n + 1);
		for(int i=1; i <= n; i++){
			for(int j = 20; j >= 0; j--){
				if(i >> j & 1){
					// msb[j].push_back(i);
					MSB[i] = j;
					break;
				}
			}
		}
		for(int i = 1; i < n; i++){
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vector<int> perm(n + 1);
		vector<vector<int>> nodes(2);
		function<void(int, int, int)> dfs = [&](int s, int p, int d){
			nodes[d].push_back(s);
			for(int v: adj[s]) if(v != p){
				dfs(v, s, d ^ 1);
			}
		};
		dfs(1, 1, 0);
		int k = sz(nodes[0]) > sz(nodes[1]);
		vector<int> pos = {0, 0};
		int K = sz(nodes[k]);
		// trace(nodes, K);
		for(int i = 1; i <= n; i++){
			int id = K >> MSB[i] & 1 ? k : k ^ 1;
			// trace(i, id);
			perm[nodes[id][pos[id]++]] = i;
		}
		for(int i = 1; i <= n; i++) cout << perm[i] << " ";
		cout << endl;
	}
}