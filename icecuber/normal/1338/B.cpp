#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e5;
vector<int> node[nax];
set<int> depths;
int skips = 0;

int dfs(int p, int par, int d, int ucov = 0) {
  int leaf = 1;
  int covered = 0;
  for (int i : node[p]) {
    if (i == par) continue;
    covered |= dfs(i,p,d+1,covered);
    leaf = 0;
  }
  if (leaf) {
    depths.insert(d%2);
    skips += ucov;
  }
  return leaf;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  int root = 0;
  while ((int)node[root].size() <= 1) root++;
  dfs(root,-1, 0);
  cout << (depths.size() == 2 ? 3 : 1) << ' ' << n-1-skips << endl;
}