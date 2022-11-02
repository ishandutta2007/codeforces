#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 2e5 + 5;
char s[maxn];
int cnt[26];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    memset(cnt, 0, sizeof(cnt));
    scanf("%s", s);
    for (int i = 0; s[i]; i++) cnt[s[i] - 'a']++;
    char *p = s;
    while (--cnt[*p - 'a']) p++;
    printf("%s\n", p);
  }
  return 0;
}