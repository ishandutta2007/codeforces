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
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	vector<int> fib{1, 1};
	while(fib.back() <= 3e5){
		fib.push_back(fib[(int)fib.size() - 2] + fib[(int)fib.size() - 1]);
	}
	vector<int> ind(2e5 + 10, -1);
	for(auto i = 0; i < (int)fib.size(); ++ i){
		if(fib[i] < (int)ind.size()){
			ind[fib[i]] = i;
		}
	}
	int n;
	cin >> n;
	graph<int> g(n);
	for(auto i = 0; i < n - 1; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.link(u, v);
	}
	if(!~ind[n]){
		cout << "No\n";
		return 0;
	}
	function<bool(int, int, int)> solve = [&](int i, int u, int pe){
		if(i <= 3){
			return true;
		}
		static vector<int> sz(n);
		static vector<int> cut(n - 1);
		vector<array<int, 3>> cur;
		function<void(int, int)> init_sz = [&](int u, int pe){
			sz[u] = 1;
			for(auto id: g.adj[u]){
				if(id == pe || cut[id] || g.ignore && g.ignore(id)) continue;
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				init_sz(v, id);
				sz[u] += sz[v];
			}
			if(ind[sz[u]] == i - 1 || ind[sz[u]] == i - 2){
				cur.push_back({ind[sz[u]], u, pe});
			}
		};
		init_sz(u, pe);
		if(!cur.empty()){
			auto [j, v, id] = cur.front();
			auto &e = g.edges[id];
			int p = v ^ e.from ^ e.to;
			cut[id] = true;
			return solve(j, v, id) && solve(j ^ i - 1 ^ i - 2, p, id);
		}
		else{
			return false;
		}
	};
	solve(ind[n], 0, -1) ? cout << "Yes\n" : cout << "No\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////