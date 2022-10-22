#include <bits/stdc++.h>
using namespace std;

int n, a[200010];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  int pos = n + 1;
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i + 1]) {
      puts("NO"); return 0;
    }
    if (a[i] > a[i + 1]) {
      pos = i + 1; break;
    }
  }
  for (int i = pos; i < n; i++) {
    if (a[i] <= a[i + 1]) {
      puts("NO"); return 0;
    }
  }
  puts("YES");
  return 0;
}