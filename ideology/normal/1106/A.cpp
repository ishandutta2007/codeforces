#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 510;

int n;
char s[N][N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%s", s[i] + 1);
  int ans = 0;
  for (int i = 2; i < n; ++i)
    for (int j = 2; j < n; ++j)
      if (s[i][j] == 'X') {
        int cnt = 0;
        for (int y = -1; y <= 1; y += 2)
          for (int z = -1; z <= 1; z += 2)
            if (s[i + y][j + z] == 'X')
              ++cnt;
        if (cnt == 4)
          ++ans;
      }
        printf("%d\n", ans)
;
#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}