#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e5 + 10;
ll s[maxn];
int n, m, a[maxn];

priority_queue <ll> Q;

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = n; i; i--) {
    s[i] = s[i + 1] + a[i];
  }
  for (int i = 2; i <= n; i++) {
    Q.push(s[i]);
  }
  ll ans = s[1];
  while (--m) {
    ans += Q.top(), Q.pop();
  }
  printf("%I64d", ans);
  return 0;
}