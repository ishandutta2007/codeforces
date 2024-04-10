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

const int N = 100010;

int n;
int a[N], c[N];
pair<int, int> good[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int m;
  ll ans = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &c[i]);
  for (int i = 1; i <= n; ++i)
    good[i] = make_pair(c[i], i);
  sort(good + 1, good + n + 1);
  int ptr = 1;
  while (m--) {
    int t, d;
    scanf("%d%d", &t, &d);
    ll cur = 0;
    int v = min(d, a[t]);
    cur += v * (ll)c[t];
    a[t] -= v;
    d -= v;
    if (d) {
      while (ptr <= n) {
        int id = good[ptr].second;
        v = min(d, a[id]);
        d -= v;
        a[id] -= v;
        cur += v * (ll)c[id];
        if (a[id] == 0)
          ++ptr;
        if (d == 0)
          break;
      }
    }
    if (d == 0)
      printf("%lld\n", cur);
    else
      puts("0");
  }

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}