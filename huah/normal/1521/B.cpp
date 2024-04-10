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
int n, a[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int mn = a[1];
    for (int i = 1; i <= n; i++) mn = min(mn, a[i]);
    int pos = 1;
    for (int i = 1; i <= n; i++)
      if (mn == a[i]) pos = i;
    printf("%d\n", n - 1);
    for (int i = 1; i <= n; i++)
      if (i != pos) {
        printf("%d %d %d %d\n", pos, i, a[pos], a[pos] + abs(i - pos));
      }
  }
}