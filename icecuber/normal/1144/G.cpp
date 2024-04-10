#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int par[200000][2];
int dp[200000][2];
int a[200000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n >> a[0];
  dp[0][0] = 1e9;
  dp[0][1] =-1e9;
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    dp[i][0] =-1e9;
    if (a[i-1] < a[i] && dp[i-1][0] > dp[i][0]) {
      dp[i][0] = dp[i-1][0];
      par[i][0] = 0;
    }
    if (dp[i-1][1] < a[i] && a[i-1] > dp[i][0]) {
      dp[i][0] = a[i-1];
      par[i][0] = 1;
    }

    dp[i][1] = 1e9;
    if (a[i-1] > a[i] && dp[i-1][1] < dp[i][1]) {
      dp[i][1] = dp[i-1][1];
      par[i][1] = 1;
    }
    if (dp[i-1][0] > a[i] && a[i-1] < dp[i][1]) {
      dp[i][1] = a[i-1];
      par[i][1] = 0;
    }
  }
  //for (int i = 0; i < n; i++)
  //cout << dp[i][0] << ' ' << dp[i][1] << endl;
  if (dp[n-1][0] ==-1e9 && dp[n-1][1] == 1e9) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    int p = (dp[n-1][0] ==-1e9);
    vector<int> ans;
    for (int i = n-1; i >= 0; i--) {
      ans.push_back(p);
      p = par[i][p];
    }
    reverse(ans.begin(), ans.end());
    for (int p : ans)
      cout << p << ' ';
    cout << endl;
  }
}