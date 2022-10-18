#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 333;
const int inf = 1e9;
const int MAXC = 2e8;

struct Spotlight {
  int x, l;
  friend bool operator < (const Spotlight& a, const Spotlight& b) {
    return a.x < b.x;
  }
} a[MAX];

int f[MAX][MAX][MAX];
int idx[MAX][3];
int rmq[MAX][MAX];

void update(int i, int left, int right, int r) {
  f[i][left][right] = max(f[i][left][right], r);
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d %d", &a[i].x, &a[i].l);
    a[i].x += MAXC;
  }
  a[n++] = {0, 0};
  sort(a, a + n);

  vector<int> pos;
  REP(i, n) {
    pos.push_back(a[i].x - a[i].l);
    pos.push_back(a[i].x);
    pos.push_back(a[i].x + a[i].l);
  }
  sort(pos.begin(), pos.end());
  pos.erase(unique(pos.begin(), pos.end()), pos.end());
  int m = pos.size();

  REP(i, n) {
    int v[3] = {a[i].x - a[i].l, a[i].x, a[i].x + a[i].l};
    REP(j, 3) REP(k, m)
      if (pos[k] == v[j]) idx[i][j] = k;
  }

  REP(i, n) FOR(j, i, n)
    FOR(k, i, j+1) rmq[i][j] = max(rmq[i][j], idx[k][2]);

  REP(i, n+1) REP(left, m) REP(right, m) f[i][left][right] = -inf;
  f[0][0][0] = 0;
  REP(i, n-1) REP(left, m) REP(right, m) {
    int r = f[i][left][right];
    if (r == -inf) continue;
    
    if (a[i+1].x <= pos[right]) {
      int nright = max(right, idx[i+1][2]);
      update(i+1, left, nright, pos[nright] - pos[right] + r);
      continue;
    }

    FOR(next, i+1, n)
      if (a[next].x - a[next].l <= pos[right]) {
        int nright = max(idx[next][1], rmq[i+1][next-1]);
        update(next, left, nright, pos[nright] - pos[right] + r);
      } else {
        int nleft = idx[next][0];
        int nright = max(idx[next][1], rmq[i+1][next-1]);
        update(next, nleft, nright, pos[nright] - pos[nleft] + r);
      }
    
    int nleft = idx[i+1][1];
    int nright = idx[i+1][2];
    update(i+1, nleft, nright, pos[nright] - pos[nleft] + r);
  }
  
  int ans = 0;
  REP(i, n) REP(left, m) REP(right, m) {
    ans = max(ans, f[i][left][right]);
  }
  printf("%d\n", ans);
  return 0;
}