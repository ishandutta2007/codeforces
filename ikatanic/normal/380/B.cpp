#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 1000001;
const int MAXL = 7007;

struct interval {
  int level, left, right;
};

int cnt[MAXN];

vector<interval> e[MAXN];
set<int> S;

bool intersect(int a, int b, int c, int d) {
  return b >= c && d >= a;
}

bool powerOfTwo(int x) {
  return (x - (x&-x)) == 0;
}

int main(void)
{
  cnt[0] = 0;
  for (int pos = 1; pos < MAXN; ++pos)
    if (powerOfTwo(pos)) cnt[pos] = cnt[pos-1] + 2; else
      cnt[pos] = cnt[pos-1] + 1;

  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int tip;
    scanf("%d", &tip);
    
    if (tip == 1) {
      int t, l, r, x;
      scanf("%d %d %d %d", &t, &l, &r, &x);
      S.insert(x);
      e[x].push_back({t, l, r});
    } else {
      int t, v;
      scanf("%d %d", &t, &v);
      
      static int lo[MAXL], hi[MAXL];
      REP(i, t) lo[i] = hi[i] = -1;

      lo[t] = v, hi[t] = v;
      for (int level = t; level < n; ++level) {
        lo[level+1] = cnt[lo[level]-1]+1;
        hi[level+1] = cnt[hi[level]];
      }

      int ans = 0;
      for (int x: S) {
        bool ok = false;
        for (interval lvlInt: e[x])
          if (intersect(lvlInt.left, lvlInt.right, lo[lvlInt.level], hi[lvlInt.level])) {
            ok = true;
            break;
          }
        ans += ok;
      }

      printf("%d\n", ans);
    }
  }
  return 0;
}