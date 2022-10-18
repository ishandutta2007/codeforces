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

llint f[55][110][2];

int main(void) {
  llint s;
  scanf("%lld", &s);
  llint ans = 0;
  REP(la, 50) REP(lb, 50) {
    // s = (2^(la+1) - 1)v + b + (2^(lc+1) - 1)v + c - v
    // s = (2^(la+1) + 2^(lb+1) - 3)v + b + c

    llint k = (1LL<<(la+1)) + (1LL<<(lb+1)) - 3;
    llint v = s / k;
    if (v == 0) continue;

    llint rem = s - v * k;
    int n = max(la, lb);

    llint tmp = rem;
    int rem_log = 0;
    while (tmp) tmp /= 2, rem_log++;
    n = max(n, rem_log + 1);


    REP(P, la+lb+1) {
      REP(i, n+1) REP(p, P+1) REP(c, 2) f[i][p][c] = 0;

      llint nrem = rem + P;
      if (nrem < 0) continue;
      if (nrem & 1) continue;
      
      f[0][0][0] = 1;
      
      REP(i, n) REP(p, P+1) REP(c, 2) {
        if (!f[i][p][c]) continue;
        
        llint bit_need = (nrem >> (i+1)) & 1;
        REP(bit_a, 2) REP(bit_b, 2) {
          if (i >= la && bit_a) continue;
          if (i >= lb && bit_b) continue;
          if (i == la-1 && bit_a) continue;
          if (i == lb-1 && !bit_b) continue;
        
          llint bit_sum = (bit_a + bit_b + c) % 2;
          llint bit_rem = (bit_a + bit_b + c) / 2;

          if (bit_sum == bit_need) {
            f[i+1][p+bit_a+bit_b][bit_rem] += f[i][p][c];
          }
        }
      }
      
      ans += f[n][P][0];
    }
  }

  printf("%lld\n", ans);
  return 0;
}