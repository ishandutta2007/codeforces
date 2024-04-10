#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int sign(double r){ return (r < -EPS) ? -1 : (r > EPS) ? 1 : 0; }
bool eq(double a, double b){ return abs(b - a) < EPS; }

struct Point{
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
  Point operator+(const Point& b) const { return Point(x + b.x, y + b.y); }
  Point operator-(const Point& b) const { return Point(x - b.x, y - b.y); }
  Point operator*(const double b) const { return Point(x * b, y * b); }
  Point operator*(const Point& b) const { return Point(x * b.x - y * b.y, x * b.y + y * b.x); }
  Point operator/(const double b) const { return Point(x / b, y / b); }
  bool operator< (const Point& b) const { return x != b.x ? x < b.x : y < b.y; }
  bool operator==(const Point& b) const { return eq(x, b.x) && eq(y, b.y); }
  double norm(){ return x * x + y * y; }
  double arg(){ return atan2(x, y); }
  double abs(){ return sqrt(norm()); }
  Point rotate(double theta){ return Point(cos(theta) * x - sin(theta) * y, sin(theta) * x + cos(theta) * y); }
  Point rotate90(){ return Point(-y, x); }
};

ostream& operator<<(ostream& os, Point& p){ return os<<"("<<p.x<<","<<p.y<<")"; }
istream& operator>>(istream& is, Point& a){ return is>>a.x>>a.y; }
double dot(const Point& a, const Point& b){ return a.x * b.x + a.y * b.y; }
double cross(const Point& a, const Point& b){ return a.x * b.y - a.y * b.x; }
Point polor(double rho, double theta){ return Point(rho * cos(theta), rho * sin(theta)); }

struct Line : public vector<Point> {
  Line(const Point& a, const Point& b) {
    push_back(a); push_back(b);
  }
  Point vector() const {
    return back() - front();
  }
};
struct Circle : Point {
  double r;
  Circle(Point p, double r) : Point(p), r(r) { }
};
typedef vector<Point> Polygon;
Point curr(const Polygon& a, int x){ return a[x]; }
Point next(const Polygon& a, int x){ return a[(x + 1) % a.size()]; }
Point prev(const Polygon& a, int x){ return a[(x - 1 + a.size()) % a.size()]; }

//a->b->c
int ccw(Point a, Point b, Point c) {
  b = b - a; c = c - a;
  if (cross(b, c) > EPS)   return +1; // 
  if (cross(b, c) < -EPS)   return -1; // 
  if (dot(b, c) < 0)     return +2; // c--a--b 
  if (b.norm() < c.norm()) return -2; // a--b--c 
  return 0;                         // a--c--b 
}
// ()
bool intersectLL(const Line& l, const Line& m) {
  return abs(cross(l.vector(), m.vector())) > EPS;
}
// 
bool equalLL(const Line& l, const Line& m){
  return abs(cross(l.vector(), m[0] - l[0])) < EPS;
}
// ()
bool intersectLS(const Line& l, const Line& s) {
  return cross(l.vector(), s[0] - l[0]) * cross(l.vector(), s[1] - l[0]) < EPS; //ls
}
// 
bool intersectLP(const Line& l, const Point& p) {
  return abs(ccw(l[0], l[1], p)) != 1;
}
// 
bool intersectSS(const Line& s, const Line& t) {
  return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
         ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0;
}
// 
bool intersectSP(const Line& s, const Point& p) {
  return ccw(s[0], s[1], p) == 0;
}
// (EPS)
bool intersectCP(const Circle& c, const Point& p){
  return (c - p).abs() < c.r + EPS;
}
// (EPS)
bool intersectCC(const Circle& c, const Circle& d){
  return (c - d).abs() < c.r + d.r + EPS && (c - d).abs() > abs(c.r - d.r) - EPS;
}
// 
Point projection(const Line& l, const Point& p){
  double t = dot(p - l[0], l.vector()) / l.vector().norm();
  return l[0] + l.vector() * t;
}
// 
Point reflection(const Line& l, const Point& p){
  return p + (projection(l, p) - p) * 2;
}
// 
double distanceLP(const Line& l, const Point& p){
  return (p - projection(l, p)).abs();
}
// 
double distanceLL(const Line& l, const Line& m){
  return intersectLL(l, m) ? 0 : distanceLP(l, m[0]);
}
// 
double distanceLS(const Line& l, const Line& s){
  if(intersectLS(l, s)) return 0;
  return min(distanceLP(l, s[0]), distanceLP(l, s[1]));
}
// 
double distanceSP(const Line& s, const Point& p){
  const Point r = projection(s, p);
  if(intersectSP(s, r)) return (r - p).abs(); //
  return min((s[0] - p).abs(), (s[1] - p).abs());
}
// 
double distanceSS(const Line& s, const Line& t){
  if(intersectSS(s, t)) return 0;
  return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
             min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}
// 
Point crosspointLL(const Line& l, const Line& m){
  double d = cross(m.vector(), l.vector());
  if(abs(d) < EPS) assert(false); // 
  return l[0] + l.vector() * cross(m.vector(), m[1] - l[0]) * (1.0 / d);
}

double area(const Polygon& P) {
  double A = 0;
  REP(i, P.size()){
    A += cross(curr(P, i), next(P, i));
  }
  return A / 2.0;
}

Polygon convex_cut(const Polygon& P, const Line& l){
  Polygon Q;
  REP(i, P.size()){
    Point A = curr(P, i), B = next(P, i);
    if(ccw(l[0], l[1], A) != -1) Q.push_back(A); //Al
    if(ccw(l[0], l[1], A) * ccw(l[0], l[1], B) < 0)
      Q.push_back(crosspointLL(l, Line(A, B)));
  }
  return Q;
}
int main(){
  double W, H, A;
  while(cin>>W>>H>>A){
    W /= 2; H /= 2;
    Polygon P;
    P.push_back(Point(W, H));
    P.push_back(Point(-W, H));
    P.push_back(Point(-W, -H));
    P.push_back(Point(W, -H));
    Polygon Q = P;
    REP(i, 4){
      Point p = curr(P, i);
      Point q = next(P, i);
      p = p.rotate(A * M_PI / 180.0);
      q = q.rotate(A * M_PI / 180.0);
      Q = convex_cut(Q, Line(p, q));
    }
    printf("%.10lf\n", area(Q));
  }
  return 0;
}