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

const int MAX = 200100;

struct Event {
  int l, r, tip;
};

map<int, vector<Event>> e;

struct Teacher {
  int l, r;
};

vector<int> E[MAX];
Teacher a[MAX];
Teacher b[MAX];
vector<int> w[MAX];
bool bio[MAX], side[MAX];
char ans[MAX];

void no_solution() {
  puts("IMPOSSIBLE");
  exit(0);
}

vector<int> v[2];

void dfs(int x, int s, int L[2], int R[2]) {
  if (bio[x]) {
    if (side[x] != s) no_solution();
    return;
  }

  bio[x] = true;
  side[x] = s;
  v[s].push_back(x);
  L[s] = max(L[s], b[x].l);
  R[s] = min(R[s], b[x].r);
  
  for (int y: E[x])
    dfs(y, s^1, L, R);
}

int main(void) {
  int lb, ub;
  scanf("%d %d", &lb, &ub);
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) scanf("%d %d", &b[i].l, &b[i].r);
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  
  int nn = 0;
  REP(i, n)
    if (!bio[i]) {
      int L[2] = {0, 0};
      int R[2] = {ub, ub};
      v[0].clear(), v[1].clear();
      dfs(i, 0, L, R);
      w[nn] = v[0];
      a[nn++] = {L[0], R[0]};
      w[nn] = v[1];
      a[nn++] = {L[1], R[1]};
      if (L[0] > R[0] || L[1] > R[1]) no_solution();
    }
  int oldn = n;
  n = nn;

  for (int i = 0; i < n; i += 2) {
    int j = i + 1;
    
    int lo = max(a[i].l, a[j].l);
    int hi = min(a[i].r, a[j].r);
    if (lo <= hi) {
      int l = min(a[i].l, a[j].l);
      int r = max(a[i].r, a[j].r);
      e[lo].push_back({l, r, +1});
      e[hi+1].push_back({l, r, -1});
    }

    for (int x: {i, j}) {
      int l = max(0, a[x].l);
      int r = min(lo-1, a[x].r);
      if (l <= r) {
        e[l].push_back({a[x^1].l, a[x^1].r, +1});
        e[r+1].push_back({a[x^1].l, a[x^1].r, -1});
      }
      l = max(hi+1, a[x].l);
      r = min(ub, a[x].r);
      if (l <= r) {
        e[l].push_back({a[x^1].l, a[x^1].r, +1});
        e[r+1].push_back({a[x^1].l, a[x^1].r, -1});
      }
    }
  }

  multiset<int> sl, sr;

  for (auto it = e.begin(); it != e.end(); ++it) {
    int x = it->first;
    int nx = ub;
    if (++it != e.end()) nx = it->first-1;
    --it;

    for (auto &ev: it->second)
      if (ev.tip == +1) {
        sl.insert(ev.l);
        sr.insert(ev.r);
      } else {
        sl.erase(sl.find(ev.l));
        sr.erase(sr.find(ev.r));
      }
    
    if (x <= ub && (int)sl.size() == n/2) {
      int L = max(lb - x, *(--sl.end()));
      int R = min(*sr.begin(), ub - x);
      
      if (L > R && nx <= ub) {
        x = nx;
        L = max(lb - x, *(--sl.end()));
        R = min(*sr.begin(), ub - x);
      }
      
      if (L <= R) {
        int y = L;
        for (int i = 0; i < n; i += 2) {
          side[i] = 0;
          if (a[i].r < x || a[i].l > x) side[i] = 1;
          if (a[i^1].r < x || a[i^1].l > x) side[i] = 0;
          if (a[i^1].r < y || a[i^1].l > y) side[i] = 1;
          for (int x: w[i]) ans[x] = side[i] + '1';
          for (int x: w[i^1]) ans[x] = (side[i]^1) + '1';
        }
        ans[oldn] = '\0';

        puts("POSSIBLE");
        printf("%d %d\n", x, y);
        puts(ans);
        exit(0);
      }
    }
  }

  no_solution();
  return 0;
}