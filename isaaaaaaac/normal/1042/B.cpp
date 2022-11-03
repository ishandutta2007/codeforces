#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 50;

int n, c[N];
int tab[10], vis[3];
char s[10];

int main() {
  for (int i = 0; i < 10; i ++) tab[i] = 1e8;
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++) {
    scanf("%d", &c[i]);
    scanf("%s", s + 1);
    int msk = 0;
    for (int j = 1; s[j]; j ++) {
      vis[s[j] - 'A'] = 1;
      msk |= 1 << (s[j] - 'A');
    }
    for (int j = msk; j; j = (j - 1) & msk)
      tab[j] = min(tab[j], c[i]);
  }
  for (int i = 0; i < 3; i ++)
    if (!vis[i]) return 0 * puts("-1");
  int ans = tab[1] + tab[2] + tab[4];
  for (int i = 0; i < 3; i ++)
    ans = min(ans, tab[1 << i] + tab[7 ^ (1 << i)]);
  ans = min(ans, tab[7]);
  printf("%d\n", ans);
  return 0;
}