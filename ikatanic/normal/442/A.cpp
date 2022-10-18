#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int N = 25;

int cnt[N];
int mask[N];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    char s[10];
    scanf("%s", s);
    int p1 = 0;
    if (s[0] == 'R') p1 = 0;
    if (s[0] == 'G') p1 = 1;
    if (s[0] == 'B') p1 = 2;
    if (s[0] == 'Y') p1 = 3;
    if (s[0] == 'W') p1 = 4;
    int p2 = s[1] - '1';
    cnt[p1*5 + p2]++;
  }

  int ans = 10;
  REP(s, 1<<10) {
    REP(j, N) mask[j] = 0;
    
    int bc = 0;
    REP(i, 10)
      if (s&(1<<i)) {
        bc++;
        REP(j, N) {
          if (i < 5 && (j/5) == i)
            mask[j] |= 1<<i;
          if (i >= 5 && (j%5) == i-5)
            mask[j] |= 1<<i;
        }
      }

    set<int> S;
    int c = 0;
    REP(j, N)
      if (cnt[j]) S.insert(mask[j]), c++;
    if (S.size() == c) ans = min(ans, bc);
  }
  
  printf("%d\n", ans);
  return 0;
}