#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
map<pll, ll> mp;
ll solve(ll n, ll m, ll step) {
  pll id = {n, m};
  if (mp.count(id)) return mp[id];
  if (!n) return mp[id] = 0;
  if (n + m <= step) return mp[id] = solve(n, m, step >> 1);
  if (n >= step) return mp[id] = m - solve(n - step, m, step);
  ll l1 = step - n, l2 = n + m - step;
  return mp[id] = solve(n, l1, step) + l2 - solve(l1, l2, step);
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    ll n, m;
    scanf("%lld%lld", &n, &m);
    printf("%lld\n", solve(n, m, 1LL << 61));
  }
  return 0;
}