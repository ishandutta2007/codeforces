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


int H, W;
char S[1'000'010];

int main() {
  for (int numCases; ~scanf("%d", &numCases); ) { for (; numCases--; ) {
    scanf("%d%d", &H, &W);
    scanf("%s", S);
    
    const int L = H * W;
    vector<int> as(L);
    for (int i = 0; i < L; ++i) {
      as[i] = S[i] - '0';
    }
    vector<int> asSum(L + 1, 0);
    for (int i = 0; i < L; ++i) {
      asSum[i + 1] = asSum[i] + as[i];
    }
    vector<int> fs(L);
    for (int i = 0; i < L; ++i) {
      fs[i] = (asSum[i + 1] - asSum[max(i + 1 - W, 0)] >= 1) ? 1 : 0;
    }
    for (int i = W; i < L; ++i) {
      fs[i] += fs[i - W];
    }
    
    vector<int> gs(L, 0);
    {
      vector<int> cols(W, 0);
      int now = 0;
      int y = 0;
      for (int i = 0; i < L; ++i) {
        if (as[i]) {
          if (!cols[y]++) {
            ++now;
          }
        }
        gs[i] = now;
        if (++y == W) y = 0;
      }
    }
    
// cerr<<"fs = ";pv(fs.begin(),fs.end());
// cerr<<"gs = ";pv(gs.begin(),gs.end());
    vector<int> ans(L, 0);
    for (int i = 0; i < L; ++i) {
      ans[i] = fs[i] + gs[i];
    }
    for (int i = 0; i < L; ++i) {
      if (i) printf(" ");
      printf("%d", ans[i]);
    }
    puts("");
  }
#ifndef LOCAL
  break;
#endif
  }
  return 0;
}