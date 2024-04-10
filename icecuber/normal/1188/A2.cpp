#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define end first
#define w second

vector<pair<int,int>> node[1000];

vector<int> dfs(int p, int par) {
  vector<int> r;
  for (auto e : node[p]) {
    int i = e.end;
    if (i == par) continue;
    int j = i, prev = p;
    while (node[j].size() > 1) {
      int tmp = j;
      j = node[j][0].end == prev ? node[j][1].end : node[j][0].end;
      prev = tmp;
    }
    r.push_back(j);
    if (r.size() == 2) break;
  }
  if (r.size() <= 1) r = {p,p};
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b, v;
    cin >> a >> b >> v;
    a--, b--;
    node[a].push_back({b,v});
    node[b].push_back({a,v});
  }
  for (int i = 0; i < n; i++) {
    if (node[i].size() == 2) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  vector<vector<int>> ans;
  for (int a = 0; a < n; a++) {
    for (auto p : node[a]) {
      int b = p.end;
      int w = p.w/2;
      if (a > b) continue;
      vector<int> va = dfs(a,b), vb = dfs(b,a);
      ans.push_back({va[0],vb[0],w});
      ans.push_back({va[1],vb[1],w});
      if (va[0] != va[1])
	ans.push_back({va[0],va[1],-w});
      if (vb[0] != vb[1])
	ans.push_back({vb[0],vb[1],-w});
    }
  }
  cout << ans.size() << endl;
  for (auto v : ans) {
    assert(node[v[0]].size() == 1);
    assert(node[v[1]].size() == 1);
    cout << v[0]+1 << ' ' << v[1]+1 << ' ' << v[2] << '\n';
  }
}