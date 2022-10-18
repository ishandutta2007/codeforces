#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 1010;

int p[MAXN];
int a[MAXN];
bool e[MAXN][MAXN];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) scanf("%d", a+i);
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    e[a][b] = e[b][a] = true;
  }
  
  REP(i, n) p[i] = i;
  sort(p, p + n, [] (const int &x, const int &y) {
      return a[x] > a[y];
    }
  );

  int ans = 0;
  REP(pi, n) {
    int i = p[pi];
    REP(j, n)
      if (e[i][j]) ans += a[j];
    a[i] = 0;
  }

  printf("%d\n", ans);
  return 0;
}