#include <bits/stdc++.h>
using namespace std;

#define ll long long
int keep[1005][1005];
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, MOD; cin >> n >> MOD;
  if (n < 3) {
    cout << 0 << '\n';
    return 0;
  }
  int shift = n * (n + 1) / 2, sz = n * (n + 1);
  
  vector<int> dp(sz);
  for (int i = shift + 1; i < sz; ++i) dp[i] = 1;
  for (int i = shift - n + 1; i < shift + n; ++i) keep[1][i - shift + n - 1] = dp[i];
  vector<__int128> pl(sz + 1), pr(sz + 1), ps(sz + 1);
  for (int i = 0; i < sz; ++i) pl[i + 1] = pl[i] + (ll) i * dp[i];
  for (int i = sz - 1; i >= 0; --i) pr[i] = pr[i + 1] + (ll) (sz - 1 - i) * dp[i];
  for (int i = 0; i < sz; ++i) ps[i + 1] = ps[i] + dp[i];
  for (int i = 2; i < n; ++i) {
    for (int off = 0; off < sz; ++off) {
      int l = off - i + 1, r = off + i - 1, al = max(0, -l) + 1, ar = max(0, r - sz + 1) + 1;
      l = max(l, 0), r = min(r, sz - 1);
      __int128 sl = pl[off] - pl[l] + (ll) (al - l) * (ps[off] - ps[l]);
      __int128 sr = pr[off] - pr[r + 1] + (ll) (ar - sz + 1 + r) * (ps[r + 1] - ps[off]);
      dp[off] = (sl + sr) % MOD;
      if (dp[off] < 0) dp[off] += MOD;
    }
    for (int j = shift - n + 1; j < shift + n; ++j) keep[i][j - shift + n - 1] = dp[j];
    for (int i = 0; i < sz; ++i) pl[i + 1] = pl[i] + (ll) i * dp[i];
    for (int i = sz - 1; i >= 0; --i) pr[i] = pr[i + 1] + (ll) (sz - 1 - i) * dp[i];
    for (int i = 0; i < sz; ++i) ps[i + 1] = ps[i] + dp[i];
  }
  vector<int> dp2(n + 1);
  for (int i = 3; i <= n; ++i) {
    for (int j = 0; j < i; ++j) {
      for (int k = j + 1; k < i; ++k) dp2[i] = (dp2[i] + keep[i - 1][n - 1 + j - k]) % MOD;
      dp2[i] = (dp2[i] + dp2[i - 1]) % MOD;
    }
  }
  cout << dp2[n] << '\n';
  return 0;
}