#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 220;
const int mod = 1e9 + 7;

bool ok[MAXN][MAXN];
int f[MAXN][MAXN];
int x[MAXN], y[MAXN];
int n;

llint ar[MAXN][MAXN];

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int mul(int a, int b) {
  return (llint(a)*b)%mod;
}

llint area(int a, int b, int c) {
  return llint(x[b]-x[a])*(y[c]-y[a]) - llint(y[b]-y[a])*(x[c]-x[a]);
}

int ccw(int a, int b, int c) {
  llint w = area(a, b, c);
  return w < 0 ? -1 : w > 0;
}

bool isGood(int a, int b, int c) {
  llint aa = area(a, b, c);
  if (aa == 0) return false;
  if (!ok[a][c] || !ok[b][c]) return false;
  return abs(ar[0][1]) == abs(aa) + abs(ar[b][a]) + abs(ar[c][b]) + abs(ar[a][c]);
}

int solve(int a, int b) {
  if (f[a][b] != -1) return f[a][b];
  
  auto next = [] (int i) { return i == n-1 ? 0 : i+1; };

  int x = b, cnt = 1;
  while (x != a) x = next(x), cnt++;

  if (cnt <= 3) return f[a][b] = 1;

  x = next(b);
  f[a][b] = 0;
  while (x != a) {
    if (isGood(a, b, x))
      f[a][b] = add(f[a][b], mul(solve(x, b), solve(a, x)));
    x = next(x);
  }
  return f[a][b];
}

bool onSegment(int a, int b, int c) {
  int x1 = x[a], y1 = y[a];
  int x2 = x[b], y2 = y[b];
  int xx = x[c], yy = y[c];

  if (ccw(a, b, c)) return false;
  if (x1 > x2) swap(x1, x2);
  if (y1 > y2) swap(y1, y2);
  return x1 <= xx && xx <= x2 && y1 <= yy && yy <= y2;
}

int main(void) {
  scanf("%d", &n);
  REP(i, n) scanf("%d %d", x+i, y+i);

  auto next = [] (int i) { return i == n-1 ? 0 : i+1; };
  
  REP(i, n) REP(j, n) {
    ar[i][j] = 0;

    vector<int> v;
    int c = j;
    while (c != i) {
      v.push_back(c);
      c = next(c);
    }
    v.push_back(i);
    
    int sz = v.size();
    if (sz < 3) continue;

    REP(k, sz) {
      int a = v[0], b = v[(k+1)%sz], c = v[(k+2)%sz];
      ar[i][j] += area(a, b, c);
    }
  }
  REP(i, n) REP(j, n) {
    ok[i][j] = true;
    REP(k, n)
      if (k != i && k != j && onSegment(i, j, k)) ok[i][j] = false;
  }

  memset(f, -1, sizeof(f));
  printf("%d\n", solve(0, 1));
  return 0;
}