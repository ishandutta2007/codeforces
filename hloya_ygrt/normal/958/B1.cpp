#include <bits/stdc++.h>

using namespace std;

int deg[1234];

int main() {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--; v--;
    deg[u]++;
    deg[v]++;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (deg[i] == 1);
  }
  printf("%d\n", ans);
  return 0;  
}