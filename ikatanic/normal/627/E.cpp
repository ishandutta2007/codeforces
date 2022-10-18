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

const int MAX = 3030;

vector<int> a[MAX];

int main(void) {
  int r, c, n, k;
  scanf("%d %d %d %d", &r, &c, &n, &k);
  REP(i, n) {
    int x, y;
    scanf("%d %d", &x, &y); --x, --y;
    a[x].push_back(y);
  }
  REP(x, r) sort(a[x].begin(), a[x].end());

  llint ans = llint(r*(r+1)/2) * (c*(c+1)/2);

  for (int i = 0; i < r; ++i) {
    static int cnt[MAX];
    REP(y, c) cnt[y] = 0;
    
    for (int j = i; j >= 0; --j)
      for (int y: a[j]) cnt[y]++;
    
    static int next[MAX], prev[MAX];
    int last = -1;
    REP(y, c)
      if (cnt[y]) {
        prev[y] = last;
        last = y;
      }
    last = c;
    for (int y = c-1; y >= 0; --y)
      if (cnt[y]) {
        next[y] = last;
        last = y;
      }

    REP(j, i+1)
      for (int k = (int)a[j].size()-1; k >= 0; --k) {
        int y = a[j][k];
        if (--cnt[y] == 0) {
          if (prev[y] != -1) next[prev[y]] = next[y];
          if (next[y] != c) prev[next[y]] = prev[y];
        }
      }

    int cur = c*(c+1) / 2;
    for (int j = i; j >= 0; --j) {
      for (int y: a[j]) {
        if (cnt[y] == 0) {
          if (prev[y] != -1) next[prev[y]] = y;
          if (next[y] != c) prev[next[y]] = y;
        }
        ++cnt[y];
        
        int start = y, sum = cnt[y];
        while (sum < k && prev[start] != -1) sum += cnt[start = prev[start]];
        
        int end = y;
        while (start <= y) {
          while (sum < k && next[end] != c) sum += cnt[end = next[end]];
          if (sum < k) break;

          if (sum == k) cur -= (start - prev[start])*(next[end] - end);
          sum -= cnt[start];
          start = next[start];
        }
      }      
      
      ans -= cur;
    }
  }

  printf("%lld\n", ans);
  return 0;
}