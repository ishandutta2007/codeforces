#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n, c[maxn], d[maxn], t[maxn];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", c + i);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", t + i);
  }
  if (c[1] != t[1] || c[n] != t[n]) {
    return puts("No"), 0;
  }
  for (int i = n; i; i--) {
    d[i] = c[i] - c[i - 1];
    t[i] -= t[i - 1];
  }
  sort(d + 2, d + n + 1);
  sort(t + 2, t + n + 1);
  for (int i = 2; i <= n; i++) {
    if (d[i] != t[i]) {
      return puts("No"), 0;
    }
  }
  puts("Yes");
  return 0;
}