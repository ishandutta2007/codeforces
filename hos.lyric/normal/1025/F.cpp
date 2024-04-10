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

int N;
Int X[2010], Y[2010];

struct Entry {
  int s;
  Int x, y;
  int t;
};
int esLen;
Entry es[4010];

int main() {
  for (; ~scanf("%d", &N); ) {
    for (int i = 0; i < N; ++i) {
      scanf("%lld%lld", &X[i], &Y[i]);
    }
    Int ans = 0;
    for (int i = 0; i < N; ++i) {
      esLen = 0;
      for (int j = 0; j < N; ++j) {
        if (j != i) {
          const Int x = X[j] - X[i];
          const Int y = Y[j] - Y[i];
          int s;
          if (y > 0) {
            s = 1;
          } else if (y == 0) {
            s = (x > 0) ? 0 : 2;
          } else {
            s = 3;
          }
          es[esLen++] = Entry{s, x, y, +1};
          es[esLen++] = Entry{s ^ 2, -x, -y, -1};
        }
      }
      sort(es, es + esLen, [](const Entry &a, const Entry &b) {
        return ((a.s != b.s) ? (a.s < b.s) : (a.x * b.y > a.y * b.x));
      });
      Int up = 0, dn = 0;
      for (int k = 0; k < esLen; ++k) {
        if (es[k].t > 0) {
          (es[k].s < 2) ? ++up : ++dn;
        }
      }
      for (int k = 0; k < esLen; ++k) {
        if (es[k].t > 0) {
          --up;
          ans += (up * (up - 1) / 2) * (dn * (dn - 1) / 2);
          ++dn;
        } else {
          --dn;
          ++up;
        }
      }
    }
    ans /= 2;
    printf("%lld\n", ans);
  }
  return 0;
}