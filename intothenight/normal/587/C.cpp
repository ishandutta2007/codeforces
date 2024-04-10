#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T, typename BO>
struct binary_lift{
	int N, root, lg;
	BO bin_op;
	const T id;
	vector<T> val;
	vector<vector<pair<int, T>>> adj, up;
	vector<int> depth;
	binary_lift(int N, int root, const vector<T> &val, BO bin_op, T id): N(N), root(root), bin_op(bin_op), id(id), lg(32 - __builtin_clz(N)), depth(N), val(val), adj(N), up(N, vector<pair<int, T>>(lg + 1)){ }
	void insert(int u, int v, T w){
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	void init(){ dfs(root, root, id); }
	void dfs(int u, int p, T w){
		up[u][0] = {p, bin_op(val[u], w)};
		for(int i = 1; i <= lg; ++ i) up[u][i] = {
			up[up[u][i - 1].first][i - 1].first
			, bin_op(up[u][i - 1].second, up[up[u][i - 1].first][i - 1].second)
		};
		for(auto &[v, x]: adj[u]) if(v != p){
			depth[v] = depth[u] + 1;
			dfs(v, u, x);
		}
	}
	pair<int, T> trace_up(int u, int dist){ // Node, Distance (Does not include weight of the node)
		T res = id;
		dist = min(dist, depth[u] - depth[root]);
		for(int d = lg; d >= 0; -- d) if(dist & (1 << d)){
			res = bin_op(res, up[u][d].second), u = up[u][d].first;
		}
		return {u, res};
	}
	pair<int, T> query(int u, int v){ // LCA, Query Value
		if(depth[u] < depth[v]) swap(u, v);
		T res;
		tie(u, res) = trace_up(u, depth[u] - depth[v]);
		for(int d = lg; d >= 0; -- d) if(up[u][d].first != up[v][d].first){
			res = bin_op(res, up[u][d].second), u = up[u][d].first;
			res = bin_op(res, up[v][d].second), v = up[v][d].first;
		}
		if(u != v) res = bin_op(bin_op(res, up[u][0].second), up[v][0].second), u = up[u][0].first;
		return {u, bin_op(res, val[u])};
	}
	int dist(int u, int v){
		return depth[u] + depth[v] - 2 * depth[query(u, v).first];
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	typedef array<int, 10> T;
	vector<int> temp(20);
	auto bin_op = [&](T x, T y){
		for(int i = 0; i < 10; ++ i){
			temp[i] = x[i];
		}
		for(int j = 0; j < 10; ++ j){
			temp[j + 10] = y[j];
		}
		sort(temp.begin(), temp.end());
		T res;
		for(int i = 0; i < 10; ++ i){
			res[i] = temp[i];
		}
		return res;
	};
	const int inf = numeric_limits<int>::max();
	T id;
	fill(id.begin(), id.end(), inf);
	int n, m, q;
	cin >> n >> m >> q;
	vector<pair<int, int>> edge(n - 1);
	for(int i = 0; i < n - 1; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		edge[i] = {u, v};
	}
	vector<T> t(n, id);
	for(int i = 0; i < m; ++ i){
		int u;
		cin >> u, -- u;
		T nt(id);
		nt[0] = i;
		t[u] = bin_op(t[u], nt);
	}
	binary_lift lift(n, 0, t, bin_op, id);
	for(auto [u, v]: edge){
		lift.insert(u, v, id);
	}
	lift.init();
	while(q --){
		int u, v, a;
		cin >> u >> v >> a, -- u, -- v;
		T res = lift.query(u, v).second;
		while(a && res[a - 1] == inf){
			-- a;
		}
		cout << a << " ";
		for(int i = 0; i < a; ++ i){
			cout << res[i] + 1 << " ";
		}
		cout << "\n";
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