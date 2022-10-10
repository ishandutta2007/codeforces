#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> words(n);
	for(auto i = 0; i < n; ++ i){
		int k;
		cin >> k;
		for(auto j = 0; j < k; ++ j){
			int x;
			cin >> x, -- x;
			words[i].push_back(x);
		}
	}
	vector<vector<int>> adj(m);
	for(auto i = 1; i < n; ++ i){
		int len = min(int(words[i - 1].size()), int(words[i].size()));
		if(equal(words[i - 1].begin(), words[i - 1].begin() + len, words[i].begin())){
			if(int(words[i - 1].size()) > int(words[i].size())){
				cout << "No\n";
				return 0;
			}
		}
		else{
			int j = 0;
			while(words[i - 1][j] == words[i][j]){
				++ j;
			}
			adj[words[i][j]].push_back(words[i - 1][j]);
		}
	}
	vector<int> flag(m);
	for(auto u = 0; u < m; ++ u){
		if(!flag[u]){
			for(auto v: adj[u]){
				if(!flag[v] && u < v){
					function<void(int)> dfs = [&](int u){
						flag[u] = true;
						for(auto v: adj[u]){
							if(u < v){
								cout << "No\n";
								exit(0);
							}
							else if(!flag[v]){
								dfs(v);
							}
						}
					};
					dfs(v);
				}
			}
		}
	}
	vector<int> res;
	for(auto u = 0; u < m; ++ u){
		if(flag[u]){
			res.push_back(u);
		}
	}
	cout << "Yes\n";
	cout << int(res.size()) << "\n";
	for(auto u: res){
		cout << u + 1 << " ";
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