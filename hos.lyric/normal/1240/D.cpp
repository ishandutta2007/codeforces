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

#include <chrono>
#include <random>

using namespace std;

using Int = long long;

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template <class T> void chmax(T &t, const T &f) { if (t < f) t = f; }

using UInt = unsigned long long;
constexpr UInt MO = 999'999'929;
UInt BASE0, BASE1;

constexpr int MAX_N = 300010;

int N;
int A[MAX_N];

int stack[MAX_N];
UInt hs0[MAX_N];
UInt hs1[MAX_N];

Int solve(int l, int r) {
  if (r - l <= 1) {
    return 0;
  }
  const int mid = (l + r) / 2;
  Int ret = 0;
  ret += solve(l, mid);
  ret += solve(mid, r);
  unordered_map<UInt, int> cnt;
  int len = 0;
  for (int i = mid; --i >= l; ) {
    if (len > 0 && stack[len - 1] == A[i]) {
      --len;
      
    } else {
      stack[len] = A[i];
      hs0[len + 1] = (hs0[len] * BASE0 + A[i]) % MO;
      hs1[len + 1] = (hs1[len] * BASE1 + A[i]) % MO;
      ++len;
    }
    ++cnt[hs0[len] | hs1[len] << 32];
  }
  len = 0;
  for (int i = mid; i < r; ++i) {
    if (len > 0 && stack[len - 1] == A[i]) {
      --len;
      
    } else {
      stack[len] = A[i];
      hs0[len + 1] = (hs0[len] * BASE0 + A[i]) % MO;
      hs1[len + 1] = (hs1[len] * BASE1 + A[i]) % MO;
      ++len;
    }
    ret += cnt[hs0[len] | hs1[len] << 32];
  }
  return ret;
}

int main() {
  mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<UInt> distr(0, MO - 1);
  BASE0 = distr(rng);
  BASE1 = distr(rng);
  
  int numCases;
  for (; ~scanf("%d", &numCases); ) {
    for (int caseId = 0; caseId < numCases; ++caseId) {
      scanf("%d", &N);
      for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
      }
      const Int ans = solve(0, N);
      printf("%lld\n", ans);
    }
  }
  return 0;
}