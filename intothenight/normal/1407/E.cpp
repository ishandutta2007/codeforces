#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct graph{
	int n;
	struct edge{
		int from, to;
		T cost;
	};
	vector<edge> edges;
	vector<vector<int>> adj;
	graph(int n): n(n), adj(n){
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

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	graph<int> rev(n);
	for(auto i = 0; i < m; ++ i){
		int u, v, w;
		cin >> u >> v >> w, -- u, -- v;
		rev.orient(v, u, w);
	}
	deque<int> dq{n - 1};
	vector<array<int, 2>> state(n);
	vector<int> dist(n, -1);
	dist[n - 1] = 0;
	vector<int> res(n);
	while(!dq.empty()){
		int u = dq.front(); dq.pop_front();
		for(auto id: rev.adj[u]){
			auto &e = rev.edges[id];
			int v = u ^ e.from ^ e.to;
			if(!~dist[v]){
				state[v][e.cost] = true;
				if(state[v][0] && state[v][1]){
					dist[v] = dist[u] + 1;
					dq.push_back(v);
				}
				else{
					res[v] = !e.cost;
				}
			}
		}
	}
	cout << dist[0] << "\n";
	for(auto x: res){
		cout << x;
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