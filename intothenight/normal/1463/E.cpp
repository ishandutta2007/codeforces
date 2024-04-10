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
	graph transposed() const{ // returns the transpose of the directed graph
		graph res(n);
		for(auto &e: edges) res.orient(e.to, e.from, e.cost);
		res.ignore = ignore;
		return res;
	}
};

struct disjoint_set{
	vector<int> p;
	disjoint_set(int n): p(n, -1){ }
	bool share(int a, int b){ return root(a) == root(b); }
	int sz(int u){ return -p[root(u)]; }
	int root(int u){ return p[u] < 0 ? u : p[u] = root(p[u]); }
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		p[u] += p[v], p[v] = u;
		return true;
	}
};

template<class T>
vector<int> topological_sort(graph<T> &g){ // O(V + E), returns less than n elem if there's a cycle
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
	int n, k;
	cin >> n >> k;
	vector<array<int, 2>> edges;
	int root;
	for(auto u = 0; u < n; ++ u){
		int p;
		cin >> p, -- p;
		if(!~p){
			root = u;
		}
		else{
			edges.push_back({p, u});
		}
	}
	graph<int> h(n);
	vector<int> indeg(n), outdeg(n);
	for(auto i = 0; i < k; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		h.orient(u, v);
		++ outdeg[u], ++ indeg[v];
	}
	for(auto u = 0; u < n; ++ u){
		if(outdeg[u] >= 2 || indeg[u] >= 2){
			cout << "0\n";
			return 0;
		}
	}
	vector<int> temp_ord(n, -1);
	vector<vector<int>> ord(n);
	disjoint_set dsu(n);
	vector<int> roots;
	for(auto r = 0; r < n; ++ r){
		if(!indeg[r]){
			function<void(int)> dfs = [&](int u){
				ord[r].push_back(u);
				for(auto id: h.adj[u]){
					int v = h.edges[id].to;
					temp_ord[v] = temp_ord[u] + 1;
					dsu.merge(u, v);
					dfs(v);
				}
			};
			temp_ord[r] = 0;
			roots.push_back(r);
			dfs(r);
		}
	}
	if(any_of(temp_ord.begin(), temp_ord.end(), [&](int x){ return !~x; })){
		cout << "0\n";
		return 0;
	}
	for(auto [u, v]: edges){
		if(dsu.share(u, v) && temp_ord[u] > temp_ord[v]){
			cout << "0\n";
			return 0;
		}
	}
	int m = (int)roots.size();
	vector<int> label(n);
	for(auto u = 0; u < n; ++ u){
		label[u] = lower_bound(roots.begin(), roots.end(), dsu.root(u)) - roots.begin();
	}
	graph<int> g(m);
	for(auto [u, v]: edges){
		if(!dsu.share(u, v)){
			g.orient(label[u], label[v]);
		}
	}
	auto order = topological_sort(g);
	if((int)order.size() < m){
		cout << "0\n";
		return 0;
	}
	for(auto i: order){
		for(auto u: ord[roots[i]]){
			cout << u + 1 << " ";
		}
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