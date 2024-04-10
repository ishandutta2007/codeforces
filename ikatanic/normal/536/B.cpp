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
const int mod = 1e9 + 7;

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
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%s", s);
  int p = strlen(s);
  calculateZ(s, p);

  int last = -1;
  REP(i, m) {
    int x;
    scanf("%d", &x); --x;
    f[x]++, f[x+p]--;
    
    if (last != -1 && last+p > x)
      if (z[x-last] < p-(x-last)) {
        printf("0\n");
        return 0;
      }
    last = x;
  }

  int ans = 1;
  int cur = 0;
  REP(i, n) {
    cur += f[i];
    if (cur == 0) ans = (ans*26LL) % mod;
  }
  printf("%d\n", ans);
    
  return 0;
}