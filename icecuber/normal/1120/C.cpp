#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int miss[5001];
int kmp(string text, string key) {
  miss[0] = -1;
  int p = -1;
  for (int i = 0; i < key.size(); i++) {
    while (p > -1 && key[p] != key[i]) p = miss[p];
    miss[i+1] = ++p;
  }
  int ans = 0;
  p = 0;
  for (char c : text) {
    while (p > -1 && key[p] != c) p = miss[p];
    ans = max(ans, ++p);
  }
  return ans;
}

ll dp[5001];

int main() {
  //cout << kmp("baabcaabaabc", "aabaab") << endl;
  //return 0;
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  fill_n(dp+1, s.size(), 1e18);
  for (int i = 0; i <= n; i++) {
    dp[i] = min(dp[i-1]+a, dp[i]);
    int m = kmp(s.substr(0, i), s.substr(i, n-i));
    dp[i+m] = min(dp[i+m], dp[i]+b);
  }
  cout << dp[n] << endl;
}