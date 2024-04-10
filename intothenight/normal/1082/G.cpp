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

template<typename T>
struct flow_network{
	static constexpr T eps = (T)1e-9;
	int N;
	vector<vector<int>> adj;
	struct Edge{
		int from, to;
		T capacity, flow;
	};
	vector<Edge> edge;
	int source, sink;
	T flow = 0;
	flow_network(int N, int source, int sink): N(N), source(source), sink(sink), adj(N){ }
	void clear(){
		for(auto &e: edge) e.flow = 0;
		flow = 0;
	}
	int insert(int from, int to, T forward_cap, T backward_cap){
		int ind = (int)edge.size();
		adj[from].push_back(ind);
		edge.push_back({from, to, forward_cap, 0});
		adj[to].push_back(ind + 1);
		edge.push_back({to, from, backward_cap, 0});
		return ind;
	}
	void add_flow(int i, T f){
		edge[i].flow += f;
		edge[i ^ 1].flow -= f;
	}
};
template<typename T>
struct dinic{
	static constexpr T inf = numeric_limits<T>::max();
	flow_network<T> &g;
	vector<int> ptr, level, q;
	dinic(flow_network<T> &g): g(g), ptr(g.N), level(g.N), q(g.N){ }
	bool bfs(){
		fill(level.begin(), level.end(), -1);
		q[0] = g.sink;
		level[g.sink] = 0;
		int beg = 0, end = 1;
		while(beg < end){
			int i = q[beg ++];
			for(auto ind: g.adj[i]){
				auto &e = g.edge[ind];
				auto &re = g.edge[ind ^ 1];
				if(re.capacity - re.flow > g.eps && level[e.to] == -1){
					level[e.to] = level[i] + 1;
					if(e.to == g.source) return true;
					q[end ++] = e.to;
				}
			}
		}
		return false;
	}
	T dfs(int u, T w){
		if(u == g.sink) return w;
		int &j = ptr[u];
		while(j >= 0){
			int ind = g.adj[u][j];
			auto &e = g.edge[ind];
			if(e.capacity - e.flow > g.eps && level[e.to] == level[u] - 1){
				T F = dfs(e.to, min(e.capacity - e.flow, w));
				if(F > g.eps){
					g.add_flow(ind, F);
					return F;
				}
			}
			-- j;
		}
		return 0;
	}
	T max_flow(){
		while(bfs()){
			for(int i = 0; i < g.N; ++ i) ptr[i] = int(g.adj[i].size()) - 1;
			T sum = 0;
			while(1){
				T add = dfs(g.source, inf);
				if(add <= g.eps) break;
				sum += add;
			}
			if(sum <= g.eps) break;
			g.flow += sum;
		}
		return g.flow;
	}
	pair<T, vector<bool>> min_cut(){
		T cut = max_flow();
		vector<bool> res(g.N);
		for(int i = 0; i < g.N; ++ i) res[i] = (level[i] != -1);
		return {cut, res};
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	int source = n + m, sink = source + 1;
	flow_network<long long> F(n + m + 2, source, sink);
	long long sum = 0;
	for(auto u = 0; u < n; ++ u){
		int w;
		cin >> w;
		F.insert(source, u, w, 0);
	}
	const long long inf = 1e15;
	for(auto i = 0; i < m; ++ i){
		int u, v, w;
		cin >> u >> v >> w, -- u, -- v;
		sum += w;
		F.insert(n + i, sink, w, 0);
		F.insert(u, n + i, inf, 0);
		F.insert(v, n + i, inf, 0);
	}
	dinic<long long> D(F);
	cout << sum - D.max_flow();
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////