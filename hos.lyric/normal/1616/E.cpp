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


template <class T> void bAdd(vector<T> &bit, int pos, const T &val) {
  const int bitN = bit.size();
  for (int x = pos; x < bitN; x |= x + 1) bit[x] += val;
}
template <class T> T bSum(const vector<T> &bit, int pos) {
  T ret = 0;
  for (int x = pos - 1; x >= 0; x = (x & (x + 1)) - 1) ret += bit[x];
  return ret;
}
template <class T> T bSum(const vector<T> &bit, int pos0, int pos1) {
  return bSum(bit, pos1) - bSum(bit, pos0);
}


constexpr int MAX_N = 100'010;
constexpr int A = 26;
constexpr Int INF = 1001001001001001001LL;

int N;
char S[MAX_N], T[MAX_N];

int main() {
  for (int numCases; ~scanf("%d", &numCases); ) {
    for (; numCases--; ) {
      scanf("%d", &N);
      scanf("%s", S);
      scanf("%s", T);
      
      vector<vector<int>> iss(A);
      for (int i = 0; i < N; ++i) {
        iss[S[i] - 'a'].push_back(i);
      }
      vector<int> poss(A, 0);
      
      vector<int> bit(N, 0);
      for (int i = 0; i < N; ++i) {
        bAdd(bit, i, +1);
      }
      
      Int ans = INF;
      Int now = 0;
      for (int j = 0; j < N; ++j) {
        const int b = T[j] - 'a';
        int im = N;
        for (int a = 0; a < b; ++a) {
          if (poss[a] < (int)iss[a].size()) {
            chmin(im, iss[a][poss[a]]);
          }
        }
        if (im < N) {
          const int res = bSum(bit, im);
          const Int cost = now + res;
          chmin(ans, cost);
        }
        if (poss[b] < (int)iss[b].size()) {
          const int i = iss[b][poss[b]++];
          const int res = bSum(bit, i);
          now += res;
          bAdd(bit, i, -1);
        } else {
          break;
        }
      }
      
      printf("%lld\n", (ans >= INF) ? -1 : ans);
    }
#ifndef LOCAL
    break;
#endif
  }
  return 0;
}