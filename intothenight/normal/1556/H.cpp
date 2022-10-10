#include <bits/stdc++.h>
using namespace std;

struct disjoint_set{
	int n;
	vector<int> p;
	disjoint_set(int n): n(n), p(n, -1){ }
	// Amortized O(alpha(n))
	int root(int u){
		return p[u] < 0 ? u : p[u] = root(p[u]);
	}
	// Amortized O(alpha(n))
	bool share(int a, int b){
		return root(a) == root(b);
	}
	// Amortized O(alpha(n))
	int size(int u){
		return -p[root(u)];
	}
	// Amortized O(alpha(n))
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		return true;
	}
	// O(n)
	void clear(){
		fill(p.begin(), p.end(), -1);
	}
	// O(n)
	vector<vector<int>> group_up(){
		vector<vector<int>> g(n);
		for(auto i = 0; i < n; ++ i) g[root(i)].push_back(i);
		g.erase(remove_if(g.begin(), g.end(), [&](auto &s){ return s.empty(); }), g.end());
		return g;
	}
};

// Requires disjoint_set
struct graphic_matroid{
	disjoint_set dsu;
	vector<array<int, 2>> e;
	vector<int> init_state;
	graphic_matroid(int n, const vector<array<int, 2>> &e): dsu(n), e(e), init_state(n, -1){ }
	graphic_matroid(int n, const vector<array<int, 2>> &e, const vector<int> &init_state): dsu(n), e(e), init_state(init_state){ }
	bool check(int i){
		return !dsu.share(e[i][0], e[i][1]);
	}
	void insert(int i){
		dsu.merge(e[i][0], e[i][1]);
	}
	void clear(){
		dsu.p = init_state;
	}
};

struct partition_matroid{
	vector<int> rem, group, limit;
	partition_matroid(const vector<int> &group, const vector<int> &limit): rem(limit), group(group), limit(limit){ }
	bool check(int i){
		return rem[group[i]];
	}
	void insert(int i){
		-- rem[group[i]];
	}
	void clear(){
		rem = limit;
	}
};

// ---------------------------------------------
// | # of member function calls where          |
// | R is the size of the answer and           |
// | N is the size of the ground set           |
// ---------------------------------------------
// | Member Function | M1         | M2         |
// ---------------------------------------------
// | insert()        | O(R^3)     | O(R^2 * N) |
// | check()         | O(R^2 * N) | O(R^2 * N) |
// | clear()         | O(R^2)     | O(R * N)   |
// ---------------------------------------------
//
// Requires matroid
template<class T, class M1, class M2>
vector<int> minimum_cost_maximum_common_independent_set_bellman_ford(const vector<T> &cost, M1 m1, M2 m2){
	int n = (int)cost.size();
	vector<bool> flag(n);
	vector<pair<T, int>> dist(n + 1);
	vector<tuple<int, int, T>> edge;
	vector<int> pv(n + 1);
	auto augment = [&]()->bool{
		fill(dist.begin(), dist.end(), pair{numeric_limits<T>::max() / 2, 0});
		edge.clear();
		fill(pv.begin(), pv.end(), -1);
		m1.clear(), m2.clear();
		for(auto u = 0; u < n; ++ u) if(flag[u]) m1.insert(u), m2.insert(u);
		for(auto u = 0; u < n; ++ u) if(!flag[u]){
			if(m1.check(u)) dist[pv[u] = u] = {cost[u], 0};
			if(m2.check(u)) edge.emplace_back(u, n, 0);
		}
		for(auto u = 0; u < n; ++ u) if(flag[u]){
			m1.clear(), m2.clear();
			for(auto v = 0; v < n; ++ v) if(u != v && flag[v]) m1.insert(v), m2.insert(v);
			for(auto v = 0; v < n; ++ v) if(!flag[v]){
				if(m1.check(v)) edge.push_back({u, v, cost[v]});
				if(m2.check(v)) edge.push_back({v, u, -cost[u]});
			}
		}
		for(auto changed = true; changed; ){
			changed = false;
			for(auto [u, v, w]: edge) if(pair<T, int> dist_next{dist[u].first + w, dist[u].second + 1}; ~pv[u] && dist_next < dist[v]) dist[v] = dist_next, pv[v] = u, changed = true;
		}
		if(!~pv[n]) return false;
		for(auto u = pv[n]; ; u = pv[u]){
			flag[u].flip();
			if(pv[u] == u) break;
		}
		return true;
	};
	while(augment());
	vector<int> res;
	for(auto u = 0; u < n; ++ u) if(flag[u]) res.push_back(u);
	return res;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	vector<int> limit(k);
	for(auto u = 0; u < k; ++ u){
		cin >> limit[u];
	}
	vector<array<int, 3>> edge;
	for(auto u = 0; u < n; ++ u){
		for(auto v = u + 1; v < n; ++ v){
			int w;
			cin >> w;
			edge.push_back({u, v, w});
		}
	}
	int m = (int)edge.size();
	{
		int sz = edge.end() - partition(edge.begin(), edge.end(), [&](auto e){ return e[0] >= k && e[1] >= k; });
		sort(edge.begin(), edge.end() - sz, [&](auto e, auto f){ return e[2] < f[2]; });
		disjoint_set dsu(n);
		vector<array<int, 3>> edge_next;
		for(auto i = 0; i < m - sz; ++ i){
			auto [u, v, w] = edge[i];
			if(dsu.merge(u, v)){
				edge_next.push_back(edge[i]);
			}
		}
		for(auto i = m - sz; i < m; ++ i){
			edge_next.push_back(edge[i]);
		}
		swap(edge, edge_next);
		m = (int)edge.size();
	}
	int sz = edge.end() - partition(edge.begin(), edge.end(), [&](auto e){ return e[0] >= k || e[1] >= k; });
	int res = numeric_limits<int>::max();
	for(auto mask = 0; mask < 1 << sz; ++ mask){
		vector<int> cur_limit = limit;
		cur_limit.push_back(numeric_limits<int>::max());
		int cur_res = 0;
		disjoint_set dsu(n);
		bool fail = false;
		for(auto i = 0; i < sz; ++ i){
			if(mask & 1 << i){
				auto [u, v, w] = edge[m - sz + i];
				-- cur_limit[u], -- cur_limit[v];
				cur_res += w;
				if(!dsu.merge(u, v)){
					fail = true;
					break;
				}
			}
		}
		for(auto u = 0; u < k; ++ u){
			if(cur_limit[u] < 0){
				fail = true;
				break;
			}
		}
		if(fail){
			continue;
		}
		vector<int> cost(m - sz), group(m - sz);
		vector<array<int, 2>> mat_edge;
		for(auto i = 0; i < m - sz; ++ i){
			auto [u, v, w] = edge[i];
			cost[i] = w;
			if(u >= k){
				swap(u, v);
			}
			mat_edge.push_back({u, v});
			if(u < k){
				group[i] = u;
			}
			else{
				group[i] = k;
			}
		}
		auto iset = minimum_cost_maximum_common_independent_set_bellman_ford(cost, graphic_matroid(n, mat_edge, dsu.p), partition_matroid(group, cur_limit));
		if((int)iset.size() + __builtin_popcount(mask) != n - 1){
			continue;
		}
		for(auto i: iset){
			cur_res += edge[i][2];
		}
		res = min(res, cur_res);
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////