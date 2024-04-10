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

constexpr int E = 30;

int N;
vector<int> A;

int main() {
  for (; ~scanf("%d", &N); ) {
    A.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
    }
    
    vector<vector<int>> mxs(E, vector<int>(N));
    mxs[0] = A;
    for (int e = 0; e < E - 1; ++e) {
      mxs[e + 1] = mxs[e];
      for (int i = 0; i + (1 << e) < N; ++i) {
        chmax(mxs[e + 1][i], mxs[e][i + (1 << e)]);
      }
    }
    
    vector<vector<int>> nxt(E, vector<int>(N + 1, N));
    for (int e = 0; e < E; ++e) {
      for (int i = N; i--; ) {
        nxt[e][i] = nxt[e][i + 1];
        if ((A[i] >> e) & 1) {
          nxt[e][i] = i;
        }
      }
    }
    
    Int ans = 0;
    for (int i = 0; i < N; ++i) {
      vector<int> js;
      for (int e = 0; e < E; ++e) {
        js.push_back(nxt[e][i]);
      }
      js.push_back(N);
      sort(js.begin(), js.end());
      js.erase(unique(js.begin(), js.end()), js.end());
// cerr<<"i = "<<i<<endl;
// cerr<<"  js = ";pv(js.begin(),js.end());
      int now = i;
      int mx = -1;
      int val = 0;
      for (const int j : js) {
        // right end: (now, j]
        if (mx < val) {
          for (int e = __lg(j - now); e >= 0; --e) {
            if (now + (1 << e) <= j && mxs[e][now] < val) {
// cerr<<"  ("<<now<<", "<<(now+(1<<e))<<"]"<<endl;
              ans += (1 << e);
              chmax(mx, mxs[e][now]);
              now += (1 << e);
            }
          }
          for (int e = __lg(j - now); e >= 0; --e) {
            if (now + (1 << e) <= j) {
              chmax(mx, mxs[e][now]);
              now += (1 << e);
            }
          }
        }
        if (j == N) {
          break;
        }
        val |= A[j];
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}