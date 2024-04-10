// Author:  HolyK
// Created: Wed Mar  9 11:26:29 2022
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

constexpr int P(1e9 + 7);
inline void inc(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}
inline void dec(int &x, int y) {
  x -= y;
  if (x < 0) x += P;
}
inline int mod(LL x) { return x % P; }
int fpow(int x, int k = P - 2) {
  int r = 1;
  for (; k; k >>= 1, x = 1LL * x * x % P) {
    if (k & 1) r = 1LL * r * x % P;
  }
  return r;
}
struct Z {
  int x;
  Z() : x(0) {}
  Z(int v) : x(v < 0 ? v + P : v >= P ? v - P : v) {}
  Z(LL v) : x((v %= P) < 0 ? v + P : v) {}
  explicit operator bool() { return !!x; }
  Z inv() const { return Z(fpow(x)); }
  Z pow(int k) const { return Z(fpow(x, k)); }
  Z operator-() const { return Z(P - x); }
  Z &operator+=(const Z &r) { return inc(x, r.x), *this; }
  Z &operator-=(const Z &r) { return dec(x, r.x), *this; }
  Z &operator*=(const Z &r) { return x = LL(x) * r.x % P, *this; }
  Z &operator/=(const Z &r) { return x = LL(x) * fpow(r.x) % P, *this; }
  inline friend Z operator+(const Z &a, const Z &b) { return Z(a) += b; }
  inline friend Z operator-(const Z &a, const Z &b) { return Z(a) -= b; }
  inline friend Z operator*(const Z &a, const Z &b) { return Z(a) *= b; }
  inline friend Z operator/(const Z &a, const Z &b) { return Z(a) /= b; }
  inline friend std::ostream &operator<<(std::ostream &os, const Z &r) {
    return os << r.x;
  }
};

void solve() {
  int n , m, s, t;
  std::cin >> n >> m >> s >> t;
  s--, t--;
  std::vector<std::vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  std::vector<int> q(n * 2), d(n, 1e9);
  int l, r;
  q[l = r = 0] = s;
  d[s] = 0;
  while (l <= r) {
    int x = q[l++];
    for (int y : g[x]) {
      if (smin(d[y], d[x] + 1)) {
        q[++r] = y;
      }
    }
  }

  std::vector<int> p(n);
  std::iota(p.begin(), p.end(), 0);
  std::sort(p.begin(), p.end(), [&](int i, int j) {
    return d[i] < d[j];
  });
  
  std::vector<Z> f(n), f2(n);
  f[s] = f2[t] = 1;
  for (int x : p) {
    for (int y : g[x]) {
      if (d[y] == d[x] + 1)
        f[y] += f[x];
    }
  }
  std::reverse(p.begin(), p.end());
  for (int x : p) {
    for (int y : g[x]) {
      if (d[y] == d[x] + 1) {
        f2[x] += f2[y];
      }
    }
  }

  Z ans = f[t];
  for (int i = 0; i < n; i++) {
    for (int j : g[i]) {
      if (d[i] == d[j]) {
        ans += f[i] * f2[j];
      }
    }
  }
  std::cout << ans << "\n";
}

int main() {
  // freopen("t.in", "r", stdin);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}