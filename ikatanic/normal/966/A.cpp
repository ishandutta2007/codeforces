#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int inf = 1e9;

int main(void) {
  int N, M, Cs, Ce, V;
  scanf("%d %d %d %d %d", &N, &M, &Cs, &Ce, &V);

  set<int> stairs, elevators;
  REP(i, Cs) {
    int x;
    scanf("%d", &x);
    stairs.insert(x);
  }

  REP(i, Ce) {
    int x;
    scanf("%d", &x);
    elevators.insert(x);
  }


  auto solve = [&] (int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
      return abs(y1 - y2);
    }

    vector<int> stairs_candidates, elevator_candidates;

    for (int y: {y1, y2}) {
      auto it = stairs.lower_bound(y);
      if (it != stairs.end()) stairs_candidates.push_back(*it);
      if (it != stairs.begin()) stairs_candidates.push_back(*(--it));
    }

    for (int y: {y1, y2}) {
      auto it = elevators.lower_bound(y);
      if (it != elevators.end()) elevator_candidates.push_back(*it);
      if (it != elevators.begin()) elevator_candidates.push_back(*(--it));
    }

    int ret = inf;
    for (int y: stairs_candidates) {
      ret = min(ret, abs(y-y1) + abs(y-y2) + abs(x1-x2));
    }
    for (int y: elevator_candidates) {
      ret = min(ret, abs(y-y1) + abs(y-y2) + (abs(x1-x2) + V - 1) / V);
    }

    return ret;
  };

  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    printf("%d\n", solve(x1, y1, x2, y2));
  }
  return 0;
}