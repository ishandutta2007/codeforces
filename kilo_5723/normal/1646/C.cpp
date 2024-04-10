#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int maxk = 20;
int bitcnt(ll n) {
  int ans = 0;
  while (n) {
    ans += n & 1;
    n >>= 1;
  }
  return ans;
}
ll fact[maxk];
int dfs(ll n, int p) {
  if (p < 3) return bitcnt(n);
  int ans = dfs(n, p - 1);
  if (n >= fact[p]) ans = min(ans, dfs(n - fact[p], p - 1) + 1);
  return ans;
}
int main() {
  fact[0] = 1;
  for (int i = 1; i < maxk; i++) fact[i] = fact[i - 1] * i;
  // for (int i = 0; i < maxk; i++) printf("%d %lld\n", i, fact[i]);
  int tt;
  scanf("%d",&tt);
  while (tt--) {
    ll n;
    scanf("%lld", &n);
    printf("%d\n", dfs(n, maxk - 1));
  }
  return 0;
}