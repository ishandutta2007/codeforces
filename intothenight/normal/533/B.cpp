#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	vector<long long> val(n);
	for(auto u = 0; u < n; ++ u){
		int p;
		cin >> p >> val[u], -- p;
		if(p >= 0){
			adj[p].push_back(u);
		}
	}
	vector<long long> x_even(n);
	vector<long long> x_odd(n, numeric_limits<long long>::min() / 2);
	vector<long long> o_even(n, numeric_limits<long long>::min() / 2);
	vector<long long> o_odd = val;
	function<void(int)> dfs = [&](int u){
		for(auto v: adj[u]){
			dfs(v);
			tie(x_even[u], x_odd[u], o_even[u], o_odd[u]) = tuple{
				max(x_even[u] + x_even[v], x_odd[u] + max(x_odd[v], o_odd[v])),
				max(x_odd[u] + x_even[v], x_even[u] + max(x_odd[v], o_odd[v])),
				max(o_even[u] + x_even[v], o_odd[u] + max(x_odd[v], o_odd[v])),
				max(o_odd[u] + x_even[v], o_even[u] + max(x_odd[v], o_odd[v]))
			};
		}
	};
	dfs(0);
	cout << max({x_even[0], x_odd[0], o_odd[0]}) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////