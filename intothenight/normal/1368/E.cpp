#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int SOLVE(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v);
	}
	vector<int> q(n, 2), res;
	for(auto u = 0; u < n; ++ u){
		if(q[u]){
			for(auto v: adj[u]){
				ctmin(q[v], q[u] - 1);
			}
		}
		else{
			res.push_back(u);
		}
	}
	cout << int(res.size()) << "\n";
	for(auto u: res){
		cout << u + 1 << " ";
	}
	cout << "\n";
	return 0;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int ttt;
	cin >> ttt;
	while(ttt --){
		SOLVE();
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