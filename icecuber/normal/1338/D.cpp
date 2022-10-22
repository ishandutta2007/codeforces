#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e5;
vector<int> node[nax];

int dp[nax][2];

int ans = 0;

void dfs(int p, int par) {
  dp[p][0] = 0;
  dp[p][1] = 1;
  int children = 0;
  vector<int> nodiff = {0,0}, takediff = {0,0};
  for (int i : node[p]) {
    if (i == par) continue;
    dfs(i,p);
    children++;
    nodiff.push_back(max(dp[i][0], dp[i][1])-1);
    takediff.push_back(dp[i][0]);
    dp[p][1] = max(dp[p][1], dp[i][0]+1);
  }
  sort(nodiff.rbegin(), nodiff.rend());
  dp[p][0] = nodiff[0]+children;

  sort(takediff.rbegin(), takediff.rend());

  //Don't take this one
  ans = max(ans, nodiff[0]+nodiff[1]+children + (par != -1));
  //Take this one
  ans = max(ans, takediff[0]+takediff[1]+1);
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
  dfs(0,-1);
  cout << ans << endl;
}