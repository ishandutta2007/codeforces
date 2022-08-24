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


constexpr int L = 30;
constexpr int MAX_V = 150'010 * L + 10;

int V;
int nxt[MAX_V][2];
Mint all[MAX_V];
int newNode() {
  nxt[V][0] = nxt[V][1] = -1;
  all[V] = 1;
  return V++;
}


int N;
int X;
vector<int> A;

Mint g(int l, int u, int v) {
  if (!~u && !~v) return 1;
  if (!~u) return all[v];
  if (!~v) return all[u];
  --l;
  Mint ret;
  if (!~l) {
    ret = all[u] * all[v];
  } else if (!(X >> l & 1)) {
    ret = 0;
    ret += all[u];
    ret += all[v];
    ret += g(l, nxt[u][0], nxt[v][0]);
    ret += g(l, nxt[u][1], nxt[v][1]);
    ret -= (~nxt[u][0]) ? all[nxt[u][0]] : 1;
    ret -= (~nxt[u][1]) ? all[nxt[u][1]] : 1;
    ret -= (~nxt[v][0]) ? all[nxt[v][0]] : 1;
    ret -= (~nxt[v][1]) ? all[nxt[v][1]] : 1;
    ret += 1;
  } else {
    ret = 1;
    ret *= g(l, nxt[u][0], nxt[v][1]);
    ret *= g(l, nxt[u][1], nxt[v][0]);
  }
// cerr<<"g "<<l<<" "<<u<<" "<<v<<" = "<<ret<<endl;
  return ret;
}

Mint f(int l, int u) {
  if (!~u) {
    return 1;
  }
  --l;
  Mint ret;
  if (!~l) {
    ret = all[u];
  } else if (!(X >> l & 1)) {
    ret = 0;
    ret += f(l, nxt[u][0]);
    ret += f(l, nxt[u][1]);
    ret -= 1;
  } else {
    ret = g(l, nxt[u][0], nxt[u][1]);
  }
// cerr<<"f "<<l<<" "<<u<<" = "<<ret<<endl;
  return ret;
}

int main() {
  for (; ~scanf("%d%d", &N, &X); ) {
    A.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
    }
    sort(A.begin(), A.end());
    
    V = 0;
    newNode();
    for (int i = 0; i < N; ++i) {
// cerr<<A[i]<<": ";
      int u = 0;
      for (int l = L; --l >= 0; ) {
// cerr<<u<<" ";
        int &v = nxt[u][A[i] >> l & 1];
        if (!~v) {
          v = newNode();
        }
        u = v;
      }
// cerr<<u<<endl;
      all[u] *= 2;
    }
    for (int u = V; --u >= 0; ) {
      for (int e = 0; e < 2; ++e) {
        const int v = nxt[u][e];
        if (~v) {
          all[u] *= all[v];
        }
      }
    }
// cerr<<"all = ";pv(all,all+V);
    
    Mint ans = f(L, 0);
    ans -= 1;
    printf("%u\n", ans.x);
  }
  return 0;
}