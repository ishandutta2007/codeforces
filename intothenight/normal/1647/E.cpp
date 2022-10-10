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
template<int h = 20>
struct binary_lifting{
	int n = 0;
	vector<int> depth;
	vector<array<int, h>> lift;
	binary_lifting(){ }
	// pv: parent vertex (-1 if root of an arborescence)
	binary_lifting(const vector<int> &pv): n((int)pv.size()), depth(n, numeric_limits<int>::max()), lift(n){
		for(auto u = 0; u < n; ++ u) lift[u][0] = ~pv[u] ? pv[u] : u;
		for(auto bit = 1; bit < h; ++ bit) for(auto u = 0; u < n; ++ u) lift[u][bit] = lift[lift[u][bit - 1]][bit - 1];
	}
	template<class T>
	binary_lifting(const graph<T> &g, const vector<int> &roots){
		vector<int> pv(g.n, -1), depth(g.n);
		auto dfs = [&](auto self, int u, int pe)->void{
			for(auto id: g.adj[u]){
				if(id == pe || g.ignore && g.ignore(id)) continue;
				auto &e = g.edge[id];
				int v = u ^ e.from ^ e.to;
				depth[v] = depth[u] + 1;
				pv[v] = u;
				self(self, v, id);
			}
		};
		for(auto u: roots) assert(!depth[u]), pv[u] = u, dfs(dfs, u, -1);
		*this = binary_lifting(pv, depth);
	}
	// pv: parent vertex (-1 if root of an arborescence)
	binary_lifting(const vector<int> &pv, const vector<int> &depth): n((int)pv.size()), depth(depth){
		lift.resize(n);
		for(auto u = 0; u < n; ++ u) lift[u][0] = ~pv[u] ? pv[u] : u;
		for(auto d = 1; d < h; ++ d) for(auto u = 0; u < n; ++ u) lift[u][d] = lift[lift[u][d - 1]][d - 1];
	}
	// Index becomes the current number of nodes
	// O(log n)
	int add_root(){
		int u = n ++;
		depth.push_back(0);
		lift.emplace_back();
		fill(lift.back().begin(), lift.back().end(), u);
		return u;
	}
	// Index becomes the current number of nodes
	// O(log n)
	int add_child(int p){
		assert(0 <= p && p < n);
		int u = n ++;
		depth.push_back(depth[p] + 1);
		lift.emplace_back();
		lift[u][0] = p;
		for(auto d = 1; d < h; ++ d) lift[u][d] = lift[lift[u][d - 1]][d - 1];
	}
	// Get the k-th ancestor of u
	// O(log n)
	int ancestor(int u, int k) const{
		for(auto d = 0; d < h; ++ d) if(k & 1 << d) u = lift[u][d];
		return u;
	}
	// Assumes u and v lies on the same arboresence
	// O(log n)
	int lca(int u, int v) const{
		if(depth[u] < depth[v]) swap(u, v);
		u = ancestor(u, depth[u] - depth[v]);
		if(u == v) return u;
		for(auto d = h - 1; d >= 0; -- d) if(lift[u][d] != lift[v][d]) u = lift[u][d], v = lift[v][d];
		return lift[u][0];
	}
	// Get # of edges between u and v
	// Assumes u and v lies on the same arboresence
	// O(log n)
	int steps(int u, int v, int w = -1) const{
		return depth[u] + depth[v] - 2 * depth[~w ? w : lca(u, v)];
	}
	// For an ancestor p of u, pred(p) is T, ..., T, F, ..., F in decreasing order of depth. Returns the highest p with T
	// O(log n)
	int find_highest(int u, auto pred) const{
		assert(pred(u));
		for(auto d = h - 1; d >= 0; -- d) if(pred(lift[u][d])) u = lift[u][d];
		return u;
	}
};

// Requires graph
struct functional_graph_processor{
	int n;
	vector<vector<int>> cycle; // main cycles
	vector<int> cycle_id; // id of the cycle it belongs to, -1 if not part of one
	vector<int> cycle_pos; // position in the cycle, -1 if not part of one
	vector<int> prev; // previous vertex in the cycle, -1 if not part of one
	vector<int> size; // size of the weakly connected component of the i-th main cycle
	vector<int> root; // first reachable node in the main cycle
	vector<int> depth; // # of edges from the main cycle
	graph<int> abr; // forest of arborescences of reversed edges not on the main cycle
	functional_graph_processor(const vector<int> &next): n((int)next.size()), cycle_id(n, -1), cycle_pos(n, -1), root(n, -1), depth(n, -1), abr(n){
		vector<int> was(n);
		for(auto u = 0; u < n; ++ u){
			if(was[u]) continue;
			int v = u;
			while(!was[v]){
				was[v] = true;
				v = next[v];
			}
			if(!~depth[v]){
				int w = v;
				vector<int> c;
				while(!~depth[w]){
					cycle_id[w] = (int)cycle.size();
					cycle_pos[w] = (int)c.size();
					c.push_back(w);
					root[w] = w;
					depth[w] = 0;
					w = next[w];
				}
				cycle.push_back(c);
				size.push_back((int)cycle.size());
			}
			auto dfs = [&](auto self, int u)->void{
				if(~depth[u]) return;
				int v = next[u];
				self(self, v);
				root[u] = root[v];
				++ size[cycle_id[root[u]]];
				depth[u] = depth[v] + 1;
				abr.orient(v, u, 1);
			};
			dfs(dfs, u);
		}
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> next(n);
	for(auto i = 0; i < n; ++ i){
		cin >> next[i], -- next[i];
	}
	functional_graph_processor fgp(next);
	vector<int> all_roots;
	for(auto c: fgp.cycle){
		all_roots.insert(all_roots.end(), c.begin(), c.end());
	}
	binary_lifting lift(fgp.abr, all_roots);
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i], -- a[i];
	}
	vector<int> leaf;
	for(auto i = 0; i < n; ++ i){
		if(!fgp.abr.degree(i) && fgp.depth[i]){
			leaf.push_back(i);
		}
	}
	assert(!leaf.empty());
	int move = a[leaf[0]] < n ? 0 : (a[leaf[0]] - n) / (int)leaf.size() + 1;
	vector<int> belong(n, -1);
	vector<vector<int>> has(n);
	set<int> unused;
	for(auto i = 0; i < n; ++ i){
		unused.insert(i);
	}
	for(auto i = 0; i < n; ++ i){
		int j;
		if(fgp.depth[i] > move){
			j = lift.ancestor(i, move);
		}
		else{
			int rem = move - fgp.depth[i];
			int r = fgp.root[i], id = fgp.cycle_id[r];
			int p = (fgp.cycle_pos[r] + rem) % (int)fgp.cycle[id].size();
			j = fgp.cycle[id][p];
		}
		belong[i] = j;
		has[j].push_back(i);
		if(unused.contains(a[j])){
			unused.erase(a[j]);
		}
	}
	vector<int> res(n, -1);
	vector<int> first(n, true);
	for(auto i = 0; i < n; ++ i){
		int j = belong[i];
		if(first[j]){
			res[i] = a[j] + 1;
			first[j] = false;
		}
		else{
			auto it = unused.lower_bound(a[j]);
			assert(it != unused.end());
			res[i] = *it + 1;
			unused.erase(it);
		}
	}
	ranges::copy(res, ostream_iterator<int>(cout, " "));
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