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


constexpr int MAX_N = 1010;

int N, K;
char A[MAX_N][MAX_N];
char B[MAX_N][MAX_N];

int col[MAX_N][MAX_N];

int judge() {
  for (int x = 0; x < N; ++x) for (int y = 0; y < N; ++y) {
    if (A[x][y] == '0') if (!(B[x][y] == '1')) return 1;
    if (A[x][y] == '1') if (!(B[x][y] == '0' || B[x][y] == '1')) return 2;
  }
  int cntDel = 0;
  for (int x = 0; x < N; ++x) for (int y = 0; y < N; ++y) if (B[x][y] == '0') {
    ++cntDel;
  }
  if (cntDel != (N - K + 1) * (N - K + 1)) {
cerr<<"cntDel = "<<cntDel<<endl;
    return 3;
  }
  vector<vector<int>> dp(N, vector<int>(N, 0));
  for (int x = 0; x < N; ++x) for (int y = 0; y < N; ++y) if (B[x][y] == '1') {
    for (int xx = 0; xx < x; ++xx) for (int yy = 0; yy < y; ++yy) {
      chmax(dp[x][y], dp[xx][yy]);
    }
    dp[x][y] += 1;
    if (dp[x][y] >= K) {
      return 4;
    }
  }
  return 0;
}

// (a, b) --> (b, a)
template <bool MAX> void path(int k, int a) {
#define WAF(z) (MAX ? (N - 1 - (z)) : (z))
// cerr<<"path<"<<MAX<<"> "<<k<<" "<<a<<endl;
// for(int x=0;x<N;++x)cerr<<B[x]<<endl;
  const int b = N - 1 - a;
  int y = b;
  for (int x = a; x <= b; ++x) {
    int yy;
    for (yy = a; yy < y; ++yy) if (A[WAF(x)][WAF(yy)] == '0' && B[WAF(x)][WAF(yy)] == '0') {
      break;
    }
    // chmin(yy, (x < a + (N - K + 1)) ? (a + (N - K + 1)) : a);
    if (x == b) {
      yy = a;
    } else {
      for (; col[x + 1][yy] > k; --yy) {}
    }
// cerr<<"  x = "<<x<<", y = "<<y<<", yy = "<<yy<<endl;
    for (; ; --y) {
      B[WAF(x)][WAF(y)] = '1';
      if (y == yy) break;
    }
  }
// cerr<<"DONE path<"<<MAX<<"> "<<k<<" "<<a<<endl;
// for(int x=0;x<N;++x)cerr<<B[x]<<endl;
// cerr<<"----"<<endl;
#undef WAF
}

bool solve() {
  for (int x = 0; x < N; ++x) {
    fill(B[x], B[x] + N, '0');
    B[x][N] = 0;
  }
  
  for (int x = 0; x < N; ++x) {
    fill(col[x], col[x] + N, -1);
  }
  for (int k = K - 1; --k >= 0; ) {
    const int a = min(k, (K - 1) - 1 - k);
    const int b = N - 1 - a;
    for (int x = a, y = b; ; ) {
      col[x][y] = k;
      if (x == b && y == a) break;
      if ((x + 1 == b && y == a) || !~col[x + 1][y]) {
        ++x;
      } else {
        --y;
      }
    }
  }
// cerr<<"col = "<<endl;for(int x=0;x<N;++x){for(int y=0;y<N;++y){if(~col[x][y])cerr<<col[x][y];else cerr<<'-';};cerr<<endl;}
  
  for (int k = 0; k < K - 1; ++k) {
    path<false>(k, min(k, (K - 1) - 1 - k));
  }
  
  for (int x = 0; x < N; ++x) for (int y = 0; y < N; ++y) {
    if (A[x][y] == '0' && B[x][y] == '0') {
      return false;
    }
  }
  return true;
}

int main() {
  for (int numCases; ~scanf("%d", &numCases); ) { for (int caseId = 1; caseId <= numCases; ++caseId) {
    scanf("%d%d", &N, &K);
    for (int x = 0; x < N; ++x) {
      scanf("%s", A[x]);
    }
    
    const bool ans = solve();
    if (ans) {
      puts("YES");
      for (int x = 0; x < N; ++x) {
        puts(B[x]);
      }
#ifdef LOCAL
const int verdict=judge();
if(verdict)cerr<<"WA "<<verdict<<endl;
assert(!verdict);
#endif
    } else {
      puts("NO");
    }
#ifdef LOCAL
cerr<<"========"<<endl;
#endif
  }
#ifndef LOCAL
  break;
#endif
  }
  return 0;
}