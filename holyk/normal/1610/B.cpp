// Author:  HolyK
// Created: Tue Nov 23 22:33:09 2021
#include <bits/stdc++.h>
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}
template <int S>
using AI = std::array<int, S>;
using LL = long long;
using PII = std::pair<int, int>;

constexpr int P(1e9 + 7);
// using Hash = std::array<uint64_t, 2>;
// Hash operator+(Hash a, Hash b) {
//   return {a[0] + b[0], (a[1] + b[1]) % P};
// }
// Hash operator-(Hash a, Hash b) {
//   return {a[0] - b[0], (a[1] - b[1]) % P};
// }
// Hash operator*(Hash a, Hash b) {
//   return {a[0] * b[0], a[1] * b[1] % P};
// }

int a[200005];
bool check(int l, int r) {
  
}
void solve() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  int l = 1, r = n;
  while (l <= r && a[l] == a[r]) l++, r--;
  if (l > r) {
    std::cout << "YES\n";
    return;
  }
  std::vector<int> b;
  for (int i = l; i <= r; i++) {
    if (a[i] != a[l]) b.push_back(a[i]);
  }
  std::vector c(b.rbegin(), b.rend());
  if (b == c) {
    std::cout << "YES\n";
    return;
  }
  b.clear();
  for (int i = l; i <= r; i++) {
    if (a[i] != a[r]) b.push_back(a[i]);
  }
  c.assign(b.rbegin(), b.rend());
  if (b == c) {
    std::cout << "YES\n";
    return;
  }
  std::cout << "NO\n";
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