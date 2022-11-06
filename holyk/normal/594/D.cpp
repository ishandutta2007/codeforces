// Author:  HolyK
// Created: Fri May 20 16:53:37 2022
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

constexpr int N(2e5 + 5);
std::vector<int> primes;
int id[N * 5], val[N], ival[N], pos[N];
void sieve(int n) {
  memset(id, -1, sizeof id);
  for (int i = 2; i <= n; i++) {
    if (~id[i]) continue;
    int o = id[i] = primes.size();
    val[o] = mod((i - 1LL) * fpow(i));
    ival[o] = fpow(val[o]);
    primes.push_back(i);
    if (1LL * i * i > n) continue;
    for (int j = i * i; j <= n; j += i) {
      id[j] = 0;
    }
  }
}

int n, m, a[N], c[N];
void add(int p, int x) {
  for (; p <= n; p += p & -p) c[p] = 1LL * c[p] * x % P;
}
int ask(int p) {
  int r = 1;
  for (; p; p -= p & -p) r = 1LL * r * c[p] % P;
  return r;
}

std::vector<PII> q[N];

void solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  
  std::cin >> m;

  std::vector<int> ans(m);
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    q[y].push_back({x, i});
  }

  int now = 1;
  for (int i = 1; i <= n; i++) c[i] = 1;
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    now = 1LL * x * now % P;
    add(i + 1, fpow(x));
    for (int j = 0; j < primes.size(); j++) {
      int y = primes[j];
      if (1LL * y * y > x) break;
      if (x % y == 0) {
        add(pos[j] + 1, val[j]);
        add(i + 1, ival[j]);
        do x /= y;
        while (x % y == 0);
        pos[j] = i;
      }
    }

    if (x > 1) {
      x = id[x];
      add(pos[x] + 1, val[x]);
      add(i + 1, ival[x]);
      pos[x] = i;
    }
    
    for (auto [l, id] : q[i]) {
      ans[id] = 1LL * now * ask(l) % P;
    }
  }

  for (int x : ans) std::cout << x << "\n";
}

int main() {
  sieve(1e6);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;
  // std::cin >> t;
  while (t--) solve();
  return 0;
}