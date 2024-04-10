#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;
typedef pair<int, int> par;
#define a first
#define b second

const int MAXN = 1010;

char a[MAXN][20][20];
vector<par> v[MAXN];

bool e[MAXN][MAXN];
int dad[MAXN];
int who[MAXN];
int n;

int findset(int x) {
  return x == dad[x] ? x : dad[x] = findset(dad[x]);
}

void merge(int x, int y) {
  dad[findset(x)] = findset(y);
}

void dfs(int x, int dad) {
  printf("%d %d\n", x+1, dad+1);
  who[x] = dad;
  REP(i, n)
    if (e[x][i] && i != dad) dfs(i, x);
}

int main(void) {
  int r, c, w;
  scanf("%d %d %d %d", &r, &c, &n, &w);
  REP(i, n) REP(j, r) scanf("%s", a[i][j]);

  REP(i, n) REP(j, i) {
    int cnt = 0;
    REP(x, r) REP(y, c)
      cnt += a[i][x][y] != a[j][x][y];
    v[cnt].push_back({i, j});
  }
  REP(i, n) dad[i] = i;

  int ans = 0, cnt = 0;
  REP(k, r*c+1) {
    if (k*w >= r*c) break;
    for (par p: v[k])
      if (findset(p.a) != findset(p.b)) {
        e[p.a][p.b] = e[p.b][p.a] = true;
        merge(p.a, p.b);
        ans += k*w;
        cnt++;
      }
  }
  ans += (n-cnt)*r*c;
  
  printf("%d\n", ans);
  REP(i, n) who[i] = -1;
  REP(i, n)
    if (who[i] == -1) dfs(i, -1);
  return 0;
}