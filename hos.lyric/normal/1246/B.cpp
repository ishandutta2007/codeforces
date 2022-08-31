// #pragma GCC optimize ("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target ("avx")

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

int N, K;
int A[100010];

int main() {
  for (; ~scanf("%d%d", &N, &K); ) {
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
    }
    Int ans = 0;
    map<vector<pair<int, int>>, int> cnt;
    for (int i = 0; i < N; ++i) {
      int a = A[i];
      vector<pair<int, int>> f, g;
      for (int p = 2; p * p <= a; ++p) {
        if (a % p == 0) {
          int e = 0;
          do {
            ++e;
            a /= p;
          } while (a % p == 0);
          if (e % K != 0) {
            f.emplace_back(p, e % K);
            g.emplace_back(p, K - e % K);
          }
        }
      }
      if (a > 1) {
        if (1 % K != 0) {
          f.emplace_back(a, 1 % K);
          g.emplace_back(a, K - 1 % K);
        }
      }
      ans += cnt[g];
      ++cnt[f];
    }
    printf("%lld\n", ans);
  }
  return 0;
}