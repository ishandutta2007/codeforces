#include <bits/stdc++.h>
using namespace std;

#prag\
ma GCC optimize(3)
typedef long long ll;
const int maxn = 5e5 + 10;
int n, m;
ll k, sum[maxn];

inline bool check(ll mid) {
  static int Q[maxn];
  static ll val[maxn];
  int l = 1, r = 0;
  ll res = 0, delta = 0;
  for (int i = 1; i <= n; i++) {
    if (l <= r && i - Q[l] > m + m) delta -= val[l++];
    ll s = sum[min(n, i + m)] - sum[max(0, i - m - 1)] + delta;
    if (s >= mid) continue;
    ll tmp = mid - s;
    delta += tmp, res += tmp;
    if (res > k) return 0;
    Q[++r] = i, val[r] = tmp;
  }
  return 1;
}

int main() {
  scanf("%d %d %I64d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", sum + i), sum[i] += sum[i - 1];
  }
  ll l = 0, r = 1100000000000000000ll, mid;
  while (l < r) {
    check(mid = (l + r + 1) >> 1) ? l = mid : r = mid - 1;
  }
  printf("%I64d", r);
  return 0;
}