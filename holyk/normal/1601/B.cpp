// Author:  HolyK
// Created: Wed Oct 27 15:27:54 2021
#include <bits/stdc++.h>
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
int n, a[N], b[N], q[N], d[N], f[N];
int find(int x) {
  while (x != f[x]) x = f[x] = f[f[x]];
  return x;
}
PII p[N];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i], a[i] = i - a[i];
  for (int i = 1; i <= n; i++) std::cin >> b[i], b[i] = i + b[i];

  int l, r;
  q[l = r = 1] = n;
  memset(d, 0x3f, sizeof d);
  d[n] = 0;
  p[n] = {n, -1};
  for (int i = 0; i <= n; i++) f[i] = i;
  f[n] = n - 1;
  while (l <= r) {
    int x = q[l++];
    for (int i = find(x); i >= a[x]; i = find(i)) {
      int y = b[i];
      if (smin(d[y], d[x] + 1)) q[++r] = y, p[y] = {i, x};
      
      f[i] = i - 1;

      if (!i) {
        std::cout << d[0] << "\n";
        std::vector<int> ans;
        for (int i = 0; i != n; i = p[i].second) {
          ans.push_back(p[i].first);
        }
        std::reverse(ans.begin(), ans.end());
        for (int i : ans) std::cout << i << " ";
        return 0;
      }
    }
  }
  std::cout << "-1\n";
  return 0;
}