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

const int MAX = 3500;
const int mod = 1e9 + 7;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int sub(int a, int b) {
  return a < b ? a-b+mod : a-b;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

inline void addd(int& a,int b) {
  a = add(a, b);
}

char A[MAX];
int s[MAX];
int f[MAX][2][2];
int nf[MAX][2][2];

int divv(char* A, int len, int p, int& q) {
  int n = 0;
  llint cur = 0;
  REP(i, len) {
    cur = cur * 10 + A[i];
    if (n > 0 || cur >= p) {
      A[n++] = cur / p;
      cur %= p;
    }
  }
  q = cur;
  return n;
}

inline int calc(int p, int r) {
  if (r < 0) return 0;
  int hi = min(p-1, r);
  int L = min(hi, max(-1, r+1-p));
  llint ans = 1LL*p*(L+1);
  if (L < hi) {
    ans += 1LL*(hi-L)*(r+1);
    ans -= (hi*1LL*(hi+1) - L*1LL*(L+1))/2;
  }
  return ans % mod;
}

int main(void) {
  int p, alpha;
  scanf("%d %d", &p, &alpha);
  scanf("%s", A);
  //p = 2;
  //  alpha = 32000;
  //  REP(i, 1000) A[i] = rand() % 10 + '0';
  //  A[1000] = '\0';

  int len = strlen(A);
  REP(i, len) A[i] -= '0';

  int n = 0;
  while (len > 0) len = divv(A, len, p, s[n++]);

  f[0][0][0] = 1;
  REP(i, n) {
    REP(j, i+1) REP(gt, 2) REP(cr, 2) nf[j][gt][cr] = 0;
    REP(j, i+1) REP(gt, 2) REP(cr, 2) {
      int cur = f[j][gt][cr];
      if (cur == 0) continue;

      int B0 = calc(p, -cr+s[i]-1);
      int C0 = calc(p, -cr+s[i]);
      int D0 = calc(p, p-1-cr);
      int B1 = calc(p, p-cr+s[i]-1);
      int C1 = calc(p, p-cr+s[i]);
      int D1 = calc(p, p+p-1-cr);

      addd(nf[j][0][0], mul(cur, B0));
      addd(nf[j][gt][0], mul(cur, sub(C0, B0)));
      addd(nf[j][1][0], mul(cur, sub(D0, C0)));
      addd(nf[j+1][0][1], mul(cur, sub(B1, D0)));
      addd(nf[j+1][gt][1], mul(cur, sub(C1, B1)));
      addd(nf[j+1][1][1], mul(cur, sub(D1, C1)));
    }
    REP(j, i+2) REP(gt, 2) REP(cr, 2) f[j][gt][cr] = nf[j][gt][cr];
  }

  int ans = 0;
  FOR(j, alpha, n+1)
    ans = add(ans, f[j][0][0]);
  printf("%d\n", ans);
  return 0;
}