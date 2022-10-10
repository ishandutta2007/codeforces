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
	vector<vector<int>> adj(n);
	for(int i = 1; i < n; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	vector<int> a(n), b(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	for(auto i = 0; i < n; ++ i){
		cin >> b[i];
	}
	vector<int> res;
	function<void(int, int, int, int)> dfs = [&](int u, int p, int flip0, int flip1){
		if(flip0 ^ a[u] ^ b[u]){
			res.push_back(u);
			flip0 ^= 1;
		}
		for(auto v: adj[u]){
			if(v != p){
				dfs(v, u, flip1, flip0);
			}
		}
	};
	dfs(0, 0, 0, 0);
	cout << int(res.size()) << "\n";
	for(auto u: res){
		cout << u + 1 << " ";
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