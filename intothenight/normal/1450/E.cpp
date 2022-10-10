#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

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
	graph(int n): n(n), adj(n), ignore(nullptr){
	}
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
	graph reversed() const{ // returns the transpose of the directed graph
		graph res(n);
		for(auto &e: edges){
			res.orient(e.to, e.from, e.cost);
		}
		return res;
	}
};

struct disjoint_set{
	vector<int> p;
	disjoint_set(int n): p(n, -1){ }
	bool share(int a, int b){ return root(a) == root(b); }
	int sz(int u){ return -p[root(u)]; }
	int root(int u){ return p[u] < 0 ? u : p[u] = root(p[u]); } // O(alpha(n))
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		return true;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	graph<int> g(n);
	disjoint_set dsu(n << 1);
	for(auto i = 0; i < m; ++ i){
		int u, v, w;
		cin >> u >> v >> w, -- u, -- v;
		dsu.merge(u, v + n), dsu.merge(v, u + n);
		if(dsu.share(u, u + n)){
			cout << "NO\n";
			return 0;
		}
		g.orient(u, v, w);
		g.orient(v, u, -w);
	}
	array<int, 2> res = {numeric_limits<int>::min(), -1};
	vector<int> l, r;
	auto solve = [&](int s){
		l.assign(n, numeric_limits<int>::min()), r.assign(n, numeric_limits<int>::max());
		l[s] = r[s] = 0;
		deque<array<int, 3>> dq{{s, l[s], r[s]}};
		while(!dq.empty()){
			auto [u, left, right] = dq.front(); dq.pop_front();
			if(left == l[u] && right == r[u]){
				for(auto id: g.adj[u]){
					auto &e = g.edges[id];
					int v = e.to, w = e.cost;
					int nlv = max(l[v], w ? l[u] + w : l[u] - 1), nrv = min(r[v], w ? r[u] + w : r[u] + 1);
					if(nlv != l[v] || nrv != r[v]){
						if(nlv > nrv){
							return;
						}
						dq.push_back({v, l[v] = nlv, r[v] = nrv});
					}
				}
			}
		}
		ctmax(res, array{*max_element(r.begin(), r.end()), s});
	};
	for(auto s = 0; s < n; ++ s){
		solve(s);
	}
	if(res[0] == numeric_limits<int>::min()){
		cout << "NO\n";
	}
	else{
		solve(res[1]);
		cout << "YES\n" << res[0] << "\n";
		for(auto x: r){
			cout << x << " ";
		}
		cout << "\n";
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