#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t = 0;
const int nax = 2e5+10;
vector<int> node[nax];
int s[nax], e[nax], depth[nax], par[nax];

void dfs(int p, int par, int d = 0) {
  depth[p] = d;
  s[p] = t++;
  ::par[p] = par;
  for (int i : node[p]) {
    if (i == par) continue;
    dfs(i,p,d+1);
  }
  e[p] = t;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  dfs(0, 0);
  while (m--) {
    int k;
    cin >> k;
    vector<pair<int,int>> v(k);
    for (int i = 0; i < k; i++) {
      int p;
      cin >> p;
      p--;
      p = par[p];
      v[i] = {depth[p], p};
    }
    sort(v.rbegin(), v.rend());
    int ok = 1;
    for (int i = 1; i < k; i++) {
      int a = v[i-1].second;
      int b = v[i].second;
      if (s[a] < s[b] || s[a] >= e[b]) ok = 0;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}