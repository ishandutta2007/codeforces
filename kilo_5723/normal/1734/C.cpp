#include <cstdio>
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
vector<int> divs[maxn];
bool vis[maxn];
char s[maxn];
int main() {
  // for (int i = 1; i < maxn; i++) mindiv[i] = i;
  for (int i = 1; i < maxn; i++)
    for (int j = i; j < maxn; j += i) divs[j].push_back(i);
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    ll ans = 0;
    fill(vis, vis + n + 1, false);
    // set<int> bans;
    for (int i = 1; i <= n; i++)
      if (s[i] == '1')
        for (auto v : divs[i]) vis[v] = true;
      else
        for (auto v : divs[i])
          if (!vis[v]) {
            ans += v;
            break;
          }
    // if (j >= bans[i].size() || bans[i][j] != divs[i][j]) {
    //   printf("%d %d %d\n", i, j, divs[i][j]);
    //   ans += divs[i][j];
    //   break;
    // }
    printf("%lld\n", ans);
  }
  return 0;
}