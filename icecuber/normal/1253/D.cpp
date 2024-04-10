#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5;
int done[nax];
vector<int> node[nax];

pair<int,int> dfs(int p) {
  if (done[p]++) return {1e9,-1e9};
  pair<int,int> r(p,p);
  for (int i : node[p]) {
    auto j = dfs(i);
    r = {min(r.first,j.first),max(r.second,j.second)};
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  vector<pair<int,int>> e;
  int ans = -1;
  for (int i = 0; i < n; i++) {
    if (!done[i]) {
      e.push_back(dfs(i));
      ans++;
    }
  }
  sort(e.begin(), e.end());
  int reach = 0;
  for (auto p : e) {
    if (p.first > reach) ans--;
    reach = max(reach,p.second);
  }
  cout << ans << endl;
}