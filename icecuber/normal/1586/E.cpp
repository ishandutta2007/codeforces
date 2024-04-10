#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> node(n);
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  vector<vector<int>> tree;
  vector<int> par(n), depth(n);
  vector<int> done(n);
  function<void(int)> dfs = [&](int p) {
    if (done[p]++) return;
    for (int i : node[p]) {
      if (done[i]) continue;
      par[i] = p;
      depth[i] = depth[p]+1;
      dfs(i);
    }
  };
  dfs(0);
  int q;
  cin >> q;
  vector<int> bal(n);
  vector<vector<int>> ans;
  while (q--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    bal[a] ^= 1;
    bal[b] ^= 1;
    vector<int> pa, pb;
    while (depth[a] > depth[b]) pa.push_back(a), a = par[a];
    while (depth[b] > depth[a]) pb.push_back(b), b = par[b];
    while (a != b) {
      pa.push_back(a), a = par[a];
      pb.push_back(b), b = par[b];
    }
    pa.push_back(a);
    while (pb.size()) pa.push_back(pb.back()), pb.pop_back();
    ans.push_back(pa);
  }
  int odds = 0;
  for (int v : bal) odds += v;
  if (odds) {
    cout << "NO" << ' ' << odds/2 << endl;
  } else {
    cout << "YES" << endl;
    for (auto v : ans) {
      cout << v.size() << endl;
      for (int i : v) cout << i+1 << ' ';
      cout << endl;
    }
  }
}