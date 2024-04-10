#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e5;
vector<int> node[nax];

vector<pair<int,int>> ans;

void dfs(int p, int par, int t) {
  ans.emplace_back(p,t);

  int t0 = t;
  int deg = node[p].size()+(par == -1);

  if (deg < t) {
    t = t-deg;
    ans.emplace_back(p,t);
    deg = 1e9;
  }

  for (int i : node[p]) {
    if (i == par) continue;
    if (t == deg) {
      t = 0;
      ans.emplace_back(p,t);
    }
    dfs(i,p,t+1);
    t++;
    ans.emplace_back(p,t);
  }
  if (t == deg) {
    t = 0;
    ans.emplace_back(p,t);
  }
  if (par != -1)
    assert(t == t0-1);
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

  dfs(0, -1, 0);

  cout << ans.size() << endl;
  for (auto [p,t] : ans) cout << p+1 << ' ' << t << '\n';
}