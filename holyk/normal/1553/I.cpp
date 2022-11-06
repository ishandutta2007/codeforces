// Author:  HolyK
// Created: Sat Jul 24 09:24:26 2021
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

namespace Polynomial {
using Poly = std::vector<int>;
constexpr int P(998244353), G(3);
inline void inc(int &x, int y) { (x += y) >= P ? x -= P : 0; }
inline int sum(int x, int y) { return x + y >= P ? x + y - P : x + y; }
inline int sub(int x, int y) { return x - y < 0 ? x - y + P : x - y; }
inline int fpow(int x, int k = P - 2) {
  int r = 1;
  for (; k; k >>= 1, x = 1LL * x * x % P)
    if (k & 1) r = 1LL * r * x % P;
  return r;
}
std::vector<int> w;
void getOmega(int k) {
  w.resize(k);
  w[0] = 1;
  int base = fpow(G, (P - 1) / (k << 1));
  for (int i = 1; i < k; i++) w[i] = 1LL * w[i - 1] * base % P;
}
void dft(int *a, int n) {
  assert((n & n - 1) == 0);
  for (int k = n >> 1; k; k >>= 1) {
    getOmega(k);
    for (int i = 0; i < n; i += k << 1) {
      for (int j = 0; j < k; j++) {
        int y = a[i + j + k];
        a[i + j + k] = (1LL * a[i + j] - y + P) * w[j] % P;
        inc(a[i + j], y);
      }
    }
  }
}
void dft(Poly &a) { dft(a.data(), a.size()); }
void idft(int *a, int n) {
  assert((n & n - 1) == 0);
  for (int k = 1; k < n; k <<= 1) {
    getOmega(k);
    for (int i = 0; i < n; i += k << 1) {
      for (int j = 0; j < k; j++) {
        int x = a[i + j], y = 1LL * a[i + j + k] * w[j] % P;
        a[i + j] = sum(x, y), a[i + j + k] = sub(x, y);
      }
    }
  }
  for (int i = 0, inv = P - (P - 1) / n; i < n; i++)
    a[i] = 1LL * a[i] * inv % P;
  std::reverse(a + 1, a + n);
}
void idft(Poly &a) { idft(a.data(), a.size()); }
Poly operator*(Poly a, Poly b) {
  int len = a.size() + b.size() - 1;
  if (a.size() <= 60 || b.size() <= 60) {
    Poly c(len);
    for (size_t i = 0; i < a.size(); i++)
      for (size_t j = 0; j < b.size(); j++)
        c[i + j] = (c[i + j] + 1LL * a[i] * b[j]) % P;
    return c;
  }
  int n = 1 << std::__lg(len - 1) + 1;
  a.resize(n), b.resize(n);
  dft(a), dft(b);
  for (int i = 0; i < n; i++) a[i] = 1LL * a[i] * b[i] % P;
  idft(a);
  a.resize(len);
  return a;
}
Poly operator+(Poly a, Poly b) {
  a.resize(std::max(a.size(), b.size()));
  for (int i = 0; i < b.size(); i++) inc(a[i], b[i]);
  return a;
}
Poly operator-(Poly a, Poly b) {
  a.resize(std::max(a.size(), b.size()));
  for (int i = 0; i < b.size(); i++) inc(a[i], P - b[i]);
  return a;
}
Poly shift(Poly a, int x) {
  if (x < 0) {
    return -x > a.size() ? Poly() : Poly(a.begin() - x, a.end());
  }
  a.insert(a.begin(), x, 0);
  return a;
}
}  // namespace Polynomial

using namespace Polynomial;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> a(n), b;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0, j; i < n; i = j) {
    j = i + a[i];
    if (j > n) return std::cout << "0\n", 0;
    for (int k = i; k < j; k++) {
      if (a[k] != a[i]) return std::cout << "0\n", 0;
    }
    b.push_back(a[i]);
  }
  auto solve = [&](auto self, int l, int r) -> std::array<std::array<Poly, 2>, 2> {
    std::array<std::array<Poly, 2>, 2> res;
    if (r - l == 1) {
      for (auto &a : res) a.fill({0, 1});
      if (b[l] == 1) res[0][0] = {0, P + 1 >> 1};
      return res;
    }
    int m = l + r >> 1;
    auto p = self(self, l, m), q = self(self, m, r);
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        res[i][j] = p[i][0] * q[0][j] + shift(p[i][1] * q[1][j], -1);
      }
    }
    return res;
  };
  auto res = solve(solve, 0, b.size());
  int ans = 0, m = b.size();
  for (int i = 1, pw = 1, fac = 1; i <= m; i++) {
    pw = 2LL * pw % P;
    fac = 1LL * fac * i % P;
    ans = (ans + 1LL * pw * fac % P * res[0][0][i] * (m - i & 1 ? -1 : 1)) % P;
  }
  std::cout << (ans + P) % P << "\n";
  return 0;
}
/*

 */