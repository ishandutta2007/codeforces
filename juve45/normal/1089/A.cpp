#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

int i, j, q, x, y, dp[6][6][205][205];
pair<int, int> from[6][6][205][205];
bool printed;

int DP(int w1, int w2, int x, int y) {
  if(w1 < 0 || w2 < 0 || x < 0 || y < 0) return 0;
  if(dp[w1][w2][x][y] != -1) return dp[w1][w2][x][y];

  int mx = w1 + w2 == 5 ? 15 : 25;
  if(w1 >= w2) {
    for(int i = 0; i <= mx - 2; ++i)
      if(DP(w1 - 1, w2, x - mx, y - i)) {
        from[w1][w2][x][y] = make_pair(mx, i);
        return dp[w1][w2][x][y] = 1;
      }

    for(int i = mx + 1; i <= x; ++i) 
      if(DP(w1 - 1, w2, x - i, y - i + 2)) {
        from[w1][w2][x][y] = make_pair(i, i - 2);
        return dp[w1][w2][x][y] = 1;
      }
  }

  if(w1 <= w2) {
    for(int i = 0; i <= mx - 2; ++i)
      if(DP(w1, w2 - 1, x - i, y - mx)) {
        from[w1][w2][x][y] = make_pair(i, mx);
        return dp[w1][w2][x][y] = 1;
      }

    for(int i = mx + 1; i <= y; ++i) 
      if(DP(w1, w2 - 1, x - i + 2, y - i)) {
        from[w1][w2][x][y] = make_pair(i - 2, i);
        return dp[w1][w2][x][y] = 1;
      }
  }

  return dp[w1][w2][x][y] = 0;
}

int main() {
  memset(dp, -1, sizeof(dp));
  dp[0][0][0][0] = 1;
  for(scanf("%d", &q); q; --q) {
    scanf("%d %d", &x, &y);
    printed = 0;
    for(j = 0; j <= 3; ++j)
      for(i = 3; i >= 0; --i) {
        if(max(i, j) < 3 || i + j > 5) continue;
        if(!DP(i, j, x, y)) continue;
        printed = 1;
        printf("%d:%d\n", i, j);
        vector<pair<int, int>> v1, v2;
        while(i || j) {
          int w = from[i][j][x][y].first;
          int r = from[i][j][x][y].second;
          if(from[i][j][x][y].first < from[i][j][x][y].second) --j; else --i;
          x -= w; y -= r;
          if(w > r) v1.push_back(make_pair(w, r));
          else v2.push_back(make_pair(w, r));
        }
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
        int mn = min(v1.size(), v2.size());
        for(i = 0; i < mn; ++i) printf("%d:%d %d:%d ", v1[i].first, v1[i].second, v2[i].first, v2[i].second);
        for(i = mn; i < v1.size(); ++i) printf("%d:%d ", v1[i].first, v1[i].second);
        for(i = mn; i < v2.size(); ++i) printf("%d:%d ", v2[i].first, v2[i].second);
        puts(""); i = -10; j = 10;
      }
    if(!printed) puts("Impossible");
  }

  return 0;
}