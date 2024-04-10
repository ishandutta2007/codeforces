#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<class T>
struct graph{
	struct E{
		int from, to;
		T cost;
	};
	int n;
	vector<E> edge;
	vector<vector<int>> adj;
	function<bool(int)> ignore;
	graph(int n): n(n), adj(n){ }
	int link(int u, int v, T w = {}){ // insert an undirected edge
		int id = (int)edge.size();
		adj[u].push_back(id), adj[v].push_back(id), edge.push_back({u, v, w});
		return id;
	}
	int orient(int u, int v, T w = {}){ // insert a directed edge
		int id = (int)edge.size();
		adj[u].push_back(id), edge.push_back({u, v, w});
		return id;
	}
	graph transposed() const{ // the transpose of the directed graph
		graph res(n);
		for(auto &e: edge) res.orient(e.to, e.from, e.cost);
		res.ignore = ignore;
		return res;
	}
	int degree(int u) const{ // the degree (outdegree if directed) of u (without the ignoration rule)
		return (int)adj[u].size();
	}
	vector<vector<int>> get_adjacency_list() const{
		vector<vector<int>> res(n);
		for(auto u = 0; u < n; ++ u) for(auto id: adj[u]){
			if(ignore && ignore(id)) continue;
			auto &e = edge[id];
			int v = u ^ e.from ^ e.to;
			res[u].push_back(v);
		}
		return res;
	}
	void set_ignoration_rule(const function<bool(int)> &f){
		ignore = f;
	}
	void reset_ignoration_rule(){
		ignore = nullptr;
	}
};

// Requires graph
template<class T>
struct dfs_forest{
	int n;
	vector<T> dist;
	vector<int> pv;
	vector<int> pe;
	vector<int> order;
	vector<int> pos;
	vector<int> end;
	vector<int> size;
	vector<int> root;
	vector<int> depth;
	vector<int> min_depth;
	vector<int> min_depth_origin;
	vector<int> min_depth_spanning_edge;
	vector<int> was;
	T T_id;
	dfs_forest(int n, T T_id = 0): T_id(T_id){ init(n); }
	void init(int n){
		this->n = n;
		pv.assign(n, -1);
		pe.assign(n, -1);
		order.clear();
		pos.assign(n, -1);
		end.assign(n, -1);
		size.assign(n, 0);
		root.assign(n, -1);
		depth.assign(n, -1);
		min_depth.assign(n, -1);
		min_depth_origin.assign(n, -1);
		min_depth_spanning_edge.assign(n, -1);
		dist.assign(n, T_id);
		was.assign(n, -1);
		attempt = 0;
	}
	int attempt;
	template<class U, class F = plus<>>
	void dfs(const graph<U> &g, int u, bool clear_order = true, F UT = plus<>()){
		assert(n == g.n);
		++ attempt;
		depth[u] = 0;
		dist[u] = T_id;
		root[u] = u;
		pv[u] = pe[u] = -1;
		if(clear_order) order.clear();
		auto recurse = [&](auto self, int u)->void{
			was[u] = attempt;
			pos[u] = (int)order.size();
			order.push_back(u);
			size[u] = 1;
			min_depth[u] = depth[u];
			min_depth_origin[u] = u;
			min_depth_spanning_edge[u] = -1;
			for(auto id: g.adj[u]){
				if(id == pe[u] || g.ignore && g.ignore(id)) continue;
				auto &e = g.edge[id];
				int v = e.from ^ e.to ^ u;
				if(was[v] == attempt){
					if(min_depth[u] > depth[v]){
						min_depth[u] = depth[v];
						min_depth_spanning_edge[u] = id;
					}
					continue;
				}
				depth[v] = depth[u] + 1;
				dist[v] = UT(e.cost, dist[u]);
				pv[v] = u;
				pe[v] = id;
				root[v] = root[u];
				self(self, v);
				size[u] += size[v];
				if(min_depth[u] > min_depth[v]){
					min_depth[u] = min_depth[v];
					min_depth_origin[u] = min_depth_origin[v];
					min_depth_spanning_edge[u] = min_depth_spanning_edge[v];
				}
			}
			end[u] = (int)order.size();
		};
		recurse(recurse, u);
	}
	template<class U, class F = plus<>>
	void dfs_all(const graph<U> &g, F UT = plus<>()){
		for(auto u = 0; u < n; ++ u) if(!~depth[u]) dfs<U, F>(g, u, false, UT);
	}
};

struct two_sat_solver{
	int n;
	vector<vector<int>> adj;
	vector<int> value, val, comp, z;
	two_sat_solver(int n = 0): n(n), adj(n << 1){ }
	int time = 0;
	int add_variable(){
		adj.emplace_back();
		adj.emplace_back();
		return n ++;
	}
	void either(int u, int v){
		u = max(2 * u, -1 - 2 * u);
		v = max(2 * v, -1 - 2 * v);
		adj[u].push_back(v ^ 1);
		adj[v].push_back(u ^ 1);
	}
	void implies(int u, int v){
		either(~u, v);
	}
	void equals(int u, int v){
		either(~u, v), either(u, ~v);
	}
	void differs(int u, int v){
		either(u, v), either(~u, ~v);
	}
	void set_value(int u, bool x = true){
		x ? either(u, u) : either(~u, ~u);
	}
	void at_most_one(const vector<int> &arr){
		if((int)arr.size() <= 1) return;
		int cur = ~arr[0];
		for(auto u = 2; u < (int)arr.size(); ++ u){
			int next = add_variable();
			either(cur, ~arr[u]), either(cur, next), either(~arr[u], next);
			cur = ~next;
		}
		either(cur, ~arr[1]);
	}
	int dfs(int u){
		int low = val[u] = ++ time, v;
		z.push_back(u);
		for(auto v: adj[u]) if(!comp[v]) low = min(low, val[v] ?: dfs(v));
		++ time;
		if(low == val[u]) do{
			v = z.back();
			z.pop_back();
			comp[v] = time;
			if(value[v >> 1] == -1) value[v >> 1] = v & 1;
		}while(v != u);
		return val[u] = low;
	}
	// O(n)
	bool solve(){
		value.assign(n, -1), val.assign(2 * n, 0), comp = val;
		for(auto u = 0; u < n << 1; ++ u) if(!comp[u]) dfs(u);
		for(auto u = 0; u < n; ++ u) if(comp[u << 1] == comp[u << 1 ^ 1]) return false;
		return true;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	graph<int> g(n);
	for(auto i = 0; i < n - 1; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.link(u, v, 1);
	}
	dfs_forest<int> df(n);
	df.dfs(g, 0);
	vector<vector<tuple<int, char, char>>> appear(n);
	const int mx = 26;
	vector<array<int, mx>> cnt(n);
	vector<tuple<int, int, string>> q(qn);
	for(auto qi = 0; qi < qn; ++ qi){
		int u, v;
		string s;
		cin >> u >> v >> s, -- u, -- v;
		q[qi] = {u, v, s};
		int len = (int)s.size(), l = 0, r = len - 1;
		while(u != v){
			if(df.depth[u] > df.depth[v]){
				appear[u].push_back({qi, s[l], s[len - 1 - l]});
				++ cnt[u][s[l] - 'a'];
				if(s[l] != s[len - 1 - l]){
					++ cnt[u][s[len - 1 - l] - 'a'];
				}
				u = df.pv[u];
				++ l;
			}
			else{
				appear[v].push_back({qi, s[r], s[len - 1 - r]});
				++ cnt[v][s[r] - 'a'];
				if(s[r] != s[len - 1 - r]){
					++ cnt[v][s[len - 1 - r] - 'a'];
				}
				v = df.pv[v];
				-- r;
			}
		}
		assert(l == r && u == v);
		appear[u].push_back({qi, s[l], s[len - 1 - l]});
		++ cnt[u][s[l] - 'a'];
		if(s[l] != s[len - 1 - l]){
			++ cnt[u][s[len - 1 - l] - 'a'];
		}
	}
	two_sat_solver tss(qn);
	for(auto u = 0; u < n; ++ u){
		if(appear[u].empty()){
			continue;
		}
		int x = (int)appear[u].size(), c = ranges::count(cnt[u], x);
		if(c == 0){
			cout << "NO\n";
			return 0;
		}
		if(c == 2){
			char c1 = 'a', c2;
			while(cnt[u][c1 - 'a'] != x){
				++ c1;
			}
			c2 = c1 + 1;
			while(cnt[u][c2 - 'a'] != x){
				++ c2;
			}
			for(auto i = 0; i < (int)appear[u].size() - 1; ++ i){
				auto [q1, l1, r1] = appear[u][i];
				assert(c1 == l1 && c2 == r1 || c1 == r1 && c2 == l1);
				auto [q2, l2, r2] = appear[u][i + 1];
				assert(c1 == l2 && c2 == r2 || c1 == r2 && c2 == l2);
				l1 == l2 ? tss.equals(q1, q2) : tss.differs(q1, q2);
			}
		}
		else{
			char c = 'a';
			while(cnt[u][c - 'a'] != x){
				++ c;
			}
			for(auto [qi, l, r]: appear[u]){
				if(l != r){
					assert(l == c || r == c);
					tss.set_value(qi, r == c);
				}
			}
		}
	}
	if(!tss.solve()){
		cout << "NO\n";
		return 0;
	}
	string res(n, 'a');
	for(auto qi = 0; qi < qn; ++ qi){
		auto [u, v, s] = q[qi];
		if(tss.value[qi]){
			ranges::reverse(s);
		}
		int len = (int)s.size(), l = 0, r = len - 1;
		while(u != v){
			if(df.depth[u] > df.depth[v]){
				res[u] = s[l];
				u = df.pv[u];
				++ l;
			}
			else{
				res[v] = s[r];
				v = df.pv[v];
				-- r;
			}
		}
		assert(l == r && u == v);
		res[u] = s[l];
	}
	cout << "YES\n" << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////