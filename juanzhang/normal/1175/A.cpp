#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll n, k;
  scanf("%I64d %I64d", &n, &k);
  ll ans = 0;
  while (n) {
    if (n % k == 0) {
      n /= k, ans++;
    } else {
      ans += n % k, n -= n % k;
    }
  }
  printf("%I64d\n", ans);
}

int main() {
  int Tests;
  scanf("%d", &Tests);
  while (Tests--) solve();
  return 0;
}