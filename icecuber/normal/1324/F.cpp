#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5;
int col[nax];
vector<int> node[nax];

int dp[nax]; //maxmimum for subtree of p

void dfs1(int p, int par) {
  dp[p] = col[p];
  for (int i : node[p]) {
    if (i == par) continue;
    dfs1(i, p);
    dp[p] += max(dp[i], 0);
  }
}

int ans[nax];

void dfs2(int p, int par, int top) {
  top = max(top, 0);
  ans[p] = dp[p]+top;

  top += dp[p];
  for (int i : node[p]) {
    if (i == par) continue;
    dfs2(i, p, top-max(dp[i],0));
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> col[i];
    col[i] = col[i]*2-1;
  }
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  dfs1(0, -1);
  dfs2(0, -1, 0);
  for (int i = 0; i < n; i++)
    cout << ans[i] << ' ';
  cout << endl;
}