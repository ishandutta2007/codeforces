#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll knapsack(int*c, int n, int m, int k, int last) {
  vector<int> dp(n+1,0);
  dp[0] = 1;
  for (int i = 0; i < 26; i++) {
    if (i == last) continue;
    for (int j = n-c[i]; j >= 0; j--)
      dp[j+c[i]] |= dp[j];
  }
  ll ans = 1e9;
  for (int i = n; i >= n-c[last] && i >= 0; i--) {
    if (dp[i]) {
      ll a = n-i;
      ll b = (i+c[last])-(k-m);
      ans = min(ans, a*b);
    }
  }
  return max(0ll,ans);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    int c[26] = {};
    for (char ci : s)
      c[ci-'A']++;
    ll ans = n*m;
    for (int i = 0; i < 26; i++) {
      ans = min(ans, knapsack(c, n, m, k, i));
    }
    cout << ans << endl;
  }
}