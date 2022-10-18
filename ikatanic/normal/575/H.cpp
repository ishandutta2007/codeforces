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
const int MAX = 2001000;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

int mul(int a, int b) {
  return llint(a)*b % mod;
}

int powmod(int a, int b) {
  if (b == 0) return 1;
  if (b&1) return mul(a, powmod(a, b-1));
  return powmod(mul(a, a), b/2);
}

int fact[MAX], invfact[MAX];

int choose(int n, int k) {
  return mul(fact[n], mul(invfact[k], invfact[n-k]));
}

int main(void) {
  fact[0] = invfact[0] = 1;
  FOR(i, 1, MAX)
    fact[i] = mul(fact[i-1], i);

  invfact[MAX-1] = powmod(fact[MAX-1], mod-2);
  for (int i = MAX-2; i >= 0; --i)
    invfact[i] = mul(invfact[i + 1], i + 1);

  int N;
  scanf("%d", &N);

  int inv2 = powmod(2, mod-2);
  int cur = choose(2*N, N);
  int ans = cur;

  for (int n = 2*N - 1; n > N; --n) {
    int a = n - N, b = N;
    cur = add(cur, choose(n, a));
    cur = add(cur, choose(n, b));
    cur = mul(cur, inv2);
    ans = add(ans, cur);
  }
  
  ans = add(ans, powmod(2, N+1));
  ans = sub(ans, 1);
  printf("%d\n", ans);
  return 0;
}