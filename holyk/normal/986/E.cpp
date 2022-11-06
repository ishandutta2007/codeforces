// Author:  HolyK
// Created: Wed Aug 24 21:07:16 2022
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

int np[10000005];
void sieve(const int n) {
  for (int i = 2; i <= n; i++) {
    if (np[i]) continue;
    np[i] = i;
    if (1LL * i * i > n) continue;
    for (int j = i * i; j <= n; j += i) {
      np[j] = i;
    }
  }
}

constexpr int N(1e5 + 5);
std::vector<int> g[N];
int st[17][N], lg[N], in[N], out[N], dfn, fa[N];
int get(int x, int y) {
  return in[x] < in[y] ? x : y;
}
int lca(int x, int y) {
  if (x == y) return x;
  x = in[x], y = in[y];
  if (x > y) std::swap(x, y);
  int k = lg[y - x];
  return get(st[k][x], st[k][y - (1 << k)]);
}
void dfs(int x, int p) {
  st[0][dfn] = fa[x] = p;
  in[x] = ++dfn;
  for (int y : g[x]) {
    if (y != p) {
      dfs(y, x);
    }
  }
  out[x] = dfn;
}

void init() {
  dfs(1, 0);
  for (int i = 2; i <= dfn; i++) {
    lg[i] = lg[i >> 1] + 1;
  }
  for (int i = 1; i < 17; i++) {
    for (int j = 1; j + (1 << i) <= dfn; j++) {
      st[i][j] = get(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
    }
  }
}

std::vector<PII> decom(int x) {
  std::vector<PII> res;
  while (x > 1) {
    int p = np[x], c = 0;
    while (x % p == 0) x /= p, c++;
    res.push_back({p, c});
  }
  return res;
}

template <class T>
struct Fenwick {
  std::vector<T> c;
  Fenwick(int n) : c(n) {}
  void clear() { std::fill(c.begin(), c.end(), 0); }
  void add(int p, T x) {
    for (; p < c.size(); p |= p + 1) c[p] += x;
  }
  T ask(int p) {
    T r = 0;
    for (; p; p &= p - 1) r += c[p - 1];
    return r;
  }
  T ask(int l, int r) { return ask(r) - ask(l); }
};

void solve() {
  int n;
  std::cin >> n;
  for (int i = 1, x, y; i < n; i++) {
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  init();

  std::vector<std::array<int, 3>> a; 
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    for (auto [p, c] : decom(x)) {
      a.push_back({p, c, -i});
    }
  }

  int m;
  std::cin >> m;
  std::vector<Z> ans(m, 1);
  std::vector<std::array<int, 3>> q(m);
  for (int i = 0; i < m; i++) {
    int x, y, z;
    std::cin >> x >> y >> z;
    for (auto [p, c] : decom(z)) {
      a.push_back({p, c, i});
    }
    q[i] = {x, y, lca(x, y)};
  }

  std::sort(a.begin(), a.end());

  Fenwick<int> t1(n), t2(n);
  for (int i = 0, j; i < a.size(); i = j) {
    for (j = i + 1; j < a.size() && a[i][0] == a[j][0]; j++) ;

    for (int k = i; k < j; k++) {
      if (a[k][2] < 0) {
        int x = -a[k][2];
        t2.add(in[x] - 1, 1), t2.add(out[x], -1);
      }
    }
    for (int k = i; k < j; k++) {
      if (a[k][2] < 0) {
        int x = -a[k][2];
        t1.add(in[x] - 1, a[k][1]), t1.add(out[x], -a[k][1]);
        t2.add(in[x] - 1, -1), t2.add(out[x], 1);
      } else {
        int id = a[k][2];
        auto [x, y, z] = q[id];
        int v1 = t1.ask(in[x]) + t1.ask(in[y]) - t1.ask(in[z]) - t1.ask(in[fa[z]]);
        int v2 = t2.ask(in[x]) + t2.ask(in[y]) - t2.ask(in[z]) - t2.ask(in[fa[z]]);
        ans[id] *= fpow(a[k][0], v1 + a[k][1] * v2);
      }
    }

    for (int k = i; k < j; k++) {
      if (a[k][2] < 0) {
        int x = -a[k][2];
        t1.add(in[x] - 1, -a[k][1]), t1.add(out[x], a[k][1]);
      }
    }
  }

  for (auto &&x : ans) std::cout << x << "\n";
}

int main() {
  sieve(1e7);
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