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

const int MAX = 500500;

int f[MAX];
int a[MAX];
int cnt[MAX];
int u[MAX];
int pr[MAX], kk[MAX];
bool in[MAX];

vector<int> p[MAX];

int calc(int i, int k) {
  int ans = 0;
  int m = (int)p[i].size();
  REP(s, 1<<m) {
    if (s == 0) u[s] = 1; else
      u[s] = u[s ^ (1<<pr[s])] * p[i][ pr[s] ];

    if (k == -1) cnt[u[s]]--;
    ans += k * kk[s] * cnt[u[s]];
    if (k == +1) cnt[u[s]]++;
  }
  return ans;
}

int main(void) {
  for (int i = 2; i*i < MAX; ++i)
    if (!f[i])
      for (int j = i*i; j < MAX; j += i)
        f[j] = i;
  
  kk[0] = 1;
  FOR(i, 1, MAX) {
    kk[i] = 1;
    REP(j, 20)
      if (i & (1<<j)) pr[i] = j, kk[i] *= -1;
  }

  int n, q;
  scanf("%d %d", &n, &q);
  REP(i, n) {
    scanf("%d", a+i);
    int x = a[i];
    while (f[x]) {
      int pr = f[x];
      p[i].push_back(pr);
      while (x % pr == 0) x /= pr;
    }
    if (x > 1) p[i].push_back(x);
  }
  
  llint ans = 0;
  while (q--) {
    int i;
    scanf("%d", &i); --i;
    ans += calc(i, in[i] ? -1 : +1);
    in[i] ^= 1;
    printf("%lld\n", ans);
  }
    
  return 0;
}