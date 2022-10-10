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

template<typename T, typename BO>
struct sparse_table{
	int n;
	BO bin_op;
	T id;
	vector<vector<T>> val;
	template<typename IT>
	sparse_table(IT begin, IT end, BO bin_op, T id): n(distance(begin, end)), bin_op(bin_op), id(id), val(1, {begin, end}){
		for(int p = 1, i = 1; p << 1 <= n; p <<= 1, ++ i){
			val.emplace_back(n - (p << 1) + 1);
			for(int j = 0; j < int(val[i].size()); ++ j) val[i][j] = min(val[i - 1][j], val[i - 1][j + p]);
		}
	}
	sparse_table(){ }
	T query(int l, int r){
		if(l >= r) return id;
		int d = __lg(r - l);
		return bin_op(val[d][l], val[d][r - (1 << d)]);
	}
};
struct lca{
	int n, T = 0;
	vector<int> time, depth, path, res;
	sparse_table<int, function<int(int, int)>> rmq;
	template<typename Graph>
	lca(const Graph &adj, int root = 0): n(int(adj.size())), time(n), depth(n){
		dfs(adj, root, root);
		rmq = {res.begin(), res.end(), [&](int x, int y){ return min(x, y); }, numeric_limits<int>::max() / 2};
	}
	template<typename Graph>
	void dfs(const Graph &adj, int u, int p){
		time[u] = T ++;
		for(auto v: adj[u]) if(v != p){
			path.push_back(u), res.push_back(time[u]), depth[v] = depth[u] + 1;
			dfs(adj, v, u);
		}
	}
	int query(int u, int v){
		if(u == v) return u;
		tie(u, v) = minmax(time[u], time[v]);
		return path[rmq.query(u, v)];
	}
	long long dist(int u, int v){ return depth[u] + depth[v] - 2 * depth[query(u, v)]; }
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> w(n), type(n, -1);
	int cntb = 0, cntc = 0;
	for(auto u = 0; u < n; ++ u){
		int b, c;
		cin >> w[u] >> b >> c;
		cntb += b, cntc += c;
		if(b ^ c) type[u] = b < c;
	}
	if(cntb != cntc){
		cout << "-1\n";
		return 0;
	}
	vector<vector<int>> adj(n);
	for(int i = 1; i < n; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	lca lca(adj);
	long long res = 0;
	function<array<int, 2>(int, int)> dfs = [&](int u, int p)->array<int, 2>{
		array<int, 2> cur{};
		if(~type[u]) ++ cur[type[u]];
		for(auto v: adj[u]){
			if(v != p){
				ctmin(w[v], w[u]);
				auto [x, y] = dfs(v, u);
				cur[0] += x, cur[1] += y;
			}
		}
		int x = min(cur[0], cur[1]);
		res += 2LL * x * w[u];
		return {cur[0] - x, cur[1] - x};
	};
	dfs(0, 0);
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