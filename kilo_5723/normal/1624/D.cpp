#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 2e5 + 5, apa = 26;
int cnt[apa];
char s[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    fill(cnt, cnt + apa, 0);
    for (int i = 0; s[i]; i++) cnt[s[i] - 'a']++;
    int pal = 0, res = 0;
    for (int i = 0; i < apa; i++) {
      pal += cnt[i] / 2;
      res += cnt[i] % 2;
    }
    int ans = pal / k * 2;
    pal -= ans * k / 2;
    res += pal * 2;
    if (res >= k) ans++;
    printf("%d\n", ans);
  }
  return 0;
}