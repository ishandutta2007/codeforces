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
	function<bool(int)> ignore; // edge ignoration rule
	graph(int n): n(n), adj(n){ }
	int link(int u, int v, T w = 1){ // insert an undirected edge
		int id = (int)edges.size();
		adj[u].push_back(id), adj[v].push_back(id), edges.push_back({u, v, w});
		return id;
	}
	int orient(int u, int v, T w = 1){ // insert a directed edge
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
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	graph<int> g(n);
	for(auto i = 0; i < n - 1; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.link(u, v);
		if(u > v){
			swap(u, v);
		}
	}
	vector<int> color(n);
	for(auto u = 0; u < n; ++ u){
		cin >> color[u], -- color[u];
	}
	vector<array<int, 2>> e;
	for(auto [u, v, ignore]: g.edges){
		if(color[u] != color[v]){
			e.push_back({u, v});
		}
	}
	if(e.empty()){
		cout << "YES\n1\n";
		return 0;
	}
	for(auto r: e[0]){
		for(auto i = 1; i < (int)e.size(); ++ i){
			if(r != e[i][0] && r != e[i][1]){
				goto FAIL;
			}
		}
		cout << "YES\n" << r + 1 << "\n";
		return 0;
		FAIL:;
	}
	cout << "NO\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////