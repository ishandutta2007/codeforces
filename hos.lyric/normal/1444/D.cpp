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

constexpr int MAX_N = 1010;
constexpr int MAX_M = 1000 * 1000 / 2 / 2 + 10;

int N[2];
int A[2][MAX_N];

bitset<MAX_M> dp[MAX_N];
vector<pair<int, int>> ans;

bool solve() {
  if (N[0] != N[1]) {
    return false;
  }
  
  int ls[2] = {};
  vector<int> bsss[2][2];
  for (int h = 0; h < 2; ++h) {
    for (int i = 0; i < N[h]; ++i) {
      ls[h] += A[h][i];
    }
    if (ls[h] % 2 != 0) {
      return false;
    }
    ls[h] /= 2;
    for (int i = 0; i <= N[h]; ++i) {
      dp[i].reset();
    }
    dp[0][0] = true;
    for (int i = 0; i < N[h]; ++i) {
      dp[i + 1] = dp[i] | dp[i] << A[h][i];
    }
    if (!dp[N[h]][ls[h]]) {
      return false;
    }
    int l = ls[h];
    for (int i = N[h]; i--; ) {
      if (dp[i][l]) {
        bsss[h][0].push_back(A[h][i]);
      } else {
        bsss[h][1].push_back(A[h][i]);
        l -= A[h][i];
        assert(dp[i][l]);
      }
    }
    assert(l == 0);
// for(int s=0;s<2;++s){cerr<<h<<" "<<s<<": ";pv(bsss[h][s].begin(),bsss[h][s].end());}
  }
  
  
  if (bsss[0][0].size() > bsss[0][1].size()) {
    swap(bsss[0][0], bsss[0][1]);
  }
  if (bsss[1][0].size() < bsss[1][1].size()) {
    swap(bsss[1][0], bsss[1][1]);
  }
  assert(bsss[0][0].size() <= bsss[1][0].size());
  assert(bsss[0][1].size() >= bsss[1][1].size());
  for (int s = 0; s < 2; ++s) {
    sort(bsss[0][s].begin(), bsss[0][s].end(), greater<int>());
    sort(bsss[1][s].begin(), bsss[1][s].end());
  }
  ans.clear();
  int xs[2] = {};
  for (int j = 0; j < N[0]; ++j) {
    for (int h = 0; h < 2; ++h) {
      ans.emplace_back(xs[0], xs[1]);
      if (j < (int)bsss[h][0].size()) {
        xs[h] += bsss[h][0][j];
      } else {
        xs[h] -= bsss[h][1][j - (int)bsss[h][0].size()];
      }
    }
  }
  assert(xs[0] == 0);
  assert(xs[1] == 0);
// cerr<<"ans = ";pv(ans.begin(),ans.end());
  
  /*
  set<pair<int, int>> ss;
  for (const auto &p : ans) {
    if (!ss.insert(p).second) {
      return false;
    }
  }
  */
  return true;
}

int main() {
  int numCases;
  for (; ~scanf("%d", &numCases); ) {
    for (int caseId = 0; caseId < numCases; ++caseId) {
      for (int h = 0; h < 2; ++h) {
        scanf("%d", &N[h]);
        for (int i = 0; i < N[h]; ++i) {
          scanf("%d", &A[h][i]);
        }
      }
      
      const bool res = solve();
      if (res) {
        puts("Yes");
        for (const auto &p : ans) {
          printf("%d %d\n", p.first, p.second);
        }
      } else {
        puts("No");
      }
    }
  }
  return 0;
}