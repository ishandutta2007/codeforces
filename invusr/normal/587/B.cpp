#include <bits/stdc++.h>
using namespace std;

typedef long long s64;

const int md = 1000000007;

inline void add(int &x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
}

inline int mul(int x, int y) {
  return (s64)x * y % md;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  s64 l;
  cin >> n >> l >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> disc = a;
  sort(disc.begin(), disc.end());
  disc.erase(unique(disc.begin(), disc.end()), disc.end());
  for (int i = 0; i < n; ++i) {
    a[i] = lower_bound(disc.begin(), disc.end(), a[i]) - disc.begin();
  }
  int extra = (l - 1) % n + 1;
  s64 total = (l - extra) / n;
  vector<int> dp(n, 1);
  int ans = l % md;
  for (int x = 2; x <= k; ++x) {
    vector<int> new_dp(n, 0);
    for (int i = 0; i < n; ++i) {
      add(new_dp[a[i]], dp[i]);
    }
    for (int i = 1; i < n; ++i) {
      add(new_dp[i], new_dp[i - 1]);
    }
    for (int i = 0; i < n; ++i) {
      dp[i] = new_dp[a[i]];
      add(ans, mul(dp[i], max(0ll, total - x + 1) % md));
      if (i < extra && x <= total + 1) {
        add(ans, dp[i]);
      }
    }
  }
  cout << ans << endl;

  return 0;
}