#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<class T>
struct graph{
	struct E{
		int from, to;
		T cost;
	};
	int n;
	vector<E> edge;
	vector<vector<int>> adj;
	function<bool(int)> ignore;
	graph(int n): n(n), adj(n){ }
	int link(int u, int v, T w = {}){ // insert an undirected edge
		int id = (int)edge.size();
		adj[u].push_back(id), adj[v].push_back(id), edge.push_back({u, v, w});
		return id;
	}
	int orient(int u, int v, T w = {}){ // insert a directed edge
		int id = (int)edge.size();
		adj[u].push_back(id), edge.push_back({u, v, w});
		return id;
	}
	graph transposed() const{ // the transpose of the directed graph
		graph res(n);
		for(auto &e: edge) res.orient(e.to, e.from, e.cost);
		res.ignore = ignore;
		return res;
	}
	int degree(int u) const{ // the degree (outdegree if directed) of u (without the ignoration rule)
		return (int)adj[u].size();
	}
	vector<vector<int>> get_adjacency_list() const{
		vector<vector<int>> res(n);
		for(auto u = 0; u < n; ++ u) for(auto id: adj[u]){
			if(ignore && ignore(id)) continue;
			auto &e = edge[id];
			int v = u ^ e.from ^ e.to;
			res[u].push_back(v);
		}
		return res;
	}
	void set_ignoration_rule(const function<bool(int)> &f){
		ignore = f;
	}
	void reset_ignoration_rule(){
		ignore = nullptr;
	}
};

// Requires graph
// O(|V| + |E|)
template<class T>
void strongly_connected_components(const graph<T> &g, auto act_comp){
	int n = g.n, it = 0, ncomps = 0, v;
	vector<int> val(n), comp(n, -1), s, cur;
	auto dfs = [&](auto self, int u)->int{
		int low = val[u] = ++ it;
		s.push_back(u);
		for(auto id: g.adj[u]){
			if(g.ignore && g.ignore(id)) continue;
			auto &e = g.edge[id];
			int v = u ^ e.from ^ e.to;
			if(comp[v] < 0) low = min(low, val[v] ?: self(self, v));
		}
		if(low == val[u]){
			do{
				v = s.back(); s.pop_back();
				comp[v] = ncomps;
				cur.push_back(v);
			}while(v != u);
			act_comp(cur); // Process the component
			cur.clear();
			++ ncomps;
		}
		return val[u] = low;
	};
	for(auto u = 0; u < n; ++ u) if(comp[u] < 0) dfs(dfs, u);
} // accesses sccs in the reverse topological order

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		for(auto i = 0; i < n; ++ i){
			cin >> b[i];
		}
		vector<int> order(n);
		ranges::copy(ranges::iota_view(0, n), begin(order));
		ranges::sort(order, [&](int u, int v){ return a[u] < a[v]; });
		graph<int> g(n);
		for(auto t = 0; t < n - 1; ++ t){
			g.orient(order[t], order[t + 1]);
		}
		ranges::sort(order, [&](int u, int v){ return b[u] < b[v]; });
		for(auto t = 0; t < n - 1; ++ t){
			g.orient(order[t], order[t + 1]);
		}
		bool first = true;
		string res(n, '0');
		strongly_connected_components(g, [&](auto c){
			if(!first){
				return;
			}
			first = false;
			for(auto u: c){
				res[u] = '1';
			}
		});
		cout << res << "\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
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