#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <map>
#include <memory>

using namespace std;
typedef long long ll;
#define mp(x, y) make_pair(x, y)
const int N = 5e5 + 5, mod = 1e9 + 7;
int n, k;
char s[N], ans[N], res[N];
int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  for (int i = 1; i <= k; i++) ans[i] = 'z';
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++)
      for (int h = j; h <= k; h += i) res[h] = s[j];
    for (int j = 1; j <= k; j++)
      if (ans[j] != res[j] && res[j] < ans[j]) {
        for (int h = 1; h <= k; h++) ans[h] = res[h];
        break;
      } else if (res[j] > ans[j])
        break;
  }
  for (int i = 1; i <= k; i++) putchar(ans[i]);
  putchar('\n');
}