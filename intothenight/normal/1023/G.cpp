#include <bits/stdc++.h>
using namespace std;

// DEBUG BEGIN
#ifdef LOCAL
template<class L, class R> ostream &operator<<(ostream &out, const pair<L, R> &p){
	return out << "(" << p.first << ", " << p.second << ")";
}
template<class Tuple, size_t N> struct TuplePrinter{
	static ostream &print(ostream &out, const Tuple &t){ return TuplePrinter<Tuple, N-1>::print(out, t) << ", " << get<N-1>(t); }
};
template<class Tuple> struct TuplePrinter<Tuple, 1>{
	static ostream &print(ostream &out, const Tuple& t){ return out << get<0>(t); }
};
template<class... Args> ostream &print_tuple(ostream &out, const tuple<Args...> &t){
	return TuplePrinter<decltype(t), sizeof...(Args)>::print(out << "(", t) << ")";
}
template<class ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){
	return print_tuple(out, t);
}
template<class T> ostream &operator<<(enable_if_t<!is_same<T, string>::value, ostream> &out, const T &arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<size_t S> ostream &operator<<(ostream &out, const bitset<S> &b){
	for(int i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void debug2_out(){ cerr << "-----DEBUG END-----\n"; }
template<class Head, class... Tail>
void debug2_out(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; debug2_out(T...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#define debug2(...) cerr << "----DEBUG BEGIN----\n[" << #__VA_ARGS__ << "]:", debug2_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug2(...) 42
#endif
// DEBUG END

template<class T>
struct graph{
	struct edge{
		int from, to;
		T cost;
	};
	int n;
	vector<edge> edges;
	vector<vector<int>> adj;
	function<bool(int)> ignore; // edge ignoration rule
	graph(int n): n(n), adj(n), ignore(nullptr){
	}
	int link(int u, int v, T w = 1){ // insert an undirected edge
		int id = (int)edges.size();
		adj[u].push_back(id), adj[v].push_back(id), edges.push_back({u, v, w});
		return id;
	}
	int orient(int u, int v, T w = 1){ // insert a directed edge
		int id = (int)edges.size();
		adj[u].push_back(id), edges.push_back({u, v, w});
		return id;
	}
	graph transposed() const{ // returns the transpose of the directed graph
		graph res(n);
		for(auto &e: edges) res.orient(e.to, e.from, e.cost);
		res.ignore = ignore;
		return res;
	}
};

using namespace chrono;
mt19937 rng(2);
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());

// Requires random
template<class Q, Q (*merge)(const Q &, const Q &), Q (*identity)()>
struct treap_base{
	vector<int> left, right, priority, sz;
	vector<Q> val, subtr_val;
	void refresh(int u){
		sz[u] = (~left[u] ? sz[left[u]] : 0) + 1 + (~right[u] ? sz[right[u]] : 0);
		subtr_val[u] = merge(merge(~left[u] ? subtr_val[left[u]] : identity(), val[u]), ~right[u] ? subtr_val[right[u]] : identity());
	}
	void heapify(int u){
		if(~u){
			int v = u;
			if(~left[u] && priority[left[u]] > priority[v]) v = left[u];
			if(~right[u] && priority[right[u]] > priority[v]) v = right[u];
			if(u != v) swap(priority[u], priority[v]), heapify(v);
		}
	}
	int get_sz(int u){
		return ~u ? sz[u] : 0;
	}
	pair<int, int> split_by_key(int u, Q x){ // split into [0, x), [x, inf), vals must be sorted, O(log n)
		if(!~u) return {-1, -1};
		if(val[u] < x){
			auto [a, b] = split_by_key(right[u], x);
			right[u] = a, refresh(u);
			return {u, b};
		}
		else{
			auto [a, b] = split_by_key(left[u], x);
			left[u] = b, refresh(u);
			return {a, u};
		}
	}
	pair<int, int> split_by_order(int u, int pos){ // split into [0, pos), [pos, inf), O(log n)
		if(!~u) return {-1, -1};
		if(get_sz(left[u]) < pos){
			auto [a, b] = split_by_order(right[u], pos - get_sz(left[u]) - 1);
			right[u] = a, refresh(u);
			return {u, b};
		}
		else{
			auto [a, b] = split_by_order(left[u], pos);
			left[u] = b, refresh(u);
			return {a, u};
		}
	}
	int append(int u, int v){ // append v onto u, O(log n)
		if(!~u || !~v) return ~u ? u : v;
		if(priority[v] < priority[u]){
			right[u] = append(right[u], v), refresh(u);
			return u;
		}
		else{
			left[v] = append(u, left[v]), refresh(v);
			return v;
		}
	}
	int insert_by_key(int u, int v){ // vals must be sorted, O(log n)
		if(!~u) return v;
		auto [a, b] = split_by_key(u, val[v]);
		return append(append(a, v), b);
	}
	int insert_by_order(int u, int v, int pos){ // O(log n)
		if(!~u) return v;
		auto [a, b] = split_by_order(u, pos);
		return append(append(a, v), b);
	}
	int erase_by_key(int u, Q x){ // Erase the smallest >= x, vals must be sorted, O(log n)
		if(!~u) return u;
		int a, b, c;
		tie(a, b) = split_by_key(u, x);
		tie(b, c) = split_by_order(b, 1);
		return append(a, c);
	}
	int erase_by_order(int u, int pos){ // O(log n)
		if(!~u) return u;
		int a, b, c;
		tie(a, b) = split_by_order(u, pos);
		tie(b, c) = split_by_order(b, 1);
		return append(a, c);
	}
	int unite_by_key(int u, int v){ // vals must be sorted, O(min(sz(u), sz(v)) * log(sz ratio))
		if(!~u || !~v) return ~u ? u : v;
		if(priority[u] < priority[v]) swap(u, v);
		auto [a, b] = split_by_key(v, val[u]);
		left[u] = unite_by_key(left[u], a), right[u] = unite_by_key(right[u], b), refresh(u);
		return u;
	}
	void act_on_subtr(int u, function<void(int)> f){
		if(~u) act_on_subtr(left[u], f), f(u), act_on_subtr(right[u], f), refresh(u);
	}
	void print(int u){
#ifdef LOCAL
		act_on_subtr(u, [&](int u){
			cerr << u << ": Left> " << left[u] << ", Right> " << right[u] << "\n";
			cerr << "(tmin: " << val[u].tmin << ", tmax: " << val[u].tmax << ", dif: " << val[u].dif << ")\n";
			cerr << "subtr: (tmin: " << subtr_val[u].tmin << ", tmax: " << subtr_val[u].tmax << ", dif: " << subtr_val[u].dif << ", crash: " << subtr_val[u].crash << ")" << endl;
		});
#endif
	}
	int new_node(Q x, int v = -1, int w = -1){
		int u = (int)val.size();
		left.push_back(v), right.push_back(w), priority.push_back(rng()), sz.push_back(1);
		val.push_back(x), subtr_val.push_back(x);
		return heapify(u), refresh(u), u;
	}
	int build(const vector<Q> &a){
		function<int(int, int)> recurse = [&](int l, int r){
			if(l == r) return -1;
			int m = l + (r - l >> 1);
			return new_node(a[m], recurse(l, m), recurse(m + 1, r));
		};
		return recurse(0, (int)a.size());
	}
	int build(int n, Q init = identity()){
		return build(vector<Q>(n, init));
	}
};
struct Q{
	int dif = 0;
	int tmin = numeric_limits<int>::max() / 2; // dif > 0
	int tmax = numeric_limits<int>::min() / 2; // dif < 0
	int crash = numeric_limits<int>::max() / 2;
	bool is_id = false;
	bool operator<(const Q &otr) const{ return true; }
};
Q merge(const Q &x, const Q &y){ // merges adjacent intervals
	if(x.is_id) return y;
	if(y.is_id) return x;
	return {
		x.dif + y.dif
		, x.tmin
		, y.tmax
		, min({x.crash, y.crash, y.tmin - x.tmax})
		, false
	};
}
Q identity(){ // Monoid Identity
	return {0, numeric_limits<int>::max() / 2, numeric_limits<int>::min() / 2, numeric_limits<int>::max() / 2, true};
}
using treap = treap_base<Q, merge, identity>;

template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n, ++ n;
	graph<int> g(n);
	g.link(0, 1, 2);
	for(auto i = 0; i < n - 2; ++ i){
		int u, v, w;
		cin >> u >> v >> w, w <<= 1;
		g.link(u, v, w);
	}
	int m;
	cin >> m;
	vector<vector<array<int, 2>>> ob(n);
	for(auto i = 0; i < m; ++ i){
		int d, f, u;
		cin >> d >> f >> u, d <<= 1;
		ob[u].push_back({d, f});
	}
	treap trp;
	vector<int> ind(n, -1);
	vector<int> delta(n);
	function<pair<int, int>(int, int, int)> split_by_delta = [&](int u, int x, int delta)->pair<int, int>{
		if(!~u) return {-1, -1};
		if((trp.val[u].dif > 0 ? trp.val[u].tmin - delta : trp.val[u].tmax + delta) < x){
			auto [a, b] = split_by_delta(trp.right[u], x, delta);
			trp.right[u] = a, trp.refresh(u);
			return {u, b};
		}
		else{
			auto [a, b] = split_by_delta(trp.left[u], x, delta);
			trp.left[u] = b, trp.refresh(u);
			return {a, u};
		}
	};
	auto insert_by_delta = [&](int u, int t, int dif, int delta){
		debug("Inserting", u, t, dif, delta);
		int a, b, c;
		tie(a, b) = split_by_delta(u, t, delta);
		tie(b, c) = split_by_delta(b, t + 1, delta);
		if(~b){
			int x = trp.val[b].dif > 0 ? trp.val[b].tmin - delta : trp.val[b].tmax + delta;
			trp.val[b].dif += dif;
			if(!trp.val[b].dif){
				return trp.append(a, c);
			}
			else if(trp.val[b].dif > 0){
				trp.val[b].tmin = x + delta, trp.val[b].tmax = numeric_limits<int>::min() / 2, trp.refresh(b);
				return trp.append(trp.append(a, b), c);
			}
			else{
				trp.val[b].tmin = numeric_limits<int>::max() / 2, trp.val[b].tmax = x - delta, trp.refresh(b);
				return trp.append(trp.append(a, b), c);
			}
		}
		else{
			int v = dif > 0 ? trp.new_node({dif, t + delta}) : trp.new_node({dif, numeric_limits<int>::max() / 2, t - delta});
			return trp.append(trp.append(a, v), c);
		}
	};
	auto crash_all = [&](int u, int delta){
		debug("Crashing", u, delta);
		function<int(int)> resolve = [&](int u){
			debug("Resolving", u, trp.left[u], trp.right[u]);
			if(~trp.left[u] && trp.val[u].tmin - trp.subtr_val[trp.left[u]].tmax <= delta << 1){
				auto [a, b] = trp.split_by_order(trp.left[u], trp.get_sz(trp.left[u]) - 1);
				debug(trp.val[b].dif, trp.val[u].dif);
				assert(trp.val[b].dif < 0 && trp.val[u].dif > 0);
				int res = trp.val[b].dif + trp.val[u].dif;
				if(res < 0){
					trp.val[b].dif = res, trp.refresh(b);
					return trp.append(trp.append(a, b), trp.right[u]);
				}
				else if(res > 0){
					trp.val[u].dif = res, trp.left[u] = a, trp.refresh(u);
					return u;
				}
				else{
					return trp.append(a, trp.right[u]);
				}
			}
			else if(~trp.right[u] && trp.subtr_val[trp.right[u]].tmin - trp.val[u].tmax <= delta << 1){
				auto [a, b] = trp.split_by_order(trp.right[u], 1);
				debug(trp.val[u].dif, trp.val[a].dif);
				assert(trp.val[u].dif < 0 && trp.val[a].dif > 0);
				int res = trp.val[u].dif + trp.val[a].dif;
				if(res < 0){
					trp.val[u].dif = res, trp.right[u] = b, trp.refresh(u);
					return u;
				}
				else if(res > 0){
					trp.val[a].dif = res, trp.refresh(a);
					return trp.append(trp.left[u], trp.append(a, b));
				}
				else{
					return trp.append(trp.left[u], b);
				}
			}
			else if(~trp.left[u] && trp.subtr_val[trp.left[u]].crash <= delta << 1){
				trp.left[u] = resolve(trp.left[u]), trp.refresh(u);
				return u;
			}
			else{
				trp.right[u] = resolve(trp.right[u]), trp.refresh(u);
				return u;
			}
		};
		while(~u && trp.subtr_val[u].crash <= delta << 1){
			u = resolve(u);
		}
		return u;
	};
	function<void(int, int)> dfs = [&](int u, int pe){
		for(auto id: g.adj[u]){
			if(id == pe) continue;
			auto &e = g.edges[id];
			int v = u ^ e.from ^ e.to;
			dfs(v, id);
			int szv = (int)ob[v].size();
			vector<int> val(szv);
			for(auto i = 0; i < szv; ++ i){
				auto [a, b] = split_by_delta(ind[v], ob[v][i][0], delta[v]);
				val[i] = ~a ? trp.subtr_val[a].dif : 0;
				ind[v] = trp.append(a, b);
			}
			ind[v] = crash_all(ind[v], delta[v] += 1);
			for(auto i = 0; i < szv; ++ i){
				auto [day, fish] = ob[v][i];
				auto [a, b] = split_by_delta(ind[v], day, delta[v]);
				if((~a ? trp.subtr_val[a].dif : 0) < val[i] + fish){
					fish = val[i] + fish - (~a ? trp.subtr_val[a].dif : 0);
					ind[v] = trp.append(a, b);
					ind[v] = insert_by_delta(ind[v], day - 1, fish, delta[v]);
					ind[v] = insert_by_delta(ind[v], day, -fish, delta[v]);
				}
				else ind[v] = trp.append(a, b);
			}
			ind[v] = crash_all(ind[v], delta[v] += e.cost - 1);
			if(trp.get_sz(ind[u]) <= trp.get_sz(ind[v])){
				int inc = delta[v] - delta[u];
				trp.act_on_subtr(ind[u], [&](int u){ trp.val[u].dif > 0 ? trp.val[u].tmin += inc : trp.val[u].tmax -= inc; });
				delta[u] += inc;
			}
			else{
				int inc = delta[u] - delta[v];
				trp.act_on_subtr(ind[v], [&](int u){ trp.val[u].dif > 0 ? trp.val[u].tmin += inc : trp.val[u].tmax -= inc; });
				delta[v] += inc;
			}
			debug(u, v, delta[u]);
			debug("\n");
			trp.print(ind[u]);
			debug("\n");
			trp.print(ind[v]);
			debug("\n");
			if(trp.get_sz(ind[u]) < trp.get_sz(ind[v])){
				swap(ind[u], ind[v]);
			}
			trp.act_on_subtr(ind[v], [&](int v){ ind[u] = insert_by_delta(ind[u], trp.val[v].dif > 0 ? trp.val[v].tmin - delta[u] : trp.val[v].tmax + delta[u], trp.val[v].dif, delta[u]); });
			trp.print(ind[u]);
			debug("\n");
		}
	};
	dfs(0, -1);
	int res = 0;
	auto f = [&](int u){
		static int sum = 0;
		sum += trp.val[u].dif;
		ctmax(res, sum);
	};
	trp.act_on_subtr(ind[0], f);
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