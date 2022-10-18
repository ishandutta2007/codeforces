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

const int MAXN = 1001000;

const int mod = 1e9 + 7;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int sub(int a, int b) {
  return a < b ? a-b+mod : a-b;
}

int mul(int a, int b) {
  return (llint(a)*b)%mod;
}

int g[MAXN];
int sumg[MAXN];
int sumgL[MAXN];
int sumgLL[MAXN];

int phi[MAXN];
int fact[MAXN];

int main(void) {
  phi[1] = 1;
  for (int i = 2; i < MAXN; ++i) {
    if (fact[i] == 0) {
      if (llint(i)*i < MAXN)
        for (int j = i*i; j < MAXN; j += i)
          fact[j] = i;
      phi[i] = i-1;
    } else {
      int x = i;
      while (x%fact[i] == 0) x /= fact[i];
      if (x == 1) phi[i] = fact[i] * phi[i / fact[i]]; else
        phi[i] = phi[x] * phi[i / x];
    }
  }
  
  int sum = 0, sumsq = 0;
  FOR(L, 1, MAXN) {
    sum = add(sum, L);
    sumsq = add(sumsq, mul(L, L));
    
    int sumgcd = 0;
    for (int i = 1; i*i <= L; ++i)
      if (L%i == 0) {
        sumgcd = add(sumgcd, mul(i, phi[L/i]));
        if (i*i != L) sumgcd = add(sumgcd, mul(L/i, phi[i]));
      }
    
    g[L] = 0;
    g[L] = add(g[L], mul(mul(L, L), L));
    g[L] = sub(g[L], mul(2*L, L));
    g[L] = sub(g[L], mul(2*L, sum));
    g[L] = add(g[L], mul(2, sumsq));
    g[L] = add(g[L], mul(2, sumgcd));

    sumg[L] = add(sumg[L-1], g[L]);
    sumgL[L] = add(sumgL[L-1], mul(L, g[L]));
    sumgLL[L] = add(sumgLL[L-1], mul(mul(L, L), g[L]));
  }
  
  int t;
  scanf("%d", &t);
  while (t--) {
    int N, M;
    scanf("%d %d", &N, &M);
    if (N > M) swap(N, M);

    int ans = 0;
    ans = add(ans, mul(mul(N+1, M+1), sumg[N]));
    ans = sub(ans, mul(N+1+M+1, sumgL[N]));
    ans = add(ans, sumgLL[N]);

    printf("%d\n", ans);
  }
  
  return 0;
}