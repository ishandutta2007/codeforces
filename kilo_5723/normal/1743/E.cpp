#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
const int maxn = 5e3 + 5;
ll dp[maxn];
int p1, p2, s;
ll t1, t2;
ll dfs(ll n) {
  // printf("%d\n", n);
  if (n <= 0) return 0;
  if (dp[n]) return dp[n];
  ll res = inf;
  for (ll i = 0; true; i++) {
    ll t = t1 * (i + 1);
    ll n_ = n - i * (p1 - s) - (i * t1 / t2) * (p2 - s);
    if (n_ <= 0) {
      res = min(res, t1 * i);
      break;
    }
    if (t < t2) continue;
    n_ = n - i * (p1 - s) - (p2 - s) * (t / t2 - 1) - p1 - p2 + s;
    res = min(res, dfs(n_) + t);
  }

  for (ll i = 0; true; i++) {
    ll t = t2 * (i + 1);
    ll n_ = n - i * (p2 - s) - (i * t2 / t1) * (p1 - s);
    if (n_ <= 0) {
      res = min(res, t2 * i);
      break;
    }
    if (t < t1) continue;
    n_ = n - i * (p2 - s) - (p1 - s) * (t / t1 - 1) - p1 - p2 + s;
    res = min(res, dfs(n_) + t);
  }
  return dp[n] = res;
}
int main() {
  scanf("%d%lld", &p1, &t1);
  scanf("%d%lld", &p2, &t2);
  int h;
  scanf("%d%d", &h, &s);
  // if (t1 < t2) {
  //   swap(t1, t2);
  //   swap(p1, p2);
  // }
  printf("%lld\n", dfs(h));
  return 0;
}