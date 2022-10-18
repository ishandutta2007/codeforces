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

const int MAXN = 1010;

struct point {
  int x, y;
  friend point operator - (const point &a, const point &b) {
    return {a.x-b.x, a.y-b.y};
  }
};

int dist0(point A) {
  return A.x*A.x + A.y*A.y;
}

point a[MAXN], b[MAXN];
point P, Q;
int n, m;

bool test() {
  REP(i, n) REP(j, m) {
    point A = a[i] - (b[j] - Q);
    point B = a[(i+1)%n] - (b[j] - Q);
    
    int lo = dist0(A), hi = dist0(B);
    if (lo > hi) swap(lo, hi);

    double kA = dist0(A) + dist0(B) - 2*A.x*B.x - 2*A.y*B.y;
    double kB = -2*A.x*A.x - 2*A.y*A.y + 2*A.x*B.x + 2*A.y*B.y;
    double lambda = -kB / (2*kA);
    if (0 <= lambda && lambda <= 1) {
      double x = A.x + lambda * (B.x - A.x);
      double y = A.y + lambda * (B.y - A.y);
      lo = ceil(x*x + y*y);
    }
    
    if (lo <= dist0(Q) && dist0(Q) <= hi) return true;
  }
  return false;
}

int main(void) {
  scanf("%d %d", &P.x, &P.y);
  scanf("%d", &n);
  REP(i, n) scanf("%d %d", &a[i].x, &a[i].y);
  scanf("%d %d", &Q.x, &Q.y);
  scanf("%d", &m);
  REP(i, m) scanf("%d %d", &b[i].x, &b[i].y);

  Q = Q - P;
  REP(i, n) a[i] = a[i] - P;
  REP(i, m) b[i] = b[i] - P;
  P = P - P;

  if (!test()) {
    P = P - Q;
    REP(i, n) a[i] = a[i] - Q;
    REP(i, m) b[i] = b[i] - Q;
    REP(i, max(n, m)) swap(a[i], b[i]);
    swap(n, m);
    Q = Q - Q;
    swap(P, Q);

    if (!test()) {
      puts("NO");
      return 0;
    }
  }

  puts("YES");
  return 0;
}