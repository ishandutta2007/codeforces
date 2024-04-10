//  Copyright 2022 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":\t" << (x) << endl
#else
    #define debug(x) 238;
#endif

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

//  by https://codeforces.com/profile/Nyaan
//  example submission:
//  https://codeforces.com/contest/1603/submission/133688639
template <uint32_t mod>
struct LazyMontgomeryModInt {
  using mint = LazyMontgomeryModInt;
  using i32 = int32_t;
  using u32 = uint32_t;
  using u64 = uint64_t;
 
  static constexpr u32 get_r() {
    u32 ret = mod;
    for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;
    return ret;
  }
 
  static constexpr u32 r = get_r();
  static constexpr u32 n2 = -u64(mod) % mod;
  static_assert(r * mod == 1, "invalid, r * mod != 1");
  static_assert(mod < (1 << 30), "invalid, mod >= 2 ^ 30");
  static_assert((mod & 1) == 1, "invalid, mod % 2 == 0");
 
  u32 a;
 
  constexpr LazyMontgomeryModInt() : a(0) {}
  constexpr LazyMontgomeryModInt(const int64_t &b)
      : a(reduce(u64(b % mod + mod) * n2)){};
 
  static constexpr u32 reduce(const u64 &b) {
    return (b + u64(u32(b) * u32(-r)) * mod) >> 32;
  }
 
  constexpr mint &operator+=(const mint &b) {
    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;
    return *this;
  }

  constexpr mint &operator++() {
    return *this += 1;
  }

  constexpr mint operator++(int) {
    auto ret = *this;
    *this += 1;
    return ret;
  }

  constexpr mint &operator-=(const mint &b) {
    if (i32(a -= b.a) < 0) a += 2 * mod;
    return *this;
  }

  constexpr mint &operator--() {
    return *this -= 1;
  }

  constexpr mint operator--(int) {
    auto ret = *this;
    *this -= 1;
    return ret;
  }
 
  constexpr mint &operator*=(const mint &b) {
    a = reduce(u64(a) * b.a);
    return *this;
  }
 
  constexpr mint &operator/=(const mint &b) {
    *this *= b.inv();
    return *this;
  }
 
  constexpr friend mint operator+(mint a, const mint &b) { return a += b; }
  constexpr friend mint operator-(mint a, const mint &b) { return a -= b; }
  constexpr friend mint operator*(mint a, const mint &b) { return a *= b; }
  constexpr friend mint operator/(mint a, const mint &b) { return a /= b; }
  constexpr friend bool operator==(mint const& a, const mint &b) {
    return (a.a >= mod ? a.a - mod : a.a) == (b.a >= mod ? b.a - mod : b.a);
  }
  constexpr friend bool operator!=(mint const& a, const mint &b) {
    return (a.a >= mod ? a.a - mod : a.a) != (b.a >= mod ? b.a - mod : b.a);
  }
  constexpr friend bool operator<(mint const& a, const mint &b) {
    return (a.a >= mod ? a.a - mod : a.a) < (b.a >= mod ? b.a - mod : b.a);
  }
  constexpr mint operator-() const { return mint() - mint(*this); }
 
  constexpr mint power(u64 n) const {
    mint ret(1), mul(*this);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  
  constexpr mint inv() const { return power(mod - 2); }
 
  friend ostream &operator<<(ostream &os, const mint &b) {
    return os << b.get();
  }
 
  friend istream &operator>>(istream &is, mint &b) {
    int64_t t;
    is >> t;
    b = LazyMontgomeryModInt<mod>(t);
    return (is);
  }
  
  constexpr u32 get() const {
    u32 ret = reduce(a);
    return ret >= mod ? ret - mod : ret;
  }

  constexpr explicit operator bool() const {
    return bool(get());
  }
 
  static constexpr u32 get_mod() { return mod; }
};
 
template <typename T>
struct Binomial {
  vector<T> f, g, h;
  Binomial(int MAX = 0) : f(1, T(1)), g(1, T(1)), h(1, T(1)) {
    extend(MAX + 1);    
  }

  void extend(int m) {
    int n = f.size();

    if (n >= m) {
      return;
    }

    f.resize(m);
    g.resize(m);
    h.resize(m);
    for (int i = n; i < m; i++) f[i] = f[i - 1] * T(i);
    g[m - 1] = f[m - 1].inv();
    h[m - 1] = g[m - 1] * f[m - 2];
    for (int i = m - 2; i >= n; i--) {
      g[i] = g[i + 1] * T(i + 1);
      h[i] = g[i] * f[i - 1];
    } 
  }

  void extend() {
    extend(2 * f.size());
  }
 
  T fact(int i) {
    if (i < 0) return T(0);
    while (i >= (int)f.size()) extend();
    return f[i];
  }
 
  T ifact(int i) {
    if (i < 0) return T(0);
    while (i >= (int)g.size()) extend();
    return g[i];
  }
 
  T inv(int i) {
    if (i < 0) return -inv(-i);
    while (i >= (int)h.size()) extend();
    return h[i];
  }
 
  T C(int n, int r) {
    if (n < 0 || n < r || r < 0) return T(0);
    return fact(n) * ifact(n - r) * ifact(r);
  }
 
  inline T operator()(int n, int r) { return C(n, r); }
 
  template <typename I>
  T multinomial(const vector<I>& r) {
    static_assert(is_integral<I>::value == true);
    int n = 0;
    for (auto& x : r) {
      if(x < 0) return T(0);
      n += x;
    }
    T res = fact(n);
    for (auto& x : r) res *= ifact(x);
    return res;
  }
 
  template <typename I>
  T operator()(const vector<I>& r) {
    return multinomial(r);
  }
 
  T C_naive(int n, int r) {
    if (n < 0 || n < r || r < 0) return T(0);
    T ret = T(1);
    r = min(r, n - r);
    for (int i = 1; i <= r; ++i) ret *= inv(i) * (n--);
    return ret;
  }
 
  T A(int n, int r) {
    if (n < 0 || n < r || r < 0) return T(0);
    return fact(n) * ifact(n - r);
  }
 
  T CR(int n, int r) {
    if (n < 0 || r < 0) return T(0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};
int const MOD = 998244353;
// int const MOD = int(1e9 + 7);
using mint = LazyMontgomeryModInt<MOD>;
Binomial<mint> C;

vector<mint> mkpow(mint base, int mx) {
  vector<mint> res(mx + 1);
  res[0] = 1;
  for (int i = 1; i <= mx; ++i) {
    res[i] = res[i - 1] * base;
  }
  return res;
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  vector adj(n, vector<mint>(n));
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    ++adj[u][v];
    ++adj[v][u];
  }
  //  [0; n) L-1
  //  [n; 2*n) L-2
  vector trans(2 * n, vector<mint>(2 * n));
  for (int i = 0; i < n; ++i) {
    trans[i + n][i] = 1;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      trans[i][j] = adj[i][j];
      trans[i][i + n] -= adj[i][j];
    }
    trans[i][i + n] += 1;
  }
  auto multiply = [&](auto const& A, auto const& B) {
    vector C(2 * n, vector<mint>(2 * n));
    for (int i = 0; i < 2 * n; ++i) {
      for (int j = 0; j < 2 * n; ++j) {
        for (int t = 0; t < 2 * n; ++t) {
          C[j][t] += A[j][i] * B[i][t];
        }
      }
    }
    return C;
  };
  auto power = [&](auto A, int d) {
    vector cur(2 * n, vector<mint>(2 * n));
    for (int i = 0; i < 2 * n; ++i) {
      cur[i][i] = 1;
    }
    while (d) {
      if (d & 1) {
        cur = multiply(cur, A);
      }
      A = multiply(A, A);
      d /= 2;
    }
    return cur;
  };
  auto padj = trans;
  for (int i = 0; i < n; ++i) {
    padj[i][i + n] -= 1;
  }
  padj = multiply(padj, power(trans, k - 1));

  // for (int i = 0; i < 2 * n; ++i) {
  //   for (int j = 0; j < 2 * n; ++j) {
  //     cout << padj[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  mint ans = 0;
  for (int s = 0; s < n; ++s) {
    ans += padj[s][s];
  }
  cout << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}