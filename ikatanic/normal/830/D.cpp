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

const int MAX = 444;
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

int f[MAX][MAX];

int solve(int n, int k) {
  int& ref = f[n][k];
  if (ref != -1) return ref;
  if (k == 0) return ref = 1;
  if (n == 1) return ref = (k == 1 ? 1 : 0);

  // n >= 2
  ref = 0;
  REP(a, k+2) { // koliko puteva iz lijevog uzimam
    // root je dodatni put
    if (a < k) {
      ref = add(ref, mul(solve(n-1, a), solve(n-1, k-a-1)));
    }

    // nakaim se na poetak kraj nekog od puteva
    if (a <= k) {
      ref = add(ref, mul(2*k, mul(solve(n-1, a), solve(n-1, k-a))));
    }
    
    // spojim jedan put iz lijevog i jedan iz desnog
    if (k+1-a >= 1 && a >= 1) {
      ref = add(ref, mul(2*a*(k+1-a), mul(solve(n-1, a), solve(n-1, k+1-a))));
    }
    
    // spojim dva iz lijevog
    if (a >= 2) {
      ref = add(ref, mul(a*(a-1), mul(solve(n-1, a), solve(n-1, k+1-a))));
    }
    
    // spojim dva iz desnog
    if (k+1-a >= 2) {
      ref = add(ref, mul((k+1-a)*(k-a), mul(solve(n-1, a), solve(n-1, k+1-a))));
    }

    // ne napravim nita
    if (a <= k) {
      ref = add(ref, mul(solve(n-1, a), solve(n-1, k-a)));
    }
  }
  return ref;
}

int main(void) {
  memset(f, -1, sizeof(f));

  int n;
  scanf("%d", &n);
  printf("%d\n", solve(n, 1));
  return 0;
}