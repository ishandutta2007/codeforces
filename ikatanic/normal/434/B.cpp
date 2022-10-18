#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 1010;

struct solver {
  int a[MAXN][MAXN];
  int h[MAXN][MAXN];
  int n, m;
  
  void calch(int j) {
    int cur = 0;
    REP(i, n) {
      if (a[i][j]) cur++; else cur = 0;
      h[i][j] = cur;
    }
  }

  void init(int w, int h, int v[MAXN][MAXN]) {
    n = w, m = h;
    REP(i, n) REP(j, m) a[i][j] = v[i][j];
    REP(j, m) calch(j);
  }
  
  void flip(int x, int y) {
    a[x][y] ^= 1;
    calch(y);
  }

  int prev[MAXN], next[MAXN];
  int query(int x, int y) {
    stack<int> S;
    REP(j, m) {
      while (!S.empty() && h[x][j] <= h[x][S.top()]) S.pop();
      prev[j] = (S.empty() ? -1 : S.top());
      S.push(j);
    }
    while (!S.empty()) S.pop();
    for (int j = m-1; j >= 0; --j) {
      while (!S.empty() && h[x][j] <= h[x][S.top()]) S.pop();
      next[j] = (S.empty() ? m : S.top());
      S.push(j);
    }

    int ans = 0;
    REP(j, m)
      if (prev[j] < y && next[j] > y) 
        ans = max(ans, (next[j]-prev[j]-1)*h[x][j]);
    return ans;
  }
} f[4];

int a[MAXN][MAXN], b[MAXN][MAXN];
int tip[MAXN], x[MAXN], y[MAXN];
vector<int> qx[4], qy[4];

int main(void) {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  REP(i, n) REP(j, m) scanf("%d", a[i]+j);
  REP(i, q) {
    scanf("%d %d %d", tip+i, x+i, y+i);
    --x[i], --y[i];
  }

  REP(r, 4) {
    f[r].init(n, m, a);
    REP(i, q) {
      qx[r].push_back(x[i]);
      qy[r].push_back(y[i]);
    }
    
    REP(i, n) REP(j, m) b[i][j] = a[i][j];
    REP(i, n) REP(j, m) a[j][n-1-i] = b[i][j];
    REP(i, q) {
      int tmp = x[i];
      x[i] = y[i];
      y[i] = n-1-tmp;
    }
    swap(n, m);
  }
  
  REP(i, q)
    if (tip[i] == 1) {
      REP(r, 4)
        f[r].flip(qx[r][i], qy[r][i]);
    } else {
      int ans = 0;
      REP(r, 4)
        ans = max(ans, f[r].query(qx[r][i], qy[r][i]));
      printf("%d\n", ans);
    }
  return 0;
}