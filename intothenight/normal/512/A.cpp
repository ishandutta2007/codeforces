#include <bits/stdc++.h>
using namespace std;

template<class T>
struct graph{
	struct edge{
		int from, to;
		T cost;
	};
	int n;
	vector<edge> edges;
	vector<vector<int>> adj;
	function<bool(int)> ignore;
	graph(int n): n(n), adj(n){ }
	int link(int u, int v, T w = {}){ // insert an undirected edge
		int id = (int)edges.size();
		adj[u].push_back(id), adj[v].push_back(id), edges.push_back({u, v, w});
		return id;
	}
	int orient(int u, int v, T w = {}){ // insert a directed edge
		int id = (int)edges.size();
		adj[u].push_back(id), edges.push_back({u, v, w});
		return id;
	}
	graph transposed() const{ // the transpose of the directed graph
		graph res(n);
		for(auto &e: edges) res.orient(e.to, e.from, e.cost);
		res.ignore = ignore;
		return res;
	}
	int degree(int u){ // the degree (outdegree if directed) of u (without the ignoration rule)
		return (int)adj[u].size();
	}
	void set_ignoration_rule(const function<bool(int)> &f){
		ignore = f;
	}
	void reset_ignoration_rule(){
		ignore = nullptr;
	}
};

template<class T>
vector<int> topological_sort(const graph<T> &g){ // O(V + E), returns less than n elem if there's a cycle
	int n = g.n;
	vector<int> indeg(n), res;
	for(int u = 0; u < n; ++ u) for(auto id: g.adj[u]){
		if(g.ignore && g.ignore(id)) continue;
		auto &e = g.edges[id];
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
			auto &e = g.edges[id];
			int v = u ^ e.from ^ e.to;
			if(!-- indeg[v]) dq.push_back(v);
		}
	}
	return res;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<string> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	graph<int> g(26);
	for(auto i = 1; i < n; ++ i){
		auto s = a[i - 1], t = a[i];
		int p = 0;
		while(p < min((int)s.size(), (int)t.size()) && s[p] == t[p]){
			++ p;
		}
		if(p == (int)t.size()){
			cout << "Impossible\n";
			return 0;
		}
		if(p < (int)s.size()){
			g.orient(s[p] - 'a', t[p] - 'a');
		}
	}
	auto order = topological_sort(g);
	if((int)order.size() < 26){
		cout << "Impossible\n";
		return 0;
	}
	for(auto u: order){
		cout << char(u + 'a');
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