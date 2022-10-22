#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef long long ll;
const int maxn = 1e6 + 10;
int n, a[maxn]; ll k;

int main() {
  scanf("%d %I64d", &n, &k);
  if (k < 1ll * n * (n + 1) / 2) {
    return puts("-1"), 0;
  }
  ll val = 0;
  for (int i = 1; i <= n; i++) {
    val += max(i, n - i + 1);
  }
  ll ans = 0;
  int l = 1, r = n;
  for (int i = 1; i <= n; i++) {
    int v = max(i, r);
    if (ans + v + 1ll * n * (n + 1) / 2 - 1ll * i * (i + 1) / 2 <= k) {
      ans += v, a[i] = r--;
    } else {
      ans += i, a[i] = l++;
    }
  }
  printf("%I64d\n", ans);
  for (int i = 1; i <= n; i++) {
    printf("%d%c", i, "\n "[i < n]);
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}