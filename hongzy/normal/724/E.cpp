#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int N = 1e4 + 5;
int n, c, a[N], b[N];
ll f[N];
int main() {
  scanf("%d%d", &n, &c);
  rep(i, 1, n) scanf("%d", a + i);
  rep(i, 1, n) scanf("%d", b + i);
  f[0] = 0;
  rep(i, 1, n) f[i] = 1ll << 60;
  rep(i, 1, n) per(j, i, 0)
    f[j] = min(j ? f[j - 1] + b[i] : 1ll << 60, f[j] + (ll)j * c + a[i]);
  printf("%lld\n", *min_element(f, f + n + 1));
  return 0;
}