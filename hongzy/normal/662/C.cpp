#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1 << 20 | 5;
int n, m, len;
ll a[N], b[N];
char s[21][100005];
void fwt(ll *a) {
  for(int i = 1; i < len; i <<= 1) {
    for(int j = 0; j < len; j += i << 1) {
      for(int k = 0; k < i; k ++) {
        ll p = a[j + k], q = a[j + k + i];
        a[j + k] = p + q; a[j + k + i] = p - q;
      }
    }
  }
}
void Ifwt(ll *a) {
  for(int i = 1; i < len; i <<= 1) {
    for(int j = 0; j < len; j += i << 1) {
      for(int k = 0; k < i; k ++) {
        ll p = a[j + k], q = a[j + k + i];
        a[j + k] = (p + q) / 2; a[j + k + i] = (p - q) / 2;
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);
  for(int i = 1; i < (1 << n); i ++) b[i] = b[i & (i - 1)] + 1;
  for(int i = 0; i < (1 << n); i ++) b[i] = min(b[i], n - b[i]);
  for(int i = 1; i <= m; i ++) {
    int x = 0;
    for(int j = 1; j <= n; j ++) {
      x = (x << 1) + s[j][i] - '0';
    }
    a[x] ++;
  }
  len = 1 << n; fwt(a); fwt(b);
  for(int i = 0; i < len; i ++) a[i] *= b[i];
  Ifwt(a);
  ll ans = 2e9;
  for(int i = 0; i < len; i ++) ans = min(ans, a[i]);
  printf("%lld\n", ans);
  return 0;
}