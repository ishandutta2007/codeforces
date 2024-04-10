#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[100010][2];
ll h[2][100000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> h[0][i];
  for (int i = 0; i < n; i++)
    cin >> h[1][i];
  for (int i = 10; i < n+10; i++) {
    for (int j = 0; j < 2; j++) {
      dp[i][j] = max(dp[i-1][!j], dp[i-2][!j])+h[j][i-10];
    }
  }
  cout << max(dp[n+10-1][0], dp[n+10-1][1]) << endl;
}