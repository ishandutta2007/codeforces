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

constexpr int MAX_N = 100010;

int main() {
  int as[MAX_N] = {}, bs[MAX_N] = {};
  int Q;
  scanf("%d", &Q);
  for (int q = 0; q < Q; ++q) {
    int t, l, r;
    scanf("%d%d%d", &t, &l, &r);
    if (t == 1) {
      int k;
      scanf("%d", &k);
      if (k > 0) {
        for (int i = l; i < r; ++i) {
          if (!as[i] || as[i] > k) {
            as[i] = k;
          }
        }
      } else {
        k = -k;
        for (int i = l; i < r; ++i) {
          if (!bs[i] || bs[i] > k) {
            bs[i] = k;
          }
        }
      }
    } else {
      Int ans = 0;
      for (int i = l; i < r; ++i) {
        if (as[i] && bs[i]) {
          ans += as[i] + bs[i];
        }
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}