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
	graph(const vector<vector<int>> &adj, bool undirected = true): n(n){
		if(undirected) for(auto u = 0; u < n; ++ u) for(auto v: adj[u]) if(u < v) link(u, v);
		else for(auto u = 0; u < n; ++ u) for(auto v: adj[u]) orient(u, v);
	}
	graph(const vector<vector<pair<int, T>>> &adj, bool undirected = true): n(n){
		if(undirected) for(auto u = 0; u < n; ++ u) for(auto [v, w]: adj[u]) if(u < v) link(u, v, w);
		else for(auto u = 0; u < n; ++ u) for(auto [v, w]: adj[u]) orient(u, v, w);
	}
	graph(int n, vector<array<int, 2>> &edge, bool undirected = true): n(n){
		for(auto [u, v]: edge) undirected ? link(u, v) : orient(u, v);
	}
	graph(int n, vector<tuple<int, int, T>> &edge, bool undirected = true): n(n){
		for(auto [u, v, w]: edge) undirected ? link(u, v, w) : orient(u, v, w);
	}
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

// Reads an undirected graph
// Process_p3(edge1, middle_vertex, edge2)
// Process_edge(edge) : process arbitrary remaining edge in a component with odd number of edges
// O(|V| + |E|)
// Requires graph
template<class T>
void decompose_into_paths_of_length_2(const graph<T> &g, auto process_p3, auto process_edge){
	int n = g.n;
	vector<int> depth(n, -1), used((int)g.edge.size());
	auto recurse = [&](auto self, int u, int pe, int d)->bool{
		int rem = -1;
		depth[u] = d;
		for(auto id: g.adj[u]){
			if(id == pe || g.ignore && g.ignore(id)) continue;
			auto &e = g.edge[id];
			int v = u ^ e.from ^ e.to;
			if(~depth[v] && !used[id] || !~depth[v] && self(self, v, id, depth[u] + 1)){
				used[id] = true;
				if(~rem){
					process_p3(rem, u, id);
					rem = -1;
				}
				else rem = id;
			}
		}
		if(!~rem) return true;
		~pe ? process_p3(pe, u, rem) : process_edge(rem);
		return false;
	};
	for(auto u = 0; u < n; ++ u) if(!~depth[u]) recurse(recurse, u, -1, 0);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	graph<int> g(n << 1);
	for(auto i = 0; i < n; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.link(u, v);
	}
	vector<array<int, 3>> p3;
	vector<int> isolated;
	decompose_into_paths_of_length_2(g, [&](int el, int u, int er){ p3.push_back({el, u, er}); }, [&](int e){ isolated.push_back(e); });
	vector<array<int, 2>> appear(n << 1, {-1, -1});
	for(auto i = 0; i < (int)p3.size(); ++ i){
		auto [el, u, er] = p3[i];
		appear[u] = {i, 1};
		appear[g.edge[el].from ^ g.edge[el].to ^ u] = {i, 0};
		appear[g.edge[er].from ^ g.edge[er].to ^ u] = {i, 2};
	}
	vector<int> used((int)p3.size(), false);
	vector<array<int, 2>> res;
	vector<string> s1, s2;
	for(auto e: isolated){
		auto [u, v, ignore] = g.edge[e];
		if(!~appear[u][0]){
			swap(u, v);
		}
		if(!~appear[u][0]){
			cout << "-1\n";
			return 0;
		}
		int i = appear[u][0];
		assert(!used[i]);
		used[i] = true;
		auto [el, _u, er] = p3[i];
		if(appear[u][1] == 1){
			assert(u == _u);
			int w = g.edge[el].from ^ g.edge[el].to ^ u;
			int x = g.edge[er].from ^ g.edge[er].to ^ u;
			
			res.push_back({u, v});
			res.push_back({w, u});
			res.push_back({u, x});

			s1.push_back("UU");
			s1.push_back("DD");
			s1.push_back("LR");
			
			s2.push_back("LR");
			s2.push_back("UU");
			s2.push_back("DD");
		}
		else{
			if(appear[u][1] == 2){
				swap(el, er);
			}
			int w = g.edge[el].from ^ g.edge[el].to ^ u;
			int x = g.edge[er].from ^ g.edge[er].to ^ w;
			swap(u, v);
			res.push_back({v, w});
			res.push_back({u, x});
			res.push_back({v, w});

			s1.push_back("UU");
			s1.push_back("DD");
			s1.push_back("LR");
			
			s2.push_back("LR");
			s2.push_back("UU");
			s2.push_back("DD");
		}
	}
	for(auto i = 0; i < (int)p3.size(); ++ i){
		if(used[i]){
			continue;
		}
		auto [el, u, er] = p3[i];
		int vl = g.edge[el].from ^ g.edge[el].to ^ u;
		int vr = g.edge[er].from ^ g.edge[er].to ^ u;
		res.push_back({u, vl});
		res.push_back({vr, u});
		
		s1.push_back("LR");
		s1.push_back("LR");
		
		s2.push_back("UU");
		s2.push_back("DD");
	}
	assert((int)res.size() == n && (int)s1.size() == n && (int)s2.size() == n);
	cout << n << " 2\n\n";
	for(auto [x, y]: res){
		cout << x + 1 << " " << y + 1 << "\n";
	}
	cout << "\n";
	ranges::copy(s1, ostream_iterator<string>(cout, "\n"));
	cout << "\n";
	ranges::copy(s2, ostream_iterator<string>(cout, "\n"));
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