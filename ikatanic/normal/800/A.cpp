#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const double inf = 1e100;
const double eps = 1e-11;

int main(void) {
  int n, p;
  scanf("%d %d", &n, &p);

  vector<pair<double, double>> v;
  REP(i, n) {
    int a, b;
    scanf("%d %d", &a, &b);
    v.push_back({b*1.0/a, a*1.0 / p});
  }

  sort(v.begin(), v.end());
  double k = 0, l = 0;

  double ret = inf; 
  for (auto& p: v) {
    if (ret < p.first) break;
    
    k += p.second;
    l -= p.first * p.second;

    if (k > 1 + eps) {
      ret = l / (1 - k);
    }
  }

  if (ret >= inf) {
    puts("-1");
  } else {
    printf("%.10lf\n", ret);
  }
  return 0;
}