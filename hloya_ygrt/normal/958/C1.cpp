#include <bits/stdc++.h>

using namespace std;

int a[1234567];

int main() {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n, p;
  scanf("%d%d", &n, &p);
  int s = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    s = (s + a[i]) % p;
  }
  int q = 0, ans = 0;
  for (int i = 0; i < n - 1; i++) {
    q = (q + a[i]) % p;
    s = ((s - a[i]) % p + p) % p;
    ans = max(ans, q + s);
  }
  printf("%d\n", ans);
  return 0;  
}