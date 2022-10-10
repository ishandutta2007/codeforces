#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for(auto u = 0; u < n; ++ u){
		int s;
		cin >> s;
		for(auto i = 0; i < s; ++ i){
			int c;
			cin >> c, -- c;
			g[u].push_back(c);
		}
	}
	vector<vector<int>> adj(n);
	for(auto i = 0; i < n - 1; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	int cnt = 0;
	vector<int> res(m, -1);
	function<void(int, int)> dfs = [&](int u, int p){
		vector<int> cur;
		for(auto c: g[u]){
			if(~res[c]){
				cur.push_back(res[c]);
			}
		}
		sort(cur.begin(), cur.end()), cur.erase(unique(cur.begin(), cur.end()), cur.end());
		int it = 0, col = 0;
		for(auto c: g[u]){
			if(!~res[c]){
				while(it < (int)cur.size() && cur[it] == col){
					++ it, ++ col;
				}
				res[c] = col ++;
			}
		}
		for(auto v: adj[u]){
			if(v ^ p){
				dfs(v, u);
			}
		}
	};
	dfs(0, -1);
	for(auto &x: res){
		if(!~x){
			x = 0;
		}
	}
	vector<int> temp = res;
	sort(temp.begin(), temp.end()), temp.erase(unique(temp.begin(), temp.end()), temp.end());
	cout << (int)temp.size() << "\n";
	for(auto x: res){
		cout << x + 1 << " ";
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////