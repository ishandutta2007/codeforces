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


int uf[110];
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
char A[110][110][110];

vector<int> par;
int dist[110][110];

bool check() {
  for (int u = 0; u < N; ++u) for (int v = 0; v < N; ++v) {
    dist[u][v] = (u == v) ? 0 : N;
  }
  for (int u = 1; u < N; ++u) {
    const int p = par[u];
    dist[p][u] = dist[u][p] = 1;
  }
  for (int w = 0; w < N; ++w) for (int u = 0; u < N; ++u) for (int v = 0; v < N; ++v) {
    chmin(dist[u][v], dist[u][w] + dist[w][v]);
  }
  for (int u = 0; u < N; ++u) for (int v = u + 1; v < N; ++v) {
    for (int w = 0; w < N; ++w) {
      if ((A[u][v][w] != '0') != (dist[u][w] == dist[v][w])) {
        return false;
      }
    }
  }
  return true;
}

bool attempt(const vector<int> &us) {
  for (const int u : us) {
    for (int v = 0; v < N; ++v) if (A[0][u][v] != '0') {
      return false;
    }
  }
  
  queue<int> que;
  par.assign(N, -1);
  par[0] = -2;
  for (const int u : us) {
    par[u] = 0;
    que.push(u);
  }
  for (; !que.empty(); ) {
    const int u = que.front();
    que.pop();
    const int p = par[u];
    for (int v = 0; v < N; ++v) if (!~par[v] && A[p][v][u] != '0') {
      par[v] = u;
      que.push(v);
    }
  }
  
  for (int u = 1; u < N; ++u) {
    if (!~par[u]) {
      return false;
    }
  }
  const bool res = check();
  return res;
}

bool solve() {
  fill(uf, uf + N, -1);
  for (int u = 1; u < N; ++u) for (int v = u + 1; v < N; ++v) {
    if (A[u][v][0] != '0') {
      connect(u, v);
    }
  }
  vector<vector<int>> uss(N);
  for (int u = 0; u < N; ++u) {
    uss[root(u)].push_back(u);
  }
  
  for (int r = 1; r < N; ++r) if (uf[r] < 0) {
    const bool res = attempt(uss[r]);
    if (res) {
      puts("Yes");
      for (int u = 1; u < N; ++u) {
        const int p = par[u];
        printf("%d %d\n", p + 1, u + 1);
      }
      return true;
    }
  }
  return false;
}

int main() {
  for (int numCases; ~scanf("%d", &numCases); ) for (; numCases--; ) {
    scanf("%d", &N);
    for (int u = 0; u < N; ++u) for (int v = u + 1; v < N; ++v) {
      scanf("%s", A[u][v]);
      copy(A[u][v], A[u][v] + N, A[v][u]);
    }
    
    const bool res = solve();
    if (!res) {
      puts("No");
    }
  }
  return 0;
}