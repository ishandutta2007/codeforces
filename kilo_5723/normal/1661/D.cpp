#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 5;
ll a[maxn], b[maxn];
bool check(int n, int k, ll m) {
  memcpy(b, a, sizeof(ll) * n);
  for (int i = 0; i < k; i++) b[n - k + i] -= m * (i + 1);
  ll sum = 0;
  for (int i = n - 1; i >= 0; i--) {
    b[i] -= sum;
    if (b[i] > 0) return false;
    b[i] = (-b[i] / k);
    if (i < n - 1) b[i] = min(b[i], b[i + 1]);
    if (i >= k) sum += b[i];
    if (i + k < n) sum -= b[i + k];
  }
  return true;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  ll l, r = 1;
  while (!check(n, k, r)) r <<= 1;
  l = (r >> 1) - 1;
  while (r > l + 1) {
    ll m = l + ((r - l) >> 1);
    if (check(n, k, m))
      r = m;
    else
      l = m;
  }
  printf("%lld\n", r);
  return 0;
}