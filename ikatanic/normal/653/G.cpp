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

const int MAX = 300300;
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

int powmod(int a, int b) {
  if (b == 0) return 1;
  if (b&1) return mul(a, powmod(a, b-1));
  return powmod(mul(a, a), b/2);
}

int f[MAX];
int invf[MAX];

int a[MAX];
int c[MAX];

int choose(int n, int k) {
  return mul(f[n], mul(invf[k], invf[n-k]));
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", &a[i]);
  
  c[1] = 1;
  for (int i = 2; i*i < MAX; ++i)
    if (!c[i])
      for (int j = i*i; j < MAX; j += i)
        c[j] = i;

  f[0] = invf[0] = 1;
  FOR(i, 1, n) {
    f[i] = mul(f[i-1], i);
    invf[i] = powmod(f[i], mod-2);
  }

  static int pf[MAX];
  pf[0] = 0;
  REP(i, n) pf[i+1] = add(pf[i], choose(n-1, i));
  
  static vector<int> v[MAX];
  REP(i, n) {
    int x = a[i];
    while (x > 1) {
      int p = c[x] ? c[x] : x;
      int cnt = 0;
      while (x % p == 0) x /= p, cnt++;
      v[p].push_back(cnt);
    }
  }

  int ans = 0;
  REP(i, MAX) {
    sort(v[i].begin(), v[i].end());
    int k = n - (int)v[i].size();
    for (int x: v[i]) {
      k++;
      int coef = sub(sub(pf[n], pf[n-k]), pf[n-k+1]);
      ans = add(ans, mul(coef, x));
    }
  }
  
  printf("%d\n", ans);
  return 0;
}