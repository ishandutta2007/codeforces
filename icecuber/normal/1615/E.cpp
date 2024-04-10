#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> node(n);
  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }

  int leaves = 0;
  function<multiset<int>(int,int)> dfs = [&](int p, int par) {
    multiset<int> r;
    for (int i : node[p]) {
      if (i == par) continue;
      auto add = dfs(i, p);
      if (add.size() > r.size()) swap(r, add);
      for (int j : add) r.insert(j);
    }
    if (r.size()) {
      int ma = *r.rbegin();
      r.erase(r.find(ma));
      r.insert(ma+1);
    } else {
      leaves++;
      r.insert(1);
    }
    return r; 
  };
  auto r = dfs(0, -1);

  int cover = 0;
  for (int i = 0; i < k && r.size(); i++) {
    int ma = *r.rbegin();
    r.erase(r.find(ma));
    cover += ma;
  }

  if (leaves <= k) {
    ll red = max(leaves, min(n/2,k));
    cout << (n-red)*red << endl;
  } else {
    ll red = k;
    ll blue = min(n/2, n-cover);
    cout << (n-red-blue)*(red-blue) << endl;
  }
}