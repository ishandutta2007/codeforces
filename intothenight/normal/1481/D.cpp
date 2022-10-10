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

template<class T>
optional<vector<int>> find_a_cycle(const graph<T> &g){
	int n = g.n;
	bool found = false;
	vector<int> cycle, vis(n, -1), s;
	function<void(int, int)> dfs = [&](int u, int pe){
		for(auto id: g.adj[u]){
			if(id == pe || g.ignore && g.ignore(id)) continue;
			auto &e = g.edges[id];
			int v = u ^ e.from ^ e.to;
			if(!~vis[v]){
				vis[v] = vis[u] + 1;
				s.push_back(id);
				dfs(v, id);
				s.pop_back();
				if(found) return;
			}
			else if(vis[v] >= 0){
				found = true;
				cycle = {s.begin() + vis[v], s.end()};
				return;
			}
		}
		vis[u] = -2;
	};
	for(auto u = 0; u < n; ++ u) if(!~vis[u] && !found) vis[u] = 0, dfs(u, -1);
	if(found) return cycle;
	else return {};
}

// Requires graph
template<class T> // convert edge path to vertex path
vector<int> convert_e_to_v(const graph<T> &g, vector<int> ep){
	if(ep.empty()) return {};
	if((int)ep.size() == 1) return {g.edges[ep[0]].from, g.edges[ep[1]].to};
	vector<int> vp{g.edges[ep[0]].to == g.edges[ep[1]].from || g.edges[ep[0]].to == g.edges[ep[1]].to ? g.edges[ep[0]].from : g.edges[ep[0]].to};
	for(auto id: ep){
		assert(g.edges[id].from == vp.back() || g.edges[id].to == vp.back());
		vp.push_back(vp.back() ^ g.edges[id].from ^ g.edges[id].to);
	}
	return vp;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, len;
		cin >> n >> len;
		graph<int> g(n);
		vector<string> adjm(n);
		for(auto &s: adjm){
			cin >> s;
		}
		for(auto u = 0; u < n; ++ u){
			for(auto v = u + 1; v < n; ++ v){
				if(adjm[u][v] == adjm[v][u]){
					cout << "YES\n";
					for(auto i = 0; i <= len; ++ i){
						cout << (i & 1 ? u : v) + 1 << " ";
					}
					cout << "\n";
					return 0;
				}
				if(adjm[u][v] == 'a'){
					g.orient(u, v);
				}
				if(adjm[v][u] == 'a'){
					g.orient(v, u);
				}
			}
		}
		if(auto temp = find_a_cycle(g); temp){
			auto C = convert_e_to_v(g, temp.value());
			cout << "YES\n";
			for(auto i = 0; i <= len; ++ i){
				cout << C[i % (int)C.size()] + 1 << " ";
			}
			cout << "\n";
			return 0;
		}
		if(n == 2 && ~len & 1){
			cout << "NO\n";
			return 0;
		}
		if(len & 1){
			cout << "YES\n";
			for(auto i = 0; i <= len; ++ i){
				cout << (i & 1) + 1 << " ";
			}
			cout << "\n";
			return 0;
		}
		else{
			vector<int> order{0, 1, 2};
			sort(order.begin(), order.end(), [&](int u, int v){ return adjm[u][v] == 'a'; });
			cout << "YES\n";
			if(len & 3){
				for(auto i = 0; i <= len / 2; ++ i){
					cout << order[i & 1] + 1 << " ";
				}
				for(auto i = len / 2 + 1; i <= len; ++ i){
					cout << order[2 - (i & 1)] + 1 << " ";
				}
				cout << "\n";
			}
			else{
				for(auto i = 0; i <= len / 2; ++ i){
					cout << order[1 - (i & 1)] + 1 << " ";
				}
				for(auto i = len / 2 + 1; i <= len; ++ i){
					cout << order[1 + (i & 1)] + 1 << " ";
				}
				cout << "\n";
			}
			return 0;
		}
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
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