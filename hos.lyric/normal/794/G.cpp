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


template<int M_> struct ModInt {
  static constexpr int M = M_;
  int x;
  constexpr ModInt() : x(0) {}
  constexpr ModInt(long long x_) : x(x_ % M) { if (x < 0) x += M; }
  ModInt &operator+=(const ModInt &a) { x += a.x; if (x >= M) x -= M; return *this; }
  ModInt &operator-=(const ModInt &a) { x -= a.x; if (x < 0) x += M; return *this; }
  ModInt &operator*=(const ModInt &a) { x = static_cast<int>((static_cast<long long>(x) * a.x) % M); return *this; }
  ModInt &operator/=(const ModInt &a) { return (*this *= a.inv()); }
  ModInt operator+(const ModInt &a) const { return (ModInt(*this) += a); }
  ModInt operator-(const ModInt &a) const { return (ModInt(*this) -= a); }
  ModInt operator*(const ModInt &a) const { return (ModInt(*this) *= a); }
  ModInt operator/(const ModInt &a) const { return (ModInt(*this) /= a); }
  ModInt operator-() const { return ModInt(-x); }
  ModInt pow(long long e) const {
    if (e < 0) return inv().pow(-e);
    ModInt x2 = x, xe = 1;
    for (; e; e >>= 1) {
      if (e & 1) xe *= x2;
      x2 *= x2;
    }
    return xe;
  }
  ModInt inv() const {
    int a = x, b = M, y = 1, z = 0, t;
    for (; ; ) {
      t = a / b; a -= t * b;
      if (a == 0) {
        assert(b == 1 || b == -1);
        return ModInt(b * z);
      }
      y -= t * z;
      t = b / a; b -= t * a;
      if (b == 0) {
        assert(a == 1 || a == -1);
        return ModInt(a * y);
      }
      z -= t * y;
    }
  }
  friend ModInt operator+(long long a, const ModInt &b) { return (ModInt(a) += b); }
  friend ModInt operator-(long long a, const ModInt &b) { return (ModInt(a) -= b); }
  friend ModInt operator*(long long a, const ModInt &b) { return (ModInt(a) *= b); }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &a) { return os << a.x; }
};

constexpr int MO = 1'000'000'007;
using Mint = ModInt<MO>;


constexpr int LIM = 300'010;
Mint inv[LIM], fac[LIM], invFac[LIM];

void prepare() {
  inv[1] = 1;
  for (int i = 2; i < LIM; ++i) {
    inv[i] = -(Mint::M / i) * inv[Mint::M % i];
  }
  fac[0] = invFac[0] = 1;
  for (int i = 1; i < LIM; ++i) {
    fac[i] = fac[i - 1] * i;
    invFac[i] = invFac[i - 1] * inv[i];
  }
}
Mint binom(Int n, Int k) {
  if (0 <= k && k <= n) {
    assert(n < LIM);
    return fac[n] * invFac[k] * invFac[n - k];
  } else {
    return 0;
  }
}


// a^-1 (mod m)
const Int modInv(Int a, Int m) {
  Int b = m, x = 1, y = 0, t = 0;
  for (; ; ) {
    t = a / b; a -= t * b;
    if (a == 0) {
      assert(b == 1 || b == -1);//, "modInv: gcd(a, m) != 1");
      if (b == -1) y = -y;
      return (y < 0) ? (y + m) : y;
    }
    x -= t * y;
    t = b / a; b -= t * a;
    if (b == 0) {
      assert(a == 1 || a == -1);//, "modInv: gcd(a, m) != 1");
      if (a == -1) x = -x;
      return (x < 0) ? (x + m) : x;
    }
    y -= t * x;
  }
}


// M: prime, G: primitive root
template <int M_, int G, int K> struct Fft {
  static constexpr int M = M_;
  // 1, 1/4, 1/8, 3/8, 1/16, 5/16, 3/16, 7/16, ...
  int gs[1 << (K - 1)];
  constexpr Fft() : gs() {
    static_assert(2 <= K && K <= 30, "Fft: 2 <= K <= 30 must hold");
    static_assert(!((M - 1) & ((1 << K) - 1)), "Fft: 2^K | M - 1 must hold");
    gs[0] = 1;
    long long g2 = G, gg = 1;
    for (int e = (M - 1) >> K; e; e >>= 1) {
      if (e & 1) gg = (gg * g2) % M;
      g2 = (g2 * g2) % M;
    }
    gs[1 << (K - 2)] = gg;
    for (int l = 1 << (K - 2); l >= 2; l >>= 1) {
      gs[l >> 1] = (static_cast<long long>(gs[l]) * gs[l]) % M;
    }
    assert((static_cast<long long>(gs[1]) * gs[1]) % M == M - 1);
    for (int l = 2; l <= 1 << (K - 2); l <<= 1) {
      for (int i = 1; i < l; ++i) {
        gs[l + i] = (static_cast<long long>(gs[l]) * gs[i]) % M;
      }
    }
  }
  void fft(vector<int> &xs) const {
    const int n = xs.size();
    assert(!(n & (n - 1)) && n <= 1 << K);
    for (int l = n; l >>= 1; ) {
      for (int i = 0; i < (n >> 1) / l; ++i) {
        const long long g = gs[i];
        for (int j = (i << 1) * l; j < (i << 1 | 1) * l; ++j) {
          const int t = (g * xs[j + l]) % M;
          if ((xs[j + l] = xs[j] - t) < 0) xs[j + l] += M;
          if ((xs[j] += t) >= M) xs[j] -= M;
        }
      }
    }
  }
  void invFft(vector<int> &xs) const {
    const int n = xs.size();
    assert(!(n & (n - 1)) && n <= 1 << K);
    for (int l = 1; l < n; l <<= 1) {
      std::reverse(xs.begin() + l, xs.begin() + (l << 1));
    }
    for (int l = 1; l < n; l <<= 1) {
      for (int i = 0; i < (n >> 1) / l; ++i) {
        const long long g = gs[i];
        for (int j = (i << 1) * l; j < (i << 1 | 1) * l; ++j) {
          int t = (g * (xs[j] - xs[j + l])) % M;
          if (t < 0) t += M;
          if ((xs[j] += xs[j + l]) >= M) xs[j] -= M;
          xs[j + l] = t;
        }
      }
    }
  }
  template<class T>
  vector<T> convolute(const vector<T> &as, const vector<T> &bs) const {
    const int na = as.size(), nb = bs.size();
    int n, invN = 1;
    for (n = 1; n < na + nb - 1; n <<= 1) {
      invN = ((invN & 1) ? (invN + M) : invN) >> 1;
    }
    vector<int> xs(n, 0), ys(n, 0);
    for (int i = 0; i < na; ++i) if ((xs[i] = as[i] % M) < 0) xs[i] += M;
    for (int i = 0; i < nb; ++i) if ((ys[i] = bs[i] % M) < 0) ys[i] += M;
    fft(xs);
    fft(ys);
    for (int i = 0; i < n; ++i) {
      xs[i] = (((static_cast<long long>(xs[i]) * ys[i]) % M) * invN) % M;
    }
    invFft(xs);
    xs.resize(na + nb - 1);
    return xs;
  }
  template <int M1>
  vector<int> convolute(const vector<ModInt<M1>> &as, const vector<ModInt<M1>> &bs) const {
    const int na = as.size(), nb = bs.size();
    int n, invN = 1;
    for (n = 1; n < na + nb - 1; n <<= 1) {
      invN = ((invN & 1) ? (invN + M) : invN) >> 1;
    }
    vector<int> xs(n, 0), ys(n, 0);
    for (int i = 0; i < na; ++i) xs[i] = as[i].x % M;
    for (int i = 0; i < nb; ++i) ys[i] = bs[i].x % M;
    fft(xs);
    fft(ys);
    for (int i = 0; i < n; ++i) {
      xs[i] = (((static_cast<long long>(xs[i]) * ys[i]) % M) * invN) % M;
    }
    invFft(xs);
    xs.resize(na + nb - 1);
    return xs;
  }
};

constexpr int FFT_K = 20;
using Fft3_0 = Fft<1045430273, 3, FFT_K>;  // 2^20 997 + 1
using Fft3_1 = Fft<1051721729, 6, FFT_K>;  // 2^20 1003 + 1
using Fft3_2 = Fft<1053818881, 7, FFT_K>;  // 2^20 1005 + 1

const Int FFT_INV01 = modInv(Fft3_0::M, Fft3_1::M);
const Int FFT_INV012 = modInv((Int)(Fft3_0::M) * Fft3_1::M, Fft3_2::M);
Fft3_0 FFT3_0;
Fft3_1 FFT3_1;
Fft3_2 FFT3_2;
void initFft3() {
  // FFT3_0 = new Fft3_0;
  // FFT3_1 = new Fft3_1;
  // FFT3_2 = new Fft3_2;
}
// ModInt!M[] convolute(int M)(inout(ModInt!M)[] as, inout(ModInt!M)[] bs) {
template<int M>
vector<ModInt<M>> convolute(const vector<ModInt<M>> &as, const vector<ModInt<M>> &bs) {
  const vector<int> cs0 = FFT3_0.convolute(as, bs);
  const vector<int> cs1 = FFT3_1.convolute(as, bs);
  const vector<int> cs2 = FFT3_2.convolute(as, bs);
  vector<ModInt<M>> cs(cs0.size());
  for (int i = 0; i < (int)cs0.size(); ++i) {
    Int d0 = cs0[i] % Fft3_0::M;
    Int d1 = (FFT_INV01 * (cs1[i] - d0)) % Fft3_1::M;
    if (d1 < 0) d1 += Fft3_1::M;
    Int d2 =
        (FFT_INV012 * ((cs2[i] - d0 - Fft3_0::M * d1) % Fft3_2::M)) % Fft3_2::M;
    if (d2 < 0) d2 += Fft3_2::M;
    cs[i] =
        (d0 + Fft3_0::M * d1 + (((Int)(Fft3_0::M) * Fft3_1::M) % M) * d2) % M;
  }
  return cs;
}


char C[300'010];
char D[300'010];

int main() {
  prepare();
  initFft3();
  
  vector<Mint> two(LIM);
  two[0] = 1;
  for (int i = 1; i < LIM; ++i) {
    two[i] = two[i - 1] * 2;
  }
  
  int N;
  for (; ~scanf("%s%s%d", C, D, &N); ) {
    const int CLen = strlen(C);
    const int DLen = strlen(D);
    
    vector<Mint> fs(CLen + 1);
    const int ca = count(C, C + CLen, 'A');
    const int cb = count(C, C + CLen, 'B');
    const int cc = CLen - ca - cb;
    for (int i = 0; i <= cc; ++i) {
      fs[ca + i] = binom(cc, i);
    }
    
    vector<Mint> gs(DLen + 1);
    const int da = count(D, D + DLen, 'A');
    const int db = count(D, D + DLen, 'B');
    const int dc = DLen - da - db;
    for (int i = 0; i <= dc; ++i) {
      gs[DLen - (da + i)] = binom(dc, i);
    }
    
    const auto hs = convolute(fs, gs);
// cerr<<"hs = ";pv(hs.begin(),hs.end());
    
    vector<Mint> dp(N + 1);
    for (int n = 1; n <= N; ++n) {
      dp[n] = Mint(N / n) * Mint(N / n);
    }
    for (int n = N; n >= 1; --n) {
      for (int m = 2 * n; m <= N; m += n) {
        dp[n] -= dp[m];
      }
    }
    Mint score = 0;
    for (int n = 1; n <= N; ++n) {
      score += dp[n] * two[n];
    }
    
    Mint ans = 0;
    for (int i = 0; i < (int)hs.size(); ++i) {
      /*
        a x + b y = a' x + b' y
        x : y = (b' - b) : (a - a')
      */
      int y = i - DLen;
      int x = -((CLen - DLen) - y);
      if (x < 0) {
        x *= -1;
        y *= -1;
      }
      if (x > 0 && y > 0) {
        const int g = __gcd(x, y);
        const int n = N / (max(x, y) / g);
        ans += hs[i] * (two[n + 1] - 2);
      } else if (x == 0 && y == 0) {
        ans += hs[i] * score;
      }
    }
    
    // exactly same
    Mint same = 1;
    if (CLen == DLen) {
      for (int i = 0; i < CLen; ++i) {
        if (C[i] == '?' && D[i] == '?') {
          same *= 2;
        } else if (C[i] == '?' || D[i] == '?') {
          same *= 1;
        } else if (C[i] == D[i]) {
          same *= 1;
        } else {
          same *= 0;
        }
      }
      ans -= same * score;
      ans += same * (two[N + 1] - 2) * (two[N + 1] - 2);
    }
    
    printf("%d\n", ans.x);
  }
  return 0;
}