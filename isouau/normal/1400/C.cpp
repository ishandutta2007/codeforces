#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

char c[N];
int ans[N];
int T, n, x;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%s%d", c + 1, &x); n = strlen(c + 1);
    for (int i = 1; i <= n; i++) ans[i] = 1;
    for (int i = 1; i <= n; i++) {
      if (c[i] == '0') {
        if (i - x >= 1) ans[i - x] = 0;
        if (i + x <= n) ans[i + x] = 0;
      }
    }
    bool cando = 1;
    for (int i = 1; i <= n; i++) {
      if (c[i] == '1') {
        bool res = 0;
        if (i - x >= 1) res |= ans[i - x];
        if (i + x <= n) res |= ans[i + x];
        if (!res) {
          cando = 0;
          break;
        }
      }
    }
    if (!cando) puts("-1");
    else {
      for (int i = 1; i <= n; i++) putchar(ans[i] + 48);
      putchar('\n');
    }
  }
  return 0;
}