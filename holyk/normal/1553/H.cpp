// Author:  HolyK
// Created: Fri Jul 23 20:31:24 2021
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

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(1 << k), min(1 << k, 1e9), max(1 << k, -1e9), ans(1 << k, 1e9);
  while (n--) {
    int x;
    std::cin >> x;
    a[x] = 1;
    min[x] = max[x] = 0;
  }
  n = 1 << k;
  for (int i = 1; i < n; i <<= 1) {
    std::vector<int> newmin(n), newmax(n), newans(n);
    for (int j = 0; j < n; j += i << 1) {
      for (int k = 0; k < i; k++) {
        int l = j + k, r = i + j + k;
        newmin[l] = std::min(min[l], i + min[r]);
        newmax[l] = std::max(max[l], i + max[r]);
        newmin[r] = std::min(min[r], i + min[l]);
        newmax[r] = std::max(max[r], i + max[l]);
        newans[l] = std::min({ans[l], ans[r], min[r] - max[l] + i});
        newans[r] = std::min({ans[l], ans[r], min[l] - max[r] + i});
      }
    }
    min.swap(newmin);
    max.swap(newmax);
    ans.swap(newans);
  }
  for (int x : ans) std::cout << x << " ";
  return 0;
}
/*

 */