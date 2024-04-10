#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

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
	int n, m, digit;
	cin >> n >> m >> digit;
	map<string, int> pattern;
	for(auto i = 0; i < n; ++ i){
		string s;
		cin >> s;
		pattern[s] = i;
	}
	graph<int> g(n);
	for(auto i = 0; i < m; ++ i){
		string s;
		int k;
		cin >> s >> k, -- k;
		vector<int> adj;
		for(auto mask = 0; mask < 1 << digit; ++ mask){
			string t = s;
			for(auto i = 0; i < digit; ++ i){
				if(mask & 1 << i){
					t[i] = '_';
				}
			}
			if(pattern.count(t)){
				adj.push_back(pattern[t]);
			}
		}
		sort(adj.begin(), adj.end());
		if(!binary_search(adj.begin(), adj.end(), k)){
			cout << "NO\n";
			return 0;
		}
		for(auto i: adj){
			if(i != k){
				g.orient(k, i);
			}
		}
	}
	auto order = topological_sort(g);
	if((int)order.size() < n){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for(auto i: order){
		cout << i + 1 << " ";
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