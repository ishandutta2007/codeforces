#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 100100;

enum {BOTH, ONE, TAIL, TAILONE};

llint f[MAX][4];
llint a[MAX];
vector<int> E[MAX];

void dfs(int x, int dad) {
  for (int y: E[x])
    if (y != dad) dfs(y, x);

  static multiset<llint, greater<llint>> S[4];
  REP(i, 4) S[i].clear();

  for (int y: E[x]) {
    if (y == dad) continue;
    REP(i, 4) S[i].insert(f[y][i]);
  }

  f[x][TAIL] = f[x][ONE] = a[x];
  for (int y: E[x]) {
    if (y == dad) continue;

    REP(i, 4) S[i].erase(S[i].find(f[y][i]));
   
    f[x][TAIL] = max(f[x][TAIL], a[x] + f[y][TAIL]);
                     
    f[x][TAILONE] = max(f[x][TAILONE], a[x] + f[y][ONE]);
    f[x][TAILONE] = max(f[x][TAILONE], a[x] + f[y][TAILONE]);
    if (S[TAIL].size()) f[x][TAILONE] = max(f[x][TAILONE], a[x] + *S[TAIL].begin() + f[y][ONE]);
    
    f[x][ONE] = max(f[x][ONE], f[y][ONE]);
    f[x][ONE] = max(f[x][ONE], a[x] + f[y][TAIL]);
    if (S[TAIL].size()) f[x][ONE] = max(f[x][ONE], a[x] + f[y][TAIL] + *S[TAIL].begin());

    if (S[ONE].size()) {
      f[x][BOTH] = max(f[x][BOTH], *S[ONE].begin() + f[y][ONE]);
      f[x][BOTH] = max(f[x][BOTH], *S[ONE].begin() + a[x] + f[y][TAIL]);
    }
    f[x][BOTH] = max(f[x][BOTH], a[x] + f[y][TAILONE]);
    f[x][BOTH] = max(f[x][BOTH], a[x] + f[y][ONE]);
    f[x][BOTH] = max(f[x][BOTH], f[y][BOTH]);

    if (S[TAIL].size() >= 2) {
      llint score = a[x] + *S[TAIL].begin() + *(++S[TAIL].begin());
      f[x][BOTH] = max(f[x][BOTH], score + f[y][ONE]);
    }
    if (S[TAIL].size()) {
      f[x][BOTH] = max(f[x][BOTH], a[x] + f[y][TAILONE] + *S[TAIL].begin());
    }

    REP(i, 4) S[i].insert(f[y][i]);
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%lld", &a[i]);
  REP(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  dfs(0, -1);
  printf("%lld\n", f[0][BOTH]);
  return 0;
}