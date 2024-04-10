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
	int degree(int u) const{ // the degree (outdegree if directed) of u (without the ignoration rule)
		return (int)adj[u].size();
	}
	vector<vector<int>> get_adjacency_list() const{
		vector<vector<int>> res(n);
		for(auto u = 0; u < n; ++ u) for(auto id: adj[u]){
			if(ignore && ignore(id)) continue;
			auto &e = edges[id];
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

// for each weakly connected components, find colorings such that (color[u] + 1) % C == color[v] for all edges u->v
// undirected graphs are regarded as its canonical directed representation
// C=1 : returns weakly connected components
// C=2 : returns bipartite colorings
// Requires graph
template<class T, int C = 2>
void directed_coloring(const graph<T> &g, auto act){
	int n = g.n;
	vector<int> was(n, -1);
	auto rg = g.transposed();
	for(auto u = 0; u < n; ++ u){
		if(!~was[u]){
			bool perfect = true;
			array<vector<int>, C> split;
			function<void(int)> dfs = [&](int u){
				for(auto id: g.adj[u]){
					if(g.ignore && g.ignore(id)) continue;
					auto &e = g.edges[id];
					int v = u ^ e.from ^ e.to;
					if(!~was[v]){
						split[was[v] = (was[u] + 1) % C].push_back(v);
						dfs(v);
					}
					else if(was[v] != (was[u] + 1) % C){
						perfect = false;
					}
				}
				for(auto id: rg.adj[u]){
					if(rg.ignore && rg.ignore(id)) continue;
					auto &e = rg.edges[id];
					int v = u ^ e.from ^ e.to;
					if(!~was[v]){
						split[was[v] = (was[u] + C - 1) % C].push_back(v);
						dfs(v);
					}
					else if(was[v] != (was[u] + C - 1) % C){
						perfect = false;
					}
				}
			};
			split[was[u] = 0].push_back(u);
			dfs(u);
			act(perfect, split);
		}
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, m;
		cin >> n >> m;
		vector<int> ori(n), obj(n);
		for(auto u = 0; u < n; ++ u){
			cin >> ori[u];
		}
		for(auto u = 0; u < n; ++ u){
			cin >> obj[u];
		}
		graph<int> g(n);
		for(auto i = 0; i < m; ++ i){
			int u, v;
			cin >> u >> v, -- u, -- v;
			g.link(u, v);
		}
		auto act = [&](bool perfect, array<vector<int>, 2> split)->void{
			if(perfect){
				accumulate(split[0].begin(), split[0].end(), 0LL, [&](auto sum, int u){ return sum + ori[u] - obj[u]; }) == accumulate(split[1].begin(), split[1].end(), 0LL, [&](auto sum, int u){ return sum + ori[u] - obj[u]; }) ? cout << "YES\n" : cout << "NO\n";
			}
			else{
				accumulate(ori.begin(), ori.end(), accumulate(obj.begin(), obj.end(), 0LL)) & 1 ? cout << "NO\n" : cout << "YES\n";
			}
		};
		directed_coloring(g, act);
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