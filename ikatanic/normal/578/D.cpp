#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 100100;

char s[MAX];
llint f[MAX][3][3][3];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%s", s);
  
  f[0][0][0][0] = 1;
  REP(i, n) {
    vector<char> v = {s[i]};
    if (i > 0) v.push_back(s[i-1]);
    if (i < n-1) v.push_back(s[i+1]);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    REP(da, 3) REP(db, 3) REP(dc, 3) {
      int a = i - da;
      int b = i - db;
      int c = i - dc;
      
      if (a < 0 || b < 0 || c < 0) continue;
      if (f[i][da][db][dc] == 0) continue;
      
      REP(j, (int)v.size()+1) {
        int na = b;
        int nb = max(na, c);
        int nc = nb;
        int koef = m - (int)v.size();

        if (j < (int)v.size()) {
          if (i > 0 && v[j] == s[i-1]) na = max(na, a + 1);
          nb = max(na, c);
          if (v[j] == s[i]) nb = max(nb, b + 1);
          nc = nb;
          if (i+1 < n && v[j] == s[i+1]) nc = max(nc, c + 1);
          koef = 1;
        }

        na = min(2, i+1-na);
        nb = min(2, i+1-nb);
        nc = min(2, i+1-nc);
        
        f[i+1][na][nb][nc] += f[i][da][db][dc] * koef;
      }
    }
  }

  llint ans = 0;
  REP(da, 3) REP(dc, 3) ans += f[n][da][1][dc];
  printf("%lld\n", ans);
  return 0;
}