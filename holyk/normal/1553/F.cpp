// Author:  HolyK
// Created: Thu Jul 22 23:31:57 2021
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

constexpr int N(3e5 + 5), T(512), S(N / T + 1);
struct Block {
  LL a[N], s[N];
  void add(int p, int x) {
    int t = p / T;
    int y = std::min(N, t * T + T);
    for (int i = p; i < y; i++) a[i] += x;
    for (int i = t + 1; i < S; i++) s[i] += x;
  }
  LL ask(int x) {
    smin(x, N - 1);
    return s[x / T] + a[x];
  }
  LL ask(int l, int r) {
    if (l > r) return 0;
    return ask(r) - ask(l - 1);
  }
} s, c;
LL sum[T];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  LL ans = 0;
  for (int i = 0; i < n; i++) {
    // > a[i]
    if (a[i] < T) {
      ans += sum[a[i]];
    } else {
      for (int j = a[i]; j < N; j += a[i]) {
        ans += s.ask(j, j + a[i] - 1) - j * c.ask(j, j + a[i] - 1);
      } 
    }
    // std::cerr << ans << "\n";
    // < a[i]
    for (int l = 1, r, x; l < a[i]; l = r + 1) {
      x = a[i] / l, r = a[i] / x;
      smin(r, a[i]);
      // std::cerr << a[i] << " " << l << " " << r << " " << c.ask(l, r) << " " << s.ask(l, r) << "\n";
      ans += a[i] * c.ask(l, r) - x * s.ask(l, r);
    }
    for (int j = 2; j < T && j < a[i]; j++) {
      sum[j] += a[i] % j;
    }
    // std::cerr << ans << "\n";
    ans += c.ask(a[i], N - 1) * a[i];
    ans += s.ask(1, a[i]);
    c.add(a[i], 1);
    s.add(a[i], a[i]);
    std::cout << ans << " \n"[i == n - 1];
  }
  return 0;
}
/*

 */