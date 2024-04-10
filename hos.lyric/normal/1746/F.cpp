#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

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
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> bool chmin(T &t, const T &f) { if (t > f) { t = f; return true; } return false; }
template <class T> bool chmax(T &t, const T &f) { if (t < f) { t = f; return true; } return false; }


// [0, 2^32)
unsigned xrand() {
  static unsigned x = 314159265, y = 358979323, z = 846264338, w = 327950288;
  unsigned t = x ^ x << 11; x = y; y = z; z = w; return w = w ^ w >> 19 ^ t ^ t >> 8;
}


template <class T> void bAdd(vector<T> &bit, int pos, const T &val) {
  const int bitN = bit.size();
  for (int x = pos; x < bitN; x |= x + 1) bit[x] += val;
}
template <class T> T bSum(const vector<T> &bit, int pos) {
  T ret = 0;
  for (int x = pos - 1; x >= 0; x = (x & (x + 1)) - 1) ret += bit[x];
  return ret;
}
template <class T> T bSum(const vector<T> &bit, int pos0, int pos1) {
  return bSum(bit, pos1) - bSum(bit, pos0);
}


int N, Q;
vector<int> A;
vector<int> T, I, X, L, R, K;
vector<int> Y;

int main() {
  for (; ~scanf("%d%d", &N, &Q); ) {
    const auto start = clock();
    
    A.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
    }
    T.assign(Q, -1);
    I.assign(Q, -1);
    X.assign(Q, -1);
    L.assign(Q, -1);
    R.assign(Q, -1);
    K.assign(Q, -1);
    for (int q = 0; q < Q; ++q) {
      scanf("%d", &T[q]);
      if (T[q] == 1) {
        scanf("%d%d", &I[q], &X[q]);
        --I[q];
      } else {
        scanf("%d%d%d", &L[q], &R[q], &K[q]);
        --L[q];
      }
    }
    
    auto as = A;
    for (int q = 0; q < Q; ++q) {
      if (T[q] == 1) {
        as.push_back(X[q]);
      }
    }
    sort(as.begin(), as.end());
    as.erase(unique(as.begin(), as.end()), as.end());
// cerr<<"as = "<<as<<endl;
    const int asLen = as.size();
    for (int i = 0; i < N; ++i) {
      A[i] = lower_bound(as.begin(), as.end(), A[i]) - as.begin();
    }
    for (int q = 0; q < Q; ++q) {
      if (T[q] == 1) {
        X[q] = lower_bound(as.begin(), as.end(), X[q]) - as.begin();
      }
    }
    
    Y.assign(Q, -1);
    {
      auto seq = A;
      for (int q = 0; q < Q; ++q) {
        if (T[q] == 1) {
          Y[q] = seq[I[q]];
          seq[I[q]] = X[q];
        }
      }
    }
// cerr<<"A = "<<A<<endl;
// cerr<<"I = "<<I<<endl;
// cerr<<"X = "<<X<<endl;
// cerr<<"Y = "<<Y<<endl;
// cerr<<"L = "<<L<<endl;
// cerr<<"R = "<<R<<endl;
// cerr<<"K = "<<K<<endl;
    
    
    vector<int> ans(Q, 1);
    
    vector<int> bs(asLen);
    vector<int> bit(N);
    
    int iter = 0;
    for (; ; ) {
      if ((double)(clock() - start) / CLOCKS_PER_SEC >= 2.0) {
        break;
      }
      for (int j = 0; j < asLen; ++j) {
        bs[j] = xrand() & 1023;
      }
      for (int i = 0; i < N; ++i) {
        bit[i] = bs[A[i]];
      }
      for (int i = 0; i < N; ++i) {
        const int ii = i | (i + 1);
        if (ii < N) {
          bit[ii] += bit[i];
        }
      }
      for (int q = 0; q < Q; ++q) {
        if (T[q] == 1) {
          bAdd(bit, I[q], bs[X[q]] - bs[Y[q]]);
        } else {
          const int res = bSum(bit, L[q], R[q]);
          if (res % K[q] != 0) {
            ans[q] = 0;
          }
        }
      }
      ++iter;
    }
// cerr<<"iter = "<<iter<<endl;
    
    for (int q = 0; q < Q; ++q) {
      if (T[q] == 1) {
      } else {
        puts(ans[q] ? "YES" : "NO");
      }
    }
  }
  return 0;
}