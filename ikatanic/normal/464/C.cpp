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

const int MAXN = 500100;
const int mod = 1e9 + 7;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int mul(int a, int b) {
  return (llint(a)*b)%mod;
}

char s[MAXN];
char *t[MAXN];
int d[MAXN], len[MAXN];
int f[MAXN][10];
int fpw[MAXN][10];
int n;

int main(void) {
  scanf("%s", s+3);
  scanf("%d", &n); n++;

  t[0] = s;
  d[0] = 0;
  int cur = len[0] = 3+strlen(s+3);
  
  FOR(i, 1, n) {
    t[i] = s + cur;
    scanf("%s", t[i]);
    cur += len[i] = strlen(t[i]);
    d[i] = t[i][0] - '0';
  }

  REP(j, 10) 
    f[n][j] = j, fpw[n][j] = 10;

  for (int i = n-1; i >= 0; --i)
    REP(j, 10) 
      if (d[i] != j) f[i][j] = f[i+1][j], fpw[i][j] = fpw[i+1][j]; else {
        f[i][j] = 0, fpw[i][j] = 1;
        for (int k = len[i]-1; k >= 3; --k) {
          int x = t[i][k] - '0';
          f[i][j] = add(f[i][j], mul(fpw[i][j], f[i+1][x]));
          fpw[i][j] = mul(fpw[i][j], fpw[i+1][x]);
        }
      }
  
  printf("%d\n", f[0][0]);
  return 0;
}