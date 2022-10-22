#include <bits/stdc++.h>
using namespace std;

int n;
bool vis[55][55];
char str[55][55];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", str[i] + 1);
  }
  if (str[1][1] == '.' || str[n][1] == '.' || str[1][n] == '.' || str[n][n] == ',') {
    return puts("NO"), 0;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      if (vis[i][j] || str[i][j] == '#') continue;
      if (i == n - 1) return puts("NO"), 0;
      if (j == 1) return puts("NO"), 0;
      if (str[i + 1][j - 1] == '#' || str[i + 1][j] == '#' || str[i + 1][j + 1] == '#' || str[i + 2][j] == '#') {
        return puts("NO"), 0;
      }
      if (vis[i + 1][j - 1] || vis[i + 1][j] || vis[i + 1][j + 1] || vis[i + 2][j]) {
        return puts("NO"), 0;
      }
      vis[i][j] = vis[i + 1][j - 1] = vis[i + 1][j] = vis[i + 1][j + 1] = vis[i + 2][j] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (str[i][j] == '.' && !vis[i][j]) {
        return puts("NO"), 0;
      }
    }
  }
  puts("YES");
  return 0;
}