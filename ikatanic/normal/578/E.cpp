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

const int MAX = 100100;

char s[MAX];
int nx[MAX];
bool bio[MAX];

vector<int> go(int x) {
  vector<int> w;
  while (!bio[x]) {
    w.push_back(x);
    bio[x] = true;
    
    if (nx[x] == -1) break;
    x = nx[x];
  }
  return w;
}

int main(void) {
  scanf("%s", s);
  vector<int> l, r;
  int n = strlen(s);
  REP(i, n) {
    s[i] = s[i] == 'R';
    if (s[i]) r.push_back(i); else
      l.push_back(i);
  }

  vector<int> ansv;
  int ans = 1e9;
  REP(rot, 2) {
    REP(i, n) s[i] ^= 1;
    swap(l, r);

    int cntl = (n + 1) / 2;
    int cntr = n - cntl;
    if (cntl != (int)l.size() || cntr != (int)r.size()) continue;

    set<int> sl(l.begin(), l.end());
    set<int> sr(r.begin(), r.end());

    int start = *sl.begin();
    sl.erase(sl.begin());

    int end = -1;
    for (int i = n-1; i >= 0; --i) {
      if (end == -1) {
        if (n%2 == 0 && s[i]) { end = i; continue; }
        if (n%2 == 1 && !s[i]) { end = i; continue; }
      }

      if (!s[i]) {
        assert(sr.size());
        auto it = sr.lower_bound(i);
        if (it == sr.end()) it = sr.begin();
        nx[i] = *it;
        sr.erase(it);
      } else {
        assert(sl.size());
        auto it = sl.lower_bound(i);
        if (it == sl.end()) it = sl.begin();
        nx[i] = *it;
        sl.erase(it);
      }
    }
    nx[end] = -1;

    REP(i, n) bio[i] = false;
    go(start);

    vector<pair<int, int>> v[2][2];
    v[s[start]][s[end]].push_back({start, end});

    REP(i, n)
      if (!bio[i]) {
        static vector<int> tmp;
        tmp = go(i);
        nx[tmp.back()] = -1;
        v[s[i]][s[tmp.back()]].push_back({i, tmp.back()});
      }

    bool ch = true;
    while (ch) {
      ch = false;
      REP(s1, 2) REP(e1, 2) REP(e2, 2)
        if (v[s1][e1].size() && v[e1^1][e2].size()) {
          if (e2 == e1 && s1 == (e1^1) && v[s1][e1].size() < 2) continue;
          auto a = v[s1][e1].back(); v[s1][e1].pop_back();
          auto b = v[e1^1][e2].back(); v[e1^1][e2].pop_back();
          
          nx[a.second] = b.first;
          v[s1][e2].push_back({a.first, b.second});
          
          ch = true;
        }
    }

    if (v[0][1].size() == 1 && v[1][0].size() == 1) {
      auto a = v[0][1].back(); v[0][1].pop_back();
      auto b = v[1][0].back(); v[1][0].pop_back();
      
      if (a > b) swap(a, b);
      int tmp = nx[a.first];
      nx[a.first] = b.first;
      nx[b.second] = tmp;
      v[0][1].push_back(a);
    }

    vector<pair<int, int>> fin;
    REP(s, 2) REP(e, 2) 
      for (auto& p: v[s][e]) 
        fin.push_back(p);

    assert(fin.size() == 1);

    REP(i, n) bio[i] = false;
    auto w = go(fin[0].first);
    assert((int)w.size() == n);

    int cost = 0;
    REP(i, n-1) cost += w[i] > w[i + 1];
    if (cost < ans) ans = cost, ansv = w;
  }

  printf("%d\n", ans);
  for (int x: ansv) printf("%d ", x+1);
  printf("\n");
  return 0;
}