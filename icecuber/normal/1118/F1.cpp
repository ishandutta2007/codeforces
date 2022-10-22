#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[300000];
int dp[300000][3], col[300000];
void dfs(int p, int par = -1) {
  dp[p][col[p]]++;
  for (int i : node[p]) {
    if (i == par) continue;
    dfs(i, p);
    for (int j = 0; j < 3; j++)
      dp[p][j] += dp[i][j];
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> col[i];
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  dfs(0);
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (dp[i][1] == 0 && dp[i][2] == dp[0][2] ||
	dp[i][2] == 0 && dp[i][1] == dp[0][1]) ans++;
  }
  cout << ans << endl;
}