#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

#include <map>
#include <set>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;
typedef pair<int, int> par;
#define x first
#define y second

const int MAXN = 100100;
const int inf = 1e9;

int a[3][MAXN];
map<int, int> M[3];

set<par> S;
multiset<int> cost;

void insert(par p) {
  auto insertCost = [](set<par> :: iterator it1, set<par> :: iterator it2) {
    if (it1 == S.end() || it2 == S.end()) return;
    if (*it1 > *it2) swap(it1, it2);
    cost.insert(it1->x + it2->y);
  };
  auto eraseCost = [](set<par> :: iterator it1, set<par> :: iterator it2) {
    if (it1 == S.end() || it2 == S.end()) return;
    if (*it1 > *it2) swap(it1, it2);
    cost.erase(cost.find(it1->x + it2->y));
  };

  auto it = S.lower_bound(p);
  if (it != S.end() && p.y <= it->y) return;
  
  if (it != S.begin()) {
    --it;
    while (p.y >= it->y) {
      auto itr = it; ++itr;
      eraseCost(it, itr);
      
      if (it == S.begin()) {
        S.erase(it);
        break;
      }
      
      auto itl = it; --itl;
      eraseCost(it, itl);
      insertCost(itl, itr);
      S.erase(it);
      it = itl;
    }
  }

  S.insert(p);
  it = S.find(p);
  auto itl = it; --itl;
  auto itr = it; ++itr;
  
  eraseCost(itl, itr);
  insertCost(it, itl);
  insertCost(it, itr);
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(j, 3) REP(i, n) {
    scanf("%d", a[j]+i);
    if (!M[j].count(a[j][i])) M[j][a[j][i]] = i+1;
  }

  int lx = 0, ly = 0;
  for (auto p: M[1])
    if (!M[0].count(p.x) && !M[2].count(p.x)) lx = max(lx, p.y);
  for (auto p: M[2])
    if (!M[0].count(p.x) && !M[1].count(p.x)) ly = max(ly, p.y);
  
  S.insert({lx, inf});
  S.insert({inf, ly});
  cost.insert(lx+ly);

  for (auto p: M[1])
    if (!M[0].count(p.x) && M[2].count(p.x)) insert({M[1][p.x], M[2][p.x]});

  bool ok = true;
  int ans = 3*n;
  for (int i = n; i > 0; --i)
    if (M[0][a[0][i-1]] == i) {
      int v = a[0][i-1];
      ans = min(ans, i + (*cost.begin()));
      if (!M[1].count(v) && !M[2].count(v)) { ok = false; break; }
      if (!M[2].count(v)) insert({M[1][v], inf}); else
        if (!M[1].count(v)) insert({inf, M[2][v]}); else
          insert({M[1][v], M[2][v]});
    }

  if (ok) ans = min(ans, 0 + (*cost.begin()));
  printf("%d\n", ans);
  return 0;
}