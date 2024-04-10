#include <bits/stdc++.h>
using namespace std;

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

// Requires graph
template<class T>
struct dial{
	int n;
	vector<T> dist;
	vector<int> pv, pe, was;
	dial(int n){ init(n); }
	void init(int n){
		this->n = n;
		dist.assign(n, numeric_limits<T>::max());
		pv.assign(n, -1);
		pe.assign(n, -1);
		was.assign(n, -1);
		attempt = 0;
	}
	int attempt;
	// O(|E_C| + min(|V_C| * C, (sum of edge weight))) where
	// C is the upper bound of edge weight,
	// V_C is the set of vertices reachable from src, and
	// E_C is the set of edges reachable from src
	template<class U>
	void run(const graph<U> &g, const int C, const vector<int> &src){
		assert(n == g.n);
		++ attempt;
		int it = 0;
		vector<deque<array<int, 2>>> dqs(C);
		for(auto u: src){
			was[u] = attempt;
			dqs[it].push_back({dist[u] = {}, u});
			pv[u] = pe[u] = -1;
		}
		while(any_of(dqs.begin(), dqs.end(), [&](auto &dq){ return !dq.empty(); })){
			while(dqs[it].empty()) it = (it + 1) % C;
			auto [d, u] = dqs[it].front(); dqs[it].pop_front();
			if(d != dist[u]) continue;
			for(auto id: g.adj[u]){
				if(g.ignore && g.ignore(id)) continue;
				auto &e = g.edge[id];
				int v = u ^ e.from ^ e.to;
				if(was[v] != attempt || d + e.cost < dist[v]){
					was[v] = attempt;
					dqs[(d + e.cost) % C].push_back({dist[v] = dist[u] + e.cost, v});
					pv[v] = u, pe[v] = id;
				}
			}
		}
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n, ++ n;
	graph<int> g(n * 3);
	for(auto i = 1; i < n; ++ i){
		g.orient(i, i << 1);
		g.orient(i, i << 1 | 1);
	}
	for(auto u = 1; u < n; ++ u){
		int d;
		cin >> d;
		for(auto l = u - d + n, r = u + 1 + n; l < r; l >>= 1, r >>= 1){
			if(l & 1) g.orient(u + 2 * n, l, 1), ++ l;
			if(r & 1) -- r, g.orient(u + 2 * n, r, 1);
		}
	}
	for(auto u = 1; u < n; ++ u){
		int b;
		cin >> b;
		g.orient(u + n, u + b + 2 * n);
	}
	dial<int> D(n * 3);
	D.run(g, 2, {2 * n - 1});
	if(D.dist[n] < numeric_limits<int>::max()){
		cout << D.dist[n] << "\n";
		vector<int> path;
		for(auto u = n; u != 2 * n - 1; u = D.pv[u]){
			if(n <= u && u < 2 * n){
				path.push_back(u);
			}
		}
		reverse(path.begin(), path.end());
		for(auto u: path){
			cout << u - n << " ";
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