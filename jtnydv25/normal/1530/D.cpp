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

struct graph {
  int L, R;
  vector<vector<int>> adj;
  vector<int> mate;
  graph(int L, int R) : L(L), R(R), adj(L+R), mate(L + R, -1) {
   }
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
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n);
		for(int & x : a){
			cin >> x;
			x--;
		}
		graph G(n, n);
		for(int i = 0; i < n; i++) G.add_edge(i, a[i]);
		int m = G.maximum_matching();
		vector<int> b(n);
		vector<int> ib(n, -1);
		vector<int> X, Y;
		for(int i = 0; i < n; i++){
			b[i] = G.mate[i];
			if(b[i] != -1){
				b[i] -= n;
				ib[b[i]] = i;
			} else{
				X.push_back(i);
			}
		}
		for(int i = 0; i < n; i++) if(ib[i] == -1) Y.push_back(i);

		if(m == n - 1 && X[0] == Y[0]){
			int u = X[0];
			int v = a[u];
			b[u] = v;

			b[ib[v]] = u;
		} else{
			for(int k = sz(X) - 1; k >= 0;){
				if(k == 1){
					if(X[k] != Y[k] && X[k - 1] != Y[k - 1]){
						b[X[k]] = Y[k];
						b[X[k - 1]] = Y[k - 1];
					} else{
						b[X[k]] = Y[k - 1];
						b[X[k - 1]] = Y[k];
					}
					break;
				} else{
					if(X[k] != Y[k]){
						b[X[k]] = Y[k];
						k--;
					} else{
						swap(X[k], X[k - 1]);
					}
				}
			}
		}
		cout << m << endl;
		for(int x : b) cout << x + 1 << " ";
		cout << endl;
	}
}