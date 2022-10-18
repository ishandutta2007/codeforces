#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <set>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

set<pair<int, int>> S;
map<pair<int, int>, pair<int, int>> M;
set<int> bio;

int main(void) {
  int n, q;
  scanf("%d %d", &n, &q);
  S.insert({0, n-1});
  M[{0, n-1}] = {-1, -1};
  REP(i, q) {
    int x, y;
    char d[11];
    scanf("%d %d %s", &y, &x, d); --x, --y;

    if (bio.count(y)) {
      printf("0\n");
      continue;
    }
    bio.insert(y);

    auto it = S.upper_bound({y, n+1});
    assert(it != S.begin());
    --it;

    auto p = *it;
    auto r = M[*it];
    S.erase(it);
    M.erase(*it);


    if (d[0] == 'U') {
      printf("%d\n", x - r.first);
      if (y > p.first) {
        S.insert({p.first, y-1});
        M[{p.first, y-1}] = r;
      }
      if (y < p.second) {
        S.insert({y+1, p.second});
        M[{y+1, p.second}] = {r.first, y};
      }
    }
    if (d[0] == 'L') {
      printf("%d\n", y - r.second);
      if (y > p.first) {
        S.insert({p.first, y-1});
        M[{p.first, y-1}] = {x, r.second};
      }
      if (y < p.second) {
        S.insert({y+1, p.second});
        M[{y+1, p.second}] = r;
      }
    }
  }

  return 0;
}