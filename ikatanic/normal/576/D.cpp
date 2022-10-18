#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <bitset>
#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int M = 150;
const int inf = 2e9;

struct matrix {
  bitset<M> r[M], c[M];
  void clear() {
    REP(i, M) r[i].reset(), c[i].reset();
  }
  bool get(int i, int j) { return r[i].test(j); }
  void set(int i, int j) { r[i].set(j); c[j].set(i); }
  friend matrix operator * (const matrix& a, const matrix& b) {
    matrix ans;
    REP(i, M) REP(j, M)
      if ((a.r[i] & b.c[j]).any()) ans.set(i, j);
    return ans;
  };
};

matrix power(matrix a, int b) {
  assert(b > 0); 
  b--;
  matrix r = a;
  while (b > 0) {
    if (b&1) r = r * a;
    a = a * a;
    b /= 2;
  }
  return r;
}

struct Flight {
  int a, b, d;
};

Flight f[M];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, m) scanf("%d %d %d", &f[i].a, &f[i].b, &f[i].d);
  REP(i, m) --f[i].a, --f[i].b;

  sort(f, f + m, [&] (const Flight& a, const Flight& b) {
      return a.d < b.d;
    }
  );

  int s = 0, t = n-1, d = 0;
  matrix cur, e;
  REP(i, n) cur.set(i, i);
  
  int ans = inf;
  REP(i, m) {
    if (f[i].d > d) {
      cur = cur * power(e, f[i].d - d);
      d = f[i].d;
    }
    e.set(f[i].a, f[i].b);
    
    static int dist[M];
    static queue<int> Q;
    REP(i, n) {
      dist[i] = -1;
      if (cur.get(s, i)) {
        dist[i] = 0;
        Q.push(i);
      }
    }

    while (!Q.empty()) {
      int x = Q.front(); Q.pop();
      REP(j, n)
        if (e.get(x, j))
          if (dist[j] == -1) {
            dist[j] = dist[x] + 1;
            Q.push(j);
          }
    }

    if (dist[t] != -1) ans = min(ans, d + dist[t]);
  }
  
  if (ans < inf) printf("%d\n", ans); else
    puts("Impossible");
  return 0;
}