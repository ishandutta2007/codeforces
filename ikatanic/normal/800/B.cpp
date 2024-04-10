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

llint cross(pair<int, int>& a, pair<int, int>& b, pair<int, int>& c) {
  llint ret = 0;
  ret += a.first * 1LL * (b.second - c.second);
  ret += b.first * 1LL * (c.second - a.second);
  ret += c.first * 1LL * (a.second - b.second);
  return abs(ret);
}
  
int main(void) {
  int N;
  scanf("%d", &N);
  vector<pair<int, int>> v(N);
  REP(i, N) {
    scanf("%d %d", &v[i].first, &v[i].second);
  }
  
  double ans = inf;
  REP(it, N) {
    for (int j = 1; j < N; ++j) {
      for (int k : {N-1, 1, j-1, j+1}) {
        if (k <= 0 || k >= N || k == j) continue;

        llint dx = v[0].first - v[j].first;
        llint dy = v[0].second - v[j].second;
        
        double dist = cross(v[0], v[j], v[k]) / 2.0 / sqrt(dx*dx + dy*dy);
        ans = min(ans, dist);
      }
      
      rotate(v.begin(), v.begin() + 1, v.end());
    }
  }
  
  printf("%.12lf\n", ans);
  return 0;
}