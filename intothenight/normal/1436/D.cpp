#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	vector<int> is_leaf(n, true);
	for(auto u = 1; u < n; ++ u){
		int p;
		cin >> p, -- p;
		adj[p].push_back(u);
		is_leaf[p] = false;
	}
	vector<int> val(n);
	for(auto u = 0; u < n; ++ u){
		cin >> val[u];
	}
	vector<map<long long, int>> state(n);
	for(auto u = 0; u < n; ++ u){
		if(is_leaf[u]){
			state[u].insert({val[u], 1});
		}
	}
	function<void(int)> solve = [&](int u){
		if(!is_leaf[u]){
			int mxv = adj[u][0];
			for(auto v: adj[u]){
				solve(v);
				if((int)state[v].size() > (int)state[mxv].size()){
					mxv = v;
				}
			}
			swap(state[u], state[mxv]);
			for(auto v: adj[u]){
				for(auto [x, cnt]: state[v]){
					state[u][x] += cnt;
				}
			}
			long long sum = val[u];
			int cnt = 0;
			while(!state[u].empty() && (!cnt || cnt * state[u].begin()->first < sum + cnt - 1)){
				sum += state[u].begin()->first * state[u].begin()->second;
				cnt += state[u].begin()->second;
				state[u].erase(state[u].begin());
			}
			long long q = sum / cnt;
			int r = sum % cnt;
			state[u][q] += cnt - r;
			if(r){
				state[u][q + 1] += r;
			}
		}
	};
	solve(0);
	cout << state[0].rbegin()->first << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////