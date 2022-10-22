#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 203;

vector<int> node[nax];
int w[nax];
int n, k;

int dp[nax][nax];
void dfs(int p, int par = -1) {
  for (int i : node[p]) {
    if (i == par) continue;
    dfs(i, p);
  }
  dp[p][0] = w[p];
  for (int i : node[p]) {
    if (i == par) continue;
    dp[p][0] += dp[i][k-1];
  }
  for (int j = 1; j <= k; j++) {
    int a = max(j-1,0), b = max({a, k-2-a, 0});
    int ma = 0;
    for (int i : node[p]) {
      if (i == par) continue;
      dp[p][j] += dp[i][b];
      ma = max(ma, dp[i][a]-dp[i][b]);
    }
    dp[p][j] += ma;
  }
  for (int j = k-1; j >= 0; j--) {
    dp[p][j] = max(dp[p][j], dp[p][j+1]);
  }
  /*cout << p+1 << endl;
  for (int j = 0; j <= k; j++)
    cout << dp[p][j] << ' ';
    cout << endl;*/
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  k++;
  for (int i = 0; i < n; i++) cin >> w[i];
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  dfs(0);
  cout << dp[0][0] << endl;
}