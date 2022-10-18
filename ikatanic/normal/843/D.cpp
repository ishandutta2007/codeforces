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

const int MAXBUFF = 1<<20;

namespace IO {
  char buffer[MAXBUFF], *p = buffer+MAXBUFF;
  
  inline char read_char() {
    if (p == buffer+MAXBUFF) {
      fread(buffer, 1, MAXBUFF, stdin);
      p = buffer;
    }
    return *p++;
  }
  
  inline int read_int() {
    char c;
    while (!isdigit(c = read_char()));
    int ret = c-'0';
    while (isdigit(c = read_char())) ret = ret*10 + c-'0';
    return ret;
  }
};

const int MAX = 100010;
const llint inf = 1e18;

vector<int> E[MAX];
int a[MAX], b[MAX], c[MAX];

llint d[MAX], f[MAX];
int n, m, qs;

void dijkstra(int x) {
  set<pair<llint, int>> S;
  REP(i, n) d[i] = inf;
  d[0] = 0;
  S.insert({d[0], 0});

  while (S.size()) {
    int x = S.begin()->second;
    S.erase(S.begin());

    for (int i: E[x]) {
      int y = b[i];
      llint nd = d[x] + c[i];
      if (nd < d[y]) {
        S.erase({d[y], y});
        d[y] = nd;
        S.insert({d[y], y});
      }
    }
  }
}

         
void recalc(int x, int ch) {
  ch++;
  vector<vector<int>> q(ch);

  REP(i, n) f[i] = inf;
  q[0].push_back(x);
  f[x] = 0;

  REP(qi, ch) {
    REP(i, (int)q[qi].size()) {
      int x = q[qi][i];
      if (qi > f[x]-d[x]) continue;
      
      for (int i: E[x]) {
        int y = b[i];
        llint nd = f[x] + c[i];
        llint g = nd - d[y];
        if (0 <= g && g < ch && nd < f[y]) {
          f[y] = nd;
          q[g].push_back(y);
        }
      }
    }
    q[qi].clear();
  }
  REP(i, n) d[i] = f[i];
}

int main(void) {
  n = IO::read_int();
  m = IO::read_int();
  qs = IO::read_int();

  REP(i, m) {
    a[i] = IO::read_int();
    b[i] = IO::read_int();
    c[i] = IO::read_int();
    --a[i], --b[i];
    E[a[i]].push_back(i);
  }

  dijkstra(0);

  int ch = 0;
  while (qs--) {
    int tip = IO::read_int();
    
    if (tip == 1) {
      int x = IO::read_int();
      --x;
      if (ch > 0) {
        recalc(0, ch);
        ch = 0;
      }
      printf("%lld\n", d[x] >= inf ? -1 : d[x]);
    }

    if (tip == 2) {
      int k = IO::read_int();
      REP(i, k) {
        int x = IO::read_int();
        --x;
        c[x]++;
      }
      ch += k;
    }
  }
  
  return 0;
}