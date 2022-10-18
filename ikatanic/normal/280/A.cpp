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

const long double pi = acos(-1);

struct Pt {
  long double x, y;
};

struct Line {
  long double A, B, C;
};

Line perpendicular_line(Line l, Pt p) {
  return {-l.B, l.A, l.B*p.x - l.A*p.y};
}

Line cross(Line a, Line b) {
  return {a.B*b.C-a.C*b.B, -(a.A*b.C-b.A*a.C), a.A*b.B-a.B*b.A};
}

Pt lines_intersection(Line a, Line b) {
  Line p = cross(a, b);
  return {p.A / p.C, p.B / p.C};
}

Line line_from_pts(Pt a, Pt b) {
  return cross({a.x, a.y, 1}, {b.x, b.y, 1});
}

long double dist(const Pt &a, const Pt &b) {
  return sqrtl((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

Pt rot(Pt A, long double a) {
  a += atan2l(A.y, A.x);
  long double R = dist(A, {0, 0});
  return {R*cosl(a), R*sinl(a)};
}

int main(void) {
  int w, h, aa;
  scanf("%d %d %d", &w, &h, &aa);
  if (aa > 90) aa = 180 - aa;
  if (aa == 0) {
    printf("%lld\n", llint(w)*h);
    return 0;
  }
  
  if (w < h) swap(w, h);

  long double a = aa / 180.0 * pi;
  
  Pt A = {-w*0.5, h*0.5};
  Pt B = {w*0.5, h*0.5};
  Pt C = {w*0.5, -h*0.5};
  Pt D = {-w*0.5, -h*0.5};
  
  long double lim = atan2(B.y, B.x) - atan2(C.y, C.x);
  if (lim >= 2*pi) lim -= 2*pi;
  if (lim < 0) lim += 2*pi;

  Pt nA = rot(A, a);
  Pt nB = rot(B, a);
  Pt nC = rot(C, a);
  Pt nD = rot(D, a);


  long double out = 0;
  if (a <= lim) {
    Pt s1 = lines_intersection(line_from_pts(A, B), line_from_pts(nA, nB));
    Pt s2 = lines_intersection(line_from_pts(A, B), line_from_pts(nB, nC));
    out += dist(s1, nB) * dist(s2, nB);

    s1 = lines_intersection(line_from_pts(C, B), line_from_pts(nC, nD));
    s2 = lines_intersection(line_from_pts(C, B), line_from_pts(nB, nC));
    out += dist(s1, nC) * dist(s2, nC);
  } else {
    Pt s1 = lines_intersection(line_from_pts(A, B), line_from_pts(nC, nD));
    Pt s2 = lines_intersection(line_from_pts(A, B), line_from_pts(nA, nB));

    long double l1 = dist(s1, nC);
    long double l2 = dist(s2, nB);
    if (l1 > l2) swap(l1, l2);
    out = 2*h*l1 + h*(l2-l1);
  }

   long double ans = llint(w)*h - out;
  printf("%.10lf\n", (double)ans);
  return 0;
}