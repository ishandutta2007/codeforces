#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int,ll>> node[300000];
ll best[300000], w[300000];

ll ans = 0;
ll dfs(int p, int par = -1, int has = 0) {
  vector<ll> v;
  for (auto e : node[p]) {
    ll dist = e.second;
    int i = e.first;
    if (i == par) continue;
    v.push_back(max(0ll,dfs(i, p, max(0ll, w[p]-dist))-dist));
  }
  if (!v.size()) {
    ans = max(ans, w[p]+has);
    return w[p];
  }
  sort(v.rbegin(), v.rend());
  if (v.size() >= 2) ans = max(ans, v[0]+v[1]+w[p]);
  ans = max(ans, v[0]+w[p]+has);
  return v[0]+w[p];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> w[i];
  for (int i = 1; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    node[a].push_back({b,c});
    node[b].push_back({a,c});
  }
  dfs(0);
  cout << ans << endl;
}