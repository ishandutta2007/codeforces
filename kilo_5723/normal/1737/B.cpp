#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll _sqrt(ll n) {
  ll m = sqrt(n) + 1;
  while (m * m > n) m--;
  return m;
}
ll solve(ll n) {
  if (!n) return 0;
  ll m = sqrt(n);
  ll ans = (m - 1) * 3;
  if (n >= m * m) ans++;
  if (n >= m * (m + 1)) ans++;
  if (n >= m * (m + 2)) ans++;
  return ans;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    ll l, r;
    scanf("%lld%lld", &l, &r);
    printf("%lld\n",solve(r) - solve(l - 1));
  }
  return 0;
}