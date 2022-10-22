#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> h(n);
  for (int&v : h) cin >> v;
  vector<vector<int>> node(n);
  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  int root = 0;
  for (int i = 0; i < n; i++) {
    if (h[i] > h[root]) root = i;
  }
  ll ans = 0;
  function<int(int,int)> dfs = [&](int p, int par) {
    int ma = 0, sma = 0;
    for (int i : node[p]) {
      if (i == par) continue;
      int s = dfs(i, p);
      if (s > ma) sma = ma, ma = s;
      else if (s > sma) sma = s;
    }
    if (h[p] > ma) ans += h[p]-ma, ma = h[p];

    if (p == root) {
      if (node[p].size() == 1) {
        ans += h[p];
      } else {
        ans += h[p]-sma;
      }
    }
    return ma;
  };
  dfs(root, -1);
  cout << ans << endl;
}