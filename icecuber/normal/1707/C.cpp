#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<array<int,2>>> node(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back({i,b});
    node[b].push_back({i,a});
  }

  vector<vector<int>> child(n);
  vector<int> par(n);

  priority_queue<array<int,3>> pq;
  vector<int> done(n);
  pq.push({0,0,-1});
  set<array<int,2>> mst;
  vector<int> depth(n);
  while (pq.size()) {
    auto [mcost, p, prev] = pq.top();
    pq.pop();
    if (done[p]++) continue;
    if (prev != -1) {
      child[prev].push_back(p);
      par[p] = prev;
      depth[p] = depth[prev]+1;
      mst.insert({p,prev});
      mst.insert({prev,p});
    }
    for (auto [c,i] : node[p]) {
      if (!done[i]) pq.push({-c,i,p});
    }
  }

  vector<int> acc(n);
  auto add = [&](int p, int v) {
    //cout << p+1 << ' ' << v << endl;
    acc[p] += v;
  };
  map<int,int> path;
  vector<int> stack;
  function<void(int)> dfs = [&](int p) {
    path[p] = stack.size();
    stack.push_back(p);
    for (auto [c,i] : node[p]) {
      if (depth[i] > depth[p] || mst.count({p,i})) continue;
      if (path.count(i)) {
        add(stack[path[i]+1],1);
        add(p,-1);
      } else {
        add(0,1);
        add(p,-1);
        add(i,-1);
      }
    }
    for (int i : child[p]) {
      dfs(i);
    }
    stack.pop_back();
    path.erase(p);
  };
  dfs(0);
  function<void(int)> dfs2 = [&](int p) {
    for (int i : child[p]) {
      acc[i] += acc[p];
      dfs2(i);
    }
  };
  dfs2(0);

  for (int i = 0; i < n; i++)
    cout << (acc[i]==0);
  cout << endl;
}