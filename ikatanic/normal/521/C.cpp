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

const int mod = 1e9 + 7;
const int MAXN = 100100;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

int mul(int a, int b) {
  return (llint(a)*b)%mod;
}

int powmod(int a, int b) {
  if (b == 0) return 1;
  if (b&1) return mul(a, powmod(a, b-1));
  return powmod(mul(a, a), b/2);
}

int f[MAXN], invf[MAXN];
int h[MAXN], sh[MAXN];
char s[MAXN];

int choose(int n, int k) {
  if (n < k) return 0;
  return mul(f[n], mul(invf[k], invf[n-k]));
}

int main(void) {
  f[0] = invf[0] = 1;
  FOR(i, 1, MAXN) {
    f[i] = mul(f[i-1], i);
    invf[i] = powmod(f[i], mod-2);
  }

  int n, k;
  scanf("%d %d", &n, &k); k++;
  scanf("%s", s);
  REP(i, n) s[i] -= '0';

  h[0] = sh[0] = 0;
  REP(i, n) {
    h[i+1] = add(mul(h[i], 10), s[i]);
    sh[i+1] = add(sh[i], h[i+1]);
  }

  if (k == 1) {
    printf("%d\n", h[n]);
    return 0;
  }


  int ans = 0;
  int pw10 = 1;
  for (int len = 1; len < n; ++len) {
    pw10 = mul(pw10, 10);

    int ch = choose(n-len-1, k-2);
    ans = add(ans, mul(h[len], ch));
    ans = add(ans, mul(h[n], ch));
    ans = sub(ans, mul(mul(h[n-len], pw10), ch));
    
    if (len >= n-1 || k < 3) continue;
    
    ch = choose(n-len-2, k-3);
    ans = add(ans, mul(sh[n-1], ch));
    ans = sub(ans, mul(sh[len], ch));

    ans = sub(ans, mul(sh[n-1-len], mul(ch, pw10)));
    ans = add(ans, mul(sh[0], mul(ch, pw10)));
  }

  printf("%d\n", ans);
  return 0;
}