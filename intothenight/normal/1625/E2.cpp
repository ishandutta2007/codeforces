#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

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
	vector<int> pv;
	vector<int> pe;
	vector<int> order;
	vector<int> pos;
	vector<int> end;
	vector<int> size;
	vector<int> root;
	vector<int> depth;
	vector<int> min_depth;
	vector<int> min_depth_origin;
	vector<int> min_depth_spanning_edge;
	vector<int> was;
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
		min_depth_origin.assign(n, -1);
		min_depth_spanning_edge.assign(n, -1);
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
			min_depth_origin[u] = u;
			min_depth_spanning_edge[u] = -1;
			for(auto id: g.adj[u]){
				if(id == pe[u] || g.ignore && g.ignore(id)) continue;
				auto &e = g.edge[id];
				int v = e.from ^ e.to ^ u;
				if(was[v] == attempt){
					if(min_depth[u] > depth[v]){
						min_depth[u] = depth[v];
						min_depth_spanning_edge[u] = id;
					}
					continue;
				}
				depth[v] = depth[u] + 1;
				dist[v] = UT(e.cost, dist[u]);
				pv[v] = u;
				pe[v] = id;
				root[v] = root[u];
				self(self, v);
				size[u] += size[v];
				if(min_depth[u] > min_depth[v]){
					min_depth[u] = min_depth[v];
					min_depth_origin[u] = min_depth_origin[v];
					min_depth_spanning_edge[u] = min_depth_spanning_edge[v];
				}
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
struct fenwick_tree{
	int n;
	vector<T> data;
	fenwick_tree(){ }
	// O(n)
	fenwick_tree(int n): n(n), data(n){ }
	// O(n)
	fenwick_tree(int n, T init): fenwick_tree(vector<T>(n, init)){ }
	// O(n)
	fenwick_tree(const vector<T> &v): n((int)v.size()), data(v){
		for(auto i = 1; i <= n; ++ i) if(i + (i & -i) <= n) data[i + (i & -i) - 1] += data[i - 1];
	}
	fenwick_tree(const fenwick_tree &otr): n(otr.n), data(otr.data){
	}
	// O(log n)
	void update(int p, T x){
		assert(0 <= p && p < n);
		for(++ p; p <= n; p += p & -p) data[p - 1] += x;
	}
	// O(log n)
	T query(int r) const{
		T s{};
		for(; r > 0; r -= r & -r) s += data[r - 1];
		return s;
	}
	// O(log n)
	T query(int l, int r) const{
		assert(0 <= l && l <= r && r <= n);
		return query(r) - query(l);
	}
	// pred(sum[0, r)) is T, T, ..., T, F, F, ..., F
	// Returns max r with T
	// O(log n)
	int max_pref(auto pred) const{
		assert(pred({}));
		int p = 0;
		T sum{};
		for(auto pw = 1 << __lg(n + 1); pw; pw >>= 1) if(p + pw <= n && pred(sum + data[p + pw - 1])){
			sum += data[p + pw - 1];
			p += pw;
		}
		return p;
	}
	template<class output_stream>
	friend output_stream &operator<<(output_stream &out, const fenwick_tree<T> &fw){
		out << "[";
		for(auto i = 0; i < fw.n; ++ i){
			out << fw.query(i, i + 1);
			if(i != fw.n - 1) out << ", ";
		}
		return out << ']';
	}
};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T, class U, class Compare = less<>> using order_statistic_map = tree<T, U, Compare, rb_tree_tag, tree_order_statistics_node_update>;
template<class T, class Compare = less<>> using order_statistic_set = order_statistic_map<T, null_type, Compare>;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	string s;
	cin >> n >> qn >> s;
	vector<int> match(n, -1);
	{
		vector<int> stack;
		for(auto i = 0; i < n; ++ i){
			if(s[i] == '('){
				stack.push_back(i);
			}
			else if(!stack.empty()){
				match[stack.back()] = i;
				match[i] = stack.back();
				stack.pop_back();
			}
		}
	}
	vector<int> repr(n, -1);
	vector<int> edge_order;
	vector<int> deg;
	vector<vector<int>> adj;
	graph<int> g(n);
	int root = y_combinator([&](auto self, int l, int r)->int{
		static int it = 0;
		int u = it ++;
		deg.push_back(0);
		for(auto i = l; i < r; ++ i){
			if(~match[i]){
				++ deg[u];
				int v = self(i + 1, match[i]);
				int id = g.orient(u, v, i);
				edge_order.push_back((int)g.adj[u].size() - 1);
				repr[i] = repr[match[i]] = id;
				i = match[i];
			}
		}
		return u;
	})(0, n);
	dfs_forest<int> df(n);
	df.dfs(g, root);
	vector<long long> init;
	for(auto u: df.order){
		init.push_back(1LL * deg[u] * (deg[u] + 1) / 2);
	}
	fenwick_tree<long long> fw(init);
	vector<order_statistic_set<int>> rem(n);
	for(auto u = 0; u < n; ++ u){
		for(auto id: g.adj[u]){
			rem[u].insert(id);
		}
	}
	for(auto qi = 0; qi < qn; ++ qi){
		int t, l, r;
		cin >> t >> l >> r, -- l;
		if(t == 1){
			int id = repr[l];
			assert(repr[r - 1] == id);
			int u = g.edge[id].from;
			fw.update(df.pos[u], -(deg[u] --));
			rem[u].erase(id);
		}
		else{
			-- r;
			int id_l = repr[l], id_r = repr[r];
			int u = g.edge[id_l].to, v = g.edge[id_r].to;
			int root = g.edge[id_l].from;
			int cnt = rem[root].order_of_key(id_r + 1) - rem[root].order_of_key(id_l);
			cout << fw.query(df.pos[u], df.end[v]) + 1LL * cnt * (cnt + 1) / 2 << "\n";
		}
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