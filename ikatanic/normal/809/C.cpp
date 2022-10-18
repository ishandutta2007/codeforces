#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int B = 32;

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

int fc[B+1][2][2][2];
int fs[B+1][2][2][2];

int f(llint x, llint y, llint k) {
  if (x < 0 || y < 0) return 0;
  
  // i <= x, j <= y, i^j <= k
  
  vector<int> X(B), Y(B), K(B);
  REP(i, B) {
    X[i] = (x >> (B-i-1)) & 1;
    Y[i] = (y >> (B-i-1)) & 1;
    K[i] = (k >> (B-i-1)) & 1;
  }

  REP(i, B+1) REP(gx, 2) REP(gy, 2) REP(gk, 2) {
    fc[i][gx][gy][gk] = 0;
    fs[i][gx][gy][gk] = 0;
  }

  fc[0][0][0][0] = 1;
  fs[0][0][0][0] = 0;
  REP(i, B) REP(gx, 2) REP(gy, 2) REP(gk, 2) {
    int c = fc[i][gx][gy][gk];
    int s = fs[i][gx][gy][gk];
    
    REP(bx, 2) REP(by, 2) {
      if (gx || (bx <= X[i])) {
        if (gy || (by <= Y[i])) {
          int bk = bx ^ by;
          if (gk || bk <= K[i]) {
            int ngx = gx || bx < X[i];
            int ngy = gy || by < Y[i];
            int ngk = gk || bk < K[i];
            fc[i+1][ngx][ngy][ngk] = add(fc[i+1][ngx][ngy][ngk], c);
            fs[i+1][ngx][ngy][ngk] = add(fs[i+1][ngx][ngy][ngk], add(s, mul(c, ((bk * 1LL) << (B-i-1)) % mod)));
          }
        }
      }
    }
  }

  int ret = 0;
  REP(gx, 2) REP(gy, 2) REP(gk, 2) {
    ret = add(ret, fc[B][gx][gy][gk]);
    ret = add(ret, fs[B][gx][gy][gk]);
  }
  return ret;
}

int main(void) {
  int q;
  scanf("%d", &q);
  while (q--) {
    int x1, y1, x2, y2, k;
    scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &k);
    --x1, --y1, --x2, --y2, --k;

    int ans = 0;
    ans = add(ans, f(x2, y2, k));
    ans = sub(ans, f(x1-1, y2, k));
    ans = sub(ans, f(x2, y1-1, k));
    ans = add(ans, f(x1-1, y1-1, k));
    printf("%d\n", ans);
  }
  return 0;
}