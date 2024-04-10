#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 1000100;
const int mod = 1e9 + 7;

int a[MAXN];
int f[MAXN];
int L[MAXN];
int fact[MAXN];
int cnt[MAXN];

int add(int x) {
  for (++x; x < MAXN; x += x&-x)
    L[x]++;
}

int get(int x) {
  int r = 0;
  for (++x; x; x -= x&-x)
    r += L[x];
  return r;
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", a+i); 
    --a[i];
  }

  fact[0] = 1;
  for (int i = 1; i <= n; ++i)
    fact[i] = (llint(fact[i-1])*i)%mod;

  f[1] = 0;
  for (int i = 2; i <= n; ++i) {
    f[i] = (llint(i)*(i-1)/2)%mod;
    f[i] = (llint(f[i])*f[i])%mod;
    f[i] = (llint(f[i])*fact[i-2])%mod;
  }

  cnt[n] = 1;
  for (int i = n-1; i >= 0; --i) {
    cnt[i] = (cnt[i+1] + llint(get(a[i]))*fact[n-i-1])%mod;
    add(a[i]);
  }
  REP(i, n+1) L[i] = 0;

  int ans = 0;
  REP(i, n) {
    int manji = a[i] - get(a[i]);
    ans = (ans + llint(manji)*f[n-i-1])%mod;
    
    int all = (llint(manji)*(manji-1)/2)%mod;
    ans = (ans + llint(all)*fact[n-i-1])%mod;
    ans = (ans + llint(manji)*cnt[i+1])%mod;
    add(a[i]);
  }
  
  printf("%d\n", ans);
  return 0;
}