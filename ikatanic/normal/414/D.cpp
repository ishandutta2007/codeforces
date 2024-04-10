#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 100100;

vector<int> E[MAXN];
int f[MAXN];
int s[MAXN];
llint w_s[MAXN];

void dfs(int x, int dad, int depth) {
  f[depth]++;
  for (int y: E[x])
    if (y != dad) dfs(y, x, depth + 1);
}

int main(void) {
  int n, k, p;
  scanf("%d %d %d", &n, &k, &p);
  REP(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  dfs(0, -1, 0);
  
  f[0] = 0;
  for (int i = 1; i < n; ++i) {
    s[i] = s[i-1] + f[i];
    w_s[i] = w_s[i-1] + llint(i)*f[i];
  }

  int ans = 0;
  for (int i = 1; i < n; ++i) {
    auto getCost = [&i] (int l) {
      // sum (i-x)*f[x], l <= x <= i
      // sum i*f[x] - x*f[x], l <= x <= i
      return llint(i)*(s[i]-s[l-1]) - (w_s[i]-w_s[l-1]);
    };

    int lo = 1, hi = i;
    while (lo < hi) {
      int mid = (lo + hi)/2;
      if (getCost(mid) <= p) hi = mid; else
        lo = mid+1;
    }

    int rem = p - getCost(lo);
    int cnt = s[i] - s[lo-1];    
    if (lo > 1) cnt += rem/(i-(lo-1));
    
    cnt = min(cnt, k);
    ans = max(ans, cnt);
  }
  
  printf("%d\n", ans);
  return 0;
}