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

const int MAXN = 110;
const int IT = 70;
const long double eps = 1e-7;
const long double MAX = 1e4;

int x[MAXN], y[MAXN], z[MAXN];
long double X, Y, Z;
int n;

long double calc(long double X, long double Y, long double Z) {
  long double ans = 0;
  REP(i, n) 
    ans = max(ans, (X-x[i])*(X-x[i]) + (Y-y[i])*(Y-y[i]) + (Z-z[i])*(Z-z[i]));
  return ans;
}

long double searchZ(long double X, long double Y) {
  long double lo = -MAX, hi = MAX;
  REP(it, IT) {
    long double mid = (lo + hi) / 2;
    if (calc(X, Y, mid) > calc(X, Y, mid + eps)) lo = mid; else
      hi = mid;
  }
  Z = lo;
  return calc(X, Y, Z);
}

long double searchY(long double X) {
  long double lo = -MAX, hi = MAX;
  REP(it, IT) {
    long double mid = (lo + hi) / 2;
    if (searchZ(X, mid) > searchZ(X, mid + eps)) lo = mid; else
      hi = mid;
  }
  Y = lo;
  return searchZ(X, Y);
}

long double searchX() {
  long double lo = -MAX, hi = MAX;
  REP(it, IT) {
    long double mid = (lo + hi) / 2;
    if (searchY(mid) > searchY(mid + eps)) lo = mid; else
      hi = mid;
  }
  X = lo;
  return searchY(X);
}

int main(void) {
  scanf("%d", &n);
  REP(i, n) scanf("%d %d %d", x+i, y+i, z+i);
  searchX();
  printf("%.10lf %.10lf %.10lf\n", double(X), double(Y), double(Z));
  return 0;
}