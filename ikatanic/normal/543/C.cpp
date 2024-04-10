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

const int MAX = 22;
const int inf = 1e9;

char a[MAX][MAX];
int c[MAX][MAX];
int best[MAX];
int f[1<<20];

int mask[MAX*MAX];
int cost[MAX*MAX];
int cnt;

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) scanf("%s", a[i]);
  REP(i, n) REP(j, m) scanf("%d", c[i]+j);
  REP(i, n) best[i] = *min_element(c[i], c[i] + m);
  
  REP(j, m) {
    static bool bio[MAX];
    REP(i, n) bio[i] = false;
    
    REP(i, n)
      if (!bio[i]) {
        int sum = 0, mini = 0, ms = 0;
        REP(ii, n)
          if (a[i][j] == a[ii][j]) {
            ms |= 1<<ii;
            sum += c[ii][j];
            mini = max(mini, c[ii][j]);
            bio[ii] = true;
          }
        sum -= mini;

        if (ms == (1<<i)) {
          best[i] = min(best[i], sum);
          continue;
        }

        mask[cnt] = ms;
        cost[cnt] = sum;
        cnt++;
      }
  }

  REP(s, 1<<n) f[s] = inf;
  f[0] = 0;

  REP(s, 1<<n) {
    REP(i, n)
      f[s | (1<<i)] = min(f[s | (1<<i)], f[s] + best[i]);
   
    REP(i, cnt)
      f[s | mask[i]] = min(f[s | mask[i]], f[s] + cost[i]);
  }
  
  printf("%d\n", f[(1<<n)-1]);
  return 0;
}