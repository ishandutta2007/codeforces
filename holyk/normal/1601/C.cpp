// Author:  HolyK
// Created: Wed Oct 27 15:48:57 2021
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

constexpr int N(1e6 + 5);
int n, m, a[N], b[N], c[N];

void add(int p, int x) {
  for (; p <= n; p += p & -p) c[p] += x;
}
int ask(int p) {
  int r = 0;
  for (; p; p -= p & -p) r += c[p];
  return r;
}


void solve() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i];

  static int p[N];
  for (int i = 1; i <= n; i++) p[i] = i, c[i] = 0;
  std::sort(p + 1, p + 1 + n, [](int i, int j) {
    return a[i] < a[j];
  });
  LL ans = 0;
  for (int i = 1, j; i <= n; ) {
    for (j = i; j <= n && a[p[i]] == a[p[j]]; j++) {
      ans += i - 1 - ask(p[j]);
    }
    while (i < j) add(p[i++], 1);
  }
  // std::cerr << ans << "\n";
  for (int i = 1; i <= m; i++) std::cin >> b[i];
  std::sort(b + 1, b + 1 + m);

  int s = 1 << std::__lg(n * 2 + 1);
  std::vector<int> sum(s * 2), min(s * 2);
  auto pushup = [&](int i) {
    sum[i] = sum[i * 2] + sum[i * 2 + 1];
    min[i] = std::min(min[i * 2], sum[i * 2] + min[i * 2 + 1]);
  };
  auto update = [&](int i, int x) {
    i += s;
    min[i] = sum[i] = x;
    while (i > 1) pushup(i >>= 1);
  };
  for (int i = 1; i <= n; i++) min[i + s] = sum[i + s] = 1;
  for (int i = s - 1; i; i--) pushup(i);
  
  for (int i = 1, j = 1; i <= m; i++) {
    for (; j <= n && a[p[j]] < b[i]; j++) {
      update(p[j], -1);
    }
    for (int k = j; k <= n && a[p[k]] == b[i]; k++) {
      update(p[k], 0);
    }
    
    int o = j - 1 + min[1];
    ans += o;
    while (i < m && b[i + 1] == b[i]) ans += o, i++;
  }
  std::cout << ans << "\n";
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