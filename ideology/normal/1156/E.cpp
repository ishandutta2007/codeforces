#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 200010;

int n, ans;
int a[N], pos[N], l[N], r[N];
set<int> st[N];

void mer(set<int>& s, set<int>& t, int x) {
  for (int v : t)
    if (s.count(x - v))
      ++ans;
  s.insert(t.begin(), t.end());
  t.clear();
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i)
    pos[a[i]] = i;
  for (int i = 1; i <= n; ++i) {
    int p = pos[i];
    int cur1 = l[p - 1], cur2 = l[p + 1];
    if (cur1 && cur2) {
      if (st[cur1].size() < st[cur2].size())
        swap(st[cur1], st[cur2]);
      mer(st[cur1], st[cur2], i);
    } else if (cur2) {
      swap(st[cur2], st[p]);
    }
    if (!cur1)
      cur1 = p;
    if (!cur2)
      cur2 = p;
    else
      cur2 = r[cur2];
    l[cur1] = l[cur2] = cur1;
    r[cur2] = r[cur1] = cur2;
    st[cur1].insert(i);
  }
  printf("%d\n", ans);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}