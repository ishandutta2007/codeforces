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


constexpr int MAX_N = 105;

int uf[MAX_N];
int root(int u) {
  return (uf[u] < 0) ? u : (uf[u] = root(uf[u]));
}
bool connect(int u, int v) {
  u = root(u);
  v = root(v);
  if (u == v) return false;
  if (uf[u] > uf[v]) swap(u, v);
  uf[u] += uf[v];
  uf[v] = u;
  return true;
}


int N;
int A[MAX_N], B[MAX_N];

vector<int> G[MAX_N];
bool del[MAX_N];

using U = __uint128_t;
using Result = pair<int, U>;
bool mem[MAX_N][MAX_N];
Result cache[MAX_N][MAX_N];
Result solve(int u, int p) {
  if (mem[u][p]) {
    return cache[u][p];
  }
  int sz = 0;
  U val = 0;
  vector<U> xs;
  for (const int i : G[u]) {
    const int v = A[i] ^ B[i] ^ u;
    if (!del[i] && v != p) {
      const auto res = solve(v, u);
      sz += res.first + 1;
      xs.push_back(res.second + 1);
    }
  }
  if (!xs.empty()) {
    priority_queue<U> que;
    for (const U x : xs) {
      que.push(x);
    }
    for (int e = sz; e--; ) {
      auto que0 = que;
      bool ok = true;
      for (int f = e; f--; ) {
        if (que0.empty()) {
          break;
        }
        const U x = que0.top();
        que0.pop();
        if (x >= U{1} << (f + 1)) {
          ok = false;
          break;
        } else if (x & U{1} << f) {
          que0.push(x ^ U{1} << f);
        }
        if (que0.empty()) {
          break;
        }
        if (que0.top() >= U{1} << f) {
          ok = false;
          break;
        }
      }
      if (!que0.empty() && que0.top()) {
        ok = false;
      }
      if (!ok) {
        val |= U{1} << e;
        const U x = que.top();
        que.pop();
        if (x & U{1} << e) {
          que.push(x ^ U{1} << e);
        }
      }
    }
  }
// cerr<<u<<" "<<p<<": "<<(Int)val<<endl;
  mem[u][p] = true;
  return cache[u][p] = make_pair(sz, val);
}

int Ask(int u, int v) {
  printf("? %d %d\n", u + 1, v + 1);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  --res;
  return res;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N - 1; ++i) {
    scanf("%d%d", &A[i], &B[i]);
    --A[i];
    --B[i];
  }
  
  for (int i = 0; i < N - 1; ++i) {
    G[A[i]].push_back(i);
    G[B[i]].push_back(i);
  }
  
  int r = 0;
  for (; ; ) {
    fill(uf, uf + N, -1);
    for (int i = 0; i < N - 1; ++i) {
      if (!del[i]) {
        connect(A[i], B[i]);
      }
    }
    memset(mem, 0, sizeof(mem));
    int im = -1;
    int mn = N;
    for (int i = 0; i < N - 1; ++i) {
      if (!del[i] && root(r) == root(A[i])) {
        const auto resA = solve(A[i], B[i]);
        const auto resB = solve(B[i], A[i]);
        const U val = resA.second | resB.second;
        int cost = -1;
        for (int e = max(resA.first, resB.first); e--; ) {
          if (val & U{1} << e) {
            cost = e;
            break;
          }
        }
        if (chmin(mn, cost)) {
          im = i;
        }
      }
    }
    if (im == -1) {
      printf("! %d\n", r + 1);
      fflush(stdout);
      break;
    }
    r = Ask(A[im], B[im]);
    del[im] = true;
  }
  
  return 0;
}