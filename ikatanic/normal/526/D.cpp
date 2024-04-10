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

const int MAXN = 1000100;

char s[MAXN];
int z[MAXN];
int f[MAXN];

void calculateZ(char *s, int n) {
  z[0] = n;
  int L = 0, R = 0;
  FOR(i, 1, n) {
    if (i > R) L = i, R = i-1, z[i] = 0; else
      if (z[i-L] < R-i+1) z[i] = z[i-L]; else
        z[i] = R-i+1, L = i;
    while (R+1 < n && s[i + z[i]] == s[z[i]]) R++, z[i]++;
  }
}

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  scanf("%s", s);
  
  calculateZ(s, n);
  
  for (int l = 1; k*l <= n; ++l) {
    bool ok = true;
    REP(i, k)
      if (z[i*l] < l) { ok = false; break; }
    
    if (!ok) continue;

    int pos = k*l-1;
    f[pos]++;
    f[pos+1 + min(l, z[pos+1])]--;
  }
  
  int cur = 0;
  REP(i, n) {
    cur += f[i];
    putchar(cur > 0 ? '1' : '0');
  }
  putchar('\n');
  return 0;
}