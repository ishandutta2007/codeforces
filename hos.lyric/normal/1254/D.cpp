#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")

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
  ModInt operator+(const ModInt &a) const { return (ModInt(*this) += a); }
  ModInt operator-(const ModInt &a) const { return (ModInt(*this) -= a); }
  ModInt operator*(const ModInt &a) const { return (ModInt(*this) *= a); }
  ModInt operator-() const { return ModInt(-x); }
  ModInt pow(long long e) const {
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

constexpr int MO = 998244353;
using Mint = ModInt<MO>;

constexpr int MAX_N = 150010;

int N, Q;
vector<int> G[MAX_N];

int zeit;
int par[MAX_N], deg[MAX_N], dis[MAX_N], fin[MAX_N];
int sz[MAX_N];

void dfs(int u, int p) {
  par[u] = p;
  dis[u] = zeit++;
  sz[u] = 1;
  
  deg[u] = G[u].size();
  for (int j = 0; j < deg[u]; ++j) {
    if (G[u][j] == p) {
      G[u].erase(G[u].begin() + j);
      break;
    }
  }
  deg[u] = G[u].size();
  
  for (const int v : G[u]) {
    dfs(v, u);
    sz[u] += sz[v];
  }
  
  fin[u] = zeit++;
}

int bitN;
Mint bit[2 * MAX_N];

void bitAdd(int pos, Mint val) {
  for (int x = pos; x < bitN; x |= x + 1) bit[x] += val;
}
Mint bitSum(int pos) {
  Mint ret = 0;
  for (int x = pos - 1; x >= 0; x = (x & (x + 1)) - 1) ret += bit[x];
  return ret;
}

int hubsLen;
int hubs[MAX_N];
vector<int> diss[MAX_N];
Mint dSum[MAX_N];

int main() {
  for (; ~scanf("%d%d", &N, &Q); ) {
    fill(G, G + N, vector<int>{});
    for (int i = 0; i < N - 1; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      --u;
      --v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    
    zeit = 0;
    dfs(0, -1);
// for(int u=0;u<N;++u){cerr<<"G["<<u<<"] = ";pv(G[u].begin(),G[u].end());}
    
    const Mint invN = Mint(N).inv();
    
    const int sqrtN = (int)sqrt(N / 8.0);
    // const int sqrtN = N + 1;
    // const int sqrtN = 0;
    hubsLen = 0;
    for (int u = 0; u < N; ++u) {
      if (deg[u] >= sqrtN) {
        hubs[hubsLen++] = u;
      }
    }
    fill(diss, diss + N, vector<int>{});
    for (int u = 0; u < N; ++u) {
      diss[u].resize(deg[u]);
      for (int j = 0; j < deg[u]; ++j) {
        diss[u][j] = dis[G[u][j]];
      }
    }
    
    bitN = 2 * N + 1;
    Mint all = 0;
    fill(dSum, dSum + N, Mint(0));
    
    for (int q = 0; q < Q; ++q) {
      int typ;
      scanf("%d", &typ);
      switch (typ) {
        case 1: {
          int v, d;
          scanf("%d%d", &v, &d);
          --v;
// cerr<<"Add "<<v<<" "<<d<<endl;
          all += Mint(d) * N;
          if (deg[v] >= sqrtN) {
            dSum[v] += d;
          } else {
            for (const int w : G[v]) {
              bitAdd(dis[w], Mint(d) * -sz[w]);
              bitAdd(fin[w] + 1, Mint(d) * +sz[w]);
            }
            if (par[v] != -1) {
              all += Mint(d) * -(N - sz[v]);
              bitAdd(dis[v], Mint(d) * +(N - sz[v]));
              bitAdd(fin[v] + 1, Mint(d) * -(N - sz[v]));
            }
          }
        } break;
        case 2: {
          int v;
          scanf("%d", &v);
          --v;
// cerr<<"Query "<<v<<endl;
          Mint ans = all;
          for (int k = 0; k < hubsLen; ++k) {
            const int hub = hubs[k];
            if (v == hub) {
              // no subtraction
            } else if (dis[hub] < dis[v] && dis[v] < fin[hub]) {
              const int j = upper_bound(diss[hub].begin(), diss[hub].end(), dis[v]) - diss[hub].begin() - 1;
              ans -= dSum[hub] * sz[G[hub][j]];
            } else {
              ans -= dSum[hub] * (N - sz[hub]);
            }
          }
          ans += bitSum(dis[v] + 1);
          ans *= invN;
          printf("%d\n", ans.x);
        } break;
        default: assert(false);
      }
    }
    
  }
  return 0;
}