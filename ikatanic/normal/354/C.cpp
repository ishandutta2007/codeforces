#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 1000100;

int s[2*MAXN];

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  REP(i, n) {
    int x;
    scanf("%d", &x);
    s[x]++;
  }
  
  for (int i = 1; i < 2*MAXN; ++i)
    s[i] += s[i-1];

  int ans = -1;
  for (int g = MAXN-1; g > 0; --g) {
    int cnt = 0;
    for (int l = g; l < MAXN; l += g) {
      cnt += s[min(l+g-1, l+k)];
      if (l-1 >= 0) cnt -= s[l-1];
    }
    if (cnt == n) { ans = g; break; }
  }

  printf("%d\n", ans);
  return 0;
}