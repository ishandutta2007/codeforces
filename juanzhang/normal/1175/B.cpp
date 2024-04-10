#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;
char str[maxn][10];
int n, top, st[maxn], num[maxn];

ll sum[maxn];
bool flg[maxn];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", str[i]);
    if (*str[i] == 'f') {
      scanf("%d", num + i);
    }
  }
  sum[0] = 1;
  ll inf = (1ll << 32) - 1;
  for (int i = 1; i <= n; i++) {
    if (*str[i] == 'f') {
      st[++top] = num[i];
      if (flg[top - 1]) {
        flg[top] = 1;
      } else {
        sum[top] = sum[top - 1] * num[i];
        if (sum[top] > inf) {
          flg[top] = 1;
        }
      }
    } else if (*str[i] == 'e') {
      flg[top--] = 0;
    } else {
      if (flg[top]) {
        return puts("OVERFLOW!!!"), 0;
      }
    }
  }
  top = 0;
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (*str[i] == 'f') {
      st[++top] = num[i];
      sum[top] = sum[top - 1] * num[i];
    } else if (*str[i] == 'e') {
      top--;
    } else {
      ans += sum[top];
      if (ans > inf) {
        return puts("OVERFLOW!!!"), 0;
      }
    }
  }
  printf("%I64d", ans);
  return 0;
}