#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 505;
char s[maxn], t[maxn];
map<pair<int, int>, ll> dp[maxn];
bool same(int p, int q) {
  if (p < q) return false;
  for (int i = 1; i <= q; i++)
    if (s[p - i] != t[q - i]) return false;
  return true;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%s", s);
    scanf("%s", t);
    int n = strlen(s), m = strlen(t);
    dp[0] = {{{0, 0}, 1}};
    for (int i = 1; i <= n; i++) {
      if (!same(i, m))
        dp[i] = dp[i - 1];
      else {
        dp[i].clear();
        for (auto pr : dp[i - m]) {
          dp[i][{pr.first.first + 1, i}] += pr.second;
        }
        for (auto pr : dp[i - 1])
          if (pr.first.second > i - m) dp[i][pr.first] += pr.second;
        for (auto &pr : dp[i]) pr.second %= mod;
      }
    }
    int k = n;
    for (auto pr : dp[n]) k = min(k, pr.first.first);
    ll ans = 0;
    for (auto pr : dp[n])
      if (pr.first.first == k) ans += pr.second;
    printf("%d ", k);
    printf("%lld\n", (mod + ans % mod) % mod);
  }
  return 0;
}