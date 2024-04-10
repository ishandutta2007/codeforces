#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int T = 1e6;
const int K = 6;

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

int digit[T][K];
int pw[K];
int cnt[T];

int f[T], fs[T], fss[T], g[T];
int pw2[T];

int main(void) {
  REP(i, T) {
    int x = i;
    REP(j, K) {
      digit[i][j] = x % 10;
      x /= 10;
    }
  }

  pw[0] = 1;
  FOR(i, 1, K) pw[i] = pw[i-1] * 10;

  pw2[0] = 1;
  FOR(i, 1, T) pw2[i] = mul(pw2[i-1], 2);
              
  int n;
  scanf("%d", &n);
  REP(i, n) {
    int x;
    scanf("%d", &x);
    cnt[x]++;
  }

  for (int x = T-1; x >= 0; --x) {
    f[x] = cnt[x];
    fs[x] = mul(x, cnt[x]);
    fss[x] = mul(x, mul(x, cnt[x]));
    
    FOR(k, 1, 1<<K) {
      bool ok = true;
      int parity = 0;
      int y = x;
      REP(i, K) {
        if (k & (1<<i)) {
          parity ^= 1;
          if (digit[x][i] < 9) {
            y += pw[i];
          } else {
            ok = false;
            break;
          }
        }
      }
      
      if (ok) {
        if (!parity) {
          fss[x] = sub(fss[x], fss[y]);
          fs[x] = sub(fs[x], fs[y]);
          f[x] = sub(f[x], f[y]);
        } else {
          fss[x] = add(fss[x], fss[y]);
          fs[x] = add(fs[x], fs[y]);
          f[x] = add(f[x], f[y]);
        }          
      }
    }
  }
  
  REP(x, T) {
    int total = 0;
    if (f[x] > 0) {
      total = add(total, mul(fss[x], pw2[f[x] - 1]));
    }
    if (f[x] > 1) {
      total = add(total, mul(sub(mul(fs[x], fs[x]), fss[x]), pw2[f[x] - 2]));
    }
    f[x] = total;
  }
  

  
  for (int x = T-1; x >= 0; --x) {
    g[x] = f[x];
    FOR(k, 1, 1<<K) {
      bool ok = true;
      int parity = 0;
      int y = x;
      REP(i, K) {
        if (k & (1<<i)) {
          parity ^= 1;
          if (digit[x][i] < 9) {
            y += pw[i];
          } else {
            ok = false;
            break;
          }
        }
      }
      
      if (ok) {
        if (!parity) {
          g[x] = add(g[x], f[y]);
        } else {
          g[x] = sub(g[x], f[y]);
        }          
      }
    }
  }


  llint ret = 0;
  REP(i, T) {
    ret ^= i * 1LL * g[i];
  }

  printf("%lld\n", ret);
  return 0;
}