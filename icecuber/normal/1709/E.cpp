#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  vector<vector<int>> node(n);
  for (int i = 0; i < n-1; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    node[x].push_back(y);
    node[y].push_back(x);
  }
  int ans = 0;
  function<pair<set<int>,int>(int,int)> dfs = [&](int p, int par) {
    set<int> sp = {a[p]};
    int xp = 0, bad = 0;
    for (int i : node[p]) {
      if (i == par) continue;
      auto [si,xi] = dfs(i, p);
      int flip = si.size() > sp.size();
      if (flip) swap(si,sp);
      for (int v : si) {
        if (sp.count(v^xi^xp)) {
          bad = 1;
        }
      }
      xi ^= a[p];
      for (int v : si) {
        sp.insert(v^xi^xp);
      }
      if (flip) swap(xi,xp);
    }
    if (bad) {
      ans++;
      return make_pair(set<int>(),0);
    }
    return make_pair(move(sp),xp);
  };
  dfs(0, -1);
  cout << ans << endl;
}