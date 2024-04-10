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
	graph(int n): n(n), adj(n), ignore(nullptr){
	}
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
	graph reversed() const{ // returns the transpose of the directed graph
		graph res(n);
		for(auto &e: edges){
			res.orient(e.to, e.from, e.cost);
		}
		return res;
	}
};

// Requires graph
template<class T> // O(V + E)
void strongly_connected_components(const graph<T> &g, function<void(vector<int>)> fc){
	int n = g.n, timer = 0, ncomps = 0, v;
	vector<int> val(n), comp(n, -1), z, cur;
	function<int(int)> dfs = [&](int u){
		int low = val[u] = ++ timer;
		z.push_back(u);
		for(auto e: g.adj[u]){
			int v = u ^ g.edges[e].from ^ g.edges[e].to;
			if(comp[v] < 0) low = min(low, val[v] ?: dfs(v));
		}
		if(low == val[u]){
			do{
				v = z.back(); z.pop_back();
				comp[v] = ncomps;
				cur.push_back(v);
			}while(v != u);
			fc(cur); // Process the component
			cur.clear();
			++ ncomps;
		}
		return val[u] = low;
	};
	for(int u = 0; u < n; ++ u) if(comp[u] < 0) dfs(u);
} // accesses sccs in the reverse topological order

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		string s;
		cin >> n >> s;
		graph<int> g(n);
		for(auto u = 0; u < n; ++ u){
			int v = (u + 1) % n;
			if(s[u] == '>'){
				g.orient(u, v);
			}
			else if(s[u] == '<'){
				g.orient(v, u);
			}
			else{
				g.orient(u, v);
				g.orient(v, u);
			}
		}
		int res = 0;
		auto fc = [&](const vector<int> &c){
			if((int)c.size() != 1){
				res += (int)c.size();
			}
		};
		strongly_connected_components(g, fc);
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