#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  int X2;
  scanf("%d", &X2);

  int p = 1, x = X2;
  for (int i = 2; i <= x; ++i) {
    if (x % i == 0) {
      while (x % i == 0) x /= i;
      p = i;
    }
  }

  int L = X2 - p + 1, R = X2;
  vector<bool> prime(X2 + 1, true);
  int ret = X2;
  for (int i = 2; i <= X2; ++i) {
    if (prime[i]) {
      for (llint j = i*1LL*i; j <= X2; j += i) {
        prime[j] = false;
      }

      int first = L;
      if (first % i) first += i - (first % i);
      if (first <= R) {
        int cand = max(i + 1, first - i + 1);
        ret = min(ret, cand);
      }
    }
  }

  printf("%d\n", ret);
  return 0;
}