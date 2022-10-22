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
    vector<vector<int>> node(n);
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      node[a].push_back(b);
      node[b].push_back(a);
    }
    vector<int> ans;

    vector<int> todo = {0};
    vector<int> mark(n, -1);

    while (todo.size()) {
      int p = todo.back();
      todo.pop_back();
      if (mark[p] != -1) continue;

      int has = 0;
      for (int i : node[p]) {
        if (mark[i] == 1) has = 1;
      }
      if (has) {
        mark[p] = 0;
      } else {
        ans.push_back(p);
        mark[p] = 1;
      }
      for (int i : node[p])
        if (mark[i] == -1)
          todo.push_back(i);
    }
    if (count(mark.begin(), mark.end(), -1)) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      cout << ans.size() << endl;
      for (int i : ans) cout << i+1 << ' ';
      cout << endl;
    }
  }
}