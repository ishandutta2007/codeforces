#include <bits/stdc++.h>
using namespace std;

vector<int> res;
vector<vector<int>> adj;

void dfs(int v, int p) {
  int children = 0;
  for (int u : adj[v]) {
    if (u == p) continue;
    children++;
    dfs(u, v);
  }
  if (children == 0)
    res.push_back(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int x = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
       if (adj[i].size() > 2){
         x = i;
         cnt++;
       }
    }

    if (cnt > 1) {
      cout << "No" << '\n';
      return 0;
    }
    dfs(x, x);
    cout << "Yes" << '\n';
    cout << res.size() << '\n';
    for (auto y : res) {
      cout << x + 1 << " " << y + 1 << '\n';
    }
}