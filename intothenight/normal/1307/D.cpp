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
 
template<typename T = long long, typename BO = plus<T>, typename Compare = less<T>>
struct shortest_path_tree{
	struct edge{
		int from, to;
		T cost;
	};
	int N;
	BO bin_op;
	Compare cmp;
	const T inf, id;
	vector<vector<int>> adj;
	vector<edge> edge;
	vector<T> dist;
	vector<int> parent;
	shortest_path_tree(int N, const T inf = numeric_limits<T>::max() / 8, BO bin_op = plus<T>(), T id = 0, Compare cmp = less<T>()): N(N), inf(inf), bin_op(bin_op), id(id), cmp(cmp), adj(N){ }
	void insert(int u, int v, T w){
		adj[u].push_back(int(edge.size()));
		edge.push_back({u, v, w});
	}
	void init(){
		dist.resize(N), parent.resize(N);
		fill(dist.begin(), dist.end(), inf), fill(parent.begin(), parent.end(), -1);
	}
	void init_bfs(const vector<int> S = {0}){
		init();
		deque<int> q;
		for(auto s: S){
			dist[s] = id;
			q.push_back(s);
		}
		while(!q.empty()){
			int u = q.front();
			q.pop_front();
			for(auto i: adj[u]){
				auto [_, v, w] = edge[i];
				if(dist[v] == inf){
					dist[v] = dist[u] + w;
					q.push_back(v);
				}
			}
		}
	}
	void init_dijkstra(const vector<int> S = {0}){
		init();
		auto qcmp = [&](const pair<T, int> &lhs, const pair<T, int> &rhs){
			return lhs.first == rhs.first ? lhs.second < rhs.second : cmp(rhs.first, lhs.first);
		};
		priority_queue<pair<T, int>, vector<pair<T, int>>, decltype(qcmp)> q(qcmp);
		for(auto s: S){
			dist[s] = id;
			q.push({id, s});
		}
		while(!q.empty()){
			auto [d, u] = q.top();
			q.pop();
			if(d != dist[u]) continue;
			for(int i: adj[u]){
				auto [u, v, w] = edge[i];
				if(cmp(bin_op(dist[u], w), dist[v])){
					dist[v] = bin_op(dist[u], w);
					parent[v] = i;
					q.push({dist[v], v});
				}
			}
		}
	}
	pair<vector<int>, vector<int>> init_bellman_ford(const vector<int> S = {0}, bool find_any_cycle = false){ // cycle {vertices, edges}
		if(find_any_cycle){
			fill(dist.begin(), dist.end(), id);
			fill(parent.begin(), parent.end(), -1);
		}
		else{
			init();
			for(auto s: S){
				dist[s] = id;
			}
		}
		int x;
		for(int i = 0; i < N; ++ i){
			x = -1;
			for(int j = 0; j < edge.size(); ++ j){
				auto [u, v, w] = edge[j];
				if(cmp(dist[u], inf) && cmp(bin_op(dist[u], w), dist[v])){
					dist[v] = cmp(-inf, bin_op(dist[u], w)) ? bin_op(dist[u], w) : -inf;
					parent[v] = j;
					x = v;
				}
			}
		}
		if(x == -1) return {};
		else{
			int y = x;
			for(int i = 0; i < N; ++ i) y = parent[y];
			vector<int> vertices, edges;
			for(int c = y; ; c = edge[parent[c]].from){
				vertices.push_back(c), edges.push_back(parent[c]);
				if(c == y && vertices.size() > 1) break;
			}
			reverse(vertices.begin(), vertices.end()), reverse(edges.begin(), edges.end());
			return {vertices, edges};
		}
	}
	bool init_spfa(const vector<int> S = {0}){ // returns false if cycle
		init();
		vector<int> cnt(N);
		vector<bool> inq(N);
		deque<int> q;
		for(auto s: S){
			dist[s] = id;
			q.push_back(s);
			inq[s] = true;
		}
		while(!q.empty()){
			int u = q.front();
			q.pop_front();
			inq[u] = false;
			for(int i: adj[u]){
				auto [u, v, w] = edge[i];
				if(cmp(bin_op(dist[u], w), dist[v])){
					dist[v] = bin_op(dist[u], w);
					parent[v] = i;
					if(!inq[v]){
						q.push_back(v);
						inq[v] = true;
						++ cnt[v];
						if(cnt[v] > N) return false;
					}
				}
			}
		}
		return true;
	}
	pair<vector<int>, vector<int>> path_from_root(int u){
		vector<int> vertices, edges;
		for(; parent[u] != -1; u = edge[parent[u]].from){
			vertices.push_back(u);
			edges.push_back(parent[u]);
		}
		vertices.push_back(u);
		reverse(vertices.begin(), vertices.end()), reverse(edges.begin(), edges.end());
		return {vertices, edges};
	}
};
 
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> spec(k);
	for(auto &x: spec){
		cin >> x, -- x;
	}
	shortest_path_tree<int> tr(n);
	for(int i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		tr.insert(u, v, 1), tr.insert(v, u, 1);
	}
	tr.init_bfs();
	int DISTANCE = tr.dist[n - 1];
	auto d = tr.dist;
	tr.init_bfs({n - 1});
	auto e = tr.dist;
	int res = 0;
	vector<pair<int, int>> t;
	for(auto u: spec){
		t.emplace_back(e[u] - d[u], d[u]);
	}
	sort(t.begin(), t.end(), greater<pair<int, int>>());
	for(auto [dif, du]: t){
		static int dv = -1;
		int eu = dif + du;
		if(dv != -1 && eu != tr.inf){
			ctmax(res, eu + dv);
		}
		if(du != tr.inf) ctmax(dv, du);
	}
	cout << min(DISTANCE, res + 1);
	return 0;
}
 
/*
 
*/
 
////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////