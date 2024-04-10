#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n, top, a[maxn], st[maxn], pos[maxn], lef[maxn], rig[maxn];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i), pos[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    while (top && a[st[top]] < a[i]) top--;
    lef[i] = st[top] + 1, st[++top] = i;
  }
  top = 0, st[0] = n + 1;
  for (int i = n; i; i--) {
    while (top && a[st[top]] < a[i]) top--;
    rig[i] = st[top] - 1, st[++top] = i;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int l = lef[i], r = rig[i];
    if (i - l < r - i) {
      for (int j = l; j <= i; j++) {
        ans += pos[a[i] - a[j]] >= i && pos[a[i] - a[j]] <= r;
      }
    } else {
      for (int j = i; j <= r; j++) {
        ans += pos[a[i] - a[j]] >= l && pos[a[i] - a[j]] <= i;
      }
    }
  }
  printf("%d", ans);
  return 0;
}