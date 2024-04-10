#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 30;
const llint inf = 1e18;

struct T {
  llint B, C;
  llint total;
  int mask;
  friend bool operator < (const T& a, const T& b) {
    return make_pair(a.B, a.C) < make_pair(b.B, b.C);
  }
};

int a[MAX], b[MAX], c[MAX];

void rec(int x, int n, llint A, llint B, llint C, int mask, vector<T>& v) {
  if (x == n) {
    v.push_back({B-A, C-B, A, mask});
    return;
  }
  rec(x+1, n, A+a[x], B+b[x], C, mask*3+2, v);
  rec(x+1, n, A+a[x], B, C+c[x], mask*3+1, v);
  rec(x+1, n, A, B+b[x], C+c[x], mask*3+0, v);
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n)
    scanf("%d %d %d", &a[i], &b[i], &c[i]);

  vector<T> vl, vr;
  rec(0, n/2, 0, 0, 0, 0, vl);
  rec(n/2, n, 0, 0, 0, 0, vr);

  sort(vl.begin(), vl.end());

  llint best = -inf;
  int mask1, mask2;
  for (auto t: vr) {
    t.B = -t.B;
    t.C = -t.C;
    auto it = lower_bound(vl.begin(), vl.end(), t);
    if (it != vl.end() && it->B == t.B && it->C == t.C) {

      llint total = t.total + it->total;
      if (total <= best) continue;
      
      best = total;
      mask1 = t.mask;
      mask2 = it->mask;
    }
  }

  if (best != -inf) {
      vector<string> ans;
      for (int i = n-1; i >= n/2; --i) {
        if (mask1 % 3 == 0) ans.push_back("MW");
        if (mask1 % 3 == 1) ans.push_back("LW");
        if (mask1 % 3 == 2) ans.push_back("LM");
        mask1 /= 3;
      }

      for (int i = n/2-1; i >= 0; --i) {
        if (mask2 % 3 == 0) ans.push_back("MW");
        if (mask2 % 3 == 1) ans.push_back("LW");
        if (mask2 % 3 == 2) ans.push_back("LM");
        mask2 /= 3;
      }

      reverse(ans.begin(), ans.end());
      for (auto& s: ans) puts(s.c_str());
      return 0;
  }

  puts("Impossible");

  return 0;
}