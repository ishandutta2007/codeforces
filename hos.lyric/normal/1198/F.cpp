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

#include <chrono>

using namespace std;

using Int = long long;

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template <class T> void chmax(T &t, const T &f) { if (t < f) t = f; }

unsigned xrand() {
  static unsigned x = 314159265, y = 358979323, z = 846264338, w = 327950288;
  unsigned t = x ^ x << 11; x = y; y = z; z = w; return w = w ^ w >> 19 ^ t ^ t >> 8;
}

constexpr int MAX_N = 100005;

int N;
int A[MAX_N];

int perm[MAX_N];

int ans[MAX_N];

int main() {
  using namespace std::chrono;
  auto begin = high_resolution_clock::now();
  
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &A[i]);
  }
  
  iota(perm, perm + N, 0);
  for (; duration_cast<milliseconds>(high_resolution_clock::now() - begin).count() <= 460; ) {
    for (int j = 1; j < N; ++j) {
      swap(perm[xrand() % (j + 1)], perm[j]);
    }
    int g1 = 0, g2 = 0;
    int pos = N + 1;
    for (int j = 0; j < N; ++j) {
      g1 = gcd(g1, A[perm[j]]);
      if (g1 == 1) {
        pos = j + 1;
        break;
      }
    }
    for (int j = pos; j < N; ++j) {
      g2 = gcd(g2, A[perm[j]]);
    }
    if (g1 == 1 && g2 == 1) {
      for (int j = 0; j < pos; ++j) {
        ans[perm[j]] = 1;
      }
      for (int j = pos; j < N; ++j) {
        ans[perm[j]] = 2;
      }
      printf("YES\n");
      for (int i = 0; i < N; ++i) {
        if (i > 0) {
          printf(" ");
        }
        printf("%d", ans[i]);
      }
      printf("\n");
      return 0;
    }
  }
  
  printf("NO\n");
  
  return 0;
}