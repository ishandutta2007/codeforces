#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, P = 998244353;
int n, a[maxn];

int main() {
  scanf("%d", &n);
  int ans = n;
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    ans = 1ll * (++a[u]) * (++a[v]) % P * ans % P;
  }
  printf("%d", ans);
  return 0;
}