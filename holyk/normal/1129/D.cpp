// Author:  HolyK
// Created: Sat Feb 26 14:54:39 2022
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

constexpr int N(1e5 + 5), T(512);
#define ls o << 1
#define rs o << 1 | 1
std::vector<PII> g[N << 2];
std::vector<int> s[N << 2];
int add[N << 2];
void pushup(int o) {
  g[o].clear();
  int i = 0, j = 0;
  while (i < g[ls].size() || j < g[rs].size()) {
    if (j == g[rs].size() || i < g[ls].size() && g[ls][i].first + add[ls] < g[rs][j].first + add[rs]) {
      g[o].push_back({g[ls][i].first + add[ls], g[ls][i].second});
      i++;
    } else {
      g[o].push_back({g[rs][j].first + add[rs], g[rs][j].second});
      j++;
    }
  }
  s[o].resize(g[o].size() + 1);
  for (int i = 0; i < g[o].size(); i++) {
    inc(s[o][i + 1] = s[o][i], g[o][i].second);
  }
}
void update(int o, int l, int r, int x, int y) {
  if (l == r) {
    g[o] = {{0, y}};
    s[o] = {0, y};
    return;
  }
  int m = l + r >> 1;
  x <= m ? update(ls, l, m, x, y) : update(rs, m + 1, r, x, y);
  if (r - l + 1 <= T) pushup(o);
}
void update(int o, int l, int r, int x, int y, int z) {
  if (x <= l && r <= y) {
    add[o] += z;
    return;
  }
  int m = l + r >> 1;
  if (x <= m) update(ls, l, m, x, y, z);
  if (y > m) update(rs, m + 1, r, x, y, z);
  if (r - l + 1 <= T) pushup(o);
}
int ask(int o, int l, int r, int x, int y, int z) {
  z -= add[o];
  if (x <= l && r <= y && r - l + 1 <= T) {
    return s[o][std::upper_bound(g[o].begin(), g[o].end(), PII(z, P)) - g[o].begin()];
  }
  int m = l + r >> 1, ans = 0;
  if (x <= m) ans = ask(ls, l, m, x, y, z);
  if (y > m) inc(ans, ask(rs, m + 1, r, x, y, z));
  return ans;
}

int pre[N], pos[N], f[N];
void solve() {
  int n, m;
  std::cin >> n >> m;
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    auto &j = pos[x];
    pre[i] = j;
    int k = pre[j];
    if (j) update(1, 1, n, k + 1, j, -1);
    update(1, 1, n, j + 1, i, 1);
    update(1, 1, n, i, f[i - 1]);
    f[i] = ask(1, 1, n, 1, i, m);
    // std::cerr << f[i] << " \n"[i == n];
    j = i;
  }
  std::cout << f[n] << "\n";
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