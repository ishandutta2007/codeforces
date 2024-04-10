#include <stdio.h>

int a[200001];

bool check(int l, int r) {
  for (int i = l; i < r; i++)
    for (int j = i + 1; j < r; j++)
      for (int k = j + 1; k < r; k++)
        if ((a[i] <= a[j] && a[j] <= a[k]) ||
            (a[i] >= a[j] && a[j] >= a[k]))
          return false;
  return true;
}

int solve(int n) {
  int ans = 0;
  for (int i = 0, j = 1; i < n; i++) {
    while (j < n && check(i, j + 1))
      j++;
    ans += j - i;
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", a + i);
    printf("%d\n", solve(n));
  }
}