#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> deg(n);
	vector<vector<int>> adj(n);
	for(auto i = 1; i < n; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		++ deg[u], ++ deg[v];
		adj[u].push_back(v), adj[v].push_back(u);
	}
	if(x >= y){
		if(any_of(deg.begin(), deg.end(), [&](auto d){ return d == n - 1; })){
			cout << 1LL * (n - 2) * y + x << "\n";
		}
		else{
			cout << 1LL * (n - 1) * y << "\n";
		}
	}
	else{
		vector<int> zero(n), one(n, -n), two(n, -n);
		function<void(int, int)> dfs = [&](int u, int p){
			for(auto v: adj[u]){
				if(v ^ p){
					dfs(v, u);
					ctmax(two[u], max(two[u] + max({zero[v], one[v], two[v]}), one[u] + 1 + max(zero[v], one[v])));
					ctmax(one[u], max(one[u] + max({zero[v], one[v], two[v]}), zero[u] + 1 + max(zero[v], one[v])));
					ctmax(zero[u], zero[u] + max({zero[v], one[v], two[v]}));
				}
			}
		};
		dfs(0, -1);
		int mx = max({zero[0], one[0], two[0]});
		cout << 1LL * mx * x + 1LL * (n - 1 - mx) * y << "\n";
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