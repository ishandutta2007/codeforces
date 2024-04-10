#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int tt;
	cin >> tt;
	while(tt --){
		int n, d;
		cin >> n >> d;
		vector<vector<int>> depth(n);
		int cur = n * (n - 1) / 2;
		if(cur < d){
			cout << "NO\n";
			continue;
		}
		cur = 0;
		for(int i = 0; i < n; ++ i){
			cur += __lg(i + 1);
		}
		if(cur > d){
			cout << "NO\n";
			continue;
		}
		cur = n * (n - 1) / 2 - d;
		depth[0].push_back(0);
		for(int i = 1; i < n; ++ i){
			depth[i].push_back(i);
		}
		int lvl = 1; // Unfilled level
		while(cur){ // Process each depth
			int curlvl = int(depth.size()) - 1;
			while(cur && !depth.back().empty()){
				int u = depth.back().back();
				depth.back().pop_back();
				if(cur >= curlvl - lvl){
					cur -= (curlvl - lvl);
					depth[lvl].push_back(u);
					if(depth[lvl].size() == 1 << lvl){
						++ lvl;
					}
				}
				else{
					depth[curlvl - cur].push_back(u);
					cur = 0;
				}
			}
			if(cur) depth.pop_back();
		}
		vector<int> par(n, -1), cnt(n);
		for(int d = 1; d < (int)depth.size(); ++ d){
			int pi = 0;
			for(auto u: depth[d]){
				int v = depth[d - 1][pi];
				par[u] = v;
				++ cnt[v];
				if(cnt[v] == 2){
					++ pi;
				}
			}
		}
		cout << "YES\n";
		for(int u = 1; u < n; ++ u){
			cout << 1 + par[u] << " ";
		}
		cout << "\n";
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