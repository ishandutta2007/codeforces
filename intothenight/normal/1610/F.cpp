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

// Decompose the given loopless undirected graph into endpoint disjoint paths and cycles
// O(|V| + |E|)
template<class T>
void euler_decomopsition(const graph<T> &g, auto process_path, auto process_cycle){
	int n = g.n, m = (int)g.edge.size();
	vector<array<int, 2>> edge;
	vector<vector<array<int, 2>>> adj(m);
	for(auto u = 0; u < n; ++ u){
		int j = -1;
		for(auto i: g.adj[u]){
			if(g.ignore && g.ignore(i)) continue;
			if(!~j) j = i;
			else{
				int id = (int)edge.size();
				adj[i].push_back({id, u}), adj[j].push_back({id, u});
				edge.push_back({i, j});
				j = -1;
			}
		}
	}
	vector<int> vis(m);
	auto update = [&](int u)->void{
		vis[u] = true;
		vector<int> path{u};
		int end = g.edge[u].from;
		for(auto [id, w]: adj[u]){
			reverse(path.begin(), path.end());
			for(auto v = u ^ edge[id][0] ^ edge[id][1]; !vis[v]; ){
				vis[v] = true;
				path.push_back(v);
				end = w ^= g.edge[v].from ^ g.edge[v].to;
				if((int)adj[v].size() == 1) break;
				id ^= adj[v][0][0] ^ adj[v][1][0];
				v ^= edge[id][0] ^ edge[id][1];
			}
		}
		int start = end;
		for(auto it = path.rbegin(); it != path.rend(); ++ it) start ^= g.edge[*it].from ^ g.edge[*it].to;
		if(start != end) process_path(start, end, path);
		else process_cycle(start, path);
	};
	for(auto u = 0; u < m; ++ u){
		if((int)adj[u].size() == 2 || vis[u] || g.ignore && g.ignore(u)) continue;
		update(u);
	}
	for(auto u = 0; u < m; ++ u){
		if(vis[u] || g.ignore && g.ignore(u)) continue;
		update(u);
	}
}

template<class F>
struct y_combinator_result{
	F f;
	template<class T> explicit y_combinator_result(T &&f): f(forward<T>(f)){ }
	template<class ...Args> decltype(auto) operator()(Args &&...args){ return f(ref(*this), forward<Args>(args)...); }
};
template<class F>
decltype(auto) y_combinator(F &&f){
	return y_combinator_result<decay_t<F>>(forward<F>(f));
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	graph<int> g(n);
	for(auto i = 0; i < m; ++ i){
		int u, v, w;
		cin >> u >> v >> w, -- u, -- v;
		g.link(u, v, w);
	}
	int res_cnt = 0;
	vector<int> res(m);
	vector<tuple<int, int, vector<int>, int>> paths;
	for(auto w = 1; w <= 2; ++ w){
		g.set_ignoration_rule([&](int id){ return g.edge[id].cost != w; });
		euler_decomopsition(g, [&](int start, int end, const vector<int> &path){
			paths.push_back({start, end, path, w});
			if(w == 1){
				res_cnt += 2;
			}
		},
		[&](int start, const vector<int> &cycle){
			int u = start;
			for(auto id: cycle){
				auto &e = g.edge[id];
				res[id] = 1 + (u == e.to);
				u ^= e.from ^ e.to;
			}
		});
	}
	int k = (int)paths.size();
	vector<vector<int>> adj(n);
	for(auto i = 0; i < k; ++ i){
		auto &[u, v, p, w] = paths[i];
		adj[u].push_back(i);
		adj[v].push_back(i);
	}
	vector<int> vis(k);
	for(auto i = 0; i < k; ++ i){
		if(vis[i]){
			continue;
		}
		y_combinator([&](auto self, int i)->void{
			vis[i] = true;
			auto &[u, v, p, w] = paths[i];
			{
				for(auto j: adj[u]){
					if(vis[j]){
						continue;
					}
					if(u != get<1>(paths[j])){
						swap(get<0>(paths[j]), get<1>(paths[j]));
						reverse(get<2>(paths[j]).begin(), get<2>(paths[j]).end());
					}
					self(j);
				}
			}
			{
				for(auto j: adj[v]){
					if(vis[j]){
						continue;
					}
					if(v != get<0>(paths[j])){
						swap(get<0>(paths[j]), get<1>(paths[j]));
						reverse(get<2>(paths[j]).begin(), get<2>(paths[j]).end());
					}
					self(j);
				}
			}
		})(i);
	}
	for(auto &[u, v, path, w]: paths){
		for(auto id: path){
			auto &e = g.edge[id];
			res[id] = 1 + (e.to == u);
			u ^= e.from ^ e.to;
		}
	}
	cout << res_cnt << "\n";
	for(auto x: res){
		assert(x);
		cout << x;
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