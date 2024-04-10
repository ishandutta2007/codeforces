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
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename Graph>
vector<int> toposort(const Graph &adj){
	int n = int(adj.size());
	vector<int> indeg(n), res;
	for(int u = 0; u < n; ++ u) for(auto v: adj[u]) ++ indeg[v];
	deque<int> q;
	for(int u = 0; u < n; ++ u) if (!indeg[u]) q.push_back(u);
	while(q.size() > 0){
		int u = q.front();
		q.pop_front();
		res.push_back(u);
		for(auto v: adj[u]) if (!(-- indeg[v])) q.push_back(v);
	}
	return res;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n), radj(n);
	for(int i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), radj[v].push_back(u);
	}
	if(toposort(adj).size() < n){
		cout << -1;
		return 0;
	}
	vector<int> dedx(n), dedy(n);
	function<void(int)> dfs_x = [&](int u){
		dedx[u] = true;
		for(auto v: adj[u]){
			if(!dedx[v]){
				dfs_x(v);
			}
		}
	};
	function<void(int)> dfs_y = [&](int u){
		dedy[u] = true;
		for(auto v: radj[u]){
			if(!dedy[v]){
				dfs_y(v);
			}
		}
	};
	int cnt = 0;
	string res(n, 'E');
	for(auto u = 0; u < n; ++ u){
		if(!dedx[u] && !dedy[u]){
			++ cnt;
			res[u] = 'A';
		}
		if(!dedx[u]){
			dfs_x(u);
		}
		if(!dedy[u]){
			dfs_y(u);
		}
	}
	cout << cnt << "\n" << res << "\n";
	return 0;
}

/*
AAAAAAAAAAEAAAAAEEEAAEAAAEAAAEAAAAEAAAEAEEAAEEAAAEAEAAEAEEAAEAEEEEEAAAAAAEAAEAEAEAEEAEAEEAAAAEAAEAAE
AAAAAAAAAAEAAAAAEEEAAEAAAEAAAEAAAEEAAAEAEEAAEEAAAEAEAEEAEEAAEAEEEEEAAAAEAEAAEAEAEAEEAEAEEAAAEEAAEEAE
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////