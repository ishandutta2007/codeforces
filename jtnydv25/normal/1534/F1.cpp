#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n'
#endif

#define fst first
#define snd second


struct graph {
  int n;
  vector<vector<int>> adj, rdj;
  graph(int n) : n(n), adj(n), rdj(n) { }
  void add_edge(int src, int dst) {
    adj[src].push_back(dst);
    rdj[dst].push_back(src);
  }
  // in topological order
  vector<vector<int>> strongly_connected_components() { // kosaraju
    vector<int> ord, visited(n);
    vector<vector<int>> scc;
    function<void(int,vector<vector<int>>&, vector<int>&)> dfs 
      = [&](int u, vector<vector<int>> &adj, vector<int> &out) {
      visited[u] = true;
      for (int v: adj[u]) 
        if (!visited[v]) dfs(v, adj, out);
      out.push_back(u);
    };
    for (int u = 0; u < n; ++u)
      if (!visited[u]) dfs(u, adj, ord);
    fill(all(visited), false);
    for (int i = n-1; i >= 0; --i) 
      if (!visited[ord[i]]) 
        scc.push_back({}), dfs(ord[i], rdj, scc.back()); 
    return scc;
  }
};

vector<int> dx = {-1, 0, 0};
vector<int> dy = {0, 1, -1};
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n, m; cin >> n >> m;
	function<int(int, int)> ID = [&](int i, int j){return m * i + j;};
	graph g(n * m);
	vector<string> type(n);
	for(int i = 0; i < n; i++) cin >> type[i];
	vector<int> a(m), leader(m, n);
	for(int j = 0; j < m; j++){
		cin >> a[j];
		for(int i = 0; i < n; i++) if(type[i][j] == '#'){
			leader[j] = i;
			break;
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(type[i][j] != '#' && i < leader[j]) continue;
			int u = ID(i, j);
			if(i != n - 1) g.add_edge(u, ID(i + 1, j));
			if(type[i][j] != '#' && i < leader[j]) continue;
			for(int d = 0; d < 4; d++){
				int _i = i + dx[d], _j = j + dy[d];
				if(min(_i, _j) < 0 || _i >= n || _j >= m) continue;
				if(type[i][j] != '#' && d == 0) continue;
				if(type[_i][_j] != '#') continue;
				g.add_edge(u, ID(_i, _j));
			}
		}
	}
	vector<vector<int>> comps = g.strongly_connected_components();
	int k = comps.size();
	vector<int> indeg(k);
	vector<int> comp(g.n);
	vector<bool> special(k);

	for(int i = 0; i < k; i++) 
		for(int j : comps[i]){
			// trace(i, j);
			if(type[j / m][j % m] == '#') special[i] = true;
			comp[j] = i;
		}
	for(int i = 0; i < g.n; i++){
		for(int j : g.adj[i]) 
			if(comp[i] != comp[j]) 
				indeg[comp[j]]++;
	}

	int ans = 0;
	// trace(comp[10], special[14],indeg[14], comps[14],g.rdj[14]);
	for(int i = 0; i < k; i++){
		ans += (special[i] && !indeg[i]);
	}

	cout << ans << endl;
}