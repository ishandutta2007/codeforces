#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct binary_lift{
	int N, lg;
	vector<vector<int>> adj, up;
	vector<int> depth;
	binary_lift(int N): N(N), lg(__lg(N) + 1), depth(N), adj(N), up(N, vector<int>(lg + 1)){ }
	void insert(int u, int v){
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	void init(){
		vector<int> visited(N);
		function<void(int, int)> dfs = [&](int u, int p){
			visited[u] = true;
			up[u][0] = p;
			for(int i = 1; i <= lg; ++ i) up[u][i] = up[up[u][i - 1]][i - 1];
			for(auto &v: adj[u]) if(!visited[v]){
				depth[v] = depth[u] + 1;
				dfs(v, u);
			}
		};
		for(int u = 0; u < N; ++ u) if(!visited[u]) dfs(u, u);
	}
	int lca(int u, int v){
		if(depth[u] < depth[v]) std::swap(u, v);
		u = trace_up(u, depth[u] - depth[v]);
		for(int d = lg; d >= 0; -- d) if(up[u][d] != up[v][d]) u = up[u][d], v = up[v][d];
		return u == v ? u : up[u][0];
	}
	int dist(int u, int v){
		return depth[u] + depth[v] - 2 * depth[lca(u, v)];
	}
	int trace_up(int u, int dist){
		dist = min(dist, depth[u]);
		for(int d = lg; d >= 0; -- d) if(dist & (1 << d)) u = up[u][d];
		return u;
	}
};

template<typename T, typename BO>
struct sparse_table{
	int N;
	BO bin_op;
	T id;
	vector<vector<T>> val;
	template<typename IT>
	sparse_table(IT begin, IT end, BO bin_op, T id): N(distance(begin, end)), bin_op(bin_op), id(id), val(__lg(N) + 1, vector<T>(begin, end)){
		for(int i = 0; i < __lg(N); ++ i) for(int j = 0; j < N; ++ j){
			val[i + 1][j] = bin_op(val[i][j], val[i][min(N - 1, j + (1 << i))]);
		}
	}
	sparse_table(){ }
	T query(int l, int r){
		if(l >= r) return id;
		int d = __lg(r - l);
		return bin_op(val[d][l], val[d][r - (1 << d)]);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, qq;
	cin >> n >> m >> qq;
	vector<int> p(n), a(m), prev(n);
	for(auto i = 0; i < n; ++ i){
		cin >> p[i], -- p[i];
	}
	for(auto i = 0; i < n; ++ i){
		prev[p[i]] = p[(i - 1 + n) % n];
	}
	for(auto i = 0; i < m; ++ i){
		cin >> a[i], -- a[i];
	}
	vector<int> lastpos(n, -1);
	binary_lift lift(m);
	for(auto i = 0; i < m; ++ i){
		if(lastpos[prev[a[i]]] != -1){
			lift.insert(lastpos[prev[a[i]]], i);
		}
		lastpos[a[i]] = i;
	}
	lift.init();
	vector<int> range(m, -1);
	for(auto u = 0; u < m; ++ u){
		if(lift.depth[u] >= n - 1){
			range[u] = lift.trace_up(u, n - 1);
		}
	}
	sparse_table tb(range.begin(), range.end(), [&](int x, int y){ return max(x, y); }, -1);
	while(qq --){
		int l, r;
		cin >> l >> r, -- l;
		l <= tb.query(l, r) ? cout << 1 : cout << 0;
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