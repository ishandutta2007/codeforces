#include <bits/stdc++.h>
using namespace std;

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
	graph(int n): n(n), adj(n){ }
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
	graph transposed() const{ // the transpose of the directed graph
		graph res(n);
		for(auto &e: edges) res.orient(e.to, e.from, e.cost);
		res.ignore = ignore;
		return res;
	}
	int degree(int u){ // the degree (outdegree if directed) of u (without the ignoration rule)
		return (int)adj[u].size();
	}
};

// Requires graph
template<class T, class Q, Q (*act)(T, Q), Q (*identity)()>
struct dfs_forest_base{
	void init(int n){
		this->n = n;
		pv.assign(n, -1);
		pe.assign(n, -1);
		order.clear();
		pos.assign(n, -1);
		end.assign(n, -1);
		sz.assign(n, 0);
		root.assign(n, -1);
		depth.assign(n, -1);
		min_depth.assign(n, -1);
		dist.assign(n, identity());
		was.assign(n, -1);
		attempt = 0;
	}
	int attempt;
	void dfs(const graph<T> &g, int u, bool clear_order = true){
		++ attempt;
		depth[u] = 0;
		dist[u] = identity();
		root[u] = u;
		pv[u] = pe[u] = -1;
		if(clear_order) order.clear();
		function<void(int)> recurse = [&](int u){
			was[u] = attempt;
			pos[u] = (int)order.size();
			order.push_back(u);
			sz[u] = 1;
			min_depth[u] = depth[u];
			for(auto id: g.adj[u]){
				if(id == pe[u] || g.ignore && g.ignore(id)) continue;
				auto &e = g.edges[id];
				int v = e.from ^ e.to ^ u;
				if(was[v] == attempt){
					min_depth[u] = min(min_depth[u], depth[v]);
					continue;
				}
				depth[v] = depth[u] + 1;
				dist[v] = act(e.cost, dist[u]);
				pv[v] = u;
				pe[v] = id;
				root[v] = root[u];
				recurse(v);
				sz[u] += sz[v];
				min_depth[u] = min(min_depth[u], min_depth[v]);
			}
			end[u] = (int)order.size();
		};
		recurse(u);
	}
	void dfs_all(const graph<T> &g){
		for(auto u = 0; u < n; ++ u) if(!~depth[u]) dfs(g, u, false);
	}
	int n;
	vector<Q> dist;
	vector<int> pv, pe, order, pos, end, sz, root, depth, min_depth, was;
	dfs_forest_base(int n){ init(n); }
};
template<class T, class Q> Q df_act(T x, Q y){
	return x + y;
}
template<class Q> Q df_id(){
	return {};
}
template<class T, class Q>
using dfs_forest = dfs_forest_base<T, Q, df_act<T, Q>, df_id<Q>>;

// Requires graph
// O(V log V)
template<class T, class Q, Q (*act)(T, Q), Q (*identity)()>
struct centroid_decomposition_base: graph<int>{ // stores the arborescence
	int n, root; // the root of the arborescence
	vector<int> pe;
	vector<vector<Q>> dist; // dist[u][i]: sum of weights from u to its i-th centroid parent
	using graph<int>::orient;
	centroid_decomposition_base(const graph<T> &g): n(g.n), graph<int>(g.n), pe(g.n), dist(g.n){
		vector<int> dead(n), sz(n);
		auto centroid = [&](int s){
			int u = s, pe = -1;
			while(true){
				for(auto id: g.adj[u]){
					if(id == pe || g.ignore && g.ignore(id)) continue;
					auto &e = g.edges[id];
					int v = u ^ e.from ^ e.to;
					if(dead[v]) continue;
					if(sz[v] > sz[s] >> 1){
						u = v, pe = id;
						goto NEXT;
					}
				}
				break;
				NEXT:;
			}
			return u;
		};
		function<void(int, int)> dfs_sz = [&](int u, int p){
			sz[u] = 1;
			for(auto id: g.adj[u]){
				if(g.ignore && g.ignore(id)) continue;
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				if(p == v || dead[v]) continue;
				dfs_sz(v, u);
				sz[u] += sz[v];
			}
		};
		function<void(int, int)> set_distance = [&](int u, int pe){
			int p = u ^ g.edges[pe].from ^ g.edges[pe].to;
			dist[u].push_back(act(g.edges[pe].cost, dist[p].back()));
			for(auto id: g.adj[u]){
				if(id == pe || g.ignore && g.ignore(id)) continue;
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				if(dead[v]) continue;
				set_distance(v, id);
			}
		};
		function<void(int, int)> construct = [&](int u, int p){
			dfs_sz(u, p);
			dead[u = centroid(u)] = true;
			if(~p) pe[u] = orient(p, u);
			else root = u;
			dist[u].push_back(identity());
			for(auto id: g.adj[u]){
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				if(!dead[v]) set_distance(v, id);
			}
			for(auto id: g.adj[u]){
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				if(!dead[v]) construct(v, u);
			}
		};
		construct(0, -1);
		for(auto u = 0; u < n; ++ u) reverse(dist[u].begin(), dist[u].end());
	}
};
template<class T, class Q> Q cd_act(T x, Q y){
	return x + y;
}
template<class Q> Q cd_id(){
	return {};
}
template<class T, class Q> // T: edge weight type, Q: edge weight sum type
using centroid_decomposition = centroid_decomposition_base<T, Q, cd_act<T, Q>, cd_id<Q>>;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> diag(n);
	vector<array<int, 2>> de(m);
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		diag[u].push_back(v), diag[v].push_back(u);
		de[i] = {u, v};
	}
	for(auto u = 0; u < n - 1; ++ u){
		diag[u].push_back(u + 1), diag[u + 1].push_back(u);
	}
	diag[0].push_back(n - 1), diag[n - 1].push_back(0);
	for(auto u = 0; u < n; ++ u){
		sort(diag[u].begin(), diag[u].end(), [&](int p, int q){ return (p < u ? p : p - n) < (q < u ? q : q - n); });
	}
	vector<vector<int>> faces;
	function<void(int, int)> find_faces = [&](int a, int b){ // solve for arc a->b
		if(b - a == 1 || a - b == n - 1) return;
		vector<int> cur;
		int u = a, pu = b;
		while(u != b){
			cur.push_back(u);
			int nu = *prev(lower_bound(diag[u].begin(), diag[u].end(), pu, [&](int p, int q){ return (p < u ? p : p - n) < (q < u ? q : q - n); }));
			find_faces(u, nu);
			pu = u, u = nu;
		}
		cur.push_back(u);
		sort(cur.rbegin(), cur.rend());
		faces.push_back(cur);
	};
	find_faces(0, n - 1);
	assert((int)faces.size() == m + 1);
	sort(faces.begin(), faces.end());
	for(auto &v: faces){
		reverse(v.begin(), v.end());
	}
	map<array<int, 2>, int> mp;
	for(auto u = 0; u <= m; ++ u){
		for(auto t = 1; t < (int)faces[u].size(); ++ t){
			mp[{faces[u][t - 1], faces[u][t]}] = u;
		}
		mp[{faces[u].back(), faces[u].front()}] = u;
	}
	graph<int> g(m + 1);
	for(auto [u, v]: de){
		g.link(mp[{u, v}], mp[{v, u}]);
	}
	centroid_decomposition<int, int> cd(g);
	vector<int> res(m + 1);
	function<void(int, int, int)> solve = [&](int u, int pe, int c){
		res[u] = c;
		for(auto id: cd.adj[u]){
			solve(cd.edges[id].to, id, c + 1);
		}
	};
	solve(cd.root, -1, 1);
	for(auto x: res){
		cout << x << " ";
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