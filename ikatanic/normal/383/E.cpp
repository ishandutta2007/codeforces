#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

#include <set>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int N = 24;
const int M = 1<<24;

int f[M], dp[M];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    char s[5];
    scanf("%s", s);
    REP(i, 3) s[i] -= 'a';

    sort(s, s + 3);
    int k = (unique(s, s + 3) - s);
    
    int s0 = 1<<s[0];
    int s1 = 1<<s[1];
    int s2 = 1<<s[2];

    if (k == 1) f[s0]++;
    if (k == 2) f[s0]++, f[s1]++, f[s0|s1]--;
    if (k == 3) {
      f[s0]++, f[s1]++, f[s2]++;
      f[s0|s1]--, f[s0|s2]--, f[s1|s2]--;
      f[s0|s1|s2]++;
    }
  }

  int ans = 0;
  REP(s, M) {
    int l = -1, r = -1;
    REP(i, N)
      if (s&(1<<i)) {
        if (l == -1) l = i;
        r = i;
      }
    if (r == -1) continue;

    if (l == r) dp[s] = f[1<<l]; else {
      dp[s] = dp[s^(1<<l)] + dp[s^(1<<r)] - dp[s^(1<<l)^(1<<r)];
      for (int k = l+1; k < r; ++k)
        if (s&(1<<k))
          dp[s] += f[(1<<l)|(1<<r)|(1<<k)];
      dp[s] += f[(1<<l)|(1<<r)];
    }
    ans ^= dp[s]*dp[s];
  }
  
  printf("%d\n", ans);
  return 0;
}