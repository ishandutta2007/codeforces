#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

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

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, r, b;
	cin >> n >> m >> r >> b;
	bool swapped = false;
	if(r < b){
		swap(r, b);
		swapped = true;
	}
	vector<int> X, Y, lcnt(n), rcnt(n);
	const int inf = numeric_limits<int>::max() / 2;
	vector<array<int, 2>> a(n);
	for(auto &[x, y]: a){
		cin >> x >> y;
		X.push_back(x), Y.push_back(y);
	}
	sort(X.begin(), X.end()), sort(Y.begin(), Y.end());
	for(auto [x, y]: a){
		++ lcnt[lower_bound(X.begin(), X.end(), x) - X.begin()];
		++ rcnt[lower_bound(Y.begin(), Y.end(), y) - Y.begin()];
	}
	vector<int> l_low(n), l_high = lcnt;
	vector<int> r_low(n), r_high = rcnt;
	for(auto i = 0; i < m; ++ i){
		int t, l, d;
		cin >> t >> l >> d;
		if(t == 1){
			if(auto it = lower_bound(X.begin(), X.end(), l); it != X.end() && *it == l){
				int i = it - X.begin();
				if(lcnt[i] > d){
					ctmax(l_low[i], lcnt[i] - d + 1 >> 1);
					ctmin(l_high[i], lcnt[i] + d >> 1);
					if(l_low[i] > l_high[i]){
						cout << "-1\n";
						return 0;
					}
				}
			}
		}
		else{
			if(auto it = lower_bound(Y.begin(), Y.end(), l); it != Y.end() && *it == l){
				int i = it - Y.begin();
				if(rcnt[i] > d){
					ctmax(r_low[i], rcnt[i] - d + 1 >> 1);
					ctmin(r_high[i], rcnt[i] + d >> 1);
					if(r_low[i] > r_high[i]){
						cout << "-1\n";
						return 0;
					}
				}
			}
		}
	}
	int source = n << 1, sink = source + 1, super_source = sink + 1, super_sink = super_source + 1;
	flow_network<int> F(n * 2 + 4);
	dinic<int> D(F);
	int cross_edge = F.insert(sink, source, inf, 0);
	for(auto i = 0; i < n; ++ i){
		F.insert(source, i, l_high[i] - l_low[i], 0);
		F.insert(super_source, i, l_low[i], 0);
		F.insert(source, super_sink, l_low[i], 0);

		F.insert(i + n, sink, r_high[i] - r_low[i], 0);
		F.insert(super_source, sink, r_low[i], 0);
		F.insert(i + n, super_sink, r_low[i], 0);
	}
	vector<int> ind(n);
	for(auto i = 0; i < n; ++ i){
		auto [x, y] = a[i];
		x = lower_bound(X.begin(), X.end(), x) - X.begin();
		y = lower_bound(Y.begin(), Y.end(), y) - Y.begin();
		ind[i] = F.insert(x, y + n, 1, 0);
	}
	if(D.max_flow(super_source, super_sink) != accumulate(l_low.begin(), l_low.end(), accumulate(r_low.begin(), r_low.end(), 0))){
		cout << "-1\n";
		return 0;
	}
	int cross_flow = F.edges[cross_edge].flow;
	F.flow = 0;
	cout << 1LL * n * r + 1LL * D.max_flow(source, sink) * (b - r) << "\n";
	for(auto id: ind){
		if(F.edges[id].flow == F.edges[id].capacity ^ swapped){
			cout << 'b';
		}
		else{
			cout << 'r';
		}
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