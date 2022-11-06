// Author:  HolyK(Asuka Kyle)
// Created: Tue Jan 11 15:51:05 2022
#include <bits/stdc++.h>
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}
template <int S>
using AI = std::array<int, S>;
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

Z s2[202][202];
void getS2(int k) {
  s2[0][0] = 1;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= i; j++) {
      s2[i][j] = s2[i - 1][j] * j + s2[i - 1][j - 1];
    }
  }
}

constexpr int N(1e5 + 5);
int n, k, siz[N];
std::vector<int> g[N];

using V = std::array<Z, 202>;
Z f[2][N][202];

void dfs(int x, int p) {
  siz[x] = 1;
  f[1][x][0] = 1;
  for (int y : g[x]) {
    if (y == p) continue;
    dfs(y, x);
    for (int i = std::min(k, siz[x] - 1); i >= 0; i--) {
      for (int j = std::min(k - i, siz[y] - 1); j >= 0; j--) {
        if (i + j + 1 <= k) {
          f[0][x][i + j + 1] += (f[1][x][i] - (i == 0)) * (f[1][y][j] * 2 - (j == 0));
          f[1][x][i + j + 1] += f[1][x][i] * (f[1][y][j] * 2 - (j == 0));
        }
        f[0][x][i + j] += (f[1][x][i] - (i == 0)) * (f[1][y][j] * 2 - (j == 0));
        f[1][x][i + j] += f[1][x][i] * (f[1][y][j] * 2 - (j == 0));
      }
    }
    for (int i = 0; i <= k && i < siz[y]; i++) {
      f[0][x][i] += f[0][y][i] + f[1][y][i];
    }
    siz[x] += siz[y];
  }
  
  
}

void solve() {
  std::cin >> n >> k;
  
  for (int i = 1; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  
  dfs(1, 0);
  
  getS2(k);
  Z fac = 1, ans = 0;
  for (int i = 0; i <= k; i++) {
    if (i) fac *= i;
    ans += (f[0][1][i] + f[1][1][i]) * fac * s2[k][i];
  }
  std::cout << ans << "\n";
}

int main() {
  // freopen("t.in", "r", stdin);
  // freopen(".out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}