#include <bits/stdc++.h>
using namespace std;

template<class T>
struct flow_network{
	int n;
	vector<vector<int>> adj;
	struct edge{
		int from, to;
		T capacity, flow;
	};
	vector<edge> edges;
	T flow = 0;
	flow_network(int n): n(n), adj(n){ }
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
	static constexpr T eps = (T)1e-9, inf = numeric_limits<T>::max();
	flow_network<T> &F;
	dinic(flow_network<T> &F): F(F), ptr(F.n), level(F.n), q(F.n){ }
	vector<int> ptr, level, q;
	int s = -1, t = -1;
	bool bfs(){
		fill(level.begin(), level.end(), -1);
		q[0] = t;
		level[t] = 0;
		int beg = 0, end = 1;
		while(beg < end){
			int i = q[beg ++];
			for(auto ind: F.adj[i]){
				auto &e = F.edges[ind];
				auto &re = F.edges[ind ^ 1];
				if(re.capacity - re.flow > eps && level[e.to] == -1){
					level[e.to] = level[i] + 1;
					if(e.to == s) return true;
					q[end ++] = e.to;
				}
			}
		}
		return false;
	}
	T dfs(int u, T w){
		if(u == t) return w;
		int &j = ptr[u];
		while(j >= 0){
			int ind = F.adj[u][j];
			auto &e = F.edges[ind];
			if(e.capacity - e.flow > eps && level[e.to] == level[u] - 1){
				T flow = dfs(e.to, min(e.capacity - e.flow, w));
				if(flow > eps){
					F.add_flow(ind, flow);
					return flow;
				}
			}
			-- j;
		}
		return 0;
	}
	T max_flow(int s, int t){ // find a maximum s-t flow, O(V^2 E) ( O(E min(V^2/3, E^1/2)) for unit network )
		this->s = s, this->t = t;
		while(bfs()){
			for(int i = 0; i < F.n; ++ i) ptr[i] = (int)F.adj[i].size() - 1;
			T sum = 0;
			while(true){
				T add = dfs(s, inf);
				if(add <= eps) break;
				sum += add;
			}
			if(sum <= eps) break;
			F.flow += sum;
		}
		return F.flow;
	}
	pair<T, vector<bool>> min_cut(int s, int t){ // find a minimum s-t cut
		T cut = max_flow(s, t);
		vector<bool> res(F.n);
		for(int i = 0; i < F.n; ++ i) res[i] = level[i] != -1;
		return {cut, res};
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
	int n, m, s, t, ss, tt;
	cin >> n >> m >> s >> t, -- s, -- t, ss = n, tt = n + 1;
	flow_network<int> F(n), F2(n + 2);
	vector<array<int, 3>> edges(m);
	const int inf = numeric_limits<int>::max() / 2;
	int obj = 0;
	F2.insert(t, s, inf, 0);
	vector<int> ind(m, -1);
	for(auto i = 0; i < m; ++ i){
		auto &[u, v, g] = edges[i];
		cin >> u >> v >> g, -- u, -- v;
		F.insert(u, v, g ?: inf, g ? inf : 0);
		if(g){
			++ obj;
			F2.insert(ss, v, 1, 0);
			ind[i] = F2.insert(u, v, inf, 0);
			F2.insert(u, tt, 1, 0);
		}
	}
	auto [sat, cut] = dinic<int>(F).min_cut(s, t);
	debug(cut);
	assert(dinic<int>(F2).max_flow(ss, tt) == obj);
	vector<array<int, 2>> res(m);
	for(auto i = 0; i < m; ++ i){
		auto [u, v, g] = edges[i];
		if(g){
			if(cut[u] || !cut[v]){
				res[i][1] = 1;
			}
			assert(F2.edges[ind[i]].flow <= numeric_limits<int>::max() / 3);
			int x = F2.edges[ind[i]].flow + 1;
			res[i][0] += x;
			res[i][1] += x;
		}
		else{
			res[i] = {0, 1};
		}
	}
	cout << sat << "\n";
	for(auto [f, c]: res){
		cout << f << " " << c << "\n";
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