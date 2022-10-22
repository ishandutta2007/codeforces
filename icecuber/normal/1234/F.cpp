#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int has[1<<20];
int dp[1<<20];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  has[0] = 1;
  for (int i = 0; i < s.size(); i++) {
    int mask = 0;
    for (int j = i; j < s.size(); j++) {
      int v = 1<<s[j]-'a';
      if (mask&v) break;
      mask |= v;
      has[mask] |= 1;
    }
  }

  for (int i = 0; i < 1<<20; i++) {
    dp[i] = has[i]*__builtin_popcount(i);
    for (int j = 0; j < 20; j++)
      if (i>>j&1)
	dp[i] = max(dp[i], dp[i^1<<j]);
  }
  int ans = 0;
  for (int i = 0; i < 1<<20; i++) {
    if (has[i]) {
      ans = max(ans, dp[i]+dp[(1<<20)-1-i]);
    }
  }
  cout << ans << endl;
}