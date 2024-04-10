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


// floor(sqrt(a))
long long floorSqrt(long long a) {
  long long b = a, x = 0, y = 0;
  for (int e = (63 - __builtin_clzll(a)) & ~1; e >= 0; e -= 2) {
    x <<= 1;
    y <<= 1;
    if (b >= (y | 1) << e) {
      b -= (y | 1) << e;
      x |= 1;
      y += 2;
    }
  }
  return x;
}


constexpr int LIM = 1'000'010;

int lpf[LIM], pi[LIM];

int main() {
  /*
  for (int n = 1; n <= 130; ++n) {
    printf("%3d: ", n);
    for (int u = 1; u <= n; ++u) {
      bool found = false;
      for (int v = 1; v <= n; ++v) {
        if (u != v) {
          const int d = __gcd(u, v);
          const int a = u / d;
          const int b = v / d;
          if (d + a > b && a + b > d && b + d > a) {
            found = true;
          }
        }
      }
      printf("%d", found);
    }
    puts("");
  }
  */
  
  iota(lpf, lpf + LIM, 0);
  for (int p = 2; p < LIM; ++p) {
    if (lpf[p] == p) {
      for (int n = 2 * p; n < LIM; n += p) {
        chmin(lpf[n], p);
      }
    }
  }
  for (int n = 2; n < LIM; ++n) {
    pi[n] = pi[n - 1] + ((lpf[n] == n) ? 1 : 0);
  }
  
  int numCases;
  for (; ~scanf("%d", &numCases); ) {
    for (int caseId = 0; caseId < numCases; ++caseId) {
      int N;
      scanf("%d", &N);
      
      const int sqrtN = floorSqrt(N);
      const int ans = pi[N] - pi[sqrtN] + 1;
      printf("%d\n", ans);
    }
  }
  return 0;
}