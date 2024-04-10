#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
const int maxn = 3e5 + 10;
pii data[maxn];
bool flg[maxn];
int n, k, a[maxn];

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i < n; i++) {
    data[i] = pii(a[i + 1] - a[i], i);
  }
  sort(data + 1, data + n);
  reverse(data + 1, data + n);
  for (int i = 1; i < k; i++) {
    flg[data[i].second] = 1;
  }
  ll ans = 0; int lst = 0;
  for (int i = 1; i <= n; i++) {
    if (flg[i] || i == n) {
      ans += a[i] - a[lst + 1], lst = i;
    }
  }
  printf("%I64d", ans);
  return 0;
}