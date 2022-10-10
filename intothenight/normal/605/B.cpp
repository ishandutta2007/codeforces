#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<array<int, 3>> edges(m);
	for(auto i = 0; i < m; ++ i){
		cin >> edges[i][0] >> edges[i][1], edges[i][1] = -edges[i][1], edges[i][2] = i;
	}
	sort(edges.begin(), edges.end());
	vector<array<int, 2>> res(m);
	vector<int> adj(n);
	for(auto i = 0, u = 0, cnt = 1; i < m; ++ i){
		if(!edges[i][1]){
			if(u + 2 + adj[u] >= cnt){
				cout << "-1\n";
				return 0;
			}
			res[edges[i][2]] = {u, u + 2 + adj[u]};
			++ adj[u];
			if(u + 2 + adj[u] == cnt){
				++ u;
			}
		}
		else{
			res[edges[i][2]] = {cnt - 1, cnt};
			u = 0;
			++ cnt;
		}
	}
	for(auto [u, v]: res){
		cout << u + 1 << " " << v + 1 << "\n";
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