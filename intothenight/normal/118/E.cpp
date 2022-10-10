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
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n);
	vector<pair<int, int>> edge(m);
	for(int i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].emplace_back(v, i), adj[v].emplace_back(u, i);
		edge[i] = {u, v};
	}
	bcc(adj, [&](const vector<int> &){  }, [&](int u, int v, int e){
		cout << 0;
		exit(0);
	});
	vector<int> visited(n), mark(m), depth(n);
	function<void(int)> dfs = [&](int u){
		visited[u] = true;
		for(auto [v, e]: adj[u]){
			if(!visited[v]){
				mark[e] = true;
				depth[v] = depth[u] + 1;
				dfs(v);
			}
		}
	};
	dfs(0);
	for(int e = 0; e < m; ++ e){
		auto [u, v] = edge[e];
		if(mark[e] ^ (depth[u] < depth[v])){
			swap(u, v);
		}
		cout << u + 1 << " " << v + 1 << "\n";
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