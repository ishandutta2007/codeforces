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
#define endl '\n' // remove in interactive
#endif

struct graph {
  int L, R;
  vector<vector<int>> adj;
  vector<int> mate;
  graph(int L, int R) : L(L), R(R), adj(L+R), mate(L+R, -1){ }
  void add_edge(int u, int v) {
	adj[u].push_back(v+L);
	adj[v+L].push_back(u);
  }
  int maximum_matching() {
	vector<int> level(L);

	function<bool(void)> levelize = [&]() { // BFS
	  queue<int> Q;
	  for (int u = 0; u < L; ++u) {
		level[u] = -1;
		if (mate[u] < 0) {
		  level[u] = 0;
		  Q.push(u); 
		}
	  }
	  while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		for (int w: adj[u]) {
		  int v = mate[w];
		  if (v < 0) return true;
		  if (level[v] < 0) {
			level[v] = level[u] + 1;
			Q.push(v); 
		  }
		}
	  }
	  return false;
	};
	function<bool(int)> augment = [&](int u) { // DFS
	  for (int w: adj[u]) {
		int v = mate[w];
		if (v < 0 || (level[v] > level[u] && augment(v))) {
		  mate[u] = w;
		  mate[w] = u;
		  return true;
		}
	  }
	  return false;
	};
	int match = 0;
	while (levelize()) 
	  for (int u = 0; u < L; ++u) 
		if (mate[u] < 0 && augment(u)) 
		  ++match;
	return match;
  }
};

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n, m; cin >> n >> m;
	int thresh = m / 3; // x <= thresh => (2x, 3x)
	vector<int> lft, rgt;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		if(x <= thresh) rgt.push_back(x);
		else lft.push_back(x);
	}
	int p = sz(lft), q = sz(rgt);
	graph G(p, q);
	for(int i = 0; i < p; i++){
		for(int j = 0; j < q; j++){
			if(lft[i] % rgt[j] == 0 && 2ll * lft[i] + rgt[j] <= m){
				G.add_edge(i, j);
			}
		}
	}
	int h = G.maximum_matching();
	// trace(lft, rgt, h);
	if(h != p){
		cout << -1 << endl;
		return 0;
	}
	vector<pii> ans;
	for(int i = 0; i < p; i++){
		int j = G.mate[i] - p;
		ans.push_back({2 * lft[i] + rgt[j], lft[i] + rgt[j]});
	}
	for(int i = 0; i < q; i++){
		if(G.mate[i + p] == -1){
			ans.push_back({3 * rgt[i], 2 * rgt[i]});
		}
	}
	cout << ans.size() << endl;
	for(auto it: ans) cout << it.first << " " << it.second << endl;
}