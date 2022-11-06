// Author:  HolyK
// Created: Sun Dec 19 16:15:08 2021
#include <bits/stdc++.h>
using namespace std;

namespace Geo2D {
using D = double;
using LD = long double;
// #define double long double
constexpr double EPS(1e-10);
const double PI = acos(-1.0);
int sgn(double x) { return (x > EPS) - (x < -EPS); }
int cmp(double x, double y) { return sgn(x - y); }

struct Pt {
  double x, y;
  void read() {
    double a, b;
    cin >> a >> b, x = a, y = b;
  }
  void print() { cout << x << " " << y << "\n"; }
  
  explicit Pt(double x = 0, double y = 0) : x(x), y(y) {}
  Pt operator+(const Pt &r) const { return Pt(x + r.x, y + r.y); }
  Pt operator-(const Pt &r) const { return Pt(x - r.x, y - r.y); }
  Pt operator*(double r) const { return Pt(x * r, y * r); }
  Pt operator/(double r) const { return Pt(x / r, y / r); }
  bool operator<(const Pt &r) const { return x < r.x || x == r.x && y < r.y; }
  bool operator==(const Pt &r) const { return !cmp(x, r.x) && !cmp(y, r.y); }
  
  double operator^(const Pt &r) const { return x * r.x + y * r.y; } // dot
  double operator*(const Pt &r) const { return x * r.y - y * r.x; } // cross
  double cross(Pt a, Pt b) const { return (a - *this) * (b - *this); }
    
  double len2() const { return x * x + y * y; }
  double len() const { return sqrt(len2()); }

  Pt rotate(double r) const {
    return Pt(x * cos(r) - y * sin(r), x * sin(r) + y * cos(r));
  }

  Pt unit() const { return *this / len(); }
  Pt perp() const { return Pt(-y, x); }
  Pt norm() const { return perp().unit(); }


  Pt proj(Pt a, Pt b) const {
    Pt d = b - a;
    return a + d * ((d ^ (*this - a)) / d.len2());
  }
  Pt refl(Pt a, Pt b) const { return proj(a, b) * 2 - *this; }

  bool onSeg(Pt a, Pt b) const {
    return !sgn(cross(a, b)) && sgn((*this - a) ^ (*this - b)) <= 0;
  }
  int side(Pt a, Pt b) const {
    return sgn(a.cross(b, *this));
  }
};
int checkLL(Pt a, Pt b, Pt c, Pt d) { // 0, 1, -1(INF)
  return sgn((b - a) * (d - c)) ? 1 : a.side(c, d) ? 0 : -1;
}
Pt getLL(Pt a, Pt b, Pt c, Pt d) {
  double p = c.cross(b, d), q = c.cross(d, a);
  return (a * p + b * q) / (p + q);
}
vector<Pt> getSS(Pt a, Pt b, Pt c, Pt d) { // 0, 1, 2(INF, return the segment endpoint)
  double oa = c.cross(d, a), ob = c.cross(d, b), oc = a.cross(b, c), od = a.cross(b, d); 
  if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0) {
    return {(a * ob - b * oa) / (ob - oa)};
  }
  vector<Pt> r;
  if (a.onSeg(c, d)) r.push_back(a);
  if (b.onSeg(c, d)) r.push_back(b);
  if (c.onSeg(a, b)) r.push_back(c);
  if (d.onSeg(a, b)) r.push_back(d);
  return r;
}

double distPL(Pt p, Pt a, Pt b) { return fabs(p.cross(a, b)) / (b - a).len(); }
double distPS(Pt p, Pt a, Pt b) {
  if (a == b) return (a - p).len();
  double d = (b - a).len2(), t = min(d, max(0.0, (b - a) ^ (p - a)));
  return ((p - a) * d - (b - a) * t).len() / d;
}
double distSS(Pt a, Pt b, Pt c, Pt d) {
  return getSS(a, b, c, d).empty() ? min({
      distPS(a, c, d), distPS(b, c, d), distPS(c, a, b), distPS(d, a, b)
    }) : 0.0;
}

struct Poly : vector<Pt> { // Polygon
#define T (*this)
  using vector::vector;
  double getArea() const {
    if (size() <= 1) return 0;
    double r = back() * T[0];
    for (int i = 0; i + 1 < size(); i++) r += T[i] * T[i + 1];
    return r / 2;
  }
  bool isConvex() const {
    int n = size();
    if (n <= 2) return false;
    Poly p(T);
    p.push_back(p[0]), p.push_back(p[1]);
    for (int i = 0; i < n; i++) {
      if (p[i + 1].side(p[i], p[i + 2]) > 0) return false;
    }
    return true;
  }
  int contain(Pt p) const { // 2 in;  1 on;  0 out.
    int r = 0;
    for (int i = 0; i < size(); i++) {
      auto u = T[i], v = i + 1 < size() ? T[i + 1] : T[0];
      if (p.onSeg(u, v)) return 1;
      if (u.y > v.y) std::swap(u, v);
      if (cmp(u.y, p.y) >= 0 || cmp(v.y, p.y) < 0) continue;
      if (p.side(u, v) > 0) r ^= 2;
    }
    return r;
  }
  Poly convex() const {
    if (size() <= 1) return T;
    Poly p(T), q(2 * size() + 1);
    std::sort(p.begin(), p.end());
    int s = 0, t = 0;
    for (int i = 2; i--; s = --t, reverse(p.begin(), p.end())) {
      for (Pt x : p) {
        while (t - 2 >= s && x.side(q[t - 2], q[t - 1]) <= 0) t--;
        q[t++] = x;
      }
    }
    if (t == 2 && q[0] == q[1]) t--;
    q.resize(t);
    return q;
  }
  double hullDiameter() const {
    int n = size(), i = 0, j = 1;
    double r = 0;
    while (j < n) {
      r = max(r, (T[i] - T[j]).len2());
      auto &v = j + 1 < n ? T[j + 1] : T[0];
      if (sgn((T[i + 1] - T[i]) * (v - T[j])) < 0) {
        i++;
      } else {
        j++;
      }
    }
    return sqrt(r);
  }

  Poly cut(Pt a, Pt b) {
    Poly r;
    int n = size();
    for (int i = 0; i < n; i++) {
      Pt p = T[i], q = i + 1 < n ? T[i + 1] : front();
      if (p.side(a, b) > 0) {
        r.push_back(p);
      }
      if ((p.side(a, b) > 0) != (q.side(a, b) > 0)) {
        r.push_back(getLL(a, b, p, q));
      }
    }
    return r;
  }
#undef T
};

double closestPair(vector<Pt> p) {
  if (p.size() <= 1) return 0;
  sort(p.begin(), p.end(), [&](Pt i, Pt j) {
    return i.y < j.y;
  });
  set<Pt> s;
  double ans = 1e18;
  int j = 0;
  for (Pt x : p) {
    Pt d {ans, 0};
    while (cmp(p[j].y, x.y - ans) < 0) s.erase(p[j++]);
    auto l = s.lower_bound(x - d), r = s.upper_bound(x + d);
    for (; l != r; l++) ans = min(ans, (*l - x).len());
    s.insert(x);
  }
  return ans;
}

double getRadius(Pt a, Pt b, Pt c) {
  Pt u = c - a, v = b - a;
  double k = u * v * 2;
  return u.len() * v.len() * (b - c).len() / abs(k); // a = 2r sinA
}
Pt getCenter(Pt a, Pt b, Pt c) {
  Pt u = c - a, v = b - a;
  double k = u * v * 2;
  return a + (u * v.len2() - v * u.len2()).perp() / k;
}

struct Circle {
  Pt o;
  double r;
  Circle() {}
  Circle(Pt o, double r) : o(o), r(r) {}
  Circle(Pt a, Pt b, Pt c) : o(getCenter(a, b, c)), r(getRadius(a, b, c)) {}
  Circle(vector<Pt> p) {
    int n = p.size();
    assert(n);
    shuffle(p.begin(), p.end(), mt19937(233));
    o = p[0], r = 0;
    for (int i = 0; i < n; i++) {
      if (cmp((o - p[i]).len(), r) <= 0) continue;
      o = p[i], r = 0;
      for (int j = 0; j < i; j++) {
        if (cmp((o - p[j]).len(), r) <= 0) continue;
        o = (p[i] + p[j]) / 2;
        r = (o - p[i]).len();
        for (int k = 0; k < j; k++) {
          if (cmp((o - p[k]).len(), r) <= 0) continue;
          o = getCenter(p[i], p[j], p[k]);
          r = (o - p[i]).len();
        }
      }
    }
  }
};

vector<Pt> getCL(Circle c, Pt a, Pt b) {
  Pt k = c.o.proj(a, b);
  double d = distPL(c.o, a, b);
  if (cmp(c.r, d) < 0) return {};
  Pt x = (b - a).unit() * sqrt(fmax(0, c.r * c.r - d * d));
  return {k - x, k + x};
}
// get tangent numbers
// checkInter: checkTgCC % 4 != 0
// corner case: a == b
int checkTgCC(Circle a, Circle b) {
  double d = (a.o - b.o).len();
  int u = cmp(d, a.r + b.r);
  return u >= 0 ? u + 3 : cmp(d, abs(a.r - b.r)) + 1;
}
vector<Pt> getCC(Circle a, Circle b) {
  if (!(checkTgCC(a, b) & 3)) return {};
  Pt v = b.o - a.o;
  double d2 = v.len2(), k = (a.r * a.r - b.r * b.r + d2) / (2 * d2), x = a.r * a.r / d2 - k * k;
  Pt o = a.o + v * k, z = v.perp() * sqrt(fmax(0, x));
  return {o - z, o + z};
}
vector<Pt> getTgCP(Circle c, Pt p) {
  Pt v = p - c.o;
  double r2 = c.r * c.r, d2 = v.len2();
  if (cmp(r2, d2) > 0) return {};
  double x = r2 / d2, y = x * (1 - x);
  Pt o = c.o + v * x, z = v.perp() * sqrt(fmax(0, y));
  return {o - z, o + z};
}
vector<pair<Pt, Pt>> getTgCC(Circle a, Circle b, int k = 1) { // k=1/-1: in/out, from kactl
  Pt v = b.o - a.o;
  double dr = a.r - b.r * k, d2 = v.len2(), h2 = d2 - dr * dr;
  if (sgn(d2) == 0 || sgn(h2) < 0) return {};
  vector<pair<Pt, Pt>> res;
  for (int t : {-1, 1}) {
    Pt z = (v * dr + v.perp() * sqrt(fmax(0, h2)) * t) / d2;
    res.push_back({a.o + z * a.r, b.o + z * b.r});
  }
  if (sgn(h2) == 0) res.pop_back();
  return res;
}
double getAreaCT(Pt p, Pt q, double r) { // Area OP -> OQ in circle r, from kactl
  auto arg = [](Pt p, Pt q) { return atan2(p * q, p ^ q); };
  double r2 = r * r / 2;
  Pt d = q - p;
  double a = (d ^ p) / d.len2(), b = (p.len2() - r * r) / d.len2(), det = a * a - b;
  if (sgn(det) <= 0) return arg(p, q) * r2;
  double s = fmax(0, -a - sqrt(fmax(0, det))), t = fmin(1, -a + sqrt(fmax(0, det)));
  if (t < 0 || 1 <= s) return arg(p, q) * r2;
  Pt u = p + d * s, v = p + d * t;
  return arg(p, u) * r2 + u * v / 2 + arg(v, q) * r2;
}
double getAreaCP(Circle c, Poly p) {
  if (p.size() <= 1) return 0;
  double ans = getAreaCT(p.back() - c.o, p[0] - c.o, c.r);
  for (int i = 0; i + 1 < p.size(); i++) {
    ans += getAreaCT(p[i] - c.o, p[i + 1] - c.o, c.r);
  }
  return ans;
}
double getAreaCC(Circle a, Circle b) {
  Pt v = b.o - a.o;
  LD d2 = (LD)v.x * v.x + (LD)v.y * v.y, d = sqrt(d2), r1 = a.r * a.r, r2 = b.r * b.r;
  if (cmp(d, a.r + b.r) >= 0) return 0;
  if (cmp(b.r, d + a.r) >= 0) return PI * r1;
  if (cmp(a.r, d + b.r) >= 0) return PI * r2;
  LD a1 = 2 * acos((d2 + r1 - r2) / (2 * d * a.r));
  LD a2 = 2 * acos((d2 + r2 - r1) / (2 * d * b.r));
  return ((a1 - sin(a1)) * r1 + (a2 - sin(a2)) * r2) / 2;
}
}

namespace {
using namespace Geo2D;
void solve() {
  Circle a, b;
  cin >> a.o.x >> a.o.y >> a.r >> b.o.x >> b.o.y >> b.r;
  cout << getAreaCC(a, b) << "\n";
}
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}