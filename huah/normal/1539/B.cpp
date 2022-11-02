#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <map>
#include <memory>

using namespace std;
typedef long long ll;
#define mp(x, y) make_pair(x, y)
const int N = 2e5 + 5;
int n, q;
char s[N];
int sum[N][26], vis[26];
int main() {
  scanf("%d%d", &n, &q);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    vis[s[i] - 'a']++;
    memcpy(sum[i], vis, sizeof(vis));
  }
  while (q--) {
    int l, r;
    ll ans = 0;
    scanf("%d%d", &l, &r);
    for (int i = 0; i < 26; i++)
      ans = (ans + 1ll * (sum[r][i] - sum[l - 1][i]) * (i + 1));
    printf("%lld\n", ans);
  }
}