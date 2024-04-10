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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	vector<int> topic(n);
	for(auto u = 0; u < n; ++ u){
		cin >> topic[u], -- topic[u];
	}
	auto cmp = [&](int u, int v){
		return topic[u] < topic[v];
	};
	for(auto u = 0; u < n; ++ u){
		sort(adj[u].begin(), adj[u].end(), cmp);
		int x = 0;
		for(auto v: adj[u]){
			if(topic[v] == x){
				++ x;
			}
		}
		if(x != topic[u]){
			cout << "-1\n";
			return 0;
		}
	}
	vector<int> res(n);
	iota(res.begin(), res.end(), 0);
	sort(res.begin(), res.end(), cmp);
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