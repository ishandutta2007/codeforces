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

// reads an undirected graph
// process(edge1, middle_vertex, edge2)
// process_rem(edge) : process arbitrary remaining edge in a component with odd number of edges
// O(|V| + |E|)
// Requires graph
template<class T>
void decompose_into_paths_of_length_2(const graph<T> &g, auto process, auto process_rem){
	int n = g.n, m = (int)g.edges.size();
	vector<bool> active(n, true), cut(m);
	vector<int> depth(n, -1), pv(n, -1), pe(n, -1);
	for(auto root = 0; root < n; ++ root){
		if(~depth[root]) continue;
		vector<int> cur;
		function<void(int)> dfs = [&](int u){
			cur.push_back(u);
			for(auto id: g.adj[u]){
				if(g.ignore && g.ignore(id)) continue;
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				if(~depth[v]) continue;
				depth[v] = depth[u] + 1;
				pv[v] = u;
				pe[v] = id;
				dfs(v);
			}
		};
		depth[root] = 0;
		dfs(root);
		int mxd = depth[*max_element(cur.begin(), cur.end(), [&](int u, int v){ return depth[u] < depth[v]; })];
		vector<vector<int>> bucket(mxd + 1);
		for(auto u: cur) bucket[depth[u]].push_back(u);
		for(auto d = mxd; d >= 0; -- d){
			// reduce the degree to 0 or 1
			for(auto u: bucket[d]){
				if(!active[u]) continue;
				vector<int> active_adj;
				for(auto id: g.adj[u]){
					if(g.ignore && g.ignore(id) || cut[id]) continue;
					auto &e = g.edges[id];
					int v = u ^ e.from ^ e.to;
					if(active[v]) active_adj.push_back(id);
				}
				if((int)active_adj.size() & 1) swap(*find(active_adj.begin(), active_adj.end(), pe[u]), active_adj.back());
				else active[u] = false;
				for(auto i = 0; i + 2 <= (int)active_adj.size(); i += 2){
					cut[active_adj[i]] = cut[active_adj[i + 1]] = true;
					process(active_adj[i], u, active_adj[i + 1]);
				}
			}
			// process degree 1 vertices
			if(d){
				for(auto u: bucket[d - 1]){
					vector<int> lower;
					int upper = -1;
					for(auto id: g.adj[u]){
						if(g.ignore && g.ignore(id) || cut[id]) continue;
						auto &e = g.edges[id];
						int v = u ^ e.from ^ e.to;
						if(active[v] && id != pe[u]){
							if(depth[v] == d) lower.push_back(id), active[v] = false;
							else upper = id;
						}
					}
					for(auto i = 0; i + 2 <= (int)lower.size(); i += 2){
						cut[lower[i]] = cut[lower[i + 1]] = true;
						process(lower[i], u, lower[i + 1]);
					}
					if((int)lower.size() & 1){
						if(~upper){
							cut[lower.back()] = cut[upper] = true;
							process(lower.back(), u, upper);
						}
						else if(~pe[u]){
							active[u] = false;
							cut[lower.back()] = cut[pe[u]] = true;
							process(lower.back(), u, pe[u]);
						}
						else{
							cut[lower.back()] = true;
							process_rem(lower.back());
						}
					}
				}
			}
		}
	}
}

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
template<class T> ostream &operator<<(class enable_if<!is_same<T, string>::value, ostream>::type &out, const T &arr){
	out << "{"; for(auto x: arr) out << x << ", ";
	return out << (arr.empty() ? "" : "\b\b") << "}";
}
template<size_t S> ostream &operator<<(ostream &out, const bitset<S> &b){
	for(auto i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void debug2_out(){ cerr << "\n"; }
template<class Head, class... Tail>
void debug2_out(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; debug2_out(T...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#define debug2(...) cerr << "[" << #__VA_ARGS__ << "]", debug2_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug2(...) 42
#endif
// DEBUG END

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<tuple<long long, long long, long long, long long>> p;
	vector<array<long long, 2>> cmpr;
	for(auto i = 0; i < n; ++ i){
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		p.push_back({a, b, c, d});
		cmpr.push_back({(a + b) * d, b * c});
		cmpr.push_back({a * d, b * (c + d)});
		debug(i);
		debug(array{(a + b) * d, b * c});
		debug(array{a * d, b * (c + d)});
	}
	auto cmp = [&](auto p, auto q)->bool{
		return (__uint128_t)p[0] * q[1] < (__uint128_t)p[1] * q[0];
	};
	debug(cmpr);
	sort(cmpr.begin(), cmpr.end(), cmp);
	cmpr.erase(unique(cmpr.begin(), cmpr.end(), [&](auto p, auto q){ return (__uint128_t)p[0] * q[1] == (__uint128_t)p[1] * q[0];; }), cmpr.end());
	debug(cmpr);
	auto ind = [&](array<long long, 2> p)->int{
		return lower_bound(cmpr.begin(), cmpr.end(), p, cmp) - cmpr.begin();
	};
	graph<int> g(n << 1);
	for(auto [a, b, c, d]: p){
		int u = ind({(a + b) * d, b * c});
		int v = ind({a * d, b * (c + d)});
		debug(u, v);
		g.link(u, v);
	}
	vector<array<int, 2>> res;
	auto process = [&](int i, int u, int j)->void{
		debug(i, u, j);
		res.push_back({i, j});
	};
	decompose_into_paths_of_length_2(g, process, [&](int i){  });
	cout << (int)res.size() << "\n";
	for(auto [i, j]: res){
		cout << i + 1 << " " << j + 1 << "\n";
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