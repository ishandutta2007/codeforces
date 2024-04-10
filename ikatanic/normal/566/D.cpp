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

typedef long long llint;

const int MAX = 200200;

int dad[MAX];

int findset(int x) {
  return x == dad[x] ? x : dad[x] = findset(dad[x]);
}

void merge(int x, int y) {
  dad[findset(x)] = findset(y);
}

int main(void) {
  int n, q;
  scanf("%d %d", &n, &q);
  REP(i, n) dad[i] = i;

  set<int> S;
  REP(i, n) S.insert(i);

  REP(i, q) {
    int t, x, y;
    scanf("%d %d %d", &t, &x, &y); --x, --y;
    
    if (t == 1) merge(x, y);

    if (t == 2) {
      auto it = --S.upper_bound(x);
      int first = *it++;
      while (it != S.end() && *it <= y) {
        merge(first, *it);
        auto next = it; next++;
        S.erase(it);
        it = next;
      }
    }

    if (t == 3) puts(findset(x) == findset(y) ? "YES" : "NO");
  }

  return 0;
}