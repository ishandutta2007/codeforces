#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int P = 1e9 + 7;

int main() {
  ll n, k, ans;
  scanf("%I64d %I64d", &k, &n), ans = (n % P) * (k % P) % P;
  for (ll l = 1, r = 0; l <= n; l = r + 1) {
    r = k / l ? min(k / (k / l), n) : n;
    ans = (ans - (l + r) % P * ((r - l + 1) % P) % P * 500000004 % P * (k / l % P) % P + P) % P;
  }
  printf("%I64d", ans);
  return 0;
}