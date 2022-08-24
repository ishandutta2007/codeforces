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

int H, G;
vector<Int> A;

Int ans;
vector<int> us;

vector<int> sz0, sz1;
vector<Int> as;
vector<pair<int, Int>> saves;

bool proc(int u, int d) {
  const int uL = u << 1;
  const int uR = u << 1 | 1;
  --sz0[u];
  saves.emplace_back(u, as[u]);
  if (as[uL] == 0 && as[uR] == 0) {
    as[u] = 0;
    return (d >= G);
  } else {
    if (as[uL] > as[uR]) {
      as[u] = as[uL];
      return proc(uL, d + 1);
    } else {
      as[u] = as[uR];
      return proc(uR, d + 1);
    }
  }
}

void solve(int u, int d) {
  if (d >= H) {
    return;
  }
// cerr<<"solve "<<u<<" "<<d<<"; "<<sz0[u]<<" -> "<<sz1[u]<<endl;
  for (; sz0[u] > sz1[u]; ) {
    saves.clear();
    const int top = as[u];
    const bool res = proc(u, d);
// cerr<<"  ";pv(as.begin(),as.end());
    if (res) {
      ans -= top;
      us.push_back(u);
    } else {
      for (const auto &save : saves) {
        ++sz0[save.first];
        as[save.first] = save.second;
      }
// cerr<<"  ";pv(as.begin(),as.end());
      solve(u << 1, d + 1);
      solve(u << 1 | 1, d + 1);
      return;
    }
  }
}

int main() {
  int numCases;
  for (; ~scanf("%d", &numCases); ) {
    for (int caseId = 0; caseId < numCases; ++caseId) {
      scanf("%d%d", &H, &G);
      A.assign(1 << H, 0);
      for (int u = 1; u < 1 << H; ++u) {
        scanf("%lld", &A[u]);
      }
      
      ans = 0;
      for (int u = 1; u < 1 << H; ++u) {
        ans += A[u];
      }
      us.clear();
      sz0.assign(1 << (H + 1), 0);
      sz1.assign(1 << (H + 1), 0);
      for (int u = 1 << H; --u; ) {
        sz0[u] = 1 + sz0[u << 1] + sz0[u << 1 | 1];
      }
      for (int u = 1 << G; --u; ) {
        sz1[u] = 1 + sz1[u << 1] + sz1[u << 1 | 1];
      }
      as.assign(1 << (H + 1), 0);
      copy(A.begin(), A.end(), as.begin());
      solve(1, 0);
      
      printf("%lld\n", ans);
      for (size_t i = 0; i < us.size(); ++i) {
        if (i > 0) printf(" ");
        printf("%d", us[i]);
      }
      puts("");
    }
  }
  return 0;
}