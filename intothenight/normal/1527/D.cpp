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
	function<bool(int)> ignore;
	graph(int n): n(n), adj(n){ }
	int link(int u, int v, T w = {}){ // insert an undirected edge
		int id = (int)edges.size();
		adj[u].push_back(id), adj[v].push_back(id), edges.push_back({u, v, w});
		return id;
	}
	int orient(int u, int v, T w = {}){ // insert a directed edge
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
	int degree(int u) const{ // the degree (outdegree if directed) of u (without the ignoration rule)
		return (int)adj[u].size();
	}
	vector<vector<int>> get_adjacency_list() const{
		vector<vector<int>> res(n);
		for(auto u = 0; u < n; ++ u) for(auto id: adj[u]){
			if(ignore && ignore(id)) continue;
			auto &e = edges[id];
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
	vector<int> pv, pe, order, pos, end, sz, root, depth, min_depth, was;
	T T_id;
	dfs_forest(int n, T T_id = 0): T_id(T_id){ init(n); }
	void init(int n){
		this->n = n;
		pv.assign(n, -1);
		pe.assign(n, -1);
		order.clear();
		pos.assign(n, -1);
		end.assign(n, -1);
		sz.assign(n, 0);
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
		auto recurse = [&](auto recurse, int u)->void{
			was[u] = attempt;
			pos[u] = (int)order.size();
			order.push_back(u);
			sz[u] = 1;
			min_depth[u] = depth[u];
			for(auto id: g.adj[u]){
				if(id == pe[u] || g.ignore && g.ignore(id)) continue;
				auto &e = g.edges[id];
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
				recurse(recurse, v);
				sz[u] += sz[v];
				min_depth[u] = min(min_depth[u], min_depth[v]);
			}
			end[u] = (int)order.size();
		};
		recurse(recurse, u);
	}
	template<class U, class F>
	void dfs_all(const graph<U> &g, F UT = plus<>()){
		for(auto u = 0; u < n; ++ u) if(!~depth[u]) dfs<U, F>(g, u, false, UT);
	}
};

template<class T>
struct counting_iterator{
	T value = 0;
	using iterator_category = random_access_iterator_tag;
	using value_type = T;
	using difference_type = T;
	using pointer = T *;
	using reference = T &;
	counting_iterator(){ }
	counting_iterator(const T &value): value(value){ }
	counting_iterator(const counting_iterator &it): value(it.value){ }
	T &operator*(){ return value; }
	T operator-(const counting_iterator &it) const{ return value - it.value; }
	counting_iterator &operator++(){ return ++ value, *this; }
	counting_iterator &operator--(){ return -- value, *this; }
	counting_iterator &operator+=(const T &x){ return value += x, *this; }
};
using iterint = counting_iterator<int>;
using iterll = counting_iterator<long long>;

template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

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
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		graph<int> g(n);
		for(auto i = 0; i < n - 1; ++ i){
			int u, v;
			cin >> u >> v;
			g.link(u, v);
		}
		dfs_forest<int> df0(n), df1(n);
		df0.dfs<int>(g, 0);
		vector<long long> pass(n + 1);
		auto ispath = [&](int x)->bool{
			int u = max_element(df0.depth.begin(), df0.depth.begin() + x) - df0.depth.begin();
			df1.dfs<int>(g, u);
			int v = max_element(df1.depth.begin(), df1.depth.begin() + x) - df1.depth.begin();
			vector<bool> appear(n);
			while(v != u){
				appear[v] = true;
				v = df1.pv[v];
			}
			appear[u] = true;
			for(auto u = 0; u < x; ++ u){
				if(!appear[u]){
					return false;
				}
			}
			return true;
		};
		int x = *partition_point(iterint(2), iterint(n + 1), ispath) - 1;
		int u = max_element(df0.depth.begin(), df0.depth.begin() + x) - df0.depth.begin();
		df1.dfs<int>(g, u);
		int v = max_element(df1.depth.begin(), df1.depth.begin() + x) - df1.depth.begin();
		vector<int> pos(n, -1), path;
		while(v != u){
			pos[v] = (int)path.size();
			path.push_back(v);
			v = df1.pv[v];
		}
		pos[u] = (int)path.size();
		path.push_back(u);
		vector<int> minpos = pos, maxpos = pos;
		for(auto u = 1; u < n; ++ u){
			ctmin(minpos[u], minpos[u - 1]);
			ctmax(maxpos[u], maxpos[u - 1]);
		}
		vector<long long> cnt(n + 2); // cnt[x]: # of paths which passes through first x vertices
		cnt[0] = 1LL * n * (n - 1) / 2;
		int sum = 0;
		for(auto id: g.adj[0]){
			auto &e = g.edges[id];
			int u = e.from ^ e.to;
			cnt[1] += 1LL * sum * df0.sz[u];
			sum += df0.sz[u];
		}
		cnt[1] += df0.sz[0] - 1;
		vector<int> sroot(n, -1);
		for(auto id: g.adj[0]){
			auto &e = g.edges[id];
			int root = e.from ^ e.to;
			y_combinator([&](auto self, int u, int pe)->void{
				sroot[u] = root;
				for(auto id: g.adj[u]){
					if(id == pe || g.ignore && g.ignore(id)) continue;
					auto &e = g.edges[id];
					int v = u ^ e.from ^ e.to;
					self(v, id);
				}
			})(root, id);
		}
		for(auto s = 2; s <= x; ++ s){
			if(minpos[s - 1] == pos[0]){
				int u = path[maxpos[s - 1]], r = sroot[u];
				cnt[s] = 1LL * df0.sz[u] * (df0.sz[0] - df0.sz[r]);
			}
			else if(maxpos[s - 1] == pos[0]){
				int u = path[minpos[s - 1]], r = sroot[u];
				cnt[s] = 1LL * df0.sz[u] * (df0.sz[0] - df0.sz[r]);
			}
			else{
				int u = path[minpos[s - 1]], v = path[maxpos[s - 1]];
				cnt[s] = 1LL * df0.sz[u] * df0.sz[v];
			}
		}
		for(auto k = 0; k <= n; ++ k){
			cout << cnt[k] - cnt[k + 1] << " ";
		}
		cout << "\n";
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