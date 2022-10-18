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

const int MAXN = 100010;

vector<int> E[MAXN];
bool bio[MAXN];

int dfs(int x) {
  if (bio[x]) return 0;
  bio[x] = true;
  int ans = 1;
  for (int y: E[x])
    ans += dfs(y);
  return ans;
}

int main(void) {
  int n, m, mod;
  scanf("%d %d %d", &n, &m, &mod);
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  
  int cnt = 0, p = 1 % mod;
  REP(i, n)
    if (!bio[i]) {
      p = llint(p) * dfs(i) % mod;
      cnt++;
    }

  int ans;
  if (cnt > 1) {
    ans = p;
    REP(i, cnt-2)
      ans = llint(ans) * n % mod;
  } else
    ans = 1 % mod;

  printf("%d\n", ans);
  return 0;
}