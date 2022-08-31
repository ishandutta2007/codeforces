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
int A[200'010];

int main() {
  for (int numCases; ~scanf("%d", &numCases); ) {
    for (; numCases--; ) {
      scanf("%d", &N);
      for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
      }
      sort(A, A + N);
      
      int ans = 0;
      for (int i = 0, j; i < N; i = j) {
        for (j = i; j < N && A[i] == A[j]; ++j) {}
        int score = j - i;
        int d = 0;
        int k = j - 1;
        for (; ; ) {
          const int kk = lower_bound(A + k + 1, A + N, A[k] + d) - A;
          if (kk >= N) {
            break;
          }
          ++score;
          d = A[kk] - A[j - 1];
          k = kk;
        }
        chmax(ans, score);
      }
      
      ans = N - ans;
      printf("%d\n", ans);
    }
#ifndef LOCAL
    break;
#endif
  }
  return 0;
}