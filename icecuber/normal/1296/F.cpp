#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 5000;
vector<pair<int,int>> node[nax];

pair<int,int> par[nax];

void dfs(int p, int parent = -1, int ei = -1) {
  par[p] = {parent, ei};
  for (auto [i,ei] : node[p]) {
    if (i != parent)
      dfs(i, p, ei);
  }
}
vector<int> path(int a, int b) {
  dfs(a);
  vector<int> r;
  while (b != a) {
    int ei;
    tie(b, ei) = par[b];
    r.push_back(ei);
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].emplace_back(b, i);
    node[b].emplace_back(a, i);
  }

  vector<int> mi(n-1, 1);
  int m;
  cin >> m;
  vector<vector<int>> paths;
  vector<int> gs;
  for (int i = 0; i < m; i++) {
    int a, b, g;
    cin >> a >> b >> g;
    a--, b--;
    paths.push_back(path(a, b));
    gs.push_back(g);
    for (int j : paths[i])
      mi[j] = max(mi[j], g);
  }
  for (int i = 0; i < m; i++) {
    int found = 0;
    for (int j : paths[i])
      if (mi[j] == gs[i]) found = 1;
    if (!found) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (int i = 0; i < n-1; i++)
    cout << mi[i] << ' ';
  cout << endl;
}