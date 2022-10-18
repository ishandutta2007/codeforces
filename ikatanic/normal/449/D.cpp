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

const int mod = 1e9 + 7;
const int MAXN = 1<<20;

int a[MAXN];
int f[MAXN];
int nf[MAXN];
int pw[MAXN];

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int main(void) {
  pw[0] = 1;
  REP(i, MAXN-1)
    pw[i+1] = add(pw[i], pw[i]);

  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", a+i);
  
  REP(i, n) f[a[i]]++;

  REP(j, 20) {
    REP(i, MAXN) nf[i] = f[i];
    REP(i, MAXN)
      if (i&(1<<j)) f[i^(1<<j)] = add(f[i^(1<<j)], nf[i]);
  }

  int ans = 0;
  REP(s, MAXN) {
    int cnt = 0;
    REP(i, 20)
      if (s&(1<<i)) cnt++;
    
    if (cnt&1) ans = (ans - pw[f[s]] + mod)%mod; else
      ans = add(ans, pw[f[s]]);
  }

  printf("%d\n", ans);
  return 0;
}