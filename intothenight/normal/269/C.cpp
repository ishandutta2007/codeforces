#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<class T>
struct flow_network{
	int n;
	vector<vector<int>> adj;
	struct E{
		int from, to;
		T capacity, flow;
	};
	vector<E> edge;
	T flow = 0;
	flow_network(int n): n(n), adj(n){ }
	void clear_flow(){
		for(auto &e: edge) e.flow = 0;
		flow = 0;
	}
	int insert(int from, int to, T forward_cap, T backward_cap = 0){
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
	friend ostream &operator<<(ostream &out, const flow_network &F){
		out << "\n";
		for(auto &e: F.edge){
			out << "{" << e.from << " -> " << e.to << ", " << e.flow << "/" << e.capacity << "\n";
		}
		return out;
	}
};

// Requires flow_network
template<class T>
struct push_relabel{
	static constexpr T eps = (T)1e-9, inf = numeric_limits<T>::max();
	flow_network<T> &F;
	vector<T> ec;
	vector<int> cur, H, co;
	vector<vector<int>> hs;
	push_relabel(flow_network<T> &F): F(F), ec(F.n), cur(F.n), H(F.n), co(F.n << 1), hs(F.n << 1){ }
	// Find a maximum source-sink flow
	// O(V^2 * sqrt(E)) with gap heuristic
	T maximum_flow(int source, int sink){
		assert(0 <= source && source < F.n && 0 <= sink && sink < F.n);
		int n = F.n;
		fill(ec.begin(), ec.end(), 0);
		ec[sink] = 1;
		fill(cur.begin(), cur.end(), 0);
		fill(H.begin(), H.end(), 0);
		H[source] = n;
		fill(co.begin(), co.end(), 0);
		co[0] = n - 1;
		fill(hs.begin(), hs.end(), vector<int>{});
		for(auto id: F.adj[source]){
			auto &e = F.edge[id];
			if(ec[e.to] <= eps && e.capacity > eps) hs[H[e.to]].push_back(e.to);
			ec[e.from] -= e.capacity;
			ec[e.to] += e.capacity;
			F.add_flow(id, e.capacity);
		}
		if(hs[0].empty()) return -ec[source];
		for(auto hi = 0; hi >= 0; ){
			int u = hs[hi].back();
			hs[hi].pop_back();
			while(ec[u] > eps){
				if(cur[u] == (int)F.adj[u].size()){
					H[u] = inf;
					for(auto i = 0; i < (int)F.adj[u].size(); ++ i){
						auto &e = F.edge[F.adj[u][i]];
						if(e.capacity - e.flow > eps && H[u] > H[e.to] + 1){
							H[u] = H[e.to] + 1;
							cur[u] = i;
						}
					}
					if(++ co[H[u]], !-- co[hi] && hi < n) for(auto i = 0; i < n; ++ i) if(hi < H[i] && H[i] < n){
						-- co[H[i]];
						H[i] = n + 1;
					}
					hi = H[u];
				}
				else{
					auto &e = F.edge[F.adj[u][cur[u]]];
					if(e.capacity - e.flow > eps && H[u] == H[e.to] + 1){
						auto f = min(ec[u], e.capacity - e.flow);
						if(ec[e.to] <= eps && f > eps) hs[H[e.to]].push_back(e.to);
						ec[e.from] -= f;
						ec[e.to] += f;
						F.add_flow(F.adj[u][cur[u]], f);
					}
					else ++ cur[u];
				}
			}
			while(hi >= 0 && hs[hi].empty()) -- hi;
		}
		return -ec[source];
	}
	vector<int> vis, q;
	// Find a minimum source-sink cut
	// O(V^2 * sqrt(E)) with gap heuristic
	tuple<T, vector<int>, vector<int>> minimum_cut(int source, int sink){
		T weight = maximum_flow(source, sink);
		vis.assign(F.n, false);
		q.resize(F.n);
		vector<int> left, right;
		q[0] = source;
		vis[source] = true;
		for(auto beg = 0, end = 1; beg < end; ){
			int u = q[beg ++];
			for(auto id: F.adj[u]){
				auto &e = F.edge[id];
				if(e.capacity - e.flow > eps && !vis[e.to]){
					vis[e.to] = true;
					q[end ++] = e.to;
				}
			}
		}
		for(auto u = 0; u < F.n; ++ u){
			if(vis[u]) left.push_back(u);
			else right.push_back(u);
		}
		return {weight, left, right};
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	flow_network<int> F(n);
	vector<int> id(m);
	for(auto i = 0; i < m; ++ i){
		int u, v, w;
		cin >> u >> v >> w, -- u, -- v;
		id[i] = F.insert(u, v, w, w);
	}
	push_relabel(F).minimum_cut(0, n - 1);
	for(auto i = 0; i < m; ++ i){
		cout << (F.edge[id[i]].flow < 0) << "\n";
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