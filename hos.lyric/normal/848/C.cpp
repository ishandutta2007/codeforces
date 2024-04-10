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

int N, Q;
vector<int> A;
vector<int> T, L, R;

int main() {
  for (; ~scanf("%d%d", &N, &Q); ) {
    A.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
      --A[i];
    }
    T.resize(Q);
    L.resize(Q);
    R.resize(Q);
    for (int q = 0; q < Q; ++q) {
      scanf("%d%d%d", &T[q], &L[q], &R[q]);
      if (T[q] == 1) {
        --L[q];
        --R[q];
      } else {
        --L[q];
      }
    }
    
    vector<Int> ans(Q, 0);
    for (int phase = 0; phase < 2; ++phase) {
      vector<set<Int>> ss(N);
      for (int a = 0; a < N; ++a) {
        ss[a].insert(-1);
        ss[a].insert(N);
      }
      for (int i = 0; i < N; ++i) {
        ss[A[i]].insert(i);
      }
      vector<int> poss(N, N);
      vector<int> nxt(N);
      for (int i = N; i--; ) {
        nxt[i] = poss[A[i]];
        poss[A[i]] = i;
      }
      
      vector<unordered_map<int, Int>> bits(N);
      auto add = [&](int i, int j, Int val) {
// cerr<<"add "<<i<<" "<<j<<" "<<val<<endl;
        for (int ii = i; ii < N; ii |= ii + 1) {
          for (int jj = j; jj <= N; jj |= jj + 1) {
            bits[ii][jj] += val;
          }
        }
      };
      auto calc = [&](int i, int j) {
        Int ret = 0;
        for (int ii = i - 1; ii >= 0; ii = (ii & (ii + 1)) - 1) {
          for (int jj = j - 1; jj >= 0; jj = (jj & (jj + 1)) - 1) {
            auto it = bits[ii].find(jj);
            if (it != bits[ii].end()) {
              ret += it->second;
            }
          }
        }
        return ret;
      };
      auto update = [&](int i, int j) {
        const Int val = (phase == 0) ? i : -(N - 1 - i);
        add(i, N - nxt[i], -val);
        nxt[i] = j;
        add(i, N - nxt[i], +val);
      };
      
      for (int i = 0; i < N; ++i) {
        add(i, N - nxt[i], (phase == 0) ? i : -(N - 1 - i));
      }
      auto as = A;
      for (int q = 0; q < Q; ++q) {
// cerr<<"as = ";pv(as.begin(),as.end());
// cerr<<"nxt = ";pv(nxt.begin(),nxt.end());
// cerr<<"q = "<<q<<endl;
        if (T[q] == 1) {
          const int i = L[q];
          {
            auto it = ss[as[i]].find(i);
            auto itL = it; --itL;
            auto itR = it; ++itR;
            if (*itL != -1) {
              update(*itL, *itR);
            }
            ss[as[i]].erase(it);
          }
          as[i] = R[q];
          {
            auto it = ss[as[i]].insert(i).first;
            auto itL = it; --itL;
            auto itR = it; ++itR;
            if (*itL != -1) {
              update(*itL, i);
            }
            update(i, *itR);
          }
        } else {
          // L[q] <= i < R[q] && R[q] <= j
          ans[q] -= calc(L[q], N - R[q] + 1);
          ans[q] += calc(R[q], N - R[q] + 1);
        }
      }
      
      reverse(A.begin(), A.end());
      for (int i = 0; i < Q; ++i) {
        if (T[i] == 1) {
          L[i] = N - 1 - L[i];
        } else {
          L[i] = N - L[i];
          R[i] = N - R[i];
          swap(L[i], R[i]);
        }
      }
    }
    
    for (int q = 0; q < Q; ++q) {
      if (T[q] == 2) {
        printf("%lld\n", ans[q]);
      }
    }
  }
  return 0;
}