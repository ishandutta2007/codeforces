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


constexpr Int INF = 1001001001001001001LL;

int N, K;
vector<int> A, B;

vector<vector<int>> G;

using Q = priority_queue<int>;
Q *dfs(int u, int p) {
  Q *ret = new Q{};
  bool leaf = true;
  for (const int i : G[u]) {
    const int v = A[i] ^ B[i] ^ u;
    if (v != p) {
      leaf = false;
      Q *res = dfs(v, u);
      if (ret->size() < res->size()) {
        swap(ret, res);
      }
      for (; !res->empty(); ) {
        const int a = res->top();
        res->pop();
        ret->push(a);
      }
    }
  }
  if (leaf) {
    ret->push(1);
  } else {
    const int a = ret->top();
    ret->pop();
    ret->push(a + 1);
  }
  return ret;
}

int main() {
  for (; ~scanf("%d%d", &N, &K); ) {
    A.resize(N - 1);
    B.resize(N - 1);
    for (int i = 0; i < N - 1; ++i) {
      scanf("%d%d", &A[i], &B[i]);
      --A[i];
      --B[i];
    }
    
    G.assign(N, {});
    for (int i = 0; i < N - 1; ++i) {
      G[A[i]].push_back(i);
      G[B[i]].push_back(i);
    }
    Q *res = dfs(0, -1);
    
    int asLen = 0;
    vector<Int> as(N, 0);
    for (; !res->empty(); ) {
      as[asLen++] = res->top();
      res->pop();
    }
    vector<Int> asSum(N + 1, 0);
    for (Int r = 0; r < N; ++r) {
      asSum[r + 1] = asSum[r] + as[r];
    }
// pv(as.begin(),as.end());
    
    Int ans = -INF;
    for (Int r = 0; r <= K; ++r) {
      const Int B = N - asSum[r];
      Int mn = INF;
      for (const Int b : {0LL, (Int)B, (Int)N / 2, (Int)(N + 1) / 2}) {
        if (0 <= b && b <= B) {
// cerr<<r<<" "<<b<<": "<<(N - r - b) * (r - b)<<endl;
          chmin(mn, (N - r - b) * (r - b));
        }
      }
// cerr<<r<<": "<<mn<<endl;
      chmax(ans, mn);
    }
    
    printf("%lld\n", ans);
  }
  return 0;
}