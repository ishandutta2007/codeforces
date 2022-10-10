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
	int n, k;
	cin >> n >> k;
	vector<vector<int>> adj(n);
	for(int i = 1; i < n; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	vector<int> prev(n), depth(n), deg(n);
	auto bfs = [&](int u){
		queue<array<int, 2>> q{{{u, u}}};
		depth[u] = 0;
		fill(deg.begin(), deg.end(), 0);
		int res;
		while(!q.empty()){
			auto [u, p] = q.front();
			res = u;
			q.pop();
			for(auto v: adj[u]){
				if(v != p){
					++ deg[u];
					prev[v] = u;
					depth[v] = depth[u] + 1;
					q.push({v, u});
				}
			}
		}
		return res;
	};
	int u = bfs(0), v = bfs(u);
	if((depth[v] - depth[u]) % 2){
		cout << "No\n";
		return 0;
	}
	vector<int> d;
	while(v != u){
		d.push_back(v);
		v = prev[v];
	}
	d.push_back(u);
	int c = d[int(d.size()) / 2];
	bfs(c);
	function<bool(int, int, int)> test = [&](int u, int p, int k){
		if(k && deg[u] < 3 || !k && deg[u]){
			return false;
		}
		for(auto v: adj[u]){
			if(v != p && !test(v, u, k - 1)){
				return false;
			}
		}
		return true;
	};
	test(c, c, k) ? cout << "Yes\n" : cout << "No\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////