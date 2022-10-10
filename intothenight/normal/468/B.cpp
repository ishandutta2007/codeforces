#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> cmpr, p(n);
	for(auto i = 0; i < n; ++ i){
		cin >> p[i];
		cmpr.push_back(p[i]);
	}
	sort(cmpr.begin(), cmpr.end()), cmpr.erase(unique(cmpr.begin(), cmpr.end()), cmpr.end());
	int mx = (int)cmpr.size();
	vector<vector<int>> ind(mx);
	for(auto i = 0; i < n; ++ i){
		ind[lower_bound(cmpr.begin(), cmpr.end(), p[i]) - cmpr.begin()].push_back(i);
	}
	vector<vector<int>> adj(mx);
	for(auto i = 0; i < mx; ++ i){
		if(auto it = lower_bound(cmpr.begin(), cmpr.end(), a - cmpr[i]); it != cmpr.end() && *it == a - cmpr[i]){
			adj[i].push_back(it - cmpr.begin());
		}
		if(auto it = lower_bound(cmpr.begin(), cmpr.end(), b - cmpr[i]); it != cmpr.end() && *it == b - cmpr[i]){
			adj[i].push_back(it - cmpr.begin());
		}
	}
	if(a == b){
		for(auto i = 0; i < mx; ++ i){
			if(cmpr[i] * 2 != a){
				if(adj[i].empty()){
					cout << "NO\n";
					return 0;
				}
			}
		}
		cout << "YES\n";
		for(auto i = 0; i < n; ++ i){
			cout << "0 ";
		}
		cout << "\n";
		return 0;
	}
	auto deg = [&](int i){
		return (int)adj[i].size();
	};
	vector<int> res(n);
	for(auto i = 0; i < mx; ++ i){
		if(!ind[i].empty()){
			if(deg(i) == 0){
				cout << "NO\n";
				return 0;
			}
			else if(deg(i) == 1){
				vector<int> path;
				function<void(int, int)> dfs = [&](int i, int pi){
					path.push_back(i);
					for(auto j: adj[i]){
						if(j != pi && i != j){
							dfs(j, i);
						}
					}
				};
				dfs(i, i);
				if((int)path.size() & 1){
					if(cmpr[path.back()] * 2 == a || cmpr[path.back()] * 2 == b){
						for(auto t: ind[path.back()]){
							res[t] = cmpr[path.back()] * 2 == b;
						}
						path.pop_back();
						for(auto i: path){
							for(auto t: ind[i]){
								res[t] = cmpr[path[0]] + cmpr[path[1]] == b;
							}
						}
					}
					else{
						int i = 1;
						while(i < (int)path.size() && (int)ind[path[i]].size() == 1){
							i += 2;
						}
						if(i == (int)path.size()){
							cout << "NO\n";
							return 0;
						}
						int type = cmpr[path[0]] + cmpr[path[1]] == b;
						for(auto j = 0; j < i; ++ j){
							for(auto t: ind[j]){
								res[t] = type;
							}
						}
						res[ind[i].back()] = type;
						ind[i].pop_back();
						path.erase(path.begin(), path.begin() + i);
						for(auto i: path){
							for(auto t: ind[i]){
								res[t] = cmpr[path[0]] + cmpr[path[1]] == b;
							}
						}
					}
				}
				else{
					for(auto i: path){
						for(auto t: ind[i]){
							res[t] = cmpr[path[0]] + cmpr[path[1]] == b;
						}
					}
				}
			}
		}
	}
	cout << "YES\n";
	for(auto x: res){
		cout << x << " ";
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