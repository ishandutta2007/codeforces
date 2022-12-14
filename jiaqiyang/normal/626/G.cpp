#include <cmath>
#include <cstdio>
#include <set>

const int N = 200000 + 10;
const double eps = 1e-12;

inline int sgn(double x) {
  if (fabs(x) < eps) return 0;
  return x > 0. ? 1 : -1;
}

int n, tot, q, p[N], l[N];

int cur[N];

inline double calcInc(int x) { return p[x] * ((cur[x] + 1.) / (cur[x] + l[x] + 1.) - (double)cur[x] / (cur[x] + l[x])); }

struct CompInc {
  inline bool operator() (int a, int b) {
    double u = calcInc(a), v = calcInc(b);
    return u > v || (u == v && a < b);
  }
};

inline double calcDec(int x) { return p[x] * ((double)cur[x] / (cur[x] + l[x]) - (cur[x] - 1.) / (cur[x] + l[x] - 1.)); }

struct CompDec {
  inline bool operator() (int a, int b) {
    double u = calcDec(a), v = calcDec(b);
    return u < v || (u == v && a < b);
  }
};

std::set<int, CompInc> inc;
std::set<int, CompDec> dec;

double ans = 0.;

inline void add(int x) {
  inc.erase(x);
  dec.erase(x);
  ans += calcInc(x);
  if (++cur[x] < l[x]) inc.insert(x);
  dec.insert(x);
}

inline void del(int x) {
  inc.erase(x);
  dec.erase(x);
  ans -= calcDec(x);
  if (--cur[x]) dec.insert(x);
  inc.insert(x);
}

inline bool maintain() {
  if (inc.empty()) return false;
  if (tot) {
    int x = *inc.begin();
    add(x);
    --tot;
    return true;
  }
  if (inc.empty() || dec.empty()) return false;
  int x = *inc.begin(), y = *dec.begin();
  if (sgn(calcInc(x) - calcDec(y)) <= 0) return false;
  add(x), del(y);
  return true;
}

int main() {
  scanf("%d%d%d", &n, &tot, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &l[i]);
  for (int i = 1; i <= n; ++i) inc.insert(i);
  while (maintain()) {}
  while (q--) {
    int t, r;
    scanf("%d%d", &t, &r);
    inc.erase(r);
    dec.erase(r);
    ans -= (double)p[r] * cur[r] / (cur[r] + l[r]);
    if (t == 1) {
      ++l[r];
      ans += (double)p[r] * cur[r] / (cur[r] + l[r]);
      if (cur[r]) dec.insert(r);
      if (cur[r] < l[r]) inc.insert(r);
    } else {
      --l[r];
      ans += (double)p[r] * cur[r] / (cur[r] + l[r]);
      if (cur[r]) {
        ans -= calcDec(r);
        --cur[r];
        ++tot;
      }
      if (cur[r]) dec.insert(r);
      if (cur[r] < l[r]) inc.insert(r);
    }
    while (maintain()) {}
    printf("%.10f\n", ans);
  }
  return 0;
}