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
  graph(int L, int R) : L(L), R(R), adj(L+R) { }
  void add_edge(int u, int v) {
	adj[u].push_back(v+L);
	adj[v+L].push_back(u);
  }
  int maximum_matching() {
	vector<int> level(L), mate(L+R, -1);

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

const int N = 50005;
int pos[N];
vector<int> divs[N];
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	for(int i = 1; i < N; i++){
		for(int j = 2 * i; j < N; j += i){
			divs[j].push_back(i);
		}
	}
	memset(pos, -1, sizeof pos);
	while(t--){
		int n; cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
			pos[a[i]] = i;
		}
		graph G(2 * n, 2 * n);
		for(int i = 0; i < n; i++){
			for(int j: divs[a[i]]){
				if(pos[j] != -1){
					int k = pos[j];
					// trace(k, i, a[k],a[i]);
					G.add_edge(k, i);
					G.add_edge(k + n, i + n);
				}
			}
			G.add_edge(i, i + n);
		}
		cout << G.maximum_matching() - n << endl;
		for(int i = 0; i < n; i++) pos[a[i]] = -1;
	}
}
// n - (# of unmatched)
// n - (2 * n - max_match)