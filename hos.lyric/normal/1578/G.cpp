#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using Int = long long;

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> bool chmin(T &t, const T &f) { if (t > f) { t = f; return true; } return false; }
template <class T> bool chmax(T &t, const T &f) { if (t < f) { t = f; return true; } return false; }

////////////////////////////////////////////////////////////////////////////////
template <unsigned M_> struct ModInt {
  static constexpr unsigned M = M_;
  unsigned x;
  constexpr ModInt() : x(0U) {}
  constexpr ModInt(unsigned x_) : x(x_ % M) {}
  constexpr ModInt(unsigned long long x_) : x(x_ % M) {}
  constexpr ModInt(int x_) : x(((x_ %= static_cast<int>(M)) < 0) ? (x_ + static_cast<int>(M)) : x_) {}
  constexpr ModInt(long long x_) : x(((x_ %= static_cast<long long>(M)) < 0) ? (x_ + static_cast<long long>(M)) : x_) {}
  ModInt &operator+=(const ModInt &a) { x = ((x += a.x) >= M) ? (x - M) : x; return *this; }
  ModInt &operator-=(const ModInt &a) { x = ((x -= a.x) >= M) ? (x + M) : x; return *this; }
  ModInt &operator*=(const ModInt &a) { x = (static_cast<unsigned long long>(x) * a.x) % M; return *this; }
  ModInt &operator/=(const ModInt &a) { return (*this *= a.inv()); }
  ModInt pow(long long e) const {
    if (e < 0) return inv().pow(-e);
    ModInt a = *this, b = 1U; for (; e; e >>= 1) { if (e & 1) b *= a; a *= a; } return b;
  }
  ModInt inv() const {
    unsigned a = M, b = x; int y = 0, z = 1;
    for (; b; ) { const unsigned q = a / b; const unsigned c = a - q * b; a = b; b = c; const int w = y - static_cast<int>(q) * z; y = z; z = w; }
    assert(a == 1U); return ModInt(y);
  }
  ModInt operator+() const { return *this; }
  ModInt operator-() const { ModInt a; a.x = x ? (M - x) : 0U; return a; }
  ModInt operator+(const ModInt &a) const { return (ModInt(*this) += a); }
  ModInt operator-(const ModInt &a) const { return (ModInt(*this) -= a); }
  ModInt operator*(const ModInt &a) const { return (ModInt(*this) *= a); }
  ModInt operator/(const ModInt &a) const { return (ModInt(*this) /= a); }
  template <class T> friend ModInt operator+(T a, const ModInt &b) { return (ModInt(a) += b); }
  template <class T> friend ModInt operator-(T a, const ModInt &b) { return (ModInt(a) -= b); }
  template <class T> friend ModInt operator*(T a, const ModInt &b) { return (ModInt(a) *= b); }
  template <class T> friend ModInt operator/(T a, const ModInt &b) { return (ModInt(a) /= b); }
  explicit operator bool() const { return x; }
  bool operator==(const ModInt &a) const { return (x == a.x); }
  bool operator!=(const ModInt &a) const { return (x != a.x); }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &a) { return os << a.x; }
};
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// M: prime, G: primitive root, 2^K | M - 1
template <unsigned M_, unsigned G_, int K_> struct Fft {
  static_assert(2U <= M_, "Fft: 2 <= M must hold.");
  static_assert(M_ < 1U << 30, "Fft: M < 2^30 must hold.");
  static_assert(1 <= K_, "Fft: 1 <= K must hold.");
  static_assert(K_ < 30, "Fft: K < 30 must hold.");
  static_assert(!((M_ - 1U) & ((1U << K_) - 1U)), "Fft: 2^K | M - 1 must hold.");
  static constexpr unsigned M = M_;
  static constexpr unsigned M2 = 2U * M_;
  static constexpr unsigned G = G_;
  static constexpr int K = K_;
  ModInt<M> FFT_ROOTS[K + 1], INV_FFT_ROOTS[K + 1];
  ModInt<M> FFT_RATIOS[K], INV_FFT_RATIOS[K];
  Fft() {
    const ModInt<M> g(G);
    for (int k = 0; k <= K; ++k) {
      FFT_ROOTS[k] = g.pow((M - 1U) >> k);
      INV_FFT_ROOTS[k] = FFT_ROOTS[k].inv();
    }
    for (int k = 0; k <= K - 2; ++k) {
      FFT_RATIOS[k] = -g.pow(3U * ((M - 1U) >> (k + 2)));
      INV_FFT_RATIOS[k] = FFT_RATIOS[k].inv();
    }
    assert(FFT_ROOTS[1] == M - 1U);
  }
  // as[rev(i)] <- \sum_j \zeta^(ij) as[j]
  void fft(ModInt<M> *as, int n) const {
    assert(!(n & (n - 1))); assert(1 <= n); assert(n <= 1 << K);
    int m = n;
    if (m >>= 1) {
      for (int i = 0; i < m; ++i) {
        const unsigned x = as[i + m].x;  // < M
        as[i + m].x = as[i].x + M - x;  // < 2 M
        as[i].x += x;  // < 2 M
      }
    }
    if (m >>= 1) {
      ModInt<M> prod = 1U;
      for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)) {
        for (int i = i0; i < i0 + m; ++i) {
          const unsigned x = (prod * as[i + m]).x;  // < M
          as[i + m].x = as[i].x + M - x;  // < 3 M
          as[i].x += x;  // < 3 M
        }
        prod *= FFT_RATIOS[__builtin_ctz(++h)];
      }
    }
    for (; m; ) {
      if (m >>= 1) {
        ModInt<M> prod = 1U;
        for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)) {
          for (int i = i0; i < i0 + m; ++i) {
            const unsigned x = (prod * as[i + m]).x;  // < M
            as[i + m].x = as[i].x + M - x;  // < 4 M
            as[i].x += x;  // < 4 M
          }
          prod *= FFT_RATIOS[__builtin_ctz(++h)];
        }
      }
      if (m >>= 1) {
        ModInt<M> prod = 1U;
        for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)) {
          for (int i = i0; i < i0 + m; ++i) {
            const unsigned x = (prod * as[i + m]).x;  // < M
            as[i].x = (as[i].x >= M2) ? (as[i].x - M2) : as[i].x;  // < 2 M
            as[i + m].x = as[i].x + M - x;  // < 3 M
            as[i].x += x;  // < 3 M
          }
          prod *= FFT_RATIOS[__builtin_ctz(++h)];
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      as[i].x = (as[i].x >= M2) ? (as[i].x - M2) : as[i].x;  // < 2 M
      as[i].x = (as[i].x >= M) ? (as[i].x - M) : as[i].x;  // < M
    }
  }
  // as[i] <- (1/n) \sum_j \zeta^(-ij) as[rev(j)]
  void invFft(ModInt<M> *as, int n) const {
    assert(!(n & (n - 1))); assert(1 <= n); assert(n <= 1 << K);
    int m = 1;
    if (m < n >> 1) {
      ModInt<M> prod = 1U;
      for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)) {
        for (int i = i0; i < i0 + m; ++i) {
          const unsigned long long y = as[i].x + M - as[i + m].x;  // < 2 M
          as[i].x += as[i + m].x;  // < 2 M
          as[i + m].x = (prod.x * y) % M;  // < M
        }
        prod *= INV_FFT_RATIOS[__builtin_ctz(++h)];
      }
      m <<= 1;
    }
    for (; m < n >> 1; m <<= 1) {
      ModInt<M> prod = 1U;
      for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)) {
        for (int i = i0; i < i0 + (m >> 1); ++i) {
          const unsigned long long y = as[i].x + M2 - as[i + m].x;  // < 4 M
          as[i].x += as[i + m].x;  // < 4 M
          as[i].x = (as[i].x >= M2) ? (as[i].x - M2) : as[i].x;  // < 2 M
          as[i + m].x = (prod.x * y) % M;  // < M
        }
        for (int i = i0 + (m >> 1); i < i0 + m; ++i) {
          const unsigned long long y = as[i].x + M - as[i + m].x;  // < 2 M
          as[i].x += as[i + m].x;  // < 2 M
          as[i + m].x = (prod.x * y) % M;  // < M
        }
        prod *= INV_FFT_RATIOS[__builtin_ctz(++h)];
      }
    }
    if (m < n) {
      for (int i = 0; i < m; ++i) {
        const unsigned y = as[i].x + M2 - as[i + m].x;  // < 4 M
        as[i].x += as[i + m].x;  // < 4 M
        as[i + m].x = y;  // < 4 M
      }
    }
    const ModInt<M> invN = ModInt<M>(n).inv();
    for (int i = 0; i < n; ++i) {
      as[i] *= invN;
    }
  }
  void fft(vector<ModInt<M>> &as) const {
    fft(as.data(), as.size());
  }
  void invFft(vector<ModInt<M>> &as) const {
    invFft(as.data(), as.size());
  }
  vector<ModInt<M>> convolve(vector<ModInt<M>> as, vector<ModInt<M>> bs) const {
    if (as.empty() || bs.empty()) return {};
    const int len = as.size() + bs.size() - 1;
    int n = 1;
    for (; n < len; n <<= 1) {}
    as.resize(n); fft(as);
    bs.resize(n); fft(bs);
    for (int i = 0; i < n; ++i) as[i] *= bs[i];
    invFft(as);
    as.resize(len);
    return as;
  }
  vector<ModInt<M>> square(vector<ModInt<M>> as) const {
    if (as.empty()) return {};
    const int len = as.size() + as.size() - 1;
    int n = 1;
    for (; n < len; n <<= 1) {}
    as.resize(n); fft(as);
    for (int i = 0; i < n; ++i) as[i] *= as[i];
    invFft(as);
    as.resize(len);
    return as;
  }
};

// M0 M1 M2 = 789204840662082423367925761 (> 7.892 * 10^26, > 2^89)
// M0 M3 M4 M5 M6 = 797766583174034668024539679147517452591562753 (> 7.977 * 10^44, > 2^149)
const Fft<998244353U, 3U, 23> FFT0;
const Fft<897581057U, 3U, 23> FFT1;
const Fft<880803841U, 26U, 23> FFT2;
const Fft<985661441U, 3U, 22> FFT3;
const Fft<943718401U, 7U, 22> FFT4;
const Fft<935329793U, 3U, 22> FFT5;
const Fft<918552577U, 5U, 22> FFT6;

// T = unsigned, unsigned long long, ModInt<M>
template <class T, unsigned M0, unsigned M1, unsigned M2>
T garner(ModInt<M0> a0, ModInt<M1> a1, ModInt<M2> a2) {
  static const ModInt<M1> INV_M0_M1 = ModInt<M1>(M0).inv();
  static const ModInt<M2> INV_M0M1_M2 = (ModInt<M2>(M0) * M1).inv();
  const ModInt<M1> b1 = INV_M0_M1 * (a1 - a0.x);
  const ModInt<M2> b2 = INV_M0M1_M2 * (a2 - (ModInt<M2>(b1.x) * M0 + a0.x));
  return (T(b2.x) * M1 + b1.x) * M0 + a0.x;
}
template <class T, unsigned M0, unsigned M1, unsigned M2, unsigned M3, unsigned M4>
T garner(ModInt<M0> a0, ModInt<M1> a1, ModInt<M2> a2, ModInt<M3> a3, ModInt<M4> a4) {
  static const ModInt<M1> INV_M0_M1 = ModInt<M1>(M0).inv();
  static const ModInt<M2> INV_M0M1_M2 = (ModInt<M2>(M0) * M1).inv();
  static const ModInt<M3> INV_M0M1M2_M3 = (ModInt<M3>(M0) * M1 * M2).inv();
  static const ModInt<M4> INV_M0M1M2M3_M4 = (ModInt<M4>(M0) * M1 * M2 * M3).inv();
  const ModInt<M1> b1 = INV_M0_M1 * (a1 - a0.x);
  const ModInt<M2> b2 = INV_M0M1_M2 * (a2 - (ModInt<M2>(b1.x) * M0 + a0.x));
  const ModInt<M3> b3 = INV_M0M1M2_M3 * (a3 - ((ModInt<M3>(b2.x) * M1 + b1.x) * M0 + a0.x));
  const ModInt<M4> b4 = INV_M0M1M2M3_M4 * (a4 - (((ModInt<M4>(b3.x) * M2 + b2.x) * M1 + b1.x) * M0 + a0.x));
  return (((T(b4.x) * M3 + b3.x) * M2 + b2.x) * M1 + b1.x) * M0 + a0.x;
}

template <unsigned M> vector<ModInt<M>> convolve(const vector<ModInt<M>> &as, const vector<ModInt<M>> &bs) {
  static constexpr unsigned M0 = decltype(FFT0)::M;
  static constexpr unsigned M1 = decltype(FFT1)::M;
  static constexpr unsigned M2 = decltype(FFT2)::M;
  if (as.empty() || bs.empty()) return {};
  const int asLen = as.size(), bsLen = bs.size();
  vector<ModInt<M0>> as0(asLen), bs0(bsLen);
  for (int i = 0; i < asLen; ++i) as0[i] = as[i].x;
  for (int i = 0; i < bsLen; ++i) bs0[i] = bs[i].x;
  const vector<ModInt<M0>> cs0 = FFT0.convolve(as0, bs0);
  vector<ModInt<M1>> as1(asLen), bs1(bsLen);
  for (int i = 0; i < asLen; ++i) as1[i] = as[i].x;
  for (int i = 0; i < bsLen; ++i) bs1[i] = bs[i].x;
  const vector<ModInt<M1>> cs1 = FFT1.convolve(as1, bs1);
  vector<ModInt<M2>> as2(asLen), bs2(bsLen);
  for (int i = 0; i < asLen; ++i) as2[i] = as[i].x;
  for (int i = 0; i < bsLen; ++i) bs2[i] = bs[i].x;
  const vector<ModInt<M2>> cs2 = FFT2.convolve(as2, bs2);
  vector<ModInt<M>> cs(asLen + bsLen - 1);
  for (int i = 0; i < asLen + bsLen - 1; ++i) {
    cs[i] = garner<ModInt<M>>(cs0[i], cs1[i], cs2[i]);
  }
  return cs;
}
template <unsigned M> vector<ModInt<M>> square(const vector<ModInt<M>> &as) {
  static constexpr unsigned M0 = decltype(FFT0)::M;
  static constexpr unsigned M1 = decltype(FFT1)::M;
  static constexpr unsigned M2 = decltype(FFT2)::M;
  if (as.empty()) return {};
  const int asLen = as.size();
  vector<ModInt<M0>> as0(asLen);
  for (int i = 0; i < asLen; ++i) as0[i] = as[i].x;
  const vector<ModInt<M0>> cs0 = FFT0.square(as0);
  vector<ModInt<M1>> as1(asLen);
  for (int i = 0; i < asLen; ++i) as1[i] = as[i].x;
  const vector<ModInt<M1>> cs1 = FFT1.square(as1);
  vector<ModInt<M2>> as2(asLen);
  for (int i = 0; i < asLen; ++i) as2[i] = as[i].x;
  const vector<ModInt<M2>> cs2 = FFT2.square(as2);
  vector<ModInt<M>> cs(asLen + asLen - 1);
  for (int i = 0; i < asLen + asLen - 1; ++i) {
    cs[i] = garner<ModInt<M>>(cs0[i], cs1[i], cs2[i]);
  }
  return cs;
}


constexpr unsigned MO = 1'000'000'007;
using Mint = ModInt<MO>;

constexpr int LIM = 200'010;
Mint inv[LIM], fac[LIM], invFac[LIM];

void prepare() {
  inv[1] = 1;
  for (int i = 2; i < LIM; ++i) {
    inv[i] = -((Mint::M / i) * inv[Mint::M % i]);
  }
  fac[0] = invFac[0] = 1;
  for (int i = 1; i < LIM; ++i) {
    fac[i] = fac[i - 1] * i;
    invFac[i] = invFac[i - 1] * inv[i];
  }
}
Mint binom(Int n, Int k) {
  if (n < 0) {
    if (k >= 0) {
      return ((k & 1) ? -1 : +1) * binom(-n + k - 1, k);
    } else if (n - k >= 0) {
      return (((n - k) & 1) ? -1 : +1) * binom(-k - 1, n - k);
    } else {
      return 0;
    }
  } else {
    if (0 <= k && k <= n) {
      assert(n < LIM);
      return fac[n] * invFac[k] * invFac[n - k];
    } else {
      return 0;
    }
  }
}


int N;
Int K;
vector<Int> A;

int main() {
  prepare();
  
  for (; ~scanf("%d%lld", &N, &K); ) {
    A.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%lld", &A[i]);
    }
    sort(A.begin(), A.end());
    
    const Mint invN = Mint(N).inv();
    const Mint invK = Mint(K).inv();
    
    vector<Mint> gs(N + 1, 0);
    for (int b = 0; b < N; ++b) {
      // 1/K = (b/N) (1-1/K) (g[b-1] - g[b]) + (1-b/N) (1/K) (g[b+1] - g[b])
      Mint tmp = (b == 0) ? 0 : (gs[b - 1] - gs[b]);
      tmp *= (Mint(b) * invN) * (1 - invK);
      tmp = invK - tmp;
      tmp *= (inv[N - b] * Mint(N)) * Mint(K);
      gs[b + 1] = gs[b] + tmp;
    }
    
    const int m = count(A.begin(), A.end(), -1);
    vector<Mint> emps(m + 1, 0);
    {
      Mint pw = 1;
      for (int b = m; b >= 0; --b) {
        emps[b] = binom(m, b) * pw;
        pw *= Mint(K - 1);
      }
    }
    vector<Mint> freq(N - m + 1, 0);
    freq[0] = K;
    for (int i = m, j; i < N; i = j) {
      for (j = i + 1; j < N && A[i] == A[j]; ++j) {}
      freq[0] -= 1;
      freq[j - i] += 1;
    }
    const auto prod = convolve(emps, freq);
    assert((int)prod.size() == N + 1);
    
    Mint ans = 0;
    for (int b = 0; b <= N; ++b) {
      ans += prod[b] * gs[b];
    }
    ans /= Mint(K).pow(m);
    ans = gs[N] - ans;
    printf("%u\n", ans.x);
  }
  return 0;
}