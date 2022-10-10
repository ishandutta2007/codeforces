#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](int __tc_num){
		int n;
		string a, b;
		cin >> n >> a >> b;
		vector<vector<int>> adj(20);
		for(auto i = 0; i < n; ++ i){
			int c = a[i] - 'a', d = b[i] - 'a';
			if(c > d){
				cout << "-1\n";
				return 0;
			}
			if(c != d){
				adj[c].push_back(d);
				adj[d].push_back(c);
			}
		}
		vector<int> vis(20);
		int res = 0;
		for(auto c = 0; c < 20; ++ c){
			if(!vis[c]){
				int cnt = 0;
				function<void(int)> dfs = [&](int c){
					vis[c] = true;
					++ cnt;
					for(auto d: adj[c]){
						if(!vis[d]){
							dfs(d);
						}
					}
				};
				dfs(c);
				res += cnt - 1;
			}
		}
		cout << res << "\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
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