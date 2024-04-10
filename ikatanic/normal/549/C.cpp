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

bool win(int a, int b, int k) {
  if (k == 0) return b%2 == 1;
  if (k % 2 == 0) {
    if (a <= k/2 && (b-(k-a))%2 == 1) return true;
    return false;
  } else {
    if (a <= k/2 && (b-(k-a))%2 == 0) return false;
    if (b <= k/2) return false;

    if (a <= k && b <= k && (b-(k-a)) % 2 == 0) {
      REP(i, k-1)
        if (i % 2 == 0) a > b ? a-- : b--; else
          (a < b && a > 0) ? a-- : b--;
      return a > 0 && b > 0;
    }

    return true;
  }
}

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  int a = 0, b = 0;
  REP(i, n) {
    int x;
    scanf("%d", &x);
    if (x % 2) b++; else
      a++;
  }

  if (win(a, b, a+b-k)) puts("Stannis"); else
    puts("Daenerys");

  return 0;
}