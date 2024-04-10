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

const int MAX = 200020;

struct Pt {
  int x, y;
};

int ccw(const Pt& a, const Pt& b, const Pt& c) {
  llint w = 0;
  w += llint(a.x) * (b.y - c.y);
  w += llint(b.x) * (c.y - a.y);
  w += llint(c.x) * (a.y - b.y);
  return w < 0 ? -1 : w > 0;
}

int a[MAX];
int s[MAX];

vector<Pt> upper(vector<Pt>& v) {
  sort(v.begin(), v.end(), [&] (const Pt& a, const Pt& b) {
      return a.x < b.x;
    }
  );
  vector<Pt> H;
  for (Pt& p: v) {
    while (H.size() >= 2 && ccw(H[H.size() - 2], H.back(), p) >= 0) H.pop_back();
    H.push_back(p);
  }
  return H;
}

vector<Pt> lower(vector<Pt>& v) {
  sort(v.begin(), v.end(), [&] (const Pt& a, const Pt& b) {
      return a.x > b.x;
    }
  );
  vector<Pt> H;
  for (Pt& p: v) {
    while (H.size() >= 2 && ccw(H[H.size() - 2], H.back(), p) >= 0) H.pop_back();
    H.push_back(p);
  }
  return H;
}

double intersect(const Pt& a, const Pt& b) {
  return double(b.y-a.y) / (a.x-b.x);
}

double eval(const Pt& a, double x) {
  return a.x*x + a.y;
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", a+i);
  s[0] = 0;
  REP(i, n) s[i+1] = s[i] + a[i];
  n++;

  vector<Pt> v;
  REP(i, n) v.push_back({-i, s[i]});

  vector<Pt> u = upper(v);
  vector<Pt> d = lower(v);

  vector<double> p = {0, -10000, +10000};
  REP(i, (int)u.size() - 1) p.push_back(intersect(u[i], u[i+1]));
  REP(i, (int)d.size() - 1) p.push_back(intersect(d[i], d[i+1]));

  sort(p.begin(), p.end());
  int cu = 0, cd = 0;
  double ans = 1e100;
  for (double x: p) {
    while (cu + 1 < (int)u.size() && eval(u[cu+1], x) > eval(u[cu], x)) cu++;
    while (cd + 1 < (int)d.size() && eval(d[cd+1], x) < eval(d[cd], x)) cd++;
    ans = min(ans, eval(u[cu], x) - eval(d[cd], x));
  }

  printf("%.10lf\n", ans);
  return 0;
}