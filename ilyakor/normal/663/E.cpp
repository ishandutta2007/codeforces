#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <functional>
#include <sstream>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

template<class T> T abs(T x) { return x >= 0 ? x : -x; }
template<class T> T sqr(T x) { return x * x; }

const int K = 13;
const int maxn = 20;
const int maxm = 110 * 1000;

int n, m;
int a[maxm];
int d[1 << (maxn - K)][K + 1];

int popc[1 << K];

int main() {
  for (int i = 0; i < (1 << K); ++i)
    popc[i] = __builtin_popcount(i);
  cin >> n >> m;
  //n = 20;
  //m = 100 * 1000;
  memset(a, 0, sizeof(a));
  char buf[maxm];
  for (int i = 0; i < n; ++i) {
    scanf("%s", buf);
    for (int j = 0; j < m; ++j)
      if (buf[j] == '1')
        a[j] |= (1 << i);
    //for (int j = 0; j < m; ++j)
    //  if (rand() % 2)
    //    a[j] |= (1 << i);
  }
  int k = min(K, n);
  int rem = n - k;
  int filt = (1 << rem) - 1;
  int pref = (1 << n) - 1;
  pref ^= filt;
  int res = 1000 * 1000 * 100;
  for (int mask1 = 0; mask1 < (1 << k); ++mask1) {
    int M = mask1 << rem;
    memset(d, 0, sizeof(d));
    for (int i = 0; i < m; ++i) {
      int x = ((a[i] & pref) ^ M) >> rem;
      d[a[i] & filt][popc[x]] += 1;//[__builtin_popcount(x)] += 1;
    }

    for (int mask2 = 0; mask2 < (1 << rem); ++mask2) {
      int cur = 0;
      for (int i = 0; i < (1 << rem); ++i) {
        int cnt = popc[mask2 ^ i];//__builtin_popcount(mask2 ^ i);
        for (int j = 0; j <= k; ++j) if (d[i][j]) {
          int val = j + cnt;
          if (val > n - val) val = n - val;
          cur += val * d[i][j];
        }
      }
//      cerr << mask1 << " " << mask2 << " " << cur << "\n";
      if (cur < res) res = cur;
    }
  }
  cout << res << "\n";
  return 0;
}