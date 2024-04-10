#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
 
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int tt;
	cin >> tt;
	while(tt --){
		string s;
		cin >> s;
		bool ok = true;
		vector<vector<int>> adj(26);
		for(int i = 1; i < int(s.size()); ++ i){
			if(s[i] == s[i - 1]){
				ok = false;
				break;
			}
			else{
				adj[s[i] - 'a'].push_back(s[i - 1] - 'a');
				adj[s[i - 1] - 'a'].push_back(s[i] - 'a');
			}
		}
		for(int i = 0; i < 26; ++ i){
			sort(adj[i].begin(), adj[i].end()), adj[i].resize(unique(adj[i].begin(), adj[i].end()) - adj[i].begin());
			if(adj[i].size() > 2){
				ok = false;
				break;
			}
		}
		if(!ok){
			cout << "NO\n";
			continue;
		}
		string res;
		vector<int> used(26);
		function<void(int, int)> dfs = [&](int u, int p){
			res.push_back(u + 'a');
			used[u] = true;
			for(auto v: adj[u]){
				if(v != p){
					dfs(v, u);
				}
			}
		};
		for(int i = 0; i < 26; ++ i){
			if(!used[i] && adj[i].size() == 1){
				dfs(i, i);
			}
		}
		for(int i = 0; i < 26; ++ i){
			if(!used[i] && adj[i].size() >= 2){
				ok = false;
				break;
			}
			if(!used[i]){
				res.push_back(i + 'a');
			}
		}
		ok ? cout << "YES\n" << res << "\n" : cout << "NO\n";
	}
	return 0;
}
 
/*
 
*/
 
////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////