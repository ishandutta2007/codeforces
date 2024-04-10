#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>

int a[200000];
int b[200000];

int rev[200000];

void solve(int n) {
  std::fill_n(b, n, -1);
  std::fill_n(rev, n, -1);

  for (int i = 0; i < n; i++)
    if (rev[a[i]] == -1) {
      b[i] = a[i];
      rev[a[i]] = i;
    }

  for (int i = 0; i < n; i++)
    if (b[i] == -1 && rev[i] == -1) {
      int j = rev[a[i]];
      b[i] = a[i];
      b[j] = i;

      rev[a[i]] = i;
      rev[i] = j;
    }

  for (int i = 0, j = 0; i < n; i++)
    if (b[i] == -1) {
      while (rev[j] != -1)
        j++;
      b[i] = j;
      rev[j] = i;
    }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      a[i]--;
    }
    solve(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
      if (a[i] == b[i])
        ans++;
    printf("%d\n", ans);
    for (int i = 0; i < n; i++)
      printf("%d%c", b[i] + 1, i == n - 1 ? '\n' : ' ');
  }
}