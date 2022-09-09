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

int good[] = {0, 0, 3, 4};

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int ans = 0;
  int n;
  scanf("%d", &n);
  int lst, llst = -1;
  scanf("%d", &lst);
  while (--n) {
    int a;
    scanf("%d", &a);
    if (a == lst || (a == 2 && lst == 3) || (a == 3 && lst == 2)) {
      puts("Infinite");
      return 0;
    }
    if (lst == 1)
      ans += good[a];
    else
      ans += good[lst];
    if (lst == 1 && llst == 3 && a == 2)
      --ans;
    llst = lst;
    lst = a;
  }
  printf("Finite\n%d\n", ans);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}