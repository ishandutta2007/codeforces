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
	int n;
	cin >> n;
	vector<long long> rem(n);
	for(auto u = 0; u < n; ++ u){
		cin >> rem[u];
	}
	long long init = accumulate(rem.begin(), rem.end(), 0LL);
	graph<int> g(n);
	for(auto i = 0; i < n - 1; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.link(u, v, 1);
	}
	vector<long long> step(n, 1);
	vector<int> deg(n);
	y_combinator([&](auto self, int u, int pe)->void{
		for(auto id: g.adj[u]){
			if(id == pe || g.ignore && g.ignore(id)) continue;
			auto &e = g.edge[id];
			int v = u ^ e.from ^ e.to;
			self(v, id);
			if(deg[u]){
				rem[u] /= deg[u];
				step[u] /= deg[u];
				while(rem[u] != rem[v]){
					if(rem[u] > rem[v]){
						rem[u] -= (rem[u] - rem[v] + step[u] - 1) / step[u] * step[u];
					}
					else{
						rem[v] -= (rem[v] - rem[u] + step[v] - 1) / step[v] * step[v];
					}
				}
			}
			rem[u] = rem[u] * deg[u] + rem[v];
			++ deg[u];
			step[u] = lcm(step[u], step[v]) * deg[u];
		}

	})(0, -1);
	cout << init - rem[0] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////