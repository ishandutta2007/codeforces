#include <bits/stdc++.h>
using namespace std;

template<class T>
struct flow_network{
	static constexpr T eps = (T)1e-9;
	int n;
	vector<vector<int>> adj;
	struct edge{
		int from, to;
		T capacity, flow;
	};
	vector<edge> edges;
	int source, sink;
	T flow = 0;
	flow_network(int n, int source, int sink): n(n), source(source), sink(sink), adj(n){ }
	void clear_flow(){
		for(auto &e: edges) e.flow = 0;
		flow = 0;
	}
	int insert(int from, int to, T forward_cap, T backward_cap){
		int ind = (int)edges.size();
		adj[from].push_back(ind);
		edges.push_back({from, to, forward_cap, 0});
		adj[to].push_back(ind + 1);
		edges.push_back({to, from, backward_cap, 0});
		return ind;
	}
	void add_flow(int i, T f){
		edges[i].flow += f;
		edges[i ^ 1].flow -= f;
	}
};
template<class T>
struct dinic{
	static constexpr T inf = numeric_limits<T>::max();
	flow_network<T> &g;
	vector<int> ptr, level, q;
	dinic(flow_network<T> &g): g(g), ptr(g.n), level(g.n), q(g.n){ }
	bool bfs(){
		fill(level.begin(), level.end(), -1);
		q[0] = g.sink;
		level[g.sink] = 0;
		int beg = 0, end = 1;
		while(beg < end){
			int i = q[beg ++];
			for(auto ind: g.adj[i]){
				auto &e = g.edges[ind];
				auto &re = g.edges[ind ^ 1];
				if(re.capacity - re.flow > g.eps && level[e.to] == -1){
					level[e.to] = level[i] + 1;
					if(e.to == g.source) return true;
					q[end ++] = e.to;
				}
			}
		}
		return false;
	}
	T dfs(int u, T w){
		if(u == g.sink) return w;
		int &j = ptr[u];
		while(j >= 0){
			int ind = g.adj[u][j];
			auto &e = g.edges[ind];
			if(e.capacity - e.flow > g.eps && level[e.to] == level[u] - 1){
				T F = dfs(e.to, min(e.capacity - e.flow, w));
				if(F > g.eps){
					g.add_flow(ind, F);
					return F;
				}
			}
			-- j;
		}
		return 0;
	}
	T max_flow(){ // O(V^2 E) ( O(E min(V^2/3, E^1/2)) for unit network )
		while(bfs()){
			for(int i = 0; i < g.n; ++ i) ptr[i] = (int)g.adj[i].size() - 1;
			T sum = 0;
			while(1){
				T add = dfs(g.source, inf);
				if(add <= g.eps) break;
				sum += add;
			}
			if(sum <= g.eps) break;
			g.flow += sum;
		}
		return g.flow;
	}
	pair<T, vector<bool>> min_cut(){
		T cut = max_flow();
		vector<bool> res(g.n);
		for(int i = 0; i < g.n; ++ i) res[i] = (level[i] != -1);
		return {cut, res};
	}
};
using namespace chrono;

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
	int n, m, x;
	cin >> n >> m >> x;
	flow_network<int> F(n, 0, n - 1);
	vector<int> w(m), id(m);
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v >> w[i], -- u, -- v;
		id[i] = F.insert(u, v, 0, 0);
	}
	dinic<int> D(F);
	double low = 1.0 / x, high = 1e9;
	auto START = high_resolution_clock::now();
	double TL = 1.2;
	auto test = [&](double th){
		F.clear_flow();
		for(auto i = 0; i < m; ++ i){
			F.edges[id[i]].capacity = w[i] / th;
		}
		return D.max_flow() >= x;
	};
	while(duration<double>(high_resolution_clock::now() - START).count() < TL){
		double mid = (low + high) / 2;
		(test(mid) ? low : high) = mid;
	}
	cout << fixed << setprecision(15);
	cout << low * x << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////