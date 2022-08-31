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


int N;
vector<int> A;

int main() {
  for (int numCases; ~scanf("%d", &numCases); ) { for (; numCases--; ) {
    scanf("%d", &N);
    A.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
    }
    
    int z = 0;
    auto as = A;
    for (int n = N; n >= 2; --n) {
      const int asLen = as.size();
      int zz = 0;
      vector<int> bs;
      if (z >= 1) {
        zz += (z - 1);
      }
      if (z >= 1 && asLen >= 1) {
        bs.push_back(as[0]);
      }
      if (asLen >= 1) {
        for (int i = 0; i < asLen - 1; ++i) {
          const int b = as[i + 1] - as[i];
          if (b == 0) {
            zz += 1;
          } else {
            bs.push_back(b);
          }
        }
      }
      sort(bs.begin(), bs.end());
// cerr<<zz<<" "<<bs<<endl;
      z = zz;
      as.swap(bs);
    }
    
    const int ans = (z > 0) ? 0 : as[0];
    printf("%d\n", ans);
  }
#ifndef LOCAL
  break;
#endif
  }
  return 0;
}