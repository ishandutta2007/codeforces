#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[5001][5001];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  sort(a.begin(), a.end());

  int j = 0;
  for (int i = 0; i < n; i++) {
    while (j+1 < n && a[j+1] <= a[i]+5) j++;
    for (int l = 0; l < k; l++) {
      dp[j+1][l+1] = max(dp[j+1][l+1], dp[i][l]+j+1-i);
    }
    for (int l = 0; l <= k; l++)
      dp[i+1][l] = max(dp[i+1][l], dp[i][l]);
  }
  int ans = 0;
  for (int l = 0; l <= k; l++)
    ans = max(ans, dp[n][l]);
  cout << ans << endl;
}