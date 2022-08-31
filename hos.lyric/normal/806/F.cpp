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


struct ModInt {
  static int_fast64_t M;
  int_fast64_t x;
  constexpr ModInt() : x(0) {}
  ModInt(int_fast64_t x_) { x = x_ % M; if (x < 0) x += M; }
  ModInt &operator+=(const ModInt &a) { x += a.x; if (x >= M) x -= M; return *this; }
  ModInt &operator-=(const ModInt &a) { x -= a.x; if (x < 0) x += M; return *this; }
  ModInt &operator*=(const ModInt &a) { x *= a.x; x %= M; return *this; }
  ModInt operator+(const ModInt &a) const { return (ModInt(*this) += a); }
  ModInt operator-(const ModInt &a) const { return (ModInt(*this) -= a); }
  ModInt operator*(const ModInt &a) const { return (ModInt(*this) *= a); }
  ModInt operator-() const { return ModInt(-x); }
  ModInt pow(int_fast64_t e) const {
    ModInt x2 = x, xe = 1;
    for (; e; e >>= 1) {
      if (e & 1) xe *= x2;
      x2 *= x2;
    }
    return xe;
  }
  ModInt inv() const {
    Int a = x, b = M, y = 1, z = 0, t;
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
  friend ModInt operator+(int_fast64_t a, const ModInt &b) { return (ModInt(a) += b); }
  friend ModInt operator-(int_fast64_t a, const ModInt &b) { return (ModInt(a) -= b); }
  friend ModInt operator*(int_fast64_t a, const ModInt &b) { return (ModInt(a) *= b); }
  friend ostream &operator<<(ostream &os, const ModInt &a) { return os << a.x; }
};
int_fast64_t ModInt::M;

using Mint = ModInt;


// M: prime, G: primitive root
template <int M, int G, int K> struct Fft {
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
};


Int modInv(Int a, Int m) {
  Int b = m, x = 1, y = 0, t;
  for (; ; ) {
    t = a / b;
    a -= t * b;
    if (a == 0) {
      assert(b == 1 || b == -1);
      if (b == -1) {
        y = -y;
      }
      return (y < 0) ? (y + m) : y;
    }
    x -= t * y;
    t = b / a;
    b -= t * a;
    if (b == 0) {
      assert(a == 1 || a == -1);
      if (a == -1) {
        x = -x;
      }
      return (x < 0) ? (x + m) : x;
    }
    y -= t * x;
  }
}


constexpr Int FFT_P0 = 469762049;  // 2^26 7 + 1
constexpr Int FFT_P1 = 167772161;  // 2^25 5 + 1
constexpr Int FFT_P2 = 754974721;  // 2^24 45 + 1
const Fft<FFT_P0, 3, 17> FFT0;
const Fft<FFT_P1, 3, 17> FFT1;
const Fft<FFT_P2, 11, 17> FFT2;

vector<Mint> multiply(const vector<Mint> &a, const vector<Mint> &b) {
  const Int FFT_INV01 = modInv(FFT_P0, FFT_P1);
  const Int FFT_INV012 = modInv(FFT_P0 * FFT_P1, FFT_P2);
  vector<int> aa(a.size()), bb(b.size());
  for (size_t i = 0; i < a.size(); ++i) aa[i] = a[i].x % FFT_P0;
  for (size_t i = 0; i < b.size(); ++i) bb[i] = b[i].x % FFT_P0;
  const vector<int> x0 = FFT0.convolute(aa, bb);
  for (size_t i = 0; i < a.size(); ++i) aa[i] = a[i].x % FFT_P1;
  for (size_t i = 0; i < b.size(); ++i) bb[i] = b[i].x % FFT_P1;
  const vector<int> x1 = FFT1.convolute(aa, bb);
  for (size_t i = 0; i < a.size(); ++i) aa[i] = a[i].x % FFT_P2;
  for (size_t i = 0; i < b.size(); ++i) bb[i] = b[i].x % FFT_P2;
  const vector<int> x2 = FFT2.convolute(aa, bb);
  vector<Mint> x(x0.size());
  for (size_t i = 0; i < x0.size(); ++i) {
    Int y0 = x0[i] % FFT_P0;
    Int y1 = (FFT_INV01 * (x1[i] - y0)) % FFT_P1;
    if (y1 < 0) {
      y1 += FFT_P1;
    }
    Int y2 = (FFT_INV012 * ((x2[i] - y0 - FFT_P0 * y1) % FFT_P2)) % FFT_P2;
    if (y2 < 0) {
      y2 += FFT_P2;
    }
    x[i] = Mint(1) * y0 + Mint(FFT_P0) * y1 + Mint(FFT_P0 * FFT_P1) * y2;
  }
  return x;
}


int N;
Int A;
int Q;

int main() {
  for (; ~scanf("%d%lld%d", &N, &A, &Q); ) {
    Mint::M = Q;
    
    Mint ans = 0;
    Int last = 1;
    vector<vector<Mint>> fss(2, vector<Mint>(N + 1, 0));
    fss[1][1] = 1;
    for (int k = __lg(A); k >= 1; --k) {
      const Int a = A >> k;
      if (last * 2 <= a) {
        // *= 2
        vector<Mint> fs01(N + 1);
        for (int i = 0; i <= N; ++i) {
          fs01[i] = fss[0][i] + fss[1][i];
        }
        vector<vector<Mint>> gss(2);
        for (int s = 0; s < 2; ++s) {
          gss[s] = multiply(fs01, fss[(s - last) & 1]);
          gss[s].resize(N + 1);
          for (int i = 0; i <= N; ++i) {
            // small only
            gss[s][i] += fss[s][i];
            // large only
            gss[s][i] += fss[(s - last) & 1][i];
          }
        }
        fss = gss;
        last *= 2;
// cerr<<"last = "<<last<<endl;for(int s=0;s<2;++s){cerr<<"  ";pv(fss[s].begin(),fss[s].end());}
      }
      if (last + 1 <= a) {
        // += 1
        for (int i = N; i >= 1; --i) {
          fss[1][i] += fss[0][i - 1] + fss[1][i - 1];
        }
        fss[1][1] += 1;
        last += 1;
// cerr<<"last = "<<last<<endl;for(int s=0;s<2;++s){cerr<<"  ";pv(fss[s].begin(),fss[s].end());}
      }
      for (int i = 1; i <= N; i += 2) {
        ans += fss[1][i];
      }
    }
    printf("%lld\n", (Int)ans.x);
  }
  return 0;
}