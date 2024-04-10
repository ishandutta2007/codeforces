#include "bits/stdc++.h"
using namespace std;

// DEBUG BEGIN
template<typename L, typename R>
ostream &operator<<(ostream &out, pair<L, R> p){
	return out << "(" << p.first << ", " << p.second << ")";
}
template<typename Tuple, size_t ...Is>
void print_tuple(ostream &out, Tuple t, index_sequence<Is...>){
	((out << (Is ? ", " : "") << get<Is>(t)), ...);
}
template<typename ...Args>
ostream &operator<<(ostream &out, tuple<Args...> t){
	out << "(", print_tuple(out, t, index_sequence_for<Args...>{}); return out << ")";
}
template<typename ...Args, template<typename...> typename T>
ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, T<Args...> arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<typename T, size_t N>
ostream &operator<<(ostream &out, array<T, N> arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<size_t S>
ostream &operator<<(ostream &out, bitset<S> b){
	for(int i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
// DEBUG END

template<typename T>
struct flow_network{
	static constexpr T eps = (T)1e-9;
	int n;
	vector<vector<int>> adj;
	struct Edge{
		int from, to;
		T capacity, flow;
	};
	vector<Edge> edge;
	int source, sink;
	T flow = 0;
	flow_network(int n, int source, int sink): n(n), source(source), sink(sink), adj(n){ debug(n, source, sink); }
	void clear(){
		for(auto &e: edge) e.flow = 0;
		flow = 0;
	}
	int insert(int from, int to, T forward_cap, T backward_cap){
		debug(from, to, forward_cap);
		int ind = (int)edge.size();
		adj[from].push_back(ind);
		edge.push_back({from, to, forward_cap, 0});
		adj[to].push_back(ind + 1);
		edge.push_back({to, from, backward_cap, 0});
		return ind;
	}
	void add_flow(int i, T f){
		edge[i].flow += f;
		edge[i ^ 1].flow -= f;
	}
};
template<typename T>
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
				auto &e = g.edge[ind];
				auto &re = g.edge[ind ^ 1];
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
			auto &e = g.edge[ind];
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
	T max_flow(){
		while(bfs()){
			for(int i = 0; i < g.n; ++ i) ptr[i] = int(g.adj[i].size()) - 1;
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

template<typename Graph, typename Process_BCC, typename Process_Bridge = function<void(int, int, int)>>
int BCC(const Graph &adj, Process_BCC f, Process_Bridge g = [](int u, int v, int e){ }){
	int n = int(adj.size());
	vector<int> num(n), st;
	int timer = 0, ncomps = 0;
	function<int(int, int)> dfs = [&](int u, int pe){
		int me = num[u] = ++ timer, top = me;
		for(auto [v, e]: adj[u]) if(e != pe){
			if(num[v]){
				top = min(top, num[v]);
				if(num[v] < me) st.push_back(e);
			}
			else{
				int si = int(st.size()), up = dfs(v, e);
				top = min(top, up);
				if(up == me){
					st.push_back(e);
					f(vector<int>(st.begin() + si, st.end())); // Processes edgelist
					st.resize(si);
					++ ncomps;
				}
				else if(up < me) st.push_back(e);
				else g(u, v, e);
			}
		}
		return top;
	};
	for(int u = 0; u < n; ++ u) if(!num[u]) dfs(u, -1);
	return ncomps;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<vector<array<int, 2>>> adj(n);
	vector<int> edge_col(m);
	for(int i = 0; i < m; ++ i){
		int u, v, c;
		cin >> u >> v >> c, -- u, -- v, -- c;
		adj[u].push_back({v, i}), adj[v].push_back({u, i});
		edge_col[i] = c;
	}
	vector<vector<int>> comps;
	vector<int> bridges;
	auto bcc_f = [&](vector<int> e_list){
		comps.push_back(e_list);
	};
	auto bcc_b = [&](int, int, int e){
		bridges.push_back(e);
	};
	BCC(adj, bcc_f, bcc_b);
	debug(comps);
	debug(bridges);
	int source = m + int(comps.size()) + int(bridges.size()), sink = source + 1;
	flow_network<int> F(m + int(comps.size()) + int(bridges.size()) + 2, source, sink);
	for(auto i = 0; i < m; ++ i){
		F.insert(source, i, 1, 0);
	}
	for(auto i = 0; i < int(comps.size()); ++ i){
		F.insert(m + i, sink, int(comps[i].size()) - 1, 0);
		for(auto e: comps[i]){
			F.insert(edge_col[e], m + i, 1, 0);
		}
	}
	for(auto i = 0; i < int(bridges.size()); ++ i){
		F.insert(m + int(comps.size()) + i, sink, 1, 0);
		F.insert(edge_col[bridges[i]], m + int(comps.size()) + i, 1, 0);
	}
	cout << dinic<int>(F).max_flow() << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////