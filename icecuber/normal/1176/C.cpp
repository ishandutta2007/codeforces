#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> dp(7,0);
  dp[0] = 1e7;
  map<int,int> m;
  m[4] = 0, m[8] = 1, m[15] = 2, m[16] = 3, m[23] = 4, m[42] = 5;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    a = m[a];
    if (!dp[a]) ans++;
    else dp[a]--, dp[a+1]++;
  }
  for (int i = 1; i < 6; i++)
    ans += dp[i]*i;
  cout << ans << endl;
}