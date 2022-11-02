#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int alpha = 30;
const int maxn = 1e5 + 5;
int cnt[alpha][alpha];
char s[maxn], t[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    memset(cnt, 0, sizeof(cnt));
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    scanf("%s", t);
    reverse(t, t + n);
    for (int i = 0; i < n; i++)
      cnt[min(s[i], t[i]) - 'a'][max(s[i], t[i]) - 'a']++;
    bool flg = true;
    for (int i = 0; i < alpha; i++)
      for (int j = i + 1; j < alpha; j++)
        if (cnt[i][j] & 1) {
          flg = false;
        }
    int res = n & 1;
    for (int i = 0; i < alpha; i++) res -= cnt[i][i] & 1;
    puts(flg && !res ? "YES" : "NO");
  }
  return 0;
}