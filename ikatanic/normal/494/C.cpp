#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 100100;
const int MAXQ = 5050;
const int R = 5010;

struct interval {
  int l, r;
  double p;
  friend bool operator < (const interval &a, const interval &b) {
     if (a.r-a.l != b.r-b.l) return a.r-a.l > b.r-b.l;
      return a.l < b.l;
    }
} s[MAXQ];

int a[MAXN];
int maks[MAXQ];
vector<int> E[MAXN];
double f[MAXQ][MAXQ];
int dad[MAXQ];
int n, q;
  
int main(void) {
  scanf("%d %d", &n, &q);
  REP(i, n) scanf("%d", a+i);
  s[0] = {0, n-1, 1.0};
  q++;
  FOR(i, 1, q) {
    scanf("%d %d %lf", &s[i].l, &s[i].r, &s[i].p);
    --s[i].l, --s[i].r;
  }
  
  sort(s + 1, s + q);

  FOR(i, 1, q) {
    dad[i] = -1;
    REP(j, i)
      if (s[j].l <= s[i].l && s[i].r <= s[j].r) dad[i] = j;
    assert(dad[i] != -1);
    E[dad[i]].push_back(i);
  }
  
  for (int i = q-1; i >= 0; --i) {
    sort(E[i].begin(), E[i].end(), [] (const int &a, const int &b) {
        return s[a].l < s[b].l;
      }
    );
    
    maks[i] = 0;
    int cur = s[i].l;
    for (int j: E[i]) {
      assert(s[j].l >= cur);
      while (cur < s[j].l) maks[i] = max(maks[i], a[cur++]);
      maks[i] = max(maks[i], maks[j]);
      cur = s[j].r + 1;
    }
    while (cur <= s[i].r) maks[i] = max(maks[i], a[cur++]);

    f[i][0] = 1.0;
    for (int j: E[i]) {
      int cur = 0;
      double prob = 0;
      double probi = 0;
      REP(k, R) {
        while (cur < R && maks[j]+cur <= maks[i]+k) prob += f[j][cur++];
        double tmp = f[i][k];

        f[i][k] = prob * f[i][k];
        if (maks[j]+R-1 >= maks[i]+k) f[i][k] += probi * f[j][ maks[i]+k - maks[j] ];
        probi += tmp;
      }
    }

    for (int k = R-1; k >= 0; --k) {
      f[i][k] *= 1 - s[i].p;
      if (k > 0) f[i][k] += f[i][k-1] * s[i].p;
    }
  }

  double ans = -1;
  REP(k, R)
    ans += (maks[0] + k) * f[0][k];
  
  printf("%.9lf\n", ans);
  return 0;
}