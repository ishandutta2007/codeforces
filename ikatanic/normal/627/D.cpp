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

const int MAX = 200200;

int a[MAX];
bool ok[MAX];
bool bio[MAX];
int n, k;

int cnt[MAX], good[MAX], tail[MAX];
int down[MAX], up[MAX], upgood[MAX];

vector<int> E[MAX];

void dfs(int x, int dad) {
  cnt[x] = 1;
  good[x] = true;
  tail[x] = 0;
  bio[x] = true;
  for (int y: E[x]) {
    if (y == dad) continue;
    if (!ok[y]) { good[x] = false; continue; }
    dfs(y, x);
    
    if (!good[y]) {
      good[x] = false;
      tail[x] = max(tail[x], down[y]);
    } else {
      cnt[x] += cnt[y];
    }
  }

  down[x] = cnt[x] + tail[x];
}

bool dfs_up(int x, int dad) {
  int whole = cnt[x];
  if (upgood[x]) whole += up[x] + tail[x];
  else whole += max(up[x], tail[x]);

  if (whole >= k) return true;
  
  int t1 = 0, t2 = 0;
  if (!upgood[x]) t1 = up[x];

  int cntbad = !upgood[x];
  for (int y: E[x]) {
    if (y == dad) continue;
    if (!ok[y]) { cntbad++; continue; }
    if (!good[y]) {
      cntbad++;
      if (down[y] >= t1) {
        t2 = t1;
        t1 = down[y];
      } else if (down[y] > t2) t2 = down[y];
    }
  }

  int ncnt = cnt[x];
  if (upgood[x]) ncnt += up[x];

  for (int y: E[x]) {
    if (y == dad) continue;
    if (!ok[y]) continue;
    
    int all = ncnt;
    if (!good[y]) all += t1 == down[y] ? t2 : t1;
    else all = all - cnt[y] + t1;
    
    up[y] = all;
    upgood[y] = (cntbad - (!good[y]) == 0);

    if (dfs_up(y, x)) return true;
  }
  return false;
}

bool can(int R) {
  REP(i, n) ok[i] = a[i] >= R;
  REP(i, n) bio[i] = false;

  REP(i, n)
    if (!bio[i] && ok[i]) {
      dfs(i, -1);
      upgood[i] = true;
      up[i] = 0;
      if (dfs_up(i, -1)) return true;
    }
  return false;
}

int main(void) {
  scanf("%d %d", &n, &k);
  REP(i, n) scanf("%d", &a[i]);
  REP(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }


  int lo = 0, hi = 1e7;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (can(mid)) lo = mid;
    else hi = mid - 1;
  }

  printf("%d\n", lo);
  return 0;
}