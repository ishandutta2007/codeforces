#include <bits/stdc++.h>
using namespace std;

int n;
char str[1010];

int main() {
  scanf("%d", &n);
  scanf("%s", str + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (str[i] == '-') {
      ans = max(0, ans - 1);
    } else {
      ans++;
    }
  }
  printf("%d", ans);
  return 0;
}