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
template<class T>
struct dfs_forest{
	int n;
	vector<T> dist;
	vector<int> pv, pe, order, pos, end, size, root, depth, min_depth, was;
	T T_id;
	dfs_forest(int n, T T_id = 0): T_id(T_id){ init(n); }
	void init(int n){
		this->n = n;
		pv.assign(n, -1);
		pe.assign(n, -1);
		order.clear();
		pos.assign(n, -1);
		end.assign(n, -1);
		size.assign(n, 0);
		root.assign(n, -1);
		depth.assign(n, -1);
		min_depth.assign(n, -1);
		dist.assign(n, T_id);
		was.assign(n, -1);
		attempt = 0;
	}
	int attempt;
	template<class U, class F = plus<>>
	void dfs(const graph<U> &g, int u, bool clear_order = true, F UT = plus<>()){
		assert(n == g.n);
		++ attempt;
		depth[u] = 0;
		dist[u] = T_id;
		root[u] = u;
		pv[u] = pe[u] = -1;
		if(clear_order) order.clear();
		auto recurse = [&](auto self, int u)->void{
			was[u] = attempt;
			pos[u] = (int)order.size();
			order.push_back(u);
			size[u] = 1;
			min_depth[u] = depth[u];
			for(auto id: g.adj[u]){
				if(id == pe[u] || g.ignore && g.ignore(id)) continue;
				auto &e = g.edge[id];
				int v = e.from ^ e.to ^ u;
				if(was[v] == attempt){
					min_depth[u] = min(min_depth[u], depth[v]);
					continue;
				}
				depth[v] = depth[u] + 1;
				dist[v] = UT(e.cost, dist[u]);
				pv[v] = u;
				pe[v] = id;
				root[v] = root[u];
				self(self, v);
				size[u] += size[v];
				min_depth[u] = min(min_depth[u], min_depth[v]);
			}
			end[u] = (int)order.size();
		};
		recurse(recurse, u);
	}
	template<class U, class F = plus<>>
	void dfs_all(const graph<U> &g, F UT = plus<>()){
		for(auto u = 0; u < n; ++ u) if(!~depth[u]) dfs<U, F>(g, u, false, UT);
	}
};

template<class T>
T &ctmin(T &x){
	return x;
}
template<class T, class Head, class ...Tail>
T &ctmin(T &x, const Head &h, const Tail &... t){
	return ctmin(x = min<T>(x, h), t...);
}
template<class T>
T &ctmax(T &x){
	return x;
}
template<class T, class Head, class ...Tail>
T &ctmax(T &x, const Head &h, const Tail &... t){
	return ctmax(x = max<T>(x, h), t...);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	graph<int> g(n);
	for(auto i = 0; i < n - 1; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.link(u, v, 1);
	}
	dfs_forest<int> df(n);
	df.dfs(g, 0);
	vector<int> leaf, is_leaf(n);
	for(auto u = 1; u < n; ++ u){
		if(g.degree(u) == 1){
			leaf.push_back(u);
			is_leaf[u] = true;
		}
	}
	if((int)size(leaf) <= k){
		long long res = 0;
		for(auto red = (int)size(leaf); red <= k; ++ red){
			ctmax(res, 1LL * (n - red) * red);
		}
		cout << res << "\n";
		return 0;
	}
	vector<int> dp(n);
	for(auto t = n - 1; t >= 0; -- t){
		int u = df.order[t];
		if(is_leaf[u]){
			dp[u] = u;
		}
		else{
			dp[u] = u;
			for(auto id: g.adj[u] | ranges::views::filter([&](int id){ return !g.ignore || !g.ignore(id);})){
				auto &e = g.edge[id];
				int v = u ^ e.from ^ e.to;
				if(df.pv[u] == v){
					continue;
				}
				if(df.depth[dp[u]] < df.depth[dp[v]]){
					dp[u] = dp[v];
				}
			}
		}
	}
	priority_queue<array<int, 2>> pq;
	pq.push({df.depth[dp[0]] + 1, 0});
	int red = 0;
	for(auto _: ranges::iota_view(0, k)){
		static vector<int> alive(n, true);
		assert(!pq.empty());
		auto [delta, u] = pq.top();
		pq.pop();
		alive[u] = false;
		red += delta;
		for(auto v = dp[u]; ; v = df.pv[v]){
			alive[v] = false;
			for(auto id: g.adj[v] | ranges::views::filter([&](int id){ return !g.ignore || !g.ignore(id);})){
				auto &e = g.edge[id];
				int w = v ^ e.from ^ e.to;
				if(df.pv[v] == w || !alive[w]){
					continue;
				}
				pq.push({df.depth[dp[w]] - df.depth[w] + 1, w});
			}
			if(u == v){
				break;
			}
		}
	}
	long long res = numeric_limits<long long>::max();
	for(auto blue = 0; blue <= n - red; ++ blue){
		ctmin(res, (n - k - blue) * 1LL * (k - blue));
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////