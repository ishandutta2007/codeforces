#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 2e5 + 5, digit = 10;
char s[maxn];
int cnt[digit];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%s", s);
    int p = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; s[i]; i++) {
      while (p && s[p - 1] > s[i]) {
        p--;
        cnt[min(s[p] - '0' + 1, digit - 1)]++;
      }
      s[p++] = s[i];
    }
    for (int i = 0; i < p; i++) cnt[s[i] - '0']++;
    for (int i = 0; i < digit; i++)
      while (cnt[i]--) putchar('0' + i);
    puts("");
  }
  return 0;
}