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

const double eps = 1e-7;
const double inf = 1e20;
const double pi = acos(-1);

inline bool lt(double a, double b) { return a+eps < b; }
inline bool gt(double a, double b) { return lt(b, a); }
inline bool eq(double a, double b) { return !lt(a, b) && !gt(a, b); }
inline bool lte(double a, double b) { return !gt(a, b); }
inline bool gte(double a, double b) { return !lt(a, b); }

inline double sqr(double x) { return x*x; }
inline int sgn(double w) { return lt(w, 0) ? -1 : gt(w, 0); }

struct Pt {
  double x, y;
  Pt operator + (const Pt &b) { return {x+b.x, y+b.y}; }
  Pt operator - (const Pt &b) { return {x-b.x, y-b.y}; }
  Pt operator * (const double &b) { return {x*b, y*b}; }
  friend bool operator < (const Pt &a, const Pt &b) {
    if (!eq(a.x, b.x)) return lt(a.x, b.x);
    return lt(a.y, b.y);
  }
};

struct Line {
  double A, B, C;
};

struct Circle {
  Pt c;
  double r;
};

struct Segment {
  Pt a, b;
};

inline double cross(const Pt &a, const Pt &b) { return a.x*b.y - b.x*a.y; }
inline double dot(const Pt &a, const Pt &b) { return a.x*b.x + a.y*b.y; }
inline double norm(const Pt &a) { return sqrt(dot(a, a)); }
inline double dist(Pt a, Pt b) { return norm(b-a); }

inline double angle(const Pt &a, const Pt &b) { 
  // angle between vectors a and b, [0, pi]
  return acos(dot(a, b) / norm(a) / norm(b));
}
inline double angle(const Pt &p) {
  return eq(p.y, 0) ? atan2(0, p.x) : atan2(p.y, p.x);
}

inline Pt rotateCCW(const Pt &p, double a) {
  return {p.x*cos(a)-p.y*sin(a), p.x*sin(a)+p.y*cos(a)};
}

inline int ccw(Pt a, Pt b, Pt c) {
  return sgn(cross(b-a, c-a));
}

inline Line cross(const Line &a, const Line &b) {
  return {a.B*b.C-a.C*b.B, -(a.A*b.C-b.A*a.C), a.A*b.B-a.B*b.A};
}

inline Line line_from_pts(const Pt &a, const Pt &b) {
  return cross({a.x, a.y, 1}, {b.x, b.y, 1});
}

inline Line perpendicular_line(const Line &l, const Pt &p) {
  return {-l.B, l.A, l.B*p.x - l.A*p.y};
}

inline double line_pt_dist(const Line &l, const Pt &p) {
  return fabs((l.A*p.x + l.B*p.y + l.C)/sqrt(l.A*l.A + l.B*l.B));
}

inline bool lines_intersect(const Line &a, const Line &b) {
  return !eq(cross(a, b).C, 0);
}

Pt lines_intersection(const Line &a, const Line &b) {
  Line p = cross(a, b);
  assert(!eq(p.C, 0));
  return {p.A / p.C, p.B / p.C};
}

bool is_pt_on_segment(const Segment &a, const Pt &p) { // ends included
  if (ccw(a.a, a.b, p)) return false;
  double x_lo = min(a.a.x, a.b.x), x_hi = max(a.a.x, a.b.x);
  double y_lo = min(a.a.y, a.b.y), y_hi = max(a.a.y, a.b.y);
  return !lt(p.x, x_lo) && !gt(p.x, x_hi) && !lt(p.y, y_lo) && !gt(p.y, y_hi);
}

bool segments_intersect(const Segment &a, const Segment &b) {
  // returns false for colinear segments or if segments are only touching
  if (ccw(a.a, a.b, b.a) * ccw(a.a, a.b, b.b) >= 0) return false;
  if (ccw(b.a, b.b, a.a) * ccw(b.a, b.b, a.b) >= 0) return false;
  return true;
}

Pt segments_intersection(const Segment &a, const Segment &b) {
  assert(segments_intersect(a, b));
  return lines_intersection(line_from_pts(a.a, a.b), line_from_pts(b.a, b.b));
}

bool is_pt_in_triangle(Pt a, Pt p1, Pt p2, Pt p3) {
  int c1 = ccw(p1, p2, a);
  int c2 = ccw(p2, p3, a);
  int c3 = ccw(p3, p1, a);
  return c1*c2 >= 0 && c1*c3 >= 0 && c2*c3 >= 0;
}

double triangle_area(Pt a, Pt b, Pt c) {
  return 0.5 * fabs(cross(b-a, c-a));
}

Circle circle_from_pts(Pt a, Pt b, Pt c) {
  assert(ccw(a, b, c));
  Line la = perpendicular_line(line_from_pts(a, c), (a+c)*0.5);
  Line lb = perpendicular_line(line_from_pts(b, c), (b+c)*0.5);
  Pt s = lines_intersection(la, lb);
  return {s, dist(s, a)};
}

// vraca bool ako postoje sjecista, sprema ih u s1 i s2
// ako je jedno sjeciste bit ce s1 == s2
// ako imas dvije tocke na pravcu onda ih proslijedi kao p1 i p2.
bool line_circle_intersection(Pt p1, Pt p2, const Circle &c, Pt &s1, Pt &s2) {
  p1 = p1 - c.c;
  p2 = p2 - c.c;

  Pt d = p2 - p1;
  double dr = dot(d, d);
  double D = cross(p1, p2);
  double dis = c.r*c.r*dr - D*D;

  if (dis < 0) return false;
  dis = sqrt(max(dis, 0.0));
  
  s1.x = c.c.x + (D*d.y + sgn(d.y)*d.x*dis) / dr;
  s2.x = c.c.x + (D*d.y - sgn(d.y)*d.x*dis) / dr;
  
  s1.y = c.c.y + (-D*d.x + sgn(d.y)*d.y*dis) / dr;
  s2.y = c.c.y + (-D*d.x - sgn(d.y)*d.y*dis) / dr;
  return true;
}

vector<Line> circles_tangents(Circle a, Circle b) {
  vector<Line> ans;
  for (int i: {-1, +1})
    for (int j: {-1, +1}) {
      if (eq(a.r, 0) && i == 1) continue;
      if (eq(b.r, 0) && j == 1) continue;

      Pt c2 = b.c - a.c;
      double r1 = a.r * i;
      double r2 = b.r * j;
      
      double r = r2 - r1;
      double z = dot(c2, c2);
      double d = z - r*r;
      if (d < 0) continue;
      
      d = sqrt(max(d, 0.0));
      
      Line l;
      l.A = (c2.x*r + c2.y*d) / z;
      l.B = (c2.y*r - c2.x*d) / z;
      l.C = r1 - l.A*a.c.x - l.B*a.c.y;
      ans.push_back(l);
    }
  return ans;
}

vector<Line> circle_pt_tangents(const Circle &a, const Pt &b) {
  return circles_tangents(a, {b, 0});
}

// is pt strictly in polygon
bool is_pt_in_poly(const vector<Pt>& P, Pt p) { 
  int np = P.size();
  int wind = 0;
 
  REP(i, np) {
    Pt a = P[i], b = P[(i+1)%np];
    if (is_pt_on_segment({a, b}, p)) return false;
 
    if (gt(b.y, a.y)) { // rising segments
      if (lte(a.y, p.y) && lt(p.y, b.y))
        if (ccw(a, b, p) > 0)
          ++wind;
    } else if (lt(b.y, a.y)) { // falling segments
      if (gt(a.y, p.y) && gte(p.y, b.y))
        if (ccw(a, b, p) <= 0)
          --wind;
    } if (eq(a.y, b.y) && eq(a.y, p.y)) { // horizontal segments
      if (lt(a.x, b.x)) { // to the right
        if (lt(a.x, p.x) && lte(p.x, b.x)) --wind;        
      }
    }
  }
 
  return (wind > 0);
}

// is segment going through poly interior or passing through poly point
bool segment_intersects_poly(const vector<Pt> &P, Segment s) {
  int n = P.size();
  REP(i, n) {
    if (eq(P[i].x, s.a.x) && eq(P[i].y, s.a.y)) continue;
    if (eq(P[i].x, s.b.x) && eq(P[i].y, s.b.y)) continue;
    if (is_pt_on_segment(s, P[i])) return true;
  }
  REP(i, n) if (segments_intersect({P[i], P[(i+1)%n]}, s)) return true;
  return is_pt_in_poly(P, (s.a + s.b)*0.5);
}

int main(void) {
  Pt p;
  int vp;
  scanf("%lf %lf %d", &p.x, &p.y, &vp);
  
  double R = sqrt(p.x*p.x + p.y*p.y);
  double period = 2*R*pi/vp;

  Pt q;
  int v, r;
  scanf("%lf %lf %d %d", &q.x, &q.y, &v, &r);
  Circle d = {{0, 0}, 1.*r};

  auto test = [&] (double t) {
    double a = fmod(t, period)/period*2*pi + atan2(p.y, p.x);
    while (a >= 2*pi) a -= 2*pi;
    while (a < 0) a += 2*pi;

    Pt np = {R*cos(a), R*sin(a)};
    
    if (eq(np.x, q.x) && eq(np.y, q.y)) return true;

    Pt s1, s2;
    if (!line_circle_intersection(q, np, d, s1, s2)) {
      return dist(q, np) <= t*v;
    } else {
      if (dist(q, s1) > dist(q, s2)) swap(s1, s2);
      if (!eq(dist(q, s1) + dist(s1, np), dist(q, np))) return dist(q, np) <= t*v;

      auto t1 = circle_pt_tangents(d, q);
      auto t2 = circle_pt_tangents(d, np);
      
      for (auto l1: t1)
        for (auto l2: t2) {
          s1 = lines_intersection(l1, perpendicular_line(l1, {0, 0}));
          s2 = lines_intersection(l2, perpendicular_line(l2, {0, 0}));

          double a = angle(s1, s2);
          double total = dist(q, s1) + dist(s2, np) + a*r;
          if (total <= t*v) return true;
        }
      return false;
    }    
  };

  double lo = 0, hi = 1e10;
  REP(it, 1000) {
    double mid = (lo + hi) / 2;
    if (test(mid)) hi = mid; else
      lo = mid;
  }

  printf("%.10lf\n", lo);
  return 0;
}