#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 5e4 + 10;
const int mod = 1e9 + 9;
const int base = 2333;
int w[N], p[N], n, last;
char s[N], a[N];
int get(int l, int r) {
  return ((w[r] - 1ll * w[l - 1] * p[r - l + 1]) % mod + mod) % mod;
}
int pre(int x, int y) {
  int l = 1, r = n - max(x, y) + 1, ans = 0;
  while(l <= r) {
    int mid = (l + r) >> 1;
    if(get(x, x + mid - 1) == get(y, y + mid - 1)) l = (ans = mid) + 1;
    else r = mid - 1;
  }
  return ans;
}
int suf(int x, int y) {
  int l = 1, r = min(x, y), ans = 0;
  while(l <= r) {
    int mid = (l + r) >> 1;
    if(get(x - mid + 1, x) == get(y - mid + 1, y)) l = (ans = mid) + 1;
    else r = mid - 1;
  }
  return ans;
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  p[0] = 1;
  rep(i, 1, n) p[i] = 1ll * p[i - 1] * base % mod;
  rep(i, 1, n) w[i] = (1ll * base * w[i - 1] + s[i]) % mod;
  rep(l, 1, n / 2) {
    bool mark = 0;
    last = 0;
    for(int i = l; i + l <= n; i += l) if(s[i] == s[i + l]) {
      int x = min(min(l, i - last), suf(i, i + l)), y = pre(i + 1, i + l + 1);
      if(x + y >= l) {
        last = i + l - x;
        rep(k, i - x + 1, last) s[k] = 0;
        mark = 1;
      }
    }
    if(mark) {
      int t = 0;
      rep(i, 1, n) if(s[i]) a[++ t] = s[i];
      copy(a + 1, a + t + 1, s + 1); n = t; s[n + 1] = 0;
      rep(i, 1, n) w[i] = (1ll * base * w[i - 1] + s[i]) % mod;
    }
  }
  puts(s + 1);
  return 0;
}