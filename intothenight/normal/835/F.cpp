#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename Graph, typename Process_BCC, typename Process_Bridge = function<void(int, int, int)>>
int bcc(const Graph &adj, Process_BCC f, Process_Bridge g = [](int u, int v, int e){ }){
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
				int si = int(st.size());
				int up = dfs(v, e);
				top = min(top, up);
				if(up == me){
					st.push_back(e);
					f(vector<int>(st.begin() + si, st.end())); // Processes edgelist
					st.resize(si);
					ncomps ++;
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
	int n;
	cin >> n;
	vector<vector<pair<int, int>>> adj(n);
	vector<array<int, 3>> edge;
	for(int i = 0; i < n; ++ i){
		int u, v, w;
		cin >> u >> v >> w, -- u, -- v;
		adj[u].emplace_back(v, i), adj[v].emplace_back(u, i);
		edge.push_back({u, v, w});
	}
	vector<int> ecycle;
	bcc(adj, [&](const vector<int> &c){ ecycle = c; });
	for(int i = 0; i < int(ecycle.size()) - 1; ++ i){
		auto &e = edge[ecycle[i]], &f = edge[ecycle[i + 1]];
		if(e[0] == f[0]){
			swap(e[0], e[1]);
		}
		else if(e[1] == f[1]){
			swap(f[0], f[1]);
		}
		else if(e[0] == f[1]){
			swap(e[0], e[1]);
			swap(f[0], f[1]);
		}
	}
	vector<int> cycle;
	for(int i = 0; i < int(ecycle.size()); ++ i){
		cycle.push_back(edge[ecycle[i]][0]);
	}
	vector<int> visited(n);
	for(auto u: cycle){
		visited[u] = true;
	}
	vector<long long> d(n), pref_res(n), suf_res(n), pref_d(n), suf_d(n);
	function<void(int)> dfs_d = [&](int u){
		visited[u] = true;
		for(auto [v, e]: adj[u]){
			if(!visited[v]){
				dfs_d(v);
				ctmax(d[u], d[v] + edge[e][2]);
			}
		}
	};
	for(auto u: cycle){
		dfs_d(u);
	}
	/*cout << "cycle = ";
	copy(cycle.begin(), cycle.end(), ostream_iterator<int>(cout, " "));
	cout << "\n";*/
	int s = cycle[0];
	pref_res[s] = numeric_limits<long long>::min() / 8;
	pref_d[s] = d[s];
	for(int i = 1; i < int(cycle.size()); ++ i){
		int u = cycle[i], v = cycle[i - 1];
		static long long len = edge[ecycle[0]][2] + d[s], sum = edge[ecycle[0]][2];
		// len: dist to farthest node from u to prefix using ate least 1 edge from cycle
		// sum: sum of len of edges in cycle from 0 to u
		pref_res[u] = max(pref_res[v], len + d[u]);
		ctmax(len, d[u]);
		len += edge[ecycle[i]][2];
		pref_d[u] = max(pref_d[v], sum + d[u]);
		sum += edge[ecycle[i]][2];
	}
	s = cycle.back();
	suf_res[s] = d[s] + d[cycle[0]] + edge[ecycle.back()][2];
	suf_d[s] = d[s] + edge[ecycle.back()][2];
	for(int i = int(cycle.size()) - 2; i >= 0; -- i){
		int u = cycle[i], v = cycle[i + 1];
		static long long len = max(d[v], d[cycle[0]] + edge[ecycle.back()][2]), sum = edge[ecycle.back()][2];
		len += edge[ecycle[i]][2];
		suf_res[u] = max(suf_res[v], len + d[u]);
		ctmax(len, d[u]);
		sum += edge[ecycle[i]][2];
		suf_d[u] = max(suf_d[v], sum + d[u]);
	}
	/*for(int u = 0; u < n; ++ u){
		cout << u << ": " << d[u] << " " << pref_res[u] << " " << suf_res[u] << " " << pref_d[u] << " " << suf_d[u] << "\n";
	}*/
	pair<long long, int> e{pref_res[cycle.back()], ecycle.back()};
	for(int i = 0; i < int(ecycle.size()) - 1; ++ i){
		int ce = ecycle[i], u = edge[ce][0], v = edge[ce][1];
		long long cur = max({pref_res[u], suf_res[v], pref_d[u] + suf_d[v]});
		//cout << "ce = " << ce << ", cur = " << cur << endl;
		ctmin(e, {cur, ce});
	}
	//cout << e.first << " " << e.second << endl;
	auto diam = [&](int s){
		deque<pair<int, int>> q{{s, -1}};
		vector<long long> dist(n);
		while(!q.empty()){
			auto [u, p] = q.front();
			q.pop_front();
			for(auto [v, i]: adj[u]){
				if(v != p && i != e.second){
					q.push_back({v, u});
					dist[v] = dist[u] + edge[i][2];
				}
			}
		}
		int u = max_element(dist.begin(), dist.end()) - dist.begin();
		return pair<long long, int>{dist[u], u};
	};
	cout << diam(diam(0).second).first;
	return 0;
}

/*
d[u]: distance from u to farthest node in subtree where u in cycle
pref_res[u]: res considering nodes 0, 1, ..., u using at least 1 edge from cycle
suf_res[u]: res considering nodes u, u + 1, ... using at least 1 edge from cycle
pref_d[u]: distance to the farthest node for subtrees of 0, 1, ..., u
suf_d[u]: distance to the farthest node for subtress of u, u + 1, ...

5
2 1 8
3 2 9
4 3 4
5 4 8
4 1 9

good: 22
bad: 25
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////