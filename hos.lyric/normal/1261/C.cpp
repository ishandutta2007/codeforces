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

char buf[1000010];

int M, N;
vector<string> A;

vector<vector<int>> sum, f, g;

bool check(int w) {
// cerr<<"check "<<w<<endl;
  f.assign(M, vector<int>(N, 0));
  g.assign(M + 1, vector<int>(N + 1, 0));
  for (int x = 0; x < M; ++x) for (int y = 0; y < N; ++y) {
    if (0 <= x - w && x + w < M && 0 <= y - w && y + w < N) {
      if (sum[x - w][y - w] - sum[x - w][y + w + 1] - sum[x + w + 1][y - w] + sum[x + w + 1][y + w + 1] == 0) {
        f[x][y] = 1;
        ++g[x - w][y - w];
        --g[x - w][y + w + 1];
        --g[x + w + 1][y - w];
        ++g[x + w + 1][y + w + 1];
      }
    }
  }
  for (int x = 0; x <= M; ++x) {
    for (int y = 0; y < N; ++y) {
      g[x][y + 1] += g[x][y];
    }
  }
  for (int x = 0; x < M; ++x) {
    for (int y = 0; y <= N; ++y) {
      g[x + 1][y] += g[x][y];
    }
  }
  for (int x = 0; x < M; ++x) for (int y = 0; y < N; ++y) {
    if ((A[x][y] == '.') != (g[x][y] == 0)) {
      return false;
    }
  }
  return true;
}

int main() {
  for (; ~scanf("%d%d", &M, &N); ) {
    A.resize(M);
    for (int x = 0; x < M; ++x) {
      scanf("%s", buf);
      A[x] = buf;
    }
    
    sum.assign(M + 1, vector<int>(N + 1, 0));
    for (int x = 0; x < M; ++x) for (int y = 0; y < N; ++y) {
      sum[x + 1][y + 1] = sum[x + 1][y] + sum[x][y + 1] - sum[x][y] + ((A[x][y] == '.') ? 1 : 0);
    }
    int lo = 0, hi = (min(M, N) - 1) / 2 + 1;
    for (; lo + 1 < hi; ) {
      const int mid = (lo + hi) / 2;
      (check(mid) ? lo : hi) = mid;
    }
    check(lo);
    printf("%d\n", lo);
    for (int x = 0; x < M; ++x) {
      for (int y = 0; y < N; ++y) {
        putchar(f[x][y] ? 'X' : '.');
      }
      puts("");
    }
  }
  return 0;
}