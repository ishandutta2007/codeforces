#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9+7;
vector<int> node[200000];
ll dp[200000][2];
ll w[200000];

void dfs(int p, int par = -1) {
  dp[p][0]++;
  for (int i : node[p]) {
    if (i == par) continue;
    dfs(i, p);
    (w[p] -= dp[i][1]*dp[i][1]) %= mod;
    (w[p] += dp[i][0]*dp[i][0]) %= mod;
    dp[p][0] += dp[i][1];
    dp[p][1] += dp[i][0];
  }
}

void dfs2(int p, int par = -1) {
  (w[p] += dp[p][0]*dp[p][0]-dp[p][1]*dp[p][1]) %= mod;
  for (int i : node[p]) {
    if (i == par) continue;
    (w[i] -= (dp[p][1]-dp[i][0])*(dp[p][1]-dp[i][0])) %= mod;
    (w[i] += (dp[p][0]-dp[i][1])*(dp[p][0]-dp[i][1])) %= mod;
    dp[i][0] = dp[p][1];
    dp[i][1] = dp[p][0];
    dfs2(i, p);
  }
}

ll v[200000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  dfs(0);
  dfs2(0);
  ll ans = 0;
  for (int i = 0; i < n; i++)
    (ans += w[i]*v[i]) %= mod;
  /*cout << endl;
  for (int i = 0; i < n; i++)
  cout << i+1 << ' ' << w[i] << endl;*/
  cout << (ans+mod)%mod << endl;
}