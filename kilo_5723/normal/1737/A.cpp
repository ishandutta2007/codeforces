#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 5, alpha = 26;
char s[maxn];
int cnt[alpha];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
    for (int i = 0; i < k; i++) {
      char ch = 'a';
      for (int j = 0; j < n / k; j++)
        if (i < cnt[ch - 'a'])
          ch++;
        else
          break;
      putchar(ch);
    }
    puts("");
  }
  return 0;
}