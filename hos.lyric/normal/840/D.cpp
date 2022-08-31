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

constexpr int M = 5;

int N, Q;
vector<int> A;
vector<int> L, R, K;

vector<vector<int>> poss;

int getCount(int l, int r, int a) {
  return lower_bound(poss[a].begin(), poss[a].end(), r) - lower_bound(poss[a].begin(), poss[a].end(), l);
}

vector<vector<int>> seg;

void build(int u, int l, int r) {
  if (r - l == 1) {
    seg[u].push_back(A[l]);
    return;
  }
  const int mid = (l + r) / 2;
  const int uL = u << 1 | 0;
  const int uR = u << 1 | 1;
  build(uL, l, mid);
  build(uR, mid, r);
  for (const int a : seg[uL]) {
    if (getCount(l, r, a) * M > r - l) {
      seg[u].push_back(a);
    }
  }
  for (const int a : seg[uR]) {
    if (getCount(l, r, a) * M > r - l) {
      seg[u].push_back(a);
    }
  }
  sort(seg[u].begin(), seg[u].end());
  seg[u].erase(unique(seg[u].begin(), seg[u].end()), seg[u].end());
// cerr<<u<<" "<<l<<" "<<r<<": ";pv(seg[u].begin(),seg[u].end());
}

vector<int> cands;

void query(int u, int l, int r, int a, int b) {
  chmax(a, l);
  chmin(b, r);
  if (a >= b) {
    return;
  }
  if (a == l && b == r) {
    cands.insert(cands.end(), seg[u].begin(), seg[u].end());
    return;
  }
  const int mid = (l + r) / 2;
  const int uL = u << 1 | 0;
  const int uR = u << 1 | 1;
  query(uL, l, mid, a, b);
  query(uR, mid, r, a, b);
}

int main() {
  for (; ~scanf("%d%d", &N, &Q); ) {
    A.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
      --A[i];
    }
    L.resize(Q);
    R.resize(Q);
    K.resize(Q);
    for (int q = 0; q < Q; ++q) {
      scanf("%d%d%d", &L[q], &R[q], &K[q]);
      --L[q];
    }
    
    poss.assign(N, {});
    for (int i = 0; i < N; ++i) {
      poss[A[i]].push_back(i);
    }
    
    seg.assign(N << 2, {});
    build(1, 0, N);
    
    for (int q = 0; q < Q; ++q) {
      cands.clear();
      query(1, 0, N, L[q], R[q]);
      sort(cands.begin(), cands.end());
      cands.erase(unique(cands.begin(), cands.end()), cands.end());
      int ans = -1;
      for (const int a : cands) {
        if (getCount(L[q], R[q], a) * K[q] > R[q] - L[q]) {
          ans = a;
          break;
        }
      }
      printf("%d\n", (ans == -1) ? -1 : (ans + 1));
    }
  }
  return 0;
}