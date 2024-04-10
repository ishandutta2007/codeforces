#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n, m, k, a[maxn];

priority_queue <int> Q;

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i < n; i++) {
    Q.push(a[i + 1] - a[i]);
  }
  int ans = 0;
  int tmp = k;
  k = k - 1;
  while (k--) {
    ans += Q.top(), Q.pop();
  }
  printf("%d", a[n] - a[1] - ans + tmp);
  return 0;
}