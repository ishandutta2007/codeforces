#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int n;
char s1[maxn], s2[maxn];

int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%s%s", s1 + 1, s2 + 1);
    int l1 = strlen(s1 + 1);
    int l2 = strlen(s2 + 1);
    if (l1 > l2) {
      puts("NO"); continue;
    }
    bool flg = 1;
    int i = 1, j = 1;
    while (i <= l1 && j <= l2) {
      if (s1[i] != s2[j]) {
        flg = 0; break;
      }
      int x = i, y = j;
      while (x < l1 && s1[x + 1] == s1[x]) x++;
      while (y < l2 && s2[y + 1] == s2[y]) y++;
      if (x - i > y - j) {
        flg = 0; break;
      }
      i = x + 1, j = y + 1;
    }
    if (i > l1 && j <= l2) flg = 0;
    if (i <= l1 && j > l2) flg = 0;
    puts(flg ? "YES" : "NO");
  }
  return 0;
}