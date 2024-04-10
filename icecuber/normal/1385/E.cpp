#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> node(n);
    vector<pair<int,int>> edges;
    for (int i = 0; i < m; i++) {
      int a, b, t;
      cin >> t >> a >> b;
      a--, b--;
      if (t == 1) {
	node[a].push_back(b);
      }
      edges.emplace_back(a, b);
    }

    int ok = 1, topos = 0;
    vector<int> done(n), topo(n);
    function<void(int)> dfs = [&](int p) {
      if (done[p]) {
	if (done[p] == 1) ok = 0;
	return;
      }
      done[p] = 1;
      for (int i : node[p]) dfs(i);
      done[p] = 2;
      topo[p] = topos++;
    };
    for (int i = 0; i < n; i++) dfs(i);
    if (!ok) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      for (auto [a, b] : edges) {
	if (topo[a] < topo[b]) swap(a, b);
	cout << a+1 << ' ' << b+1 << endl;
      }
    }
  }
}