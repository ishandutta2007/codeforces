#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <map>
#include <memory>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
#define mp(x, y) make_pair(x, y)
const int N = 1e5 + 5, bs = 320, mod = 1e9 + 7;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (b == 1)
      printf("NO\n");
    else {
      printf("YES\n");
      printf("%d %lld %lld\n", a, 1ll * a * (2 * b - 1), 1ll * a * b * 2);
    }
  }
}