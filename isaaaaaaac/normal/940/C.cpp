#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

char s[N];
int cnt[150];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i ++) cnt[s[i]] ++;
  if (k > n) {
    char ch;
    for (int i = 'a'; i <= 'z'; i ++)
      if (cnt[i]) { ch = i; break; }
    for (int i = 1; i <= n; i ++) putchar(s[i]);
    for (int j = n + 1; j <= k; j ++) putchar(ch);
    puts("");
    return 0;
  }
  char ch;
  for (int i = 'a'; i <= 'z'; i ++)
    if (cnt[i]) ch = i;
  for (int i = k; i >= 1; i --)
    if (s[i] != ch) {
      for (int j = 1; j < i; j ++) putchar(s[j]);
      for (int j = s[i] + 1; j <= 'z'; j ++)
        if (cnt[j]) { putchar(j); break; }
      for (int l = 'a'; l <= 'z'; l ++)
        if (cnt[l]) {
          for (int j = i + 1; j <= k; j ++) putchar(l);
          puts("");
          return 0;
        }
    }
  return 0;
}