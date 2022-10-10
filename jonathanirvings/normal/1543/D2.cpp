#include <bits/stdc++.h>
using namespace std;

int add(int a, int b, int K) {
  int multiplier = 1;
  int res = 0;
  while (a > 0 || b > 0) {
    int add = a % K + b % K;
    if (add >= K) {
      add -= K;
    }
    res += add * multiplier;
    a /= K;
    b /= K;
    multiplier *= K;
  }
  return res;
}

int sub(int a, int b, int K) {
  int multiplier = 1;
  int res = 0;
  while (a > 0 || b > 0) {
    int add = a % K - b % K;
    if (add < 0) {
      add += K;
    }
    res += add * multiplier;
    a /= K;
    b /= K;
    multiplier *= K;
  }
  return res;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N, K;
    scanf("%d %d", &N, &K);
    int tot = 0;
    for (int i = 0; i < N; ++i) {
      int y = (i & 1) ? sub(tot, i, K) : add(tot, i, K);
      printf("%d\n", y);
      fflush(stdout);
      int r;
      scanf("%d", &r);
      if (r == 1) {
        break;
      }
      tot = sub(y, tot, K);
    }
  }
}