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
	graph reversed() const{ // returns the transpose of the directed graph
		graph res(n);
		for(auto &e: edges){
			res.orient(e.to, e.from, e.cost);
		}
		return res;
	}
};

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

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	graph<int> g(n);
	for(auto i = 0; i < n - 1; ++ i){
		int u, v, w;
		cin >> u >> v >> w, -- u, -- v;
		g.link(u, v, w);
	}
	vector<int> sz(n, 1), par(n, -1);
	vector<double> one(n), two(n), three(n);
	function<void(int, int)> dfs = [&](int u, int p){
		par[u] = p;
		for(auto id: g.adj[u]){
			auto &e = g.edges[id];
			int v = u ^ e.from ^ e.to;
			if(v ^ p){
				dfs(v, u);
				three[u]
					+= two[u] * sz[v] + one[v] * sz[u] * (sz[u] - 1) / 2 + 1.0 * sz[u] * (sz[u] - 1) * sz[v] / 2 * e.cost
					+ one[u] * sz[v] * (sz[v] - 1) / 2 + two[v] * sz[u] + 1.0 * sz[u] * sz[v] * (sz[v] - 1) / 2 * e.cost
					+ three[v];
				two[u]
					+= one[u] * sz[v] + one[v] * sz[u] + 1.0 * sz[u] * sz[v] * e.cost
					+ two[v] + 1.0 * sz[v] * (sz[v] - 1) / 2 * e.cost;
				one[u]
					+= one[v] + 1.0 * sz[v] * e.cost;
				sz[u] += sz[v];
			}
		}
	};
	dfs(0, -1);
	debug(one);
	debug(two);
	debug(three);
	double res = three[0] * 2;
	debug(res);
	cout << fixed << setprecision(15);
	int qn;
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		int i;
		double w;
		cin >> i >> w, -- i;
		auto &e = g.edges[i];
		int u = e.from, v = e.to;
		if(par[u] != v){
			swap(u, v);
		}
		double delta = e.cost - w;
		debug(delta);
		cout << (res -= delta * (1LL * sz[u] * (n - sz[u]) * (n - sz[u] - 1) + 1LL * sz[u] * (sz[u] - 1) * (n - sz[u]))) * 1.0 / (1LL * n * (n - 1) * (n - 2) / 6) << "\n";
		e.cost = w;
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