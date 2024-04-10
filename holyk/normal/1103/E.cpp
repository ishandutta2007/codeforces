// Author:  HolyK
// Created: Sun Aug  8 21:08:34 2021
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

using u64 = uint64_t;
using Poly = std::array<u64, 4>;
Poly operator*(Poly a, Poly b) {
  static u64 c[7];
  memset(c, 0, sizeof c);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      c[i + j] += a[i] * b[j];
    }
  }
  return {c[0] - c[4] - c[5], c[1] + c[4] - c[6], c[2] - c[4], c[3] + c[4]};
}
Poly &operator+=(Poly &a, Poly b) {
  for (int i = 0; i < 4; i++) {
    a[i] += b[i];
  }
  return a;
}
Poly &operator-=(Poly &a, Poly b) {
  for (int i = 0; i < 4; i++) {
    a[i] -= b[i];
  }
  return a;
}
Poly operator+(Poly a, Poly b) {
  return a += b;
}
Poly operator-(Poly a, Poly b) {
  return a -= b;
}
constexpr Poly w[] = {
  Poly({1ULL, 0ULL, 0ULL, 0ULL}),
  Poly({0ULL, 1ULL, 0ULL, 0ULL}),
  Poly({0ULL, 0ULL, 1ULL, 0ULL}),
  Poly({0ULL, 0ULL, 0ULL, 1ULL}),
  Poly({~0ULL, 1ULL, ~0ULL, 1ULL}),
  Poly({~0ULL, 0ULL, 0ULL, 0ULL}),
  Poly({0ULL, ~0ULL, 0ULL, 0ULL}),
  Poly({0ULL, 0ULL, ~0ULL, 0ULL}),
  Poly({0ULL, 0ULL, 0ULL, ~0ULL}),
  Poly({1ULL, ~0ULL, 1ULL, ~0ULL})
};
constexpr int N(100000), M(10);
void fwt(Poly *a, int f) {
  for (int i = 1; i < N; i *= M) {
    for (int j = 0; j < N; j += i * M) {
      for (int k = 0; k < i; k++) {
        static Poly t[M];
        for (int p = 0; p < M; p++) {
          t[p].fill(0);
          for (int q = 0; q < M; q++) {
            t[p] += a[i * q + j + k] * w[(M + p * f) * q % M];
          }
        }
        for (int p = 0; p < M; p++) {
          a[i * p + j + k] = t[p];
        }
      }
    }
  }
}
Poly fpow(Poly x, int k) {
  Poly r;
  r.fill(0);
  r[0] = 1;
  for (; k; k >>= 1, x = x * x) {
    if (k & 1) r = r * x;
  }
  return r;
}
Poly a[N];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    a[x][0]++;
  }
  fwt(a, 1);
  for (int i = 0; i < N; i++) {
    a[i] = fpow(a[i], n);
  }
  fwt(a, -1);
  for (int i = 0; i < n; i++) {
    assert(a[i][1] == 0 && a[i][2] == 0 && a[i][3] == 0);
    // std::cout << a[i][0] << "\n";
    std::cout << (a[i][0] >> 5) * 94170628496287261ULL % (1ULL << 58) << "\n";
  }
  return 0;
}