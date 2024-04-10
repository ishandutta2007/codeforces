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

// O(log n) applications of insert() and erase(), O(n) applications of answer()
// Requires graph
template<class T>
struct small_to_large_on_forest{
	int n;
	graph<T> g;
	vector<int> roots, sz, order, pos, end;
	small_to_large_on_forest(const graph<T> &g, const vector<int> &_roots): n(g.n), g(g), sz(n, 1), pos(n, -1), end(n, -1), roots(_roots){
		auto dfs = [&](auto self, int u, int pe)->void{
			pos[u] = (int)order.size();
			order.push_back(u);
			for(auto id: g.adj[u]){
				if(id == pe || g.ignore && g.ignore(id)) continue;
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				self(self, v, id);
				sz[u] += sz[v];
			}
			end[u] = (int)order.size();
		};
		for(auto u: roots) assert(!~pos[u]), dfs(dfs, u, -1);
	}
	void solve(int root, auto insert, auto clear, auto answer){
		auto dfs = [&](auto self, int u, int pe, bool keep)->void{
			int hv = -1, hid = -1;
			for(auto id: g.adj[u]){
				if(id == pe || g.ignore && g.ignore(id)) continue;
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				if(!~hv || sz[hv] < sz[v]) hv = v, hid = id;
			}
			for(auto id: g.adj[u]){
				if(id == pe || id == hid || g.ignore && g.ignore(id)) continue;
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				self(self, v, id, false);
			}
			if(~hid) self(self, hv, hid, true);
			for(auto id: g.adj[u]){
				if(id == pe || id == hid || g.ignore && g.ignore(id)) continue;
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				for(auto i = pos[v]; i < end[v]; ++ i) insert(order[i]);
			}
			answer(u, false), insert(u), answer(u, true);
			if(!keep) clear(u);
		};
		dfs(dfs, root, -1, false);
	}
	void solve(auto insert, auto clear, auto answer){
		for(auto r: roots) solve(r, insert, clear, answer);
	}
};

struct line_type{
	mutable long long d, k, p;
	bool operator<(const line_type &otr) const{ return d < otr.d; }
	bool operator<(long long x) const{ return p < x;}
	friend ostream &operator<<(ostream &out, const line_type &L){
		return out << "{" << L.d << ", " << L.k << ", " << L.p << "}";
	}
};
template<bool GET_MAX = true>
struct line_container: multiset<line_type, less<>>{
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static constexpr long long inf = numeric_limits<long long>::max();
	long long div(long long a, long long b){ return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y){
		if(y == end()){ x->p = inf; return false; }
		if(x->d == y->d) x->p = x->k > y->k ? inf : -inf;
		else x->p = div(y->k - x->k, x->d - y->d);
		return x->p >= y->p;
	}
	void push(line_type L){
		if(!GET_MAX) L.d = -L.d, L.k = -L.k;
		L.p = 0;
		auto z = insert(L), y = z ++, x = y;
		while(isect(y, z)) z = erase(z);
		if(x != begin() && isect(-- x, y)) isect(x, y = erase(y));
		while((y = x) != begin() && (-- x)->p >= y->p) isect(x, erase(y));
	}
	long long query(long long x){
		assert(!empty());
		auto l = *lower_bound(x);
		return (l.d * x + l.k) * (GET_MAX ? 1 : -1);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(auto u = 0; u < n; ++ u){
		cin >> a[u];
	}
	for(auto u = 0; u < n; ++ u){
		cin >> b[u];
	}
	graph<int> g(n);
	for(auto i = 0; i < n - 1; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.link(u, v);
	}
	line_container<false> lc;
	vector<long long> res(n);
	auto insert = [&](int u)->void{
		lc.push({b[u], res[u]});
	};
	auto clear = [&](int u)->void{
		lc.clear();
	};
	auto answer = [&](int u, bool contain_itself)->void{
		if(!contain_itself && !lc.empty()){
			res[u] = lc.query(a[u]);
		}
	};
	small_to_large_on_forest stl(g, {0});
	stl.solve(insert, clear, answer);
	for(auto x: res){
		cout << x << " ";
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