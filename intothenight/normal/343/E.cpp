#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<class T>
struct flow_network{
	int n;
	vector<vector<int>> adj;
	struct E{
		int from, to;
		T capacity, flow;
	};
	vector<E> edge;
	T flow = 0;
	flow_network(int n): n(n), adj(n){ }
	void clear_flow(){
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

// Requires flow_network
template<class T>
struct dinic_maximum_flow{
	static constexpr T eps = (T)1e-9, inf = numeric_limits<T>::max();
	flow_network<T> &F;
	dinic_maximum_flow(flow_network<T> &F): F(F), ptr(F.n), level(F.n), q(F.n){ }
	vector<int> ptr, level, q;
	bool bfs(int source, int sink){
		fill(level.begin(), level.end(), -1);
		q[0] = sink;
		level[sink] = 0;
		int beg = 0, end = 1;
		while(beg < end){
			int i = q[beg ++];
			for(auto ind: F.adj[i]){
				auto &e = F.edge[ind];
				auto &re = F.edge[ind ^ 1];
				if(re.capacity - re.flow > eps && level[e.to] == -1){
					level[e.to] = level[i] + 1;
					if(e.to == source) return true;
					q[end ++] = e.to;
				}
			}
		}
		return false;
	}
	T dfs(int u, T w, int sink){
		if(u == sink) return w;
		int &j = ptr[u];
		while(j >= 0){
			int ind = F.adj[u][j];
			auto &e = F.edge[ind];
			if(e.capacity - e.flow > eps && level[e.to] == level[u] - 1){
				T flow = dfs(e.to, min(e.capacity - e.flow, w), sink);
				if(flow > eps){
					F.add_flow(ind, flow);
					return flow;
				}
			}
			-- j;
		}
		return 0;
	}
	// Find a maximum source-sink flow
	// O(V^2 E) ( O(E min(V^2/3, E^1/2)) for unit network )
	T maximum_flow(int source, int sink){
		while(bfs(source, sink)){
			for(auto i = 0; i < F.n; ++ i) ptr[i] = (int)F.adj[i].size() - 1;
			T sum = 0;
			while(true){
				T add = dfs(source, inf, sink);
				if(add <= eps) break;
				sum += add;
			}
			if(sum <= eps) break;
			F.flow += sum;
		}
		return F.flow;
	}
	// Find a minimum source-sink cut
	// O(V^2 E) ( O(E min(V^2/3, E^1/2)) for unit network )
	auto minimum_cut(int source, int sink){
		T cut_weight = maximum_flow(source, sink);
		vector<int> left, right;
		for(auto u = 0; u < F.n; ++ u) (!~level[u] ? left : right).push_back(u);
		return tuple{cut_weight, left, right};
	}
};

// Returns a tree T where for all s!=t, min s-t cut of g equals
// min_{e is in s-t path in T}( (capacity of S_e-T_e cut in G) = (capacity of s-t edge in T) ) 
// n - 1 dinic_maximum_flow.minimum_cut() calls
// Requires flow_network and dinic_maximum_flow
template<class T>
vector<tuple<int, int, T>> gomory_hu_tree(int n, const vector<tuple<int, int, T>> &edge){
	flow_network<T> F(n);
	for(auto &[u, v, w]: edge) F.insert(u, v, w, w);
	vector<tuple<int, int, T>> res(max(n - 1, 0));
	vector<int> pv(n), cut(n);
	for(auto i = 1; i < n; ++ i){
		F.clear_flow();
		auto [flow, left, right] = dinic_maximum_flow<T>(F).minimum_cut(pv[i], i);
		fill(cut.begin(), cut.end(), 0);
		for(auto u: right) cut[u] = 1;
		for(auto j = i + 1; j < n; ++ j) if(cut[j] == cut[i] && pv[j] == pv[i]) pv[j] = i;
		res[i - 1] = {pv[i], i, flow};
	}
	return res;
}

template<bool Enable_small_to_large = true>
struct disjoint_set{
	int n, _classes;
	vector<int> p;
	disjoint_set(int n): n(n), _classes(n), p(n, -1){ }
	int classes() const{
		return _classes;
	}
	int root(int u){
		return p[u] < 0 ? u : p[u] = root(p[u]);
	}
	bool share(int a, int b){
		return root(a) == root(b);
	}
	int size(int u){
		return -p[root(u)];
	}
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		-- _classes;
		if constexpr(Enable_small_to_large) if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		return true;
	}
	bool merge(int u, int v, auto act){
		u = root(u), v = root(v);
		if(u == v) return false;
		-- _classes;
		if constexpr(Enable_small_to_large) if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		act(u, v);
		return true;
	}
	void clear(){
		_classes = n;
		fill(p.begin(), p.end(), -1);
	}
	vector<vector<int>> group_up(){
		vector<vector<int>> g(n);
		for(auto i = 0; i < n; ++ i) g[root(i)].push_back(i);
		g.erase(remove_if(g.begin(), g.end(), [&](auto &s){ return s.empty(); }), g.end());
		return g;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>> edge(m);
	for(auto &[u, v, w]: edge){
		cin >> u >> v >> w, -- u, -- v;
	}
	auto tree_edge = gomory_hu_tree(n, edge);
	ranges::sort(tree_edge, [&](auto e, auto f){ return get<2>(e) > get<2>(f); });
	disjoint_set dsu(n);
	vector<list<int>> res(n);
	for(auto u = 0; u < n; ++ u){
		res[u].push_back(u);
	}
	long long sum = 0;
	for(auto [u, v, w]: tree_edge){
		sum += w;
		dsu.merge(u, v, [&](int u, int v){ res[u].splice(res[u].end(), res[v]); });
	}
	cout << sum << "\n";
	for(auto u: res[dsu.root(0)]){
		cout << u + 1 << " ";
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////