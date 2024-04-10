#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

namespace Tarjan {
  const int MAXN = 200020;

  stack<int> S;
  vector<int> E[MAXN];
  int disc[MAXN];
  int comp_id[MAXN];
  bool stk[MAXN];
  int tick;
  bool good;

  bool inCycle[MAXN];
  
  int dfs(int x) {
    int lowlink = disc[x] = tick++;
    stk[x] = true;
    S.push(x);
    for (int y: E[x])
      if (!disc[y]) lowlink = min(lowlink, dfs(y)); else
        if (stk[y]) lowlink = min(lowlink, disc[y]);
    
    if (lowlink == disc[x]) {
      vector<int> cyc;
      while (stk[x]) {
        cyc.push_back(S.top());
        comp_id[S.top()] = x;
        stk[S.top()] = false;
        S.pop();
      }
      if (cyc.size() > 1) {
        for (int x: cyc)
          inCycle[x] = true;
      }
    }
    return lowlink;
  }
  
  void init(int n) {
    REP(i, n) E[i].clear();
  }
  
  void run(int n) {
    tick = 1;
    REP(i, n) inCycle[i] = false;
    REP(i, n) disc[i] = 0;
    REP(i, n) if (!disc[i]) dfs(i);
  }
};

const int MAX = 201000;
const int MAXN = 31;

char a[MAX];
char* s[MAXN];
int len[MAXN];
int z[MAXN][MAX];

void calculateZ(char *s, int *z, int n) { 
  z[0] = n;
  int L = 0, R = 0;
  FOR(i, 1, n) {
    if (i > R) L = i, R = i-1, z[i] = 0; else
      if (z[i-L] < R-i+1) z[i] = z[i-L]; else
        z[i] = R-i+1, L = i;
    while (R+1 < n && s[i + z[i]] == s[z[i]]) R++, z[i]++;
  }
}

int main(void) {
  int tlen = 0;
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%s", a + tlen);
    s[i] = a + tlen;
    len[i] = strlen(a + tlen);
    tlen += len[i];
  }
  
  REP(i, n) {
    static char buf[MAX];
    int p = 0;
    REP(j, len[i]) buf[p++] = s[i][j];
    REP(j, tlen) buf[p++] = a[j];
    calculateZ(buf, z[i], p);
  }
  
  auto good = [&] (int l, int r) {
    Tarjan::init(2*tlen+1);
    FOR(i, l, r) {
      int x = s[i]-a;
      Tarjan::E[2*tlen].push_back(2*x);
      Tarjan::E[2*tlen].push_back(2*x+1);
      
      REP(j, len[i]) {
        FOR(k, l, r) {
          if (k == i && j == 0) continue;
          
          int lcp = min(z[k][s[i]+j-a+len[k]], min(len[k], len[i] - j));

          if (lcp == len[k] && lcp == len[i]-j) {
            int x = s[i]-a+j;
            Tarjan::E[2*x].push_back(2*tlen);
            Tarjan::E[2*x+1].push_back(2*tlen);
          } else
          if (lcp == len[i]-j) {
            int x = s[i]-a+j;
            int y = s[k]-a+lcp;
            Tarjan::E[2*x].push_back(2*y+1);
            Tarjan::E[2*x+1].push_back(2*y);
          } else
          if (lcp == len[k]) {
            int x = s[i]-a+j;
            int y = s[i]-a+j+lcp;
            Tarjan::E[2*x].push_back(2*y+1);
            Tarjan::E[2*x+1].push_back(2*y);
          }
        }
      }
    }

    Tarjan::run(2*tlen+1);
    FOR(i, l, r) FOR(j, 1, len[i])
    if (Tarjan::inCycle[2*(s[i]-a+j)]) return false;

    return true;
  };
  
  int ans = 0;
  int j = 0;
  REP(i, n) {
    j = max(j, i);
    while (j < n && good(i, j+1)) j++;
    ans += j - i;
  }

  printf("%d\n", ans);
  return 0;
}