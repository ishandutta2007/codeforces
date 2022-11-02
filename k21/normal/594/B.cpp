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

static const double PI = 2 * acos(0);
typedef long long ll;

bool can(double dist, double angle) {
  angle /= 2;
  double maxDist = 2 * (angle + sin(angle));
  return dist <= maxDist;
}

double getAngle(double dist) {
  double l = 0;
  double h = 2*PI;
  REP(i,100) {
    double m = (l + h) / 2;
    if (can(dist, m)) {
      h = m;
    } else {
      l = m;
    }
  }
  return (l + h) / 2;
}

int main() {
  DEBUG(PI)
  int N;
  double R, V, S, F;
  scanf("%d%lf%lf", &N, &R, &V);
  double circ = 2*PI*R;
  REP(i,N) {
    scanf("%lf%lf", &S, &F);
    double D = F-S;
    ll whole = (ll)(D / circ);
    double t = whole * circ / V;
    D -= whole * circ;
    t += getAngle(D / R) * R / V;
    printf("%.12lf\n", t);
  }
  return 0;
}