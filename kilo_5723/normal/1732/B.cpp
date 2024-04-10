#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;
char s[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    int ans = 0;
    bool flg1 = s[0] == '0', flg2 = false;
    for (int i = 1; i < n; i++) {
      ans += s[i] != s[i - 1];
      flg2 = flg2 || s[i] == '1';
    }
    printf("%d\n", ans - (flg1 && flg2));
  }
  return 0;
}