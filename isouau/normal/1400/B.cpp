#include <bits/stdc++.h>
using namespace std;

int T, p, f, cnts, cntw, s, w, ans;

int main() {
  scanf("%d", &T);
  while (T--) {
    ans = 0;
    scanf("%d%d%d%d%d%d", &p, &f, &cnts, &cntw, &s, &w);
    if (s > w) swap(cnts, cntw), swap(s, w);
    for (int i = 0; i <= min(cnts, p / s); i++) {
      int cnt = min(f / s, cnts - i);
      int res = i + cnt + min((p - i * s) / w + (f - cnt * s) / w, cntw);
      ans = max(ans, res);
    }
    printf("%d\n", ans);
  }
  return 0;
}