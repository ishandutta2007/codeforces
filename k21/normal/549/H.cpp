#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

double A, B, C, D;

bool possible(double t) {
  double A1 = A - t, A2 = A + t;
  double B1 = B - t, B2 = B + t;
  double C1 = C - t, C2 = C + t;
  double D1 = D - t, D2 = D + t;
  double l1 = min(A1 * D1, A1 * D2);
  l1 = min(l1, A2 * D1);
  l1 = min(l1, A2 * D2);
  double l2 = max(A1 * D1, A1 * D2);
  l2 = max(l2, A2 * D1);
  l2 = max(l2, A2 * D2);
  double r1 = min(B1 * C1, B1 * C2);
  r1 = min(r1, B2 * C1);
  r1 = min(r1, B2 * C2);
  double r2 = max(B1 * C1, B1 * C2);
  r2 = max(r2, B2 * C1);
  r2 = max(r2, B2 * C2);
  return l1 <= r2 && r1 <= l2;
}

int main() {
  scanf("%lf%lf%lf%lf", &A, &B, &C, &D);
  double lo = 0;
  double hi = 2e9;
  REP(i,150) {
    double mid = (lo + hi) / 2;
    if (possible(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  printf("%.12lf\n", lo);
  return 0;
}