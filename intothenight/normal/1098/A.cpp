#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/rope"
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
#define lambdify(x) [&](auto &&...args){ return x(forward<decltype(args)>(args)...); }
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> p(n);
	vector<vector<int>> adj(n);
	for(auto u = 1; u < n; ++ u){
		cin >> p[u], -- p[u];
		adj[p[u]].push_back(u);
	}
	vector<int> sum(n);
	for(auto u = 0; u < n; ++ u){
		cin >> sum[u];
	}
	long long res = sum[0];
	for(auto u = 0; u < n; ++ u){
		if(!~sum[u] && !adj[u].empty()){
			int low = numeric_limits<int>::max();
			for(auto v: adj[u]){
				ctmin(low, sum[v]);
			}
			if(low < sum[p[u]]){
				cout << "-1\n";
				return 0;
			}
			res += low - sum[p[u]];
			for(auto v: adj[u]){
				res += sum[v] - low;
			}
		}
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////