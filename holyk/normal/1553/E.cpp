// Author:  HolyK
// Created: Thu Jul 22 23:26:33 2021
#include <bits/stdc++.h>
#define dbg(a...) fprintf(stderr, a)
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}

using LL = long long;
using PII = std::pair<int, int>;

constexpr int N(3e5 + 5);
int a[N], cnt[N];
void solve() {
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) cnt[i] = 0;
  for (int i = 1; i <= n; i++) std::cin >> a[i], cnt[(i - a[i] + n) % n]++;
  std::vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (cnt[i] < n - m * 2) continue;
    // std::cerr << i << "\n";
    std::vector<int> b(n), vis(n);
    for (int j = i + 1; j <= n; j++) b[j - i - 1] = a[j] - 1;
    for (int j = 1; j <= i; j++) b[n - i + j - 1] = a[j] - 1;
    int c = 0;
    for (int j = 0; j < n; j++) {
      if (vis[j]) continue;
      for (int k = j; !vis[k]; k = b[k]) vis[k] = 1;
      c++;
    }
    if (n - c <= m) ans.push_back(i);
  }
  // std::sort(ans.begin(), ans.end());
  std::cout << ans.size();
  for (int x : ans) std::cout << " " << x;
  std::cout << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
/*

 */