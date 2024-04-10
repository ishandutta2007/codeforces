// Author:  HolyK
// Created: Thu Feb 24 16:30:28 2022
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

constexpr int P(998244353), G(3), L(1 << 20);
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
int w[L], fac[L], ifac[L], inv[L], _ = [] {
  w[L / 2] = 1;
  for (int i = L / 2 + 1, x = fpow(G, (P - 1) / L); i < L; i++) w[i] = 1LL * w[i - 1] * x % P;
  for (int i = L / 2 - 1; i >= 0; i--) w[i] = w[i << 1];
  
  fac[0] = 1;
  for (int i = 1; i < L; i++) fac[i] = 1LL * fac[i - 1] * i % P;
  ifac[L - 1] = fpow(fac[L - 1]);
  for (int i = L - 1; i; i--) {
    ifac[i - 1] = 1LL * ifac[i] * i % P;
    inv[i] = 1LL * ifac[i] * fac[i - 1] % P;
  }
  return 0;
}();
void dft(int *a, int n) {
  assert((n & n - 1) == 0);
  for (int k = n >> 1; k; k >>= 1) {
    for (int i = 0; i < n; i += k << 1) {
      for (int j = 0; j < k; j++) {
        int &x = a[i + j], y = a[i + j + k];
        a[i + j + k] = 1LL * (x - y + P) * w[k + j] % P;
        inc(x, y);
      }
    }
  }
}
void idft(int *a, int n) {
  assert((n & n - 1) == 0);
  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < n; i += k << 1) {
      for (int j = 0; j < k; j++) {
        int x = a[i + j], y = 1LL * a[i + j + k] * w[k + j] % P;
        a[i + j + k] = x - y < 0 ? x - y + P : x - y;
        inc(a[i + j], y);
      }
    }
  }
  for (int i = 0, inv = P - (P - 1) / n; i < n; i++)
    a[i] = 1LL * a[i] * inv % P;
  std::reverse(a + 1, a + n);
}
inline int norm(int n) { return 1 << std::__lg(n * 2 - 1); }
struct Poly : public std::vector<int> {
#define T (*this)  
  using std::vector<int>::vector;
  void append(const Poly &r) {
    insert(end(), r.begin(), r.end());
  }
  int len() const { return size(); }
  Poly operator-() const {
    Poly r(T);
    for (auto &x : r) x = x ? P - x : 0;
    return r;
  }
  Poly &operator+=(const Poly &r) {
    if (r.len() > len()) resize(r.len());
    for (int i = 0; i < r.len(); i++) inc(T[i], r[i]);
    return T;
  }
  Poly &operator-=(const Poly &r) {
    if (r.len() > len()) resize(r.len());
    for (int i = 0; i < r.len(); i++) dec(T[i], r[i]);
    return T;
  }
  Poly &operator^=(const Poly &r) {
    if (r.len() < len()) resize(r.len());
    for (int i = 0; i < len(); i++) T[i] = 1LL * T[i] * r[i] % P;
    return T;
  }
  Poly &operator*=(int r) {
    for (int &x : T) x = 1LL * x * r % P;
    return T;
  }

  Poly operator+(const Poly &r) const { return Poly(T) += r; }
  Poly operator-(const Poly &r) const { return Poly(T) -= r; }
  Poly operator^(const Poly &r) const { return Poly(T) ^= r; }
  Poly operator*(int r) const { return Poly(T) *= r; }

  Poly &operator<<=(int k) { return insert(begin(), k, 0), T; }
  Poly operator<<(int r) const { return Poly(T) <<= r; }
  Poly operator>>(int r) const { return r >= len() ? Poly() : Poly(begin() + r, end()); }
  Poly &operator>>=(int r) { return T = T >> r; }

  Poly pre(int k) const { return k < len() ? Poly(begin(), begin() + k) : T; }
  friend void dft(Poly &a) { dft(a.data(), a.len()); }
  friend void idft(Poly &a) { idft(a.data(), a.len()); }
  friend Poly conv(const Poly &a, const Poly &b, int n) {
    Poly p(a), q;
    p.resize(n), dft(p);
    p ^= &a == &b ? p : (q = b, q.resize(n), dft(q), q);
    idft(p);
    return p;
  }
  friend Poly operator*(const Poly &a, const Poly &b) {
    int len = a.len() + b.len() - 1;
    if (a.len() <= 16 || b.len() <= 16) {
      Poly c(len);
      for (int i = 0; i < a.len(); i++)
        for (int j = 0; j < b.len(); j++)
          c[i + j] = (c[i + j] + 1LL * a[i] * b[j]) % P;
      return c;
    }
    return conv(a, b, norm(len)).pre(len);
  }

  Poly deriv() const {
    if (empty()) return Poly();
    Poly r(len() - 1);
    for (int i = 1; i < len(); i++) r[i - 1] = 1LL * i * T[i] % P;
    return r;
  }
  Poly integ() const {
    if (empty()) return Poly();
    Poly r(len() + 1);
    for (int i = 0; i < len(); i++) r[i + 1] = 1LL * fpow(i + 1) * T[i] % P;
    return r;
  }
  Poly inv(int m) const {
    Poly x = {fpow(T[0])};
    for (int k = 1; k < m; k *= 2) {
      x.append(-((conv(pre(k * 2), x, k * 2) >> k) * x).pre(k));
    }
    return x.pre(m);
  }
  Poly log(int m) const { return (deriv() * inv(m)).integ().pre(m); }
  Poly exp(int m) const {
    Poly x = {1};
    for (int k = 1; k < m; k *= 2) {
      x.append((x * (pre(k * 2) - x.log(k * 2) >> k)).pre(k));
    }
    return x.pre(m);
  }
  Poly sqrt(int m) const {
    Poly x = {1}, y = {1};
    for (int k = 1; k < m; k *= 2) {
      x.append(((pre(k * 2) - x * x >> k) * y).pre(k) * (P + 1 >> 1));
      if (k * 2 < m) {
        y.append(-((conv(x.pre(k * 2), y, k * 2) >> k) * y).pre(k));
      }
    }
    return x.pre(m);
  }

  Poly rev() const { return Poly(rbegin(), rend()); }
  Poly mulT(Poly b) { return T * b.rev() >> b.len() - 1; }

#undef T
};

Poly operator/(Poly a, Poly b) {
  int n = a.len(), m = b.len();
  if (n < m) return {0};
  int k = norm(n - m + 1);
  a = a.rev();
  a.resize(k);
  return (a * b.rev().inv(k)).pre(n - m + 1).rev();
}
std::pair<Poly, Poly> div(Poly a, Poly b) {
  int m = b.len();
  Poly c = a / b;
  return {c, a.pre(m - 1) - (b * c).pre(m - 1)};
}
Poly operator%(Poly a, Poly b) {
  return div(a, b).second;
}

struct SegTree {
  std::vector<Poly> p;
  int n, raw_n;
  SegTree(Poly a) {
    n = norm(raw_n = a.size());
    p.resize(n * 2);
    for (int i = 0; i < n; i++) {
      p[i + n] = Poly({1, i < raw_n ? P - a[i] : 0});
    }
    for (int i = n - 1; i; i--) {
      int l = i * 2, r = l | 1, k = p[l].size() - 1 << 1;
      p[l].resize(k), dft(p[l]);
      p[r].resize(k), dft(p[r]);
      idft(p[i] = p[l] ^ p[r]);
      p[i].push_back((p[i][0] - 1 + P) % P);
      p[i][0] = 1;
    }
  }
  Poly eval(Poly f) {
    int m = f.size();
    if (m == 1) return Poly(raw_n, f[0]);
    Poly q = f.rev() * p[1].inv(m);
    q.resize(m);
    if (m > n) {
      q >>= m - n;
    } else {
      q <<= n - m;
    }
    for (int k = n, o = 1; k > 1; k >>= 1) {
      for (int i = 0; i < n; i += k, o++) {
        if (i >= raw_n) continue;
        int *a = &q[i], *l = p[o * 2].data(), *r = p[o * 2 + 1].data();
        dft(a, k);
        Poly x(k), y(k);
        for (int j = 0; j < k; j++) x[j] = 1LL * a[j] * r[j] % P;
        for (int j = 0; j < k; j++) y[j] = 1LL * a[j] * l[j] % P;
        idft(x), idft(y);
        for (int j = k / 2; j < k; j++) *a++ = x[j];
        for (int j = k / 2; j < k; j++) *a++ = y[j];
      }
    }
    return q.pre(raw_n);
  }
  Poly interpolate(Poly b) {
    assert(b.len() == raw_n);
    Poly q = eval(p[1].pre(raw_n + 1).rev().deriv());
    for (int i = 0; i < raw_n; i++) q[i] = 1LL * fpow(q[i]) * b[i] % P;
    q.resize(n);
    for (int k = 1, h = n >> 1; k < n; k <<= 1, h >>= 1)
      for (int i = 0, o = h; i < n; i += k << 1, o++) {
        if (i >= raw_n) continue;
        int *a = &q[i], *b = &q[i + k], *l = p[o * 2].data(), *r = p[o * 2 + 1].data();
        Poly x(k * 2), y(k * 2);
        for (int j = 0; j < k; j++) x[j] = a[j];
        for (int j = 0; j < k; j++) y[j] = b[j];
        dft(x), dft(y);
        for (int j = 0; j < k * 2; j++) x[j] = (1LL * x[j] * r[j] + 1LL * y[j] * l[j]) % P;
        idft(x);
        for (int j = 0; j < k * 2; j++) a[j] = x[j];
      }
    q.resize(raw_n);
    return q.rev();
  }
};

int divAt(Poly f, Poly g, int64_t n) {
  int len = std::max(f.size(), g.size()), m = 1 << std::__lg(len * 2 - 1);
  for (; n; n >>= 1) {
    f.resize(m * 2), g.resize(m * 2);
    dft(f), dft(g);
    for (int i = 0; i < m * 2; i++) f[i] = 1LL * f[i] * g[i ^ 1] % P;
    for (int i = 0; i < m; i++) g[i] = 1LL * g[i * 2] * g[i * 2 + 1] % P;
    g.resize(m);
    idft(f), idft(g);
    for (int i = 0, j = n & 1; i < len; i++, j += 2) f[i] = f[j];
    f.resize(len), g.resize(len);
  }
  return 1LL * f[0] * fpow(g[0]) % P;
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) std::cin >> a[i];
  for (int i = 0; i < m; i++) {
    int x;
    std::cin >> x;
    b[x - 1] = 1;
  }

  std::vector<int> pw(n + 1), pre(n), suf(n);
  pw[0] = 1;
  for (int i = 1; i <= n; i++) {
    pw[i] = 2LL * pw[i - 1] % P;
  }

  for (int i = 1; i < n; i++) {
    pre[i] = b[i - 1] + pre[i - 1];
  }

  for (int &i : pre) i = pw[i];
  suf[n - 1] = b[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suf[i] = suf[i + 1] + b[i];
  }

  std::vector<int> ans(n);

  std::function<void(int, int)> solve = [&](int l, int r) {
    if (r - l == 1) return;
    
    int m = l + r >> 1;
    solve(l, m), solve(m, r);
    Poly p(m - l), q, s;
    int delta = l + m;
    for (int i = l; i < m; i++) {
      p[i - l] = b[i] * pre[i];
    }
    for (int i = m; i <= 2 * (r - 1) - l; i++) {
      q.push_back(i < n ? pw[suf[i]] : 1);
    }
    s = p * q;
    for (int i = m; i < r; i++) {
      ans[i] = (ans[i] + 1LL * i * s[i * 2 - delta]) % P;
    }
    for (int i = l; i < m; i++) {
      p[i - l] = 1LL * p[i - l] * (P - i) % P;
    }
    s = p * q;
    for (int i = m; i < r; i++) {
      inc(ans[i], s[i * 2 - delta]);
    }

    delta = m + 2 * l - (r - 1);
    p.assign(r - m, 0);
    for (int i = m; i < r; i++) {
      p[i - m] = b[i] * (P - pw[suf[i] - 1]);
    }
    q.clear();
    for (int i = 2 * l - (r - 1); i <= 2 * (m - 1) - m; i++) {
      q.push_back(i < 0 ? 1 : pre[i]);
    }
    
    s = p * q;
    for (int i = l; i < m; i++) {
      ans[i] = (ans[i] + 1LL * i * s[i * 2 - delta]) % P;
    }
    for (int i = m; i < r; i++) {
      p[i - m] = 1LL * p[i - m] * (P - i) % P;
    }
    s = p * q;
    for (int i = l; i < m; i++) {
      inc(ans[i], s[i * 2 - delta]);
    }
  };

  solve(0, n);
  
  int s = 0;
  for (int i = 0; i < n; i++) {
    // std::cerr << ans[i] << " \n"[i + 1 == n];
    s = (s + 1LL * ans[i] * a[i]) % P;
  }
  s = 1LL * s * fpow(pw[m] - 1) % P;
  std::cout << s << "\n";
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