#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll calc(int x, int n) {
  ll res = 0, cnt = 0;
  for (int i = 1; i <= n; i <<= 1) {
    if (n & i) {
      n ^= i;
      if (!(x & n)) res += 1 << cnt;
    }
    cnt += !(x & i);
  }
  return res;
}

ll dfs(int l, int r) {
  if (l == r) return 0;
  if (!l) return 2 * r - 1 + dfs(1, r);
  ll res = 0;
  if (l & 1) {
    res += 2 * (calc(l, r) - calc(l, l)), l++;
  }
  if (r & 1) {
    res += 2 * (calc(r - 1, r) - calc(r - 1, l)), r--;
  }
  return res + 3 * dfs(l / 2, r / 2);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%I64d\n", dfs(l, r + 1));
  }
  return 0;
}