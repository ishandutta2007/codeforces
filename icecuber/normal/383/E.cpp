#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[1<<24];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int mask = 0;
    for (char c : s)
      mask |= 1<<c-'a';
    for (int j = mask; j; j = (j-1)&mask)
      dp[j] += __builtin_popcount(j)&1 ? 1 : -1;
  }
  for (int j = 0; j < 24; j++)
    for (int i = 0; i < 1<<24; i++)
      if (i>>j&1)
	dp[i] += dp[i^1<<j];
  ll ans = 0;
  for (int i = 0; i < 1<<24; i++) {
    ans ^= dp[i]*dp[i];
  }
  cout << ans << endl;
}