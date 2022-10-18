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

const int MAX = 1010;

bool bio[MAX];
bool e[MAX][MAX];
int n;

void dfs(int x) {
  bio[x] = true;
  REP(i, n)
    if (!bio[i] && e[x][i]) dfs(i);
}

int main(void) {
  int m;
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    e[a][b] = e[b][a] = 1;
  }

  dfs(0);
  int ans = 0;
  REP(i, n) ans += bio[i];

  if (ans == n && m == n-1) puts("yes");
  else puts("no");
  return 0;
}