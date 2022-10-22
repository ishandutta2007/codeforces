#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> node[3];
  node[1].resize(n);
  node[2].resize(n);
  vector<array<int,3>> edge;
  vector<int> sum(n);
  for (int ei = 0; ei < m; ei++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    node[c][a].push_back(ei);
    node[c][b].push_back(ei);
    edge.push_back({a,b,c});
    sum[a] += c;
    sum[b] += c;
  }

  vector<int> bal(n), done(m), dir(m);

  auto other = [&](int ei, int p) {
    return edge[ei][0] == p ? edge[ei][1] : edge[ei][0];
  };

  auto chain = [&](vector<int>&ind, int s, int c) {
    int p = s;
    vector<array<int,2>> ret;
    ret.push_back({p,-1});
    while (1) {
      while (ind[p] < (int)node[c][p].size() && done[node[c][p][ind[p]]]) ind[p]++;
      if (ind[p] == (int)node[c][p].size()) break;
      int ei = node[c][p][ind[p]];
      int q = other(ei, p);
      ret.push_back({q,ei});
      done[ei] = 1;
      p = q;
    }
    return ret;
  };

  vector<vector<array<int,2>>> chains;
  for (int c : {1,2}) {
    vector<int> ind(n);
    for (int i = 0; i < n; i++) {
      if (node[c][i].size()%2) {
        auto add = chain(ind, i, c);
        if (add.size() > 1)
          chains.push_back(add);
      }
    }
    for (int i = 0; i < n; i++) {
      while (ind[i] < (int)node[c][i].size()) {
        auto add = chain(ind, i, c);
        if (add.size() > 1)
          chains.push_back(add);
      }
    }
  }
  /*for (auto c : chains) {
    for (auto [a,b] : c) cout << a << ',' << b << ' ';
    cout << endl;
  }
  exit(0);*/

  auto addchain = [&](int ci, int flip) {
    auto c = chains[ci];
    for (int j = 1; j < (int)c.size(); j++) {
      auto [p,ei] = c[j];
      int side = (edge[ei][0] == p)^flip;
      dir[ei] = (side ? 2 : 1);
      bal[edge[ei][0]] += edge[ei][2] * (side*2-1);
      bal[edge[ei][1]] -= edge[ei][2] * (side*2-1);
      //cout << edge[ei][0] << ' ' << edge[ei][1] << endl;
    }
  };

  vector<vector<int>> core(n);
  for (int ci = 0; ci < (int)chains.size(); ci++) {
    auto c = chains[ci];
    int a = c[0][0], b = c.back()[0];
    if (a == b) {
      addchain(ci,0);
    } else {
      core[a].push_back(ci);
      core[b].push_back(ci);
    }
  }
  for (int i = 0; i < n; i++) assert(!bal[i]);

  for (int k : {1,2}) {
    for (int i = 0; i < n; i++) {
      assert(core[i].size() <= 2);
      if ((int)core[i].size() == k) {
        int p = i;
        while (core[p].size()) {
          int ci = core[p][0];
          int a = chains[ci][0][0], b = chains[ci].back()[0];
          int flip = (b == p);
          addchain(ci, flip);
          int q = a^b^p;
          core[p].erase(find(core[p].begin(), core[p].end(), ci)); 
          core[q].erase(find(core[q].begin(), core[q].end(), ci)); 
          p = q;
        }
      }
    }
  }

  for (int i = 0; i < m; i++) assert(done[i]);
  int score = 0;
  for (int i = 0; i < n; i++) {
    score += (abs(bal[i]) == 1);
  }
  cout << score << endl;
  for (int i = 0; i < m; i++) cout << dir[i];
  cout << endl;
  for (int i = 0; i < n; i++) {
    if (sum[i]%2) assert(abs(bal[i]) == 1);
  }
}