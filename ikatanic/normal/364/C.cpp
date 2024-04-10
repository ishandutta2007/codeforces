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

int pr[5] = {2, 3, 5, 7, 11};

set<int> S;
int lim, k;

void rec(int p, int end, llint x) {
  if (x > lim || (int)S.size() == k) return;
  if (p == end) {
    S.insert(x);
    return;
  }
  rec(p+1, end, x);
  rec(p, end, x*pr[p]);
}

int main(void) {
  scanf("%d", &k);
  lim = 2*k*k;
  
  auto solve = [] (int end) {
    S.clear();
    rec(0, end, 1);
    if ((int)S.size() != k) return false;
    REP(p, end) {
      int x = pr[p];
      int c = 0;
      for (int y: S)
        if (y%x == 0) c++;
      if (2*c < k) return false;
    }
    return true;
  };
    
  for (int end = 1; end <= 5; ++end)
    if (solve(end)) break;

  for (int x: S)
    printf("%d ", x);
  printf("\n");
  return 0;
}