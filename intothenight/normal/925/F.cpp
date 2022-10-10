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
	flow_network<T> &g;
	dinic(flow_network<T> &g): g(g), ptr(g.n), level(g.n), q(g.n){ }
	vector<int> ptr, level, q;
	int s = -1, t = -1;
	bool bfs(){
		fill(level.begin(), level.end(), -1);
		q[0] = t;
		level[t] = 0;
		int beg = 0, end = 1;
		while(beg < end){
			int i = q[beg ++];
			for(auto ind: g.adj[i]){
				auto &e = g.edges[ind];
				auto &re = g.edges[ind ^ 1];
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
			int ind = g.adj[u][j];
			auto &e = g.edges[ind];
			if(e.capacity - e.flow > eps && level[e.to] == level[u] - 1){
				T F = dfs(e.to, min(e.capacity - e.flow, w));
				if(F > eps){
					g.add_flow(ind, F);
					return F;
				}
			}
			-- j;
		}
		return 0;
	}
	T max_flow(int s, int t){ // find a maximum s-t flow, O(V^2 E) ( O(E min(V^2/3, E^1/2)) for unit network )
		this->s = s, this->t = t;
		while(bfs()){
			for(int i = 0; i < g.n; ++ i) ptr[i] = (int)g.adj[i].size() - 1;
			T sum = 0;
			while(true){
				T add = dfs(s, inf);
				if(add <= eps) break;
				sum += add;
			}
			if(sum <= eps) break;
			g.flow += sum;
		}
		return g.flow;
	}
	pair<T, vector<bool>> min_cut(int s, int t){ // find a minimum s-t cut
		T cut = max_flow(s, t);
		vector<bool> res(g.n);
		for(int i = 0; i < g.n; ++ i) res[i] = level[i] != -1;
		return {cut, res};
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	flow_network<long long> F(n + 2);
	dinic<long long> D(F);
	int src = n, snk = n + 1;
	const int scale = 1e7;
	vector<array<int, 6>> edges(m);
	vector<array<int, 3>> ind(m);
	long long req = 0;
	for(auto i = 0; i < m; ++ i){
		for(auto j = 0; j < 6; ++ j){
			cin >> edges[i][j];
		}
		-- edges[i][0], -- edges[i][1];
		ind[i] = {F.insert(src, edges[i][1], 0, 0), F.insert(edges[i][0], edges[i][1], 0, 0), F.insert(edges[i][0], snk, 0, 0)};
	}
	auto gap = [&](int t){
		F.clear_flow();
		long long lsum = 0;
		for(auto i = 0; i < m; ++ i){
			auto [u, v, a, b, c, d] = edges[i];
			F.edges[ind[i][0]].capacity = 1LL * t * a + 1LL * scale * b;
			F.edges[ind[i][1]].capacity = 1LL * t * (c - a) + 1LL * scale * (d - b);
			F.edges[ind[i][2]].capacity = 1LL * t * a + 1LL * scale * b;
			lsum += 1LL * t * a + 1LL * scale * b;
		}
		return lsum - D.max_flow(src, snk);
	};
	int low = 0, high = 1e7 + 1;
	while(high - low >= 2){
		int mid = low + (high - low >> 1);
		if(gap(mid - 1) > gap(mid)){
			low = mid;
		}
		else{
			high = mid;
		}
	}
	int l = low;
	if(gap(l)){
		cout << "0\n";
		return 0;
	}
	low = l, high = 1e7 + 1;
	while(high - low >= 2){
		int mid = low + (high - low >> 1);
		if(gap(mid)){
			high = mid;
		}
		else{
			low = mid;
		}
	}
	int r = high;
	cout << fixed << setprecision(15);
	cout << 1.0 * (r - l) / scale << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////