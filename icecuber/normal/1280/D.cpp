#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 3000;
ll b[nax], w[nax];

vector<pair<ll,ll>> dp[nax];
vector<int> node[nax];

pair<ll,ll> operator+(pair<ll,ll> a, pair<ll,ll> b) {
  return {a.first+b.first, a.second+b.second};
}

void dfs(int p, int par) {
  dp[p] = {{0, w[p]-b[p]}};
  for (int i : node[p]) {
    if (i == par) continue;
    dfs(i, p);
    vector<pair<ll,ll>> ndp;
    for (int j = 0; j+1 < dp[p].size()+dp[i].size(); j++) {
      pair<ll,ll> v = {-1,-1e18};
      for (int k = max(j+1-(int)dp[i].size(), 0); k <= j && k < dp[p].size(); k++) {
	v = max(v, dp[p][k]+dp[i][j-k]);
      }
      ndp.push_back(v);
    }
    swap(dp[p], ndp);
  }
  if (par != -1) {
    dp[p].push_back({-1,-1e18});
    for (int i = 0; i+1 < dp[p].size(); i++)
      dp[p][i+1] = max(dp[p][i+1], make_pair(dp[p][i].first+ll(dp[p][i].second>0), 0ll));
  }

  /*cout << p+1 << endl;
  for (auto [a,b] : dp[p])
    cout << a << ',' << b << ' ';
    cout << endl;*/
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < n; i++) node[i].clear(), dp[i].clear();
    for (int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      node[a].push_back(b);
      node[b].push_back(a);
    }
    dfs(0, -1);
    cout << dp[0][m-1].first+(dp[0][m-1].second>0) << '\n';
  }
}