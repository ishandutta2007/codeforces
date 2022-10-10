#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	const int mx = 15, full_mask = (1 << mx) - 1;
	vector<int> dist(1 << mx, -1);
	vector<vector<int>> adj(1 << mx);
	for(auto u = 0; u < 1 << mx; ++ u){
		adj[u + 1 & full_mask].push_back(u);
		adj[u << 1 & full_mask].push_back(u);
	}
	dist[0] = 0;
	deque<int> dq{0};
	while(!dq.empty()){
		int u = dq.front();
		dq.pop_front();
		for(auto v: adj[u]){
			if(!~dist[v]){
				dist[v] = dist[u] + 1;
				dq.push_back(v);
			}
		}
	}
	int n;
	cin >> n;
	for(auto i = 0; i < n; ++ i){
		int u;
		cin >> u;
		cout << dist[u] << " ";
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