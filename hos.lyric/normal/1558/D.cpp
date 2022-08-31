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

constexpr unsigned MO = 998244353;
using Mint = ModInt<MO>;

constexpr int LIM = 600'010;
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


template <class T> void bitAdd(vector<T> &bit, int pos, const T &val) {
  const int bitN = bit.size();
  for (int x = pos; x < bitN; x |= x + 1) bit[x] += val;
}
template <class T> T bitSum(const vector<T> &bit, int pos) {
  T ret = 0;
  for (int x = pos - 1; x >= 0; x = (x & (x + 1)) - 1) ret += bit[x];
  return ret;
}
template <class T> T bitSum(const vector<T> &bit, int pos0, int pos1) {
  return bitSum(bit, pos1) - bitSum(bit, pos0);
}

// min pos s.t. pred(sum of [0, pos))
//   assume pred(sum of [0, pos)) is non-decreasing
//
// pred: * >= tar
int bitBinarySearch(const vector<int> &bit, int tar) {
  if (0 >= tar) return 0;
  int pos = 0;
  int sum = 0;
  for (int e = 31 - __builtin_clz(bit.size()); e >= 0; --e) {
    const int x = (pos | 1 << e) - 1;
    if (x < (int)bit.size() && !(sum + bit[x] >= tar)) {
      pos |= 1 << e;
      sum += bit[x];
    }
  }
  return pos + 1;
}


constexpr int MAX_N = 200'010;

int N, M;
vector<int> X, Y;

int main() {
  prepare();
  
  vector<int> bit(MAX_N, 0);
  for (int i = 0; i < MAX_N; ++i) {
    bitAdd(bit, i, +1);
  }
  
  for (int numCases; ~scanf("%d", &numCases); ) {
    for (int caseId = 0; caseId < numCases; ++caseId) {
      scanf("%d%d", &N, &M);
      X.resize(M);
      Y.resize(M);
      for (int i = 0; i < M; ++i) {
        scanf("%d%d", &X[i], &Y[i]);
      }
      
      vector<int> poss(M);
      vector<int> cuts;
      for (int i = M; i--; ) {
        poss[i] = bitBinarySearch(bit, Y[i]);
        if (bitSum(bit, poss[i] + 1) > Y[i]) {
          cuts.push_back(poss[i]);
        }
        bitAdd(bit, poss[i] - 1, -1);
      }
      for (int i = 0; i < M; ++i) {
        bitAdd(bit, poss[i] - 1, +1);
      }
      
      cuts.push_back(0);
      cuts.push_back(N);
      sort(cuts.begin(), cuts.end());
      const int cutsLen = cuts.size();
// cerr<<"cuts = ";pv(cuts.begin(),cuts.end());
      
      // x^a / (1 - x)^b
      int a = 0, b = cutsLen;
      for (int i = 0; i < cutsLen - 1; ++i) {
        a += 1;
        b += cuts[i + 1] - cuts[i] - 1;
      }
// cerr<<a<<" "<<b<<endl;
      
      Mint ans = 0;
      if (N >= a) {
        ans = binom(b + (N - a) - 1, N - a);
      }
      printf("%u\n", ans.x);
    }
  }
  return 0;
}