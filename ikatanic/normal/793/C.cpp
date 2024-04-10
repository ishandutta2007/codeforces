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


llint gcd(llint a, llint b) {
  return !b ? a : gcd(b, a%b);
}

struct frac {
  llint a, b;
  frac (llint _a = 0, llint _b = 1) {
    if (_b < 0) _a = -_a, _b = -_b;
    llint g = gcd(abs(_a), abs(_b));
    a = _a/g, b = _b/g;
  }

  friend frac operator + (const frac &a, const frac &b) {
    return frac(llint(a.a)*b.b + llint(a.b)*b.a, llint(a.b)*b.b);
  }
  friend frac operator * (const frac &a, const frac &b) {
    return frac(llint(a.a)*b.a, llint(a.b)*b.b);
  }
  friend frac operator / (const frac &a, const frac &b) {
    return frac(llint(a.a)*b.b, llint(a.b)*b.a);
  }
  friend frac operator - (const frac &a, const frac &b) {
    return frac(llint(a.a)*b.b - llint(a.b)*b.a, llint(a.b)*b.b);
  }
  friend bool operator < (const frac &a, const frac &b) {
    return llint(a.a)*b.b < llint(b.a)*a.b;
  }
  friend bool operator == (const frac &a, const frac &b) {
    return llint(a.a)*b.b == llint(b.a)*a.b;
  }
  friend bool operator <= (const frac &a, const frac &b) {
    return !(b < a);
  }
};

int main(void) {
  int n;
  scanf("%d", &n);
  llint x1, y1, x2, y2;
  scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);

  frac lo = 0;
  frac hi = 1e6;
  
  REP(i, n) {
    llint rx, ry, vx, vy;
    scanf("%lld %lld %lld %lld", &rx, &ry, &vx, &vy);

    set<frac> ts;
    if (vx != 0) {
      frac t = frac(x1-rx, vx);
      frac y = ry + t * vy;
      if (y1 <= y && y <= y2) ts.insert(t);
      
      t = frac(x2-rx, vx);
      y = ry + t * vy;
      if (y1 <= y && y <= y2) ts.insert(t);
    } else {
      if (rx == x1 || rx == x2) ts.insert(0);
    }

    if (vy != 0) {
      frac t = frac(y1-ry, vy);
      frac x = rx + t * vx;
      if (x1 <= x && x <= x2) ts.insert(t);

      t = frac(y2-ry, vy);
      x = rx + t * vx;
      if (x1 <= x && x <= x2) ts.insert(t);
    } else {
      if (ry == y1 || ry == y2) ts.insert(0);
    }

    if (vy == 0 && (rx == x1 || rx == x2)) {
      puts("-1");
      return 0;
    }
    
    if (vx == 0 && (ry == y1 || ry == y2)) {
      puts("-1");
      return 0;
    }
    
    if (ts.size() == 0) {
      if (vx == 0 && vy == 0) {
        if (x1 < rx && rx < x2 && y1 < ry && ry < y2) {
          continue;
        }
      }
      
      printf("-1\n");
      return 0;
    } else if (ts.size() == 2) {
      frac t1 = max(*ts.begin(), frac(0));
      frac t2 = max(*(++ts.begin()), frac(0));
      lo = max(lo, min(t1, t2));
      hi = min(hi, max(t1, t2));
    } else {
      puts("-1");
      return 0;
    }
  }

  if (lo < hi) {
    printf("%.15lf\n", (double)(lo.a*1.0l / lo.b));
  } else {
    printf("-1\n");
  }
  return 0;
}