#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...) // remove in interactive
#define endl '\n'
#endif

#define fst first
#define snd second

struct graph {
  int n;
  struct edge { int src, dst, rev;};
  vector<vector<edge>> adj;
//   graph() : n(0) { }
  graph(int n) : n(n), adj(n) { }

  void add_edge(int src, int dst) {
    	adj[src].push_back({src, dst, (int)adj[dst].size()});
    	adj[dst].push_back({dst, src, (int)adj[src].size()-1});
  }

  // destructive
  vector<int> path;
  void visit(int u) {
    while (!adj[u].empty()) {
      auto e = adj[u].back();
      adj[u].pop_back();
      if (e.src >= 0) {
		if(e.rev != -1)
        	adj[e.dst][e.rev].src = -1;
        visit(e.dst);
      }
    }
    path.push_back(u);
  }
  vector<int> eulerian_tour(int s) {
    path.clear(); visit(s);
    return path;
  }

  vector<vector<int>> tours(){
	  vector<int> vis(n);
	  vector<vector<int>> ret;
	  for(int i = 0; i < n; i++){
		  if(!vis[i]){
			  vector<int> nodes = eulerian_tour(i);
			  ret.push_back(nodes);
			  for(int j: nodes) vis[j] = 1;
		  }
	  }
	  return ret;
  }
};

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n, m;
	cin >> n >> m;
	vector<graph> G(2, graph(n + 1));
	vector<int> A(m), B(m), C(m);
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		A[i] = u;
		B[i] = v;
		G[C[i] = w - 1].add_edge(u, v);
	}
	int cnt = 0;
	for(int r = 0; r < 2; r++){
		for(int i = 1; i <= n; i++) if(sz(G[r].adj[i]) % 2 == 1){
			G[r].add_edge(0, i);
			if(r==0) cnt++;
		}
	}
	vector<vector<vector<int>>> X(2);
	X[0] = G[0].tours();
	X[1] = G[1].tours();

	vector<vector<vector<int>>> paths(2);
	vector<vector<int>> where(2, vector<int>(n + 1, -1));
	vector<multiset<pii>> edges(2);
	for(int r = 0; r < 2; r++){
		for(auto path: X[r]){
			int i = 0, j = 0;
			while(i < sz(path)){
				if(path[i] == 0){
					if(j != 0){
						where[r][path[j]] = where[r][path[i - 1]] = paths[r].size();
						paths[r].push_back(vector<int> (path.begin() + j, path.begin() + i));
					}
					i++;
					j = i;
					continue;
				}
				i++;
			}
			for(; j + 1 < sz(path); j++){
				edges[r].insert({path[j], path[j + 1]});
			}
		}
	}

	vector<vector<bool>> vis(2, vector<bool>(max(paths[0].size(), paths[1].size())));
	
	function<void(int, int, int)>  orient = [&](int r, int id, int dir){
		vis[r][id] = true;
		int u = paths[r][id][0], v = paths[r][id].back();
		if(dir){
			swap(u, v);
			reverse(all(paths[r][id]));
		}
		for(int i = 1; i < sz(paths[r][id]); i++){
			edges[r].insert({paths[r][id][i - 1], paths[r][id][i]});
		}

		int w_u = where[r ^ 1][u], w_v = where[r ^ 1][v];
		
		if(w_u != -1 && !vis[r ^ 1][w_u]){
			orient(r ^ 1, w_u, u == paths[r ^ 1][w_u][0]);
		}

		if(w_v != -1 && !vis[r ^ 1][w_v]){
			orient(r ^ 1, w_v, v == paths[r ^ 1][w_v].back());
		}
	};
	for(int r = 0; r < 2; r++){
		for(int i = 0; i < sz(paths[r]); i++) if(!vis[r][i]) orient(r, i, 0);
	}
	cout << cnt << endl;
	for(int i = 0; i < m; i++){
		int u = A[i], v = B[i];
		if(edges[C[i]].find({u, v}) != edges[C[i]].end()){
			cout << 1;
			edges[C[i]].erase(edges[C[i]].find({u, v}));
		} else{
			cout << 2;
			edges[C[i]].erase(edges[C[i]].find({v, u}));
		}
	}
	cout << endl;
}