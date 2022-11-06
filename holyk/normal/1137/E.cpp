// Author:  HolyK
// Created: Thu Nov  4 14:10:26 2021
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
LL a[N << 1], c[N][2];
int l, r;
void add(int p, LL x0, LL x1) {
  p -= l - 1;
  for (; p <= r - l + 1; p += p & -p) c[p][0] += x0, c[p][1] += x1;
}
LL ask(int p) {
  int x = a[p];
  LL res = 0;
  for (p -= l - 1; p; p -= p & -p) res += c[p][0] + c[p][1] * x;
  return res;
}

using LLL = __int128_t;
LLL cross(LL x0, LL y0, LL x1, LL y1, LL x2, LL y2) {
  return LLL(x1 - x0) * (y2 - y0) - LLL(x2 - x0) * (y1 - y0);
}

int main() {
  // freopen("t.in", "r", stdin);
  // freopen(".out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  
  std::vector<std::array<int, 3>> opt(m);
  int p = 1, q = n + 1;
  a[l = r = m] = 1;
  
  for (auto &[x, y, z] : opt) {
    std::cin >> x >> y;

    if (x == 1) {
      a[--l] = p -= y;
    } else if (x == 2) {
      a[++r] = q;
      q += y;
    } else {
      std::cin >> z;
    }
  }

  static int s[N], t;
  s[t = 1] = p = q = m;
  for (auto &[x, y, z] : opt) {
    if (x == 1) {
      s[t = 1] = --p;
    } else if (x == 2) {
      q++;
      while (t > 1 && cross(a[s[t - 1]], ask(s[t - 1]), a[q], 0, a[s[t]], ask(s[t])) >= 0) t--;
      s[++t] = q;
    } else {
      add(p, y - 1LL * z * a[p], z);
      add(q + 1, -y + 1LL * z * a[p], -z);
    }
    while (t > 1 && ask(s[t]) >= ask(s[t - 1])) t--;
    std::cout << a[s[t]] - a[p] + 1 << " " << ask(s[t]) << "\n";
  }
  return 0;
}