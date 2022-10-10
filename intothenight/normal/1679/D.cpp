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
	graph(int n = 0): n(n), adj(n){ }
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
	friend ostream &operator<<(ostream &out, const graph &g){
		for(auto id = 0; id < (int)g.edge.size(); ++ id){
			if(g.ignore && g.ignore(id)) continue;
			auto &e = g.edge[id];
			out << "{" << e.from << ", " << e.to << ", " << e.cost << "}\n";
		}
		return out;
	}
};

// O(|V| + |E|)
template<class T>
optional<vector<int>> topological_sort(const graph<T> &g){
	int n = g.n;
	vector<int> indeg(n), res;
	for(int u = 0; u < n; ++ u) for(auto id: g.adj[u]){
		if(g.ignore && g.ignore(id)) continue;
		auto &e = g.edge[id];
		int v = u ^ e.from ^ e.to;
		++ indeg[v];
	}
	deque<int> dq;
	for(int u = 0; u < n; ++ u) if (!indeg[u]) dq.push_back(u);
	while(!dq.empty()){
		int u = dq.front(); dq.pop_front();
		res.push_back(u);
		for(auto id: g.adj[u]){
			if(g.ignore && g.ignore(id)) continue;
			auto &e = g.edge[id];
			int v = u ^ e.from ^ e.to;
			if(!-- indeg[v]) dq.push_back(v);
		}
	}
	return (int)res.size() == n ? optional{res} : optional<vector<int>>{};
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	long long k;
	cin >> k;
	vector<int> a(n);
	copy_n(istream_iterator<int>(cin), n, a.begin());
	graph<int> g(n);
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.orient(u, v, 1);
	}
	vector<int> dp(n);
	auto fail = [&](int th)->int{
		g.set_ignoration_rule([&](int id){ return a[g.edge[id].to] > th; });
		auto orderptr = topological_sort(g);
		if(!orderptr){
			return false;
		}
		ranges::fill(dp, 1);
		for(auto u: *orderptr | ranges::views::reverse){
			if(a[u] > th){
				continue;
			}
			for(auto id: g.adj[u] | ranges::views::filter([&](int id){ return !g.ignore || !g.ignore(id);})){
				auto v = g.edge[id].to;
				dp[u] = max(dp[u], dp[v] + 1);
			}
			if(dp[u] >= k){
				return false;
			}
		}
		return true;
	};
	int res = *ranges::partition_point(ranges::iota_view(0, 1000000001), fail);
	if(res == 1000000001){
		res = -1;
	}
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