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


#ifdef LOCAL
constexpr int SMALL = 10;
#else
constexpr int SMALL = 400;
#endif

int N, M;
vector<int> X, Y;
vector<int> O, K;

int fss[SMALL + 10][SMALL + 10];

int main() {
  for (; ~scanf("%d%d", &N, &M); ) {
    X.resize(N);
    Y.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d%d", &X[i], &Y[i]);
      chmin(X[i], M);
      chmin(Y[i], M);
    }
    O.resize(M);
    K.resize(M);
    for (int m = 0; m < M; ++m) {
      scanf("%d%d", &O[m], &K[m]);
      --K[m];
    }
    
    vector<int> added(N, -1);
    memset(fss, 0, sizeof(fss));
    vector<int> gs(M, 0);
    int all = 0, now = 0;
    for (int m = 0; m < M; ++m) {
      for (int z = 1; z <= SMALL; ++z) {
        now += fss[z][m % z];
      }
      now += gs[m];
      
      {
        const int i = K[m];
        const int z = X[i] + Y[i];
        if (O[m] == 1) {
          ++all;
          added[i] = m;
          if (z <= SMALL) {
            fss[z][added[i] % z] += 1;
            fss[z][(added[i] + X[i]) % z] -= 1;
          } else {
            for (int t = added[i]; t < M; t += z) {
              gs[t] += 1;
              if (t + X[i] < M) {
                gs[t + X[i]] -= 1;
              }
            }
          }
          if ((m - added[i]) % z < X[i]) {
            ++now;
          }
        } else {
          if (z <= SMALL) {
            fss[z][added[i] % z] -= 1;
            fss[z][(added[i] + X[i]) % z] += 1;
          } else {
            for (int t = added[i]; t < M; t += z) {
              gs[t] -= 1;
              if (t + X[i] < M) {
                gs[t + X[i]] += 1;
              }
            }
          }
          if ((m - added[i]) % z < X[i]) {
            --now;
          }
          --all;
          added[i] = -1;
        }
      }
// cerr<<"fss[2] = ";pv(fss[2],fss[2]+2);
// cerr<<"gs = ";pv(gs.begin(),gs.end());
// cerr<<"all = "<<all<<", now = "<<now<<endl;
      printf("%d\n", all - now);
    }
  }
  return 0;
}