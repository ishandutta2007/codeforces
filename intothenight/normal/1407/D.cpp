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
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	graph<int> g(n);
	for(auto i = 1; i < n; ++ i){
		g.orient(i - 1, i);
	}
	set<pair<int, int>> s;
	vector<pair<int, int>> ord(n);
	for(auto i = 0; i < n; ++ i){
		ord[i] = {a[i], i};
		s.insert({i, a[i]});
	}
	sort(ord.begin(), ord.end());
	for(auto [x, i]: ord){
		auto it = s.lower_bound({i, x});
		if(it != s.begin() && next(it) != s.end() && x != prev(it)->second && x != next(it)->second){
			g.orient(prev(it)->first, next(it)->first);
		}
		s.erase(it);
	}
	s.clear();
	for(auto i = 0; i < n; ++ i){
		s.insert({i, a[i]});
	}
	sort(ord.rbegin(), ord.rend());
	for(auto [x, i]: ord){
		auto it = s.lower_bound({i, x});
		if(it != s.begin() && next(it) != s.end() && x != prev(it)->second && x != next(it)->second){
			g.orient(prev(it)->first, next(it)->first);
		}
		s.erase(it);
	}
	deque<int> dq{{0}};
	vector<int> dist(n, -1);
	dist[0] = 0;
	while(!dq.empty()){
		int u = dq.front(); dq.pop_front();
		for(auto id: g.adj[u]){
			auto &e = g.edges[id];
			int v = e.from ^ e.to ^ u;
			if(!~dist[v]){
				dist[v] = dist[u] + 1;
				dq.push_back(v);
			}
		}
	}
	cout << dist[n - 1] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////