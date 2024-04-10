#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <map>
#include <memory>

using namespace std;
typedef long long ll;
#define mp(x, y) make_pair(x, y)
const int N = 2e5 + 5;
int n, x, t;
int main() {
  int k;
  scanf("%d", &k);
  while (k--) {
    scanf("%d%d%d", &n, &x, &t);
    int sum = t / x;
    if (sum >= n - 1) {
      printf("%lld\n", 1ll * n * (n - 1) / 2);
    } else {
      printf("%lld\n", 1ll * sum * (n - sum) + 1ll * sum * (sum - 1) / 2);
    }
  }
}