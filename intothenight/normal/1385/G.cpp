#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](){
		int n;
		cin >> n;
		vector<int> temp;
		array<vector<vector<int>>, 2> pos({vector<vector<int>>(n), vector<vector<int>>(n)});
		for(auto i = 0; i < 2; ++ i){
			for(auto j = 0; j < n; ++ j){
				int x;
				cin >> x, -- x;
				temp.push_back(x);
				pos[i][x].push_back(j);
			}
		}
		sort(temp.begin(), temp.end());
		for(auto i = 0; i < n << 1; ++ i){
			if(temp[i] != i >> 1){
				cout << "-1\n";
				return 0;
			}
		}
		vector<vector<int>> eadj(n), dadj(n);
		for(auto x = 0; x < n; ++ x){
			if(int(pos[0][x].size()) == 1){
				eadj[pos[0][x][0]].push_back(pos[1][x][0]);
				eadj[pos[1][x][0]].push_back(pos[0][x][0]);
			}
			for(auto i = 0; i < 2; ++ i){
				if(int(pos[i][x].size()) == 2){
					dadj[pos[i][x][0]].push_back(pos[i][x][1]);
					dadj[pos[i][x][1]].push_back(pos[i][x][0]);
				}
			}
		}
		vector<int> vis(n), res;
		for(auto u = 0; u < n; ++ u){
			if(!vis[u] && !dadj[u].empty()){
				array<vector<int>, 2> col;
				function<void(int, int)> dfs = [&](int u, int color){
					col[color].push_back(u);
					vis[u] = true;
					for(auto v: eadj[u]){
						if(!vis[v]){
							dfs(v, color);
						}
					}
					for(auto v: dadj[u]){
						if(!vis[v]){
							dfs(v, !color);
						}
					}
				};
				dfs(u, 0);
				for(auto u: *min_element(col.begin(), col.end(), [&](auto x, auto y){ return int(x.size()) < int(y.size()); })){
					res.push_back(u);
				}
			}
		}
		cout << int(res.size()) << "\n";
		for(auto u: res){
			cout << u + 1 << " ";
		}
		cout << "\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_it = 0; __tc_it < __tc_cnt; ++ __tc_it){
		__solve_tc();
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