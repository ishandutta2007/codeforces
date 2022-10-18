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

const int MAX = 100100;
const llint inf = 4e18;

llint x[MAX], y[MAX], z[MAX];
int n;

llint px, py, pz;

bool can(llint R) {
  vector<llint> l(4, -inf);
  vector<llint> r(4, +inf);
  
  REP(i, n) {
    l[0] = max(l[0], x[i]+y[i]+z[i]-R);
    r[0] = min(r[0], x[i]+y[i]+z[i]+R);
    l[1] = max(l[1], x[i]+y[i]-z[i]-R);
    r[1] = min(r[1], x[i]+y[i]-z[i]+R);
    l[2] = max(l[2], x[i]-y[i]+z[i]-R);
    r[2] = min(r[2], x[i]-y[i]+z[i]+R);
    l[3] = max(l[3], x[i]-y[i]-z[i]-R);
    r[3] = min(r[3], x[i]-y[i]-z[i]+R);
  }

  REP(k, 4)
    if (l[k] > r[k]) return false;
  
  vector<llint> v(4);
  REP(a, 4) {
    v[0] = a < 2 ? l[0] + a : r[0] - 3 + a;
    if (v[0] < l[0] || v[0] > r[0]) continue;
    
    REP(b, 4) {
      v[1] = b < 2 ? l[1] + b : r[1] - 3 + b;
      if ((v[0] - v[1]) % 2) continue;
      if (v[1] < l[1] || v[1] > r[1]) continue;
    
      REP(c, 4) {
        v[2] = c < 2 ? l[2] + c : r[2] - 3 + c;
        if ((v[0] - v[2]) % 2) continue;
        if (v[2] < l[2] || v[2] > r[2]) continue;
        REP(d, 4) {
          v[3] = d < 2 ? l[3] + d : r[3] - 3 + d;
          if ((v[0] - v[3]) % 2) continue;
          if (v[3] < l[3] || v[3] > r[3]) continue;
    
          
          REP(k, 4) {
            if (k == 0) {
              px = (v[1] + v[2]) / 2;
              py = (2*px - v[2] - v[3]) / 2;
              pz = v[2] - px + py;
            } else if (k == 1) {
              px = (v[0] + v[3]) / 2;
              py = (v[0] - v[2]) / 2;
              pz = v[0] - px - py;
            } else if (k == 2) {
              px = (v[0] + v[3]) / 2;
              py = (v[0] + v[1] - 2*px) / 2;
              pz = v[0] - px - py;
            } else {
              px = (v[1] + v[2]) / 2;
              py = (v[0] + v[1] - 2*px) / 2;
              pz = v[0] - px - py;
            }
            
            if (l[0] <= px + py + pz && px + py + pz <= r[0])
              if (l[1] <= px + py - pz && px + py - pz <= r[1])
                if (l[2] <= px - py + pz && px - py + pz <= r[2])
                  if (l[3] <= px - py - pz && px - py - pz <= r[3])
                    return true;
          }
        }
      }
    }
  }
  
  return false;
}

int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    REP(i, n) scanf("%lld %lld %lld", &x[i], &y[i], &z[i]);

    llint lo = 0, hi = inf;
    while (lo < hi) {
      llint mid = (lo + hi) / 2;
      if (can(mid)) hi = mid;
      else lo = mid + 1;
    }

    can(lo);
    printf("%lld %lld %lld\n", px, py, pz);
  }
  return 0;
}