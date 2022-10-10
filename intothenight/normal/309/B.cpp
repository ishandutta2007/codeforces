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

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, r, c;
	cin >> n >> r >> c;
	vector<string> a(n);
	vector<int> pref(n + 1);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		pref[i + 1] = pref[i] + (int)a[i].size();
	}
	auto length = [&](int i, int j){
		assert(i <= j);
		return pref[j] - pref[i] + max(j - i - 1, 0);
	};
	graph<int> g(n + 1);
	vector<int> reach(n + 1), roots;
	for(auto i = 0, j = 0; i <= n; ){
		while(j < n && length(i, j + 1) <= c){
			++ j;
		}
		reach[i] = j;
		if(i == j){
			roots.push_back(i);
			++ i, ++ j;
		}
		else{
			g.orient(j, i);
			++ i;
		}
	}
	debug(reach);
	vector<int> s, mxlen(n + 1);
	function<void(int)> dfs = [&](int u){
		s.push_back(u);
		for(auto id: g.adj[u]){
			int v = g.edges[id].to;
			dfs(v);
			mxlen[v] = s[max((int)s.size() - r, 0)] - v;
		}
		s.pop_back();
	};
	for(auto u: roots){
		dfs(u);
	}
	int u = max_element(mxlen.begin(), mxlen.end()) - mxlen.begin();
	debug(u, mxlen);
	for(auto i = 0; i < r && reach[u] != u; u = reach[u], ++ i){
		for(auto i = u; i < reach[u] - 1; ++ i){
			cout << a[i] << " ";
		}
		cout << a[reach[u] - 1] << "\n";
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