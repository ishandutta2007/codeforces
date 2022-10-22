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
    vector<vector<array<int,2>>> node(n);
    vector<array<int,3>> edge;
    for (int i = 1; i < n; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      a--, b--;
      edge.push_back({a,b,c});
      if (c != -1) {
        node[a].push_back({b, __builtin_popcount(c)%2});
        node[b].push_back({a, __builtin_popcount(c)%2});
      }
    }
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      a--, b--;
      node[a].push_back({b,c});
      node[b].push_back({a,c});
    }
    vector<int> col(n, -1);
    int ok = 1;
    function<void(int,int)> dfs = [&](int p, int c) {
      if (col[p] != -1) {
        if (col[p] != c) ok = 0;
        return;
      }
      col[p] = c;
      for (auto [i,f] : node[p]) {
        dfs(i, c^f);
      }
    };
    for (int i = 0; i < n; i++) if (col[i] == -1) dfs(i,0);
    if (!ok) {
      cout << "NO" << endl;
      continue;
    }
    
    cout << "YES" << endl;
    for (auto [a,b,c] : edge) {
      int C = c;
      if (c == -1) {
        C = col[a]^col[b];
      }
      cout << a+1 << ' ' << b+1 << ' ' << C << endl;
    }
  }
}