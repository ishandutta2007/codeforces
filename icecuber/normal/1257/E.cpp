#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[200010][3];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int k[3];
  cin >> k[0] >> k[1] >> k[2];
  int n = k[0]+k[1]+k[2];
  vector<int> a(n);
  for (int j = 0; j < 3; j++) {
    while (k[j]--) {
      int i;
      cin >> i;
      a[i-1] = j;
    }
  }
  for (int i = 0; i < n; i++) {
    dp[i+1][0] = dp[i][0]+(a[i]==0);
    dp[i+1][1] = max(dp[i][1]+(a[i]==1), dp[i+1][0]);
    dp[i+1][2] = max(dp[i][2]+(a[i]==2), dp[i+1][1]);
  }
  cout << n-dp[n][2] << endl;
}