#include <stdio.h>
#include <vector>
#include <algorithm>

int n, p, k;
char buf[100005];
int x, y;

void solve() {
  scanf("%d%d%d", &n, &p, &k);
  scanf("%s", buf);
  scanf("%d%d", &x, &y);
  --p;
  long long ans = 1ll << 62; // read the problem >_>
  for (int skip = 0; skip < k; ++skip) {
    std::vector<bool> have;
    for (int i = p+skip; i < n; i+=k) have.push_back(buf[i] == '1');

    long long cu = 0;
    for (int i = (int)(have.size())-1; i >= 0; --i) {
      if (!have[i]) cu += x;
      ans = std::min(ans, 1ll*skip*y + 1ll*i*k*y + cu);
    }
  }
  printf("%lld\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}