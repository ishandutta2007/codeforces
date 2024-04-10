#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long double ldb;

const int MAX = 200100;
const ldb eps = 1e-16;
const ldb pi = acosl(-1);

inline bool lt(ldb a, ldb b) { return a+eps < b; }
inline bool eq(ldb a, ldb b) { return !lt(a, b) && !lt(b, a); }
inline int sgn(ldb w) { return lt(w, 0) ? -1 : lt(0, w); }

struct Pt {
  ldb x, y;
  Pt operator + (const Pt &b) { return {x+b.x, y+b.y}; }
  Pt operator - (const Pt &b) { return {x-b.x, y-b.y}; }
  Pt operator * (const ldb &b) { return {x*b, y*b}; }
  friend bool operator < (const Pt &a, const Pt &b) {
    if (!eq(a.x, b.x)) return lt(a.x, b.x);
    return lt(a.y, b.y);
  }
};

inline ldb cross(const Pt &a, const Pt &b) { return a.x*b.y - b.x*a.y; }
inline ldb dot(const Pt &a, const Pt &b) { return a.x*b.x + a.y*b.y; }

bool line_circle_intersection(Pt& p1, Pt& p2, ldb r, Pt &s1, Pt &s2) {
  Pt d = p2 - p1;
  ldb dr = dot(d, d);
  ldb D = cross(p1, p2);
  ldb dis = r*r*dr - D*D;

  if (lt(dis, 0)) return false;
  dis = sqrtl(max(dis, 0.0l));
  
  int sgn = d.y < 0 ? -1 : +1;
  s1.x = (D*d.y + sgn*d.x*dis) / dr;
  s2.x = (D*d.y - sgn*d.x*dis) / dr;
  
  s1.y = (-D*d.x + fabsl(d.y)*dis) / dr;
  s2.y = (-D*d.x - fabsl(d.y)*dis) / dr;
  return true;
}

struct Interval {
  ldb a, b;
  int i;
  int x, y;
  friend bool operator < (const Interval& a, const Interval& b) {
    if (a.y != b.y) return a.y > b.y;
    return a.x > b.x;
  }
};

ldb k[MAX], l[MAX];
Pt p1[MAX], p2[MAX];
int n;

ldb mod(ldb d) {
  while (d < 0) d += 2*pi;
  while (d >= 2*pi) d -= 2*pi;
  return d;
}

int findIntervals(vector<Interval>& v, ldb r) {
  v.clear();
  REP(i, n) {
    Pt s1, s2;
    if (line_circle_intersection(p1[i], p2[i], r, s1, s2)) {
      ldb a = mod(atan2l(s2.y, s2.x));
      ldb b = mod(atan2l(s1.y, s1.x));
      if (eq(a, b)) continue;

      if (mod(b-a) > mod(a-b)) swap(a, b);
      v.push_back({a, b, i});
      if (a < b) v.push_back({a+2*pi, b+2*pi, i});
      else v.back().b += 2*pi;
    }
  }

  vector<pair<ldb, int>> a;
  REP(i, (int)v.size()) {
    a.push_back({v[i].a, i*2});
    a.push_back({v[i].b, i*2+1});
  }
  a.push_back({2*pi, -1});

  sort(a.begin(), a.end());
  int i = 0, cur = 0, h = -1;
  while (i < (int)a.size()) {
    int j = i;
    while (j < (int)a.size() && eq(a[i].first, a[j].first)) j++;
    for (int k = i; k < j; ++k) {
      int idx = a[k].second;
      if (idx != -1) {
        if (idx % 2 == 0) v[idx/2].x = cur;
        else v[idx/2].y = cur;
      } else {
        h = cur;
      }
    }
    i = j;
    cur++;
  }

  return h;
}
    

int L[MAX];

void add(int x, int v) {
  for (++x; x < MAX; x += x&-x)
    L[x] += v;
}

int sum(int x) {
  int r = 0;
  for (++x; x; x -= x&-x)
    r += L[x];
  return r;
}

int count(ldb r) {
  vector<Interval> v;
  int h = findIntervals(v, r);
  
  sort(v.begin(), v.end());
  REP(i, MAX) L[i] = 0;

  int ans = 0;
  for (auto a: v) {
    if (a.x < h) {
      ans += sum(a.y - 1) - sum(a.x);
    }
    add(a.x, +1);
  }

  return ans;
}

Pt c;

ldb calc(int i, int j) {
  ldb x = (l[i] - l[j]) / (k[j] - k[i]);
  ldb y = k[i] * x + l[i];
  x -= c.x, y -= c.y;
  return sqrtl(x*x + y*y);
}

pair<int, ldb> solve(ldb r) {
  vector<Interval> v;
  int h = findIntervals(v, r);
  
  sort(v.begin(), v.end());
  REP(i, MAX) L[i] = 0;
  
  set<pair<int, int>> S;
  int ans = 0;
  ldb sum = 0;
  for (auto a: v) {
    if (a.x < h) {
      auto it = S.lower_bound({a.x + 1, -1});
      while (it != S.end() && it->first < a.y) {
        ans++;
        sum += calc(a.i, it->second);
        it++;
      }
    }
    S.insert({a.x, a.i});
  }

  return {ans, sum};
}

int main(void) {
  int m;
  double x, y;
  scanf("%d", &n);
  scanf("%lf %lf %d", &x, &y, &m);
  x /= 1000, y /= 1000;
  c = {x, y};

  REP(i, n) {
    double a, b;
    scanf("%lf %lf", &a, &b);
    p1[i] = {0, b / 1000.0};
    p2[i] = {1000.0, a + b / 1000.0};
    p1[i] = p1[i] - c;
    p2[i] = p2[i] - c;
    k[i] = a / 1000;
    l[i] = b / 1000;
  }

  ldb lo = 0, hi = 1e10;
  REP(it, 100) {
    ldb mid = (lo + hi)/2;
    if (count(mid) < m) lo = mid; else
      hi = mid;
  }

  auto w = solve(lo);
  assert(w.first <= m);
  ldb ans = w.second + (m - w.first) * lo;
  printf("%.18lf\n", (double)ans);
  return 0;
}