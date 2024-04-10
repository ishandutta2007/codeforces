#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<array<int,2>> lr(n);
    for (int i = 0; i < n; i++) cin >> lr[i][0] >> lr[i][1];
    vector<vector<int>> node(n);
    for (int i = 0; i < n-1; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      node[a].push_back(b);
      node[b].push_back(a);
    }
    vector<array<ll,2>> dp(n);
    function<void(int,int)> dfs = [&](int p, int par) {
      for (int i : node[p]) {
        if (i == par) continue;
        dfs(i, p);
        for (int k : {0,1}) {
          ll m = 0;
          for (int l : {0,1}) {
            m = max(m, dp[i][l]+abs(lr[i][l]-lr[p][k]));
          }
          dp[p][k] += m;
        }
      }
    };
    dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]) << endl;
  }
}