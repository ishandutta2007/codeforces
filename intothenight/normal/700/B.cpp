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
	int n, k;
	cin >> n >> k;
	graph<int> g(n);
	vector<int> special(n);
	for(auto i = 0; i < k << 1; ++ i){
		int u;
		cin >> u, -- u;
		special[u] = true;
	}
	for(auto i = 0; i < n - 1; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.link(u, v);
	}
	vector<int> cnt = special;
	function<void(int, int)> dfs = [&](int u, int pe){
		for(auto id: g.adj[u]){
			if(id == pe || g.ignore && g.ignore(id)) continue;
			auto &e = g.edges[id];
			int v = u ^ e.from ^ e.to;
			dfs(v, id);
			cnt[u] += cnt[v];
		}
	};
	dfs(0, -1);
	int c = 0;
	for(auto pe = -1; ; ){
		for(auto id: g.adj[c]){
			if(id == pe) continue;
			auto &e = g.edges[id];
			int u = c ^ e.from ^ e.to;
			if(cnt[u] > k){
				c = u, pe = id;
				goto NEXT;
			}
		}
		break;
		NEXT:;
	}
	long long res = 0;
	vector<int> depth(n);
	function<void(int, int)> solve = [&](int u, int pe){
		if(special[u]){
			res += depth[u];
		}
		for(auto id: g.adj[u]){
			if(id == pe || g.ignore && g.ignore(id)) continue;
			auto &e = g.edges[id];
			int v = u ^ e.from ^ e.to;
			depth[v] = depth[u] + 1;
			solve(v, id);
		}
	};
	solve(c, -1);
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