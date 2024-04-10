#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;
int n, k, P;

map <int, int> s;

int main() {
  scanf("%d %d %d", &n, &P, &k);
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    s[1ll * x * (1ll * x * x % P * x % P + P - k) % P]++;
  }
  long long ans = 0;
  for (pii p : s) {
    ans += 1ll * p.second * (p.second - 1) / 2;
  }
  printf("%I64d", ans);
  return 0;
}