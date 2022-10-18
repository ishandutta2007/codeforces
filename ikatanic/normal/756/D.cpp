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

const int MAX = 5050;

const int mod = 1e9 + 7;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

int powmod(int a, int b) {
  if (b == 0) return 1;
  if (b&1) return mul(a, powmod(a, b-1));
  return powmod(mul(a, a), b/2);
}

int f[MAX][MAX];
int g[MAX][MAX];
int last[MAX];
char s[MAX];

int fact[2*MAX], invfact[2*MAX];

int choose(int n, int k) {
  return mul(fact[n], mul(invfact[k], invfact[n-k]));
}

int main(void) {
  fact[0] = invfact[0] = 1;
  FOR(i, 1, MAX) {
    fact[i] = mul(fact[i-1], i);
    invfact[i] = powmod(fact[i], mod-2);
  }
  
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%s", s+1);
  
  f[0][0] = 1;
  g[0][0] = 1;
  
  REP(j, 26) last[j] = -1;
  
  for (int i = 1; i <= n; ++i) {
    int l = last[s[i]-'a'];
    FOR(j, 1, i+1) {
      f[i][j] = sub(g[i-1][j-1], (l >= 0 ? g[l][j-1] : 0));
    }
    REP(j, n+1) g[i][j] = add(g[i-1][j], f[i][j]);
    last[s[i]-'a'] = i;
  }

  int ans = 0;
  FOR(l, 1, n+1) {
    int ways = 0;
    REP(i, n) ways = add(ways, f[i+1][l]);
    ans = add(ans, mul(ways, choose(n-1, l-1)));
  }

  printf("%d\n", ans);
  return 0;
}