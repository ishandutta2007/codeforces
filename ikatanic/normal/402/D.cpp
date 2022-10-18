#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

#include <set>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 5005;
const int MAX = 1.e9;

int a[MAXN];
int g[MAXN];
int ca[MAXN], cg[MAXN];
int bad[MAXN];
int prime[MAXN];
int n, m, n_primes;

int gcd(int a, int b) { return !b ? a : gcd(b, a%b); }

int isGood(int prime) {
  return !binary_search(bad, bad+m, prime);
}

int calc(int x) {
  int ans = 0;
  REP(i, n_primes)
    while (x%prime[i] == 0) {
      if (isGood(prime[i])) ans++; else
        ans--;
      x /= prime[i];
    }
  if (x > 1) {
    if (isGood(x)) ans++; else
      ans--;
  }
  return ans;
}

int main(void) {
  for (int i = 2; i*i <= MAX; ++i) {
    bool ok = true;
    for (int j = 2; j*j <= i; ++j)
      if (i%j == 0) { ok = false; break; }
    if (ok) prime[n_primes++] = i;
  }

  scanf("%d %d", &n, &m);
  REP(i, n) {
    scanf("%d", a+i);
    if (i > 0) g[i] = gcd(g[i-1], a[i]); else
      g[i] = a[i];
  }
  REP(i, m) scanf("%d", bad+i);
  
  int ans = 0;
  REP(i, n) {
    ca[i] = calc(a[i]);
    cg[i] = calc(g[i]);
    ans += ca[i];
  }

  g[n] = 1, cg[n] = 0;
  int last = n;
  for (int i = n-1; i >= 0; --i)
    if (cg[i]-cg[last] < 0) ans -= (i+1)*(cg[i]-cg[last]), last = i;
  printf("%d\n", ans);
  return 0;
}