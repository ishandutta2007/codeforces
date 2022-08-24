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

constexpr int LIM = 70;
constexpr Int INF = 1'000'000'000'000'000'000;

Int bn[LIM][LIM];

int R, C;
char S[LIM];

Int loses[LIM][LIM];

vector<Int> pss[LIM];
int qsLen;
Int qs[1 << 20];

void dfs1(int i, int a, int b, Int sum, bool match0, bool match1) {
  if (i == 2 * R + C) {
    pss[a].push_back(sum << 2 | (match0 ? 1 : 0) | (match1 ? 2 : 0));
  } else {
    if (a < R + C) {
      dfs1(i + 1, a + 1, b, sum + loses[a][b], match0 && (S[i] != 'B'), match1 && (S[i] != 'A'));
    }
    if (b < R + C) {
      dfs1(i + 1, a, b + 1, sum - loses[b][a], match0 && (S[i] != 'A'), match1 && (S[i] != 'B'));
    }
  }
}
void dfs2(int i, int a, int b, Int sum, bool match0, bool match1) {
  if (i == 2 * R + 2 * C) {
    qs[qsLen++] = sum << 2 | (match0 ? 1 : 0) | (match1 ? 2 : 0);
  } else {
    if (a < R + C) {
      dfs2(i + 1, a + 1, b, sum + loses[a][b], match0 && (S[i] != 'B'), match1 && (S[i] != 'A'));
    }
    if (b < R + C) {
      dfs2(i + 1, a, b + 1, sum - loses[b][a], match0 && (S[i] != 'A'), match1 && (S[i] != 'B'));
    }
  }
}

int main() {
  for (int n = 0; n < LIM; ++n) {
    bn[n][0] = bn[n][n] = 1;
    for (int k = 1; k < n; ++k) {
      bn[n][k] = bn[n - 1][k - 1] + bn[n - 1][k];
    }
  }
  
  for (; ~scanf("%d%d%s", &R, &C, S); ) {
    // # of losing patterns when (a, b) -> (a + 1, b)
    for (int a = 0; a <= R + C; ++a) for (int b = 0; b <= R + C; ++b) {
      loses[a][b] = 0;
    }
    for (int a = R - 1; a <= R + C - 1; ++a) for (int b = 0; b <= R + C; ++b) {
      for (int x = 0; x <= R - 1; ++x) {
        loses[a][b] += bn[a][R - 1] * bn[b][x] * bn[2 * (R + C) - (a + 1) - b][R - x];
      }
    }
    
    int sa = 0, sb = 0;
    for (int i = 0; i < 2 * R - 1; ++i) {
      if (S[i] == 'A') ++sa;
      if (S[i] == 'B') ++sb;
    }
    
    Int opt = INF;
    Int ans = 0;
    for (int a0 = 0; a0 <= R - 1; ++a0) {
      const int b0 = (2 * R - 1) - a0;
      if (a0 <= R + C && b0 <= R + C) {
        const Int head0 = (sa <= a0 && sb <= b0) ? bn[(2 * R - 1) - sa - sb][a0 - sa] : 0;
        const Int head1 = (sb <= a0 && sa <= b0) ? bn[(2 * R - 1) - sb - sa][a0 - sb] : 0;
        Int start = 0;
        for (int a = 0; a < a0; ++a) {
          start += loses[a][0];
        }
        for (int b = 0; b < b0; ++b) {
          start -= loses[b][a0];
        }
        for (int a = 0; a <= R + C; ++a) {
          pss[a].clear();
        }
        dfs1(2 * R - 1, a0, b0, start, true, true);
// cerr<<"a0 = "<<a0<<endl;
        for (int a = 0; a <= R + C; ++a) {
          const int b = (2 * R + C) - a;
          if (!pss[a].empty()) {
            sort(pss[a].begin(), pss[a].end());
            const auto &ps = pss[a];
            const int psLen = ps.size();
            qsLen = 0;
            dfs2(2 * R + C, a, b, 0, true, true);
            sort(qs, qs + qsLen);
// cerr<<"  pss["<<a<<"] = ";pv(pss[a].begin(),pss[a].end());
// cerr<<"  qs = ";pv(qs,qs+qsLen);
            Int mn = INF;
            for (int j = 0, k = qsLen - 1; j < psLen && k >= 0; ) {
              const Int sum = (ps[j] & ~3LL) + (qs[k] & ~3LL);
              if (sum >= 0) {
                chmin(mn, sum);
                --k;
              } else {
                chmin(mn, -sum);
                ++j;
              }
            }
            if (chmin(opt, mn)) {
              ans = 0;
            }
            if (opt == mn) {
              Int now0 = 0, now1 = 0;
              Int sum0 = 0, sum1 = 0;
              for (int j = psLen - 1, k0 = 0, k1 = 0; j >= 0; --j) {
                if (ps[j] & 3LL) {
                  for (; k0 < qsLen && (ps[j] & ~3LL) + (qs[k0] & ~3LL) < -mn; ++k0) {
                    if (qs[k0] & 1LL) --now0;
                    if (qs[k0] & 2LL) --now1;
                  }
                  for (; k1 < qsLen && (ps[j] & ~3LL) + (qs[k1] & ~3LL) <= mn; ++k1) {
                    if (qs[k1] & 1LL) ++now0;
                    if (qs[k1] & 2LL) ++now1;
                  }
                  if (ps[j] & 1LL) sum0 += now0;
                  if (ps[j] & 2LL) sum1 += now1;
                }
              }
              ans += head0 * sum0;
              ans += head1 * sum1;
            }
          }
        }
      }
    }
// cerr<<"opt = "<<opt<<endl;
    printf("%lld\n", ans);
  }
  return 0;
}