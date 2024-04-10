#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
struct flow_network{
	static constexpr T eps = (T)1e-9;
	int N;
	vector<vector<int>> adj;
	struct Edge{
		int from, to;
		T capacity, flow;
	};
	vector<Edge> edge;
	int source, sink;
	T flow = 0;
	flow_network(int N, int source, int sink): N(N), source(source), sink(sink), adj(N){ }
	void clear(){
		for(auto &e: edge) e.flow = 0;
		flow = 0;
	}
	int insert(int from, int to, T forward_cap, T backward_cap){
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
	dinic(flow_network<T> &g): g(g), ptr(g.N), level(g.N), q(g.N){ }
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
			for(int i = 0; i < g.N; ++ i) ptr[i] = int(g.adj[i].size()) - 1;
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
		vector<bool> res(g.N);
		for(int i = 0; i < g.N; ++ i) res[i] = (level[i] != -1);
		return {cut, res};
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	int n = int(s.size()), m;
	cin >> m;
	const int alp = 6;
	const int mx = 1 << alp;
	vector<int> a(n, mx - 1);
	while(m --){
		int pos;
		string t;
		cin >> pos >> t, -- pos;
		a[pos] = 0;
		for(auto c: t){
			a[pos] ^= 1 << (c - 'a');
		}
	}
	vector<int> cnt_alp(alp), cnt_mask(mx);
	for(auto c: s){
		++ cnt_alp[c - 'a'];
	}
	for(auto mask: a){
		++ cnt_mask[mask];
	}
	int source = alp + mx, sink = source + 1;
	flow_network<int> F(alp + mx + 2, source, sink);
	const int inf = numeric_limits<int>::max();
	vector<int> ind_alp(alp), ind_mask(mx);
	vector<vector<int>> ind(alp, vector<int>(mx, -1));
	for(int c = 0; c < alp; ++ c){
		ind_alp[c] = F.insert(source, c, cnt_alp[c], 0);
	}
	for(int mask = 0; mask < mx; ++ mask){
		ind_mask[mask] = F.insert(mask + alp, sink, cnt_mask[mask], 0);
	}
	for(int c = 0; c < alp; ++ c){
		for(int mask = 0; mask < mx; ++ mask){
			if(mask & 1 << c){
				ind[c][mask] = F.insert(c, mask + alp, inf, 0);
			}
		}
	}
	dinic<int> D(F);
	if(D.max_flow() < n){
		cout << "Impossible";
		return 0;
	}
	string res(n, 'a');
	for(int i = 0; i < n; ++ i){
		for(int c = 0; c < alp; ++ c){
			if(a[i] & 1 << c && F.edge[ind_alp[c]].capacity && F.edge[ind_mask[a[i]]].capacity){
				F.add_flow(ind_alp[c], -1);
				F.add_flow(ind_mask[a[i]], -1);
				-- F.edge[ind_alp[c]].capacity;
				-- F.edge[ind_mask[a[i]]].capacity;
				if(F.edge[ind[c][a[i]]].flow){
					res[i] = 'a' + c;
					F.add_flow(ind[c][a[i]], -1);
					-- F.flow;
					break;
				}
				for(int mask = 0; mask < mx; ++ mask){
					if(ind[c][mask] != -1 && F.edge[ind[c][mask]].flow){
						F.add_flow(ind[c][mask], -1);
						F.add_flow(ind_mask[mask], -1);
						-- F.flow;
						break;
					}
				}
				for(int c = 0; c < alp; ++ c){
					if(ind[c][a[i]] != -1 && F.edge[ind[c][a[i]]].flow){
						F.add_flow(ind_alp[c], -1);
						F.add_flow(ind[c][a[i]], -1);
						-- F.flow;
						break;
					}
				}
				if(D.max_flow() == n - 1 - i){
					res[i] = 'a' + c;
					break;
				}
				++ F.edge[ind_alp[c]].capacity;
				++ F.edge[ind_mask[a[i]]].capacity;
				D.max_flow();
			}
		}
	}
	cout << res;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////