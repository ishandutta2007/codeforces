#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 50;

int n, a[N];
long long fx[N];

inline int calc(int x) {
  int p = n;
  for (; p && a[p] < x; p --);
  for (int i = n; i > p; i --) a[i + 1] = a[i];
  a[p + 1] = x;
  for (int i = n + 1; i; i --) fx[i] = a[i] + fx[i + 1];
  long long pf = 0;
  int res = -1;
  for (int i = 1, j = n + 1; i <= n + 1; i ++) {
    j = max(j, i + 1);
    while (j > i && a[j] < i) j --;
    long long rt = 1ll * i * (i - 1) + fx[j + 1] + 1ll * i * (j - i);
    pf += a[i];
    if (rt < pf) {
      res = (p + 1 <= i);
      break;
    }
  }
  for (int i = p + 1; i <= n; i ++) a[i] = a[i + 1];
  a[n + 1] = 0;
  // cerr << x << endl;
  return res;
}

int main() {
  scanf("%d", &n);
  int su = 0;
  for (int i = 1; i <= n; i ++) {
    scanf("%d", &a[i]);
    su ^= (a[i] & 1);
  }
  sort(a + 1, a + n + 1, greater <int> ());
  int le = -1, ri = -1;
  int L = su, R = n / 2 + 2, mid;
  while (L <= R) {
    mid = (L + R) >> 1;
    int u = calc(2 * mid - su);
    if (u == -1) {
      le = mid;
      R = mid - 1;
    }
    else if (u) R = mid - 1;
    else L = mid + 1;
  }
  if (le == -1) return 0 * puts("-1");
  L = su; R = n / 2 + 2;
  while (L <= R) {
    mid = (L + R) >> 1;
    int u = calc(2 * mid - su);
    if (u == -1) {
      ri = mid;
      L = mid + 1;
    }
    else if (u) R = mid - 1;
    else L = mid + 1;
  }
  for (int i = le; i <= ri; i ++)
    printf("%d ", i * 2 - su);
  puts("");
  return 0;
}