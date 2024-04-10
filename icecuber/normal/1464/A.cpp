#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> node(n), rnode(n);
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      if (a == b) continue;
      node[a].push_back(b);
      rnode[b].push_back(a);
    }
    int ans = 0;
    vector<int> done(n);
    for (int i = 0; i < n; i++) {
      if (rnode[i].empty()) {
        assert(!done[i]);
        int p = i;
        done[i] = 1;
        while (node[p].size()) {
          assert(node[p].size() == 1);
          p = node[p][0];
          done[p] = 1;
          ans++;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (done[i] || node[i].empty()) continue;
      int p = i;
      ans++;
      while (!done[p]) {
        done[p] = 1;
        p = node[p][0];
        ans++;
      }
    }
    cout << ans << endl;
  }
}