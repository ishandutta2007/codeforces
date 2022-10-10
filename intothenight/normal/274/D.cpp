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
	vector<array<int, 2>> edge;
	int cnt = m;
	for(auto i = 0; i < n; ++ i){
		vector<int> a(m);
		for(auto j = 0; j < m; ++ j){
			cin >> a[j];
		}
		vector<int> order(m);
		iota(order.begin(), order.end(), 0);
		ranges::sort(order, [&](int j1, int j2){ return a[j1] < a[j2]; });
		vector<array<int, 2>> ranges;
		for(auto l = 0; l < m; ){
			while(l < m && !~a[order[l]]){
				++ l;
			}
			if(l == m){
				break;
			}
			int r = l;
			while(r < m && a[order[l]] == a[order[r]]){
				++ r;
			}
			ranges.push_back({l, r});
			l = r;
		}
		for(auto k = 0; k < (int)ranges.size() - 1; ++ k){
			auto [l1, r1] = ranges[k];
			auto [l2, r2] = ranges[k + 1];
			for(auto j = l1; j < r1; ++ j){
				edge.push_back({order[j], cnt});
			}
			for(auto j = l2; j < r2; ++ j){
				edge.push_back({cnt, order[j]});
			}
			++ cnt;
		}
	}
	graph<int> g(cnt);
	for(auto [u, v]: edge){
		g.orient(u, v);
	}
	if(auto res = topological_sort(g)){
		for(auto u: *res){
			if(u < m){
				cout << u + 1 << " ";
			}
		}
		cout << "\n";
	}
	else{
		cout << "-1\n";
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