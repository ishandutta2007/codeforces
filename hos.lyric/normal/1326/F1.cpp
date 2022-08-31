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

constexpr int MAX_N = 14;

int N;
char A[MAX_N][MAX_N + 1];

Int ans[1 << MAX_N];

// (N - 1 - H, H)
int H;
int freqL[1 << (MAX_N / 2 + MAX_N)];
int freqR[1 << (MAX_N / 2 + MAX_N)];
void dfs(int pos, int used, int last, int seqL, int seqR) {
  if (pos == N - 1 - H) {
    ++freqL[used << H | seqL];
  }
  if (pos == H) {
    ++freqR[used << H | seqR];
    return;
  }
  for (int u = 0; u < N; ++u) {
    if (!(used & 1 << u)) {
      const int a = A[last][u] - '0';
      dfs(pos + 1, used | 1 << u, u, a | seqL << 1, seqR | a << pos);
    }
  }
}

int main() {
  for (; ~scanf("%d", &N); ) {
    for (int u = 0; u < N; ++u) {
      scanf("%s", A[u]);
    }
    fill(ans, ans + (1 << (N - 1)), 0);
    H = N / 2;
    for (int s = 0; s < N; ++s) {
// cerr<<"s = "<<s<<endl;
      fill(freqL, freqL + (1 << (H + N)), 0);
      fill(freqR, freqR + (1 << (H + N)), 0);
      dfs(0, 1 << s, s, 0, 0);
      for (int q = 0; q < 1 << (H + N); ++q) {
        if (freqR[q]) {
          const int qLowShift = (q & ((1 << H) - 1)) << (N - 1 - H);
          const int pUpp = (((1 << (H + N)) - (1 << H)) & ~q) | 1 << (H + s);
          for (int pLow = 0; pLow < 1 << (N - 1 - H); ++pLow) {
            ans[qLowShift + pLow] += freqR[q] * freqL[pUpp + pLow];
          }
        }
      }
    }
    for (int f = 0; f < 1 << (N - 1); ++f) {
      if (f > 0) printf(" ");
      printf("%lld", ans[f]);
    }
    puts("");
  }
  return 0;
}