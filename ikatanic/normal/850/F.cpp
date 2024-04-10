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

const int M = 100010;

int f[M];

int main(void) {
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  REP(i, n) scanf("%d", &a[i]);

  int m = accumulate(a.begin(), a.end(), 0);

  f[0] = 0;
  f[1] = mul(mul(m-1, m-1), powmod(m, mod-2));
  FOR(x, 1, M-1) {
    int w = powmod(mul(m, m-1), mod - 2);

    int a = mul(mul(x, m - x), w);
    int b = mul(mul(x, x - 1), w);
    int d = mul(mul(m - x, m - x - 1), w);

    // f(x) = a(1 + f(x+1)) + b(1 + f(x)) + af(x-1) + df(x)
    
    int s = sub(1, add(b, d));
    // sf(x) = a(1 + f(x+1)) + b + af(x-1)
    // f(x+1) = (sf(x) - b - af(x-1) - a) / a
    f[x+1] = mul(sub(mul(s, f[x]), add(b, add(a, mul(a, f[x-1])))), powmod(a, mod-2));
  }

  int ret = 0;
  REP(i, n) ret = add(ret, f[a[i]]);
  printf("%d\n", ret);
  return 0;
}