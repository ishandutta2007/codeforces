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
struct bfs_forest{
	int n;
	vector<T> dist;
	vector<int> pv, pe, order, pos, root, depth, was;
	T T_id;
	bfs_forest(int n, T T_id = 0): T_id(T_id){
		init(n);
	}
	void init(int n){
		this->n = n;
		pv.assign(n, -1);
		pe.assign(n, -1);
		order.clear();
		pos.assign(n, -1);
		root.assign(n, -1);
		depth.assign(n, -1);
		dist.assign(n, T_id);
		was.assign(n, -1);
		attempt = 0;
	}
	int attempt = 0;
	template<class U, class F = plus<>>
	void bfs(const graph<U> &g, const vector<int> &src, bool clear_order = true, F UT = plus<>()){
		assert(n == g.n);
		++ attempt;
		if(clear_order) order.clear();
		deque<int> dq;
		for(auto u: src){
			was[u] = attempt;
			depth[u] = 0;
			dist[u] = T_id;
			root[u] = u;
			pv[u] = pe[u] = -1;
			dq.push_back(u);
		}
		while(!dq.empty()){
			int u = dq.front(); dq.pop_front();
			pos[u] = (int)order.size();
			order.push_back(u);
			for(auto id: g.adj[u]){
				if(g.ignore && g.ignore(id)) continue;
				auto &e = g.edge[id];
				int v = u ^ e.from ^ e.to;
				if(was[v] == attempt) continue;
				was[v] = attempt;
				depth[v] = depth[u] + 1;
				dist[v] = UT(e.cost, dist[u]);
				pv[v] = u;
				pe[v] = id;
				root[v] = root[u];
				dq.push_back(v);
			}
		}
	}
	template<class U, class F = plus<>>
	void bfs_all(const graph<U> &g, F UT = plus<>()){
		for(int u = 0; u < n; ++ u) if(!~depth[u]) bfs<U, F>(g, {u}, false, UT);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, k;
		cin >> n >> k;
		graph<int> g(n);
		for(auto i = 0; i < n - 1; ++ i){
			int u, v;
			cin >> u >> v, -- u, -- v;
			g.link(u, v, 1);
		}
		vector<int> deg(n), used(n);
		deque<int> dq;
		for(auto u = 0; u < n; ++ u){
			if((deg[u] = g.degree(u)) <= 1){
				used[u] = true;
				dq.push_back(u);
			}
		}
		int res = n;
		for(auto rep = k; rep && !dq.empty(); -- rep){
			int sz = (int)dq.size();
			res -= sz;
			for(auto rep = sz; rep; -- rep){
				int u = dq.front();
				dq.pop_front();
				for(auto id: g.adj[u]){
					if(g.ignore && g.ignore(id)) continue;
					auto &e = g.edge[id];
					int v = u ^ e.from ^ e.to;
					if(used[v]) continue;
					-- deg[v];
					if(deg[v] <= 1){
						used[v] = true;
						dq.push_back(v);
					}
				}
			}
		}
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