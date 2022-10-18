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

int main(void) {
  int hpy, atky, defy;
  int hpm, atkm, defm;
  int h, a, d;
  scanf("%d %d %d", &hpy, &atky, &defy);
  scanf("%d %d %d", &hpm, &atkm, &defm);
  scanf("%d %d %d", &h, &a, &d);
  
  if (hpm == 0) { printf("%d\n", 0); return 0; }

  int ans = 1e9;
  REP(ea, 222) REP(ed, 222) {
    int chp = hpy;
    int catk = atky + ea;
    int cdef = defy + ed;
    
    int dd = max(0, catk - defm);
    if (dd == 0) continue;
    
    int hm = hpm;
    while (hm > 0) hm -= dd, chp -= max(0, atkm - cdef);
    
    int em = max(0, -chp+1);
    ans = min(ans, ea*a + ed*d + em*h);
  }
  printf("%d\n", ans);
  return 0;
}