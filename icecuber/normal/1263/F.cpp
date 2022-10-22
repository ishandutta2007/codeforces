#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int leaf[2][2000];
vector<int> node[2][2000];

vector<pair<int,int>> seg[2];
pair<int,int> dfs(int k, int p = 0, int par = -1) {
  //cout << k << ' ' << p << endl;
  pair<int,int> r = {1e9,-1e9};
  for (int i : node[k][p]) {
    if (i == par) continue;
    auto c = dfs(k, i, p);
    r.first = min(r.first, c.first);
    r.second = max(r.second, c.second);
  }
  if (r.first == 1e9) {
    r = {leaf[k][p], leaf[k][p]};
  }
  if (par != -1)
    seg[k].emplace_back(r.first, -r.second);
  return r;
}

int dp[1010][1010][2];

int main() {
  int m;
  cin >> m;
  int n[2];
  for (int k = 0; k < 2; k++) {
    cin >> n[k];
    for (int i = 1; i < n[k]; i++) {
      int a = i, b;
      cin >> b;
      b--;
      node[k][a].push_back(b);
      node[k][b].push_back(a);
    }
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      leaf[k][x-1] = i;
    }
    dfs(k);
    sort(seg[k].rbegin(), seg[k].rend());
  }
  //for (auto p : seg[0]) cout << p.first << ' ' << -p.second << endl;

  int j[2] = {};
  for (int i = m-1; i >= 0; i--) {
    for (int k : {0,1}) {
      int acc = 0;
      for (int s = 1; s <= m-i; s++) {
	//if (!k)
	//  cout << i << ' ' << i+s-1 << endl << ", " << 0 << ' ' << m-1 << endl;
	while (j[k] < seg[k].size() && seg[k][j[k]].first == i && -seg[k][j[k]].second == i+s-1) {
	  j[k]++;
	  acc++;
	}
	dp[i][s][k] = max(dp[i][s][k], dp[i+1][s-1][k]+acc);
	if (s == 1) {
	  for (int t = 0; t < m-i; t++)
	    dp[i][1][k] = max(dp[i][1][k], dp[i+1][t][!k]+acc);
	}
      }
    }
  }
  for (int k : {0,1})
    assert(j[k] == seg[k].size());
  int ans = 0;
  for (int i = 0; i <= m; i++)
    for (int k : {0,1})
      ans = max(ans, dp[0][i][k]);
  cout << ans << endl;
}