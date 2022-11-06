// LUOGU_RID: 92516386
// Author:  HolyK
// Created: Wed Nov  2 00:31:05 2022
#include "bits/stdc++.h"

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
  int p, q;
  std::string s;
  std::cin >> p >> q >> s;
  std::vector<int> v(s.size()), a;
  for (int i = 0; i < s.size(); i++) v[i] = s[i] - '0';
  
  for (;;) {
    int t = -1;
    LL x = 0;
    for (int i = 0; i < v.size(); i++) {
      x = x * 10 + v[i];
      v[i] = x / p, x %= p;
      if (v[i] && t == -1) t = i;
    }
    a.push_back(x);
    if (t == -1) break;
    v.erase(v.begin(), v.begin() + t);
  }

  int d = a.size();

  if (q >= d) {
    std::cout << "0\n";
    return;
  }
  
  // [cnt][ub][fwd]
  
  std::vector<std::array<Z, 4>> f(q + 1), g;
  f[0][2] = 1;

  std::reverse(a.begin(), a.end());
  for (int rx : a) {
    g.assign(q + 1, {});
    for (int i = 0; i <= q; i++) {
      for (int j = 0; j < 4; j++) { // fwd ub
        for (int k = 0; k < 4; k++) {
          int e = j & 2 ? rx : p - 1;
          e -= k & 1;
          
          LL v;
          if (k & 2) {
            if (j & 1) {
              v = p - 1 - e;
            } else {
              v = e + 1;
            }
          } else {
            e--;
            if (j & 1) {
              // p <= a + b <= p + e
              // 1 p-1
              // 2 p-2..p-1
              // ...
              // e+1 p-e-1..p-1
              // e+2 p-e-2..p-2
              // ...
              // p-1 1..e+1

              v = (1LL + e) * e / 2 + (1LL + e) * (p - 1 - e);
              if (k & 1) v += p;
            } else {
              // a + b <= e
              v = (1LL + e) * (2 + e) >> 1;
            }
          }
          
          g[std::min(i + (j & 1), q)][k & (j & 2 | 1)] += f[i][j] * v;
        }
      }
    }
    f.swap(g);
  }

  Z ans = f[q][0] + f[q][2];
  std::cout << ans << "\n";
}

int main() {
  // freopen("t.in", "r", stdin);
  // freopen("t.out", "w", stdout);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  // std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}