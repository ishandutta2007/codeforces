// Author:  HolyK
// Created: Wed Sep 21 14:44:05 2022
#include <algorithm>
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

constexpr int P(998244353);
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

constexpr LL M(1LL << 60);

std::vector<LL> p[61], q[61];

void get1(LL l, LL r, LL x, LL y) {
  if (r <= x || y <= l) return;
  if (x <= l && r <= y) {
    p[__builtin_ctzll(l ^ r)].push_back(l);
    return;
  }
  auto m = l + r >> 1;
  get1(l, m, x, y), get1(m, r, x, y);
}

void get2(LL l, LL r, LL x, LL y) {
  if (r <= x || y <= l) return;
  q[__builtin_ctzll(l ^ r)].push_back(l);
  if (x <= l && r <= y) return;
  auto m = l + r >> 1;
  get2(l, m, x, y), get2(m, r, x, y);
}

std::array<uint32_t, 3> res[15000000];
int cnt;
void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<LL, LL>> a(n), b;

  for (int i = 0; i < n; i++) {
    LL l, r;
    std::cin >> l >> r;
    a[i] = {l, r + 1};
  }

  std::cin >> n;
  b.resize(n);
  for (int i = 0; i < n; i++) {
    LL l, r;
    std::cin >> l >> r;
    b[i] = {l, r + 1};
  }

  
  auto work = [&] {
    for (int i = 0; i <= 60; i++) p[i].clear(), q[i].clear();
    for (auto &[l, r] : a) get1(0, M, l, r);
    for (auto &[l, r] : b) get2(0, M, l, r);

    for (int i = 0; i <= 60; i++) {
      std::sort(p[i].begin(), p[i].end());
      p[i].erase(std::unique(p[i].begin(), p[i].end()), p[i].end());
      std::sort(q[i].begin(), q[i].end());
      q[i].erase(std::unique(q[i].begin(), q[i].end()), q[i].end());
      for (auto x : p[i])
        for (auto y : q[i]) {
          LL l = x ^ y;
          res[cnt][0] = l >> 32;
          res[cnt][1] = l & 0xffffffffu;
          res[cnt][2] = i;
          cnt++;
        }
    }
  };

  work();
  std::swap(a, b);
  work();

  int ans = 0;

  std::sort(res, res + cnt);
  LL l = 0, r = 0;
  auto cal = [&] {
    l %= P, r %= P;
    ans = (ans + (l + r - 1) * (r - l) / 2) % P;
  };
  
  for (int i = 0; i < cnt; i++) {
    LL x = ((uint64_t)res[i][0] << 32) | uint64_t(res[i][1]);
    LL y = x + (1LL << res[i][2]);
    if (x > r) {
      cal();
      l = x;
      r = y;
    } else {
      smax(r, y);
    }
  }

  cal();

  std::cout << (ans + P) % P << "\n";
}

int main() {
  // freopen("t.in", "r", stdin);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  // std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}