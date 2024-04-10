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

const int MAXN = 100010;

struct interval {
  int a, b, k, i;
  friend bool operator < (const interval &a, const interval &b) {
    if (a.b != b.b) return a.b > b.b;
    return a.a > b.a;
  }
};

int who[MAXN];
interval act[MAXN], part[MAXN];

struct cmp {
  bool operator () (const int &a, const int &b) {
    if (act[a].a != act[b].a) return act[a].a < act[b].a;
    return a < b;
  }
};
    
set<int, cmp> S;

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d %d", &part[i].a, &part[i].b);
    part[i].i = i;
  }

  int m;
  scanf("%d", &m);
  REP(i, m) {
    scanf("%d %d %d", &act[i].a, &act[i].b, &act[i].k); 
    act[i].i = i;
  }

  sort(act, act + m);
  sort(part, part + n);
  
  int cur = 0;
  REP(i, n) {
    while (cur < m && act[cur].b >= part[i].b) S.insert(cur++);
      

    act[m].a = part[i].a;
    auto it = S.lower_bound(m);
    if (it == S.begin()) {
      puts("NO");
      return 0;
    }
    
    --it;
    int j = *it;
    act[j].k--;
    if (act[j].k == 0) S.erase(it);

    who[part[i].i] = act[j].i;
  }

  puts("YES");
  REP(i, n) printf("%d%c", who[i]+1, i+1 < n ? ' ' : '\n');
  return 0;
}