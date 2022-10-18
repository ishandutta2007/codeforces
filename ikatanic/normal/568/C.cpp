#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

namespace tarjan2sat {
  const int MAXN = 420;

  vector<int> E[MAXN];

  bool ans[MAXN];
  bool stk[MAXN];
  int val[MAXN];
  int disc[MAXN];
  int n, t;
  bool consistent;

  stack<int> S;
  
  int tarjan(int x) {
    int lw = disc[x] = ++t;
    
    stk[x] = true;
    S.push(x);

    for (int y: E[x])
      if (disc[y] == 0) lw = min(lw, tarjan(y)); else
        if (stk[y]) lw = min(lw, disc[y]);
    
    if (lw == disc[x]) {
      vector<int> comp;
      bool ok = true;
      while (!S.empty()) {
        int y = S.top(); S.pop();
        comp.push_back(y);
        ok &= val[y/2] == -1;
        stk[y] = false;
        if (y == x) break;
      }

      if (ok) {
        for (int y: comp)
          val[y/2] = y&1;
        for (int y: comp)
          if (val[y/2] != (y&1)) consistent = false;
      }
    }
    return lw;
  }

  bool solve() {
    consistent = true;
    REP(i, 2*n)
      if (!disc[i]) tarjan(i);
    return consistent;
  }
  
  void add_impl(int i, bool vi, int j, bool vj) {
    E[2*i + vi].push_back(2*j + vj);
    E[2*j + !vj].push_back(2*i + !vi);
  }

  void add_must(int i, bool v) {
    E[2*i + !v].push_back(2*i + v);
  }

  void init(int _n) {
    n = _n, t = 0;
    REP(i, 2*n) {
      disc[i] = 0;
      stk[i] = false;
      E[i].clear();
    }
    REP(i, n) val[i] = -1;
  }
};

const int MAX = 444;

char s[MAX];
char type[MAX];
vector<int> E[MAX];

int main(void) {
  scanf("%s", type);
  int sigma = strlen(type);

  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int pos1, pos2;
    char t1[11], t2[11];
    scanf("%d %s %d %s", &pos1, t1, &pos2, t2);
    --pos1, --pos2;
    E[pos1*2 + (t1[0] == 'V')].push_back(pos2*2 + (t2[0] == 'V'));
  }

  scanf("%s", s);
  REP(i, n) s[i] -= 'a';

  bool good = true;
  REP(i, n) {
    int x = i*2 + (type[s[i]] == 'V');
    for (int y: E[x]) {
      int j = y / 2;
      good &= (type[s[j]] == 'V') == (y % 2);
    }
  }

  if (good) {
    REP(i, n) putchar(s[i] + 'a');
    putchar('\n');
    return 0;
  }

  for (char c: {'V', 'C'}) {
    bool all = true;
    REP(i, sigma) all &= type[i] == c;
    if (all) {
      REP(i, n) E[2*i + !(c == 'V')].push_back(2*i + (c == 'V'));
    }
  }

  for (int i = n-1; i >= 0; --i) {
    bool bio[2] = {false, false};
    for (int c = s[i] + 1; c < sigma; ++c) {
      if (bio[type[c] == 'V']) continue;
      bio[type[c] == 'V'] = true;

      tarjan2sat::init(n);
      REP(x, 2*n) for (int y: E[x])
        tarjan2sat::add_impl(x/2, x%2, y/2, y%2);
      REP(j, i) tarjan2sat::add_must(j, type[s[j]] == 'V');
      tarjan2sat::add_must(i, type[c] == 'V');

      if (tarjan2sat::solve()) {
        s[i] = c;
        for (int j = i + 1; j < n; ++j) {
          bool bioj[2] = {false, false};
          bool ok = false;

          for (int cj = 0; cj < sigma; ++cj) {
            if (bioj[type[cj] == 'V']) continue;
            bioj[type[cj] == 'V'] = true;

            tarjan2sat::init(n);
            REP(x, 2*n) for (int y: E[x])
              tarjan2sat::add_impl(x/2, x%2, y/2, y%2);
            REP(k, j) tarjan2sat::add_must(k, type[s[k]] == 'V');
            tarjan2sat::add_must(j, type[cj] == 'V');
            
            if (tarjan2sat::solve()) {
              s[j] = cj;
              ok = true;
              break;
            }
          }
          
          assert(ok);
        }

        REP(i, n) putchar(s[i] + 'a');
        putchar('\n');
        return 0;
      }
    }
  }

  puts("-1");
  return 0;
}