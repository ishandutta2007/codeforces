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
vector<int> P;

int f[5010][5010];

int main() {
  for (int numCases; ~scanf("%d", &numCases); ) { for (; numCases--; ) {
    scanf("%d", &N);
    P.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &P[i]);
      --P[i];
    }
    
    for (int i = 0; i <= N; ++i) {
      fill(f[i], f[i] + N + 1, 0);
    }
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j <= N; ++j) {
        f[i + 1][j] = f[i][j] + ((P[i] < j) ? 1 : 0);
      }
    }
    
    Int ans = 0;
    for (int i = 0; i < N; ++i) for (int j = i + 1; j < N; ++j) {
      ans += 1LL * f[i][P[j]] * (f[N][P[i]] - f[j + 1][P[i]]);
    }
    printf("%lld\n", ans);
  }
#ifndef LOCAL
  break;
#endif
  }
  return 0;
}