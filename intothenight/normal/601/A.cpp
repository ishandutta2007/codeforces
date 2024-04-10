#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adjm(n, vector<int>(n));
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adjm[u][v] = adjm[v][u] = true;
	}
	int t = !adjm[0][n - 1];
	vector<int> vis(n, -1);
	deque<int> dq{0};
	vis[0] = 0;
	while(!dq.empty()){
		int u = dq.front(); dq.pop_front();
		for(auto v = 0; v < n; ++ v){
			if(u != v && adjm[u][v] == t && !~vis[v]){
				vis[v] = vis[u] + 1;
				dq.push_back(v);
			}
		}
	}
	cout << vis[n - 1] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////