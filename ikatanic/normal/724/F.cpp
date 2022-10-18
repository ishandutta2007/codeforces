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

int mod;

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

int inv[12];
int f[1010][1010][12];

int main(void) {
  int N, D;
  scanf("%d %d %d", &N, &D, &mod);
  
  if (N <= 2) {
    puts("1");
    return 0;
  }

  for (int i = 1; i <= D; ++i) {
    inv[i] = powmod(i, mod - 2);
  }
  
  int ms = (N-1) / 2;
  REP(i, ms+1) f[0][i][0] = 1;
  for (int n = 1; n <= N; ++n) {
    for (int s = 1; s <= n && s <= ms; ++s) {
      for (int d = 1; d <= D; ++d) {
        int c = s == 1 ? 1 : f[s-1][s-1][D-1];
        int ways = 1;
        REP(k, d+1)
          if (n - k*s >= 0) {
            f[n][s][d] = add(f[n][s][d], mul(ways, f[n - k*s][min(n - k*s, s - 1)][d - k]));
            ways = mul(ways, add(c, k));
            ways = mul(ways, inv[k+1]);
          }
      }
    }
  }
  

  int ans = f[N-1][ms][D];
  if (N % 2 == 0) {
    int w = f[N/2-1][ms][D-1];
    w = mul(w, add(w, 1));
    w = mul(w, (mod + 1) / 2);
    ans = add(ans, w);
  }
  
  printf("%d\n", ans);
  return 0;
}