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

constexpr int LIM = 10005;

int N, L, R;
int A[LIM], B[LIM];

int xsLen, ysLen;
int xs[LIM], ys[LIM];

bitset<LIM> dp0, dp1;

int main() {
  for (; ~scanf("%d%d%d", &N, &L, &R); ) {
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; ++i) {
      scanf("%d", &B[i]);
    }
    xsLen = ysLen = 0;
    for (int i = 0; i < N; ++i) {
      if (B[i] == 0) {
        xs[xsLen++] = A[i];
      } else {
        ys[ysLen++] = A[i];
      }
    }
    sort(xs, xs + xsLen);
    sort(ys, ys + ysLen);
// cerr<<"xs = ";pv(xs,xs+xsLen);
// cerr<<"ys = ";pv(ys,ys+ysLen);
    dp0.reset();
    dp1.reset();
    dp0[0] = 1;
    for (int i = 0; i < xsLen; ++i) {
      dp0 = dp0 | dp0 << xs[i];
    }
    int ans = 0;
    for (int k = ysLen; k >= 0; --k) {
      if (k < ysLen) {
        dp1 = dp1 | dp1 << ys[k] | dp0;
        dp0 = dp0 | dp0 << ys[k];
      }
      auto calc = [&](int z) {
        for (int j = 0; j < k; ++j) {
          z += ys[j];
          if (z > R) {
            return j;
          }
        }
        return k;
      };
      for (int z = L; z <= R; ++z) {
        if (dp0[z]) {
          chmax(ans, calc(z));
          break;
        }
      }
      for (int z = L; z <= R; ++z) {
        if (dp1[z]) {
          chmax(ans, calc(z) + 1);
          break;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}