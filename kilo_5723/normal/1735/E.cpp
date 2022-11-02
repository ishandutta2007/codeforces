#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 5;
ll _abs(ll n) { return n > 0 ? n : -n; }
struct value {
  ll val;
  bool id;
};
bool operator<(value a, value b) {
  if (a.val != b.val) return a.val > b.val;
  if (a.id != b.id) return a.id < b.id;
  return false;
}
ll a[maxn], b[maxn], t[maxn], sizt;
bool check(ll a[], ll b[], int n, int diff) {
  multiset<value> st;
  for (int i = 0; i < n; i++) st.insert({a[i], false});
  for (int i = 0; i < n; i++) st.insert({b[i], true});
  sizt = 0;
  while (st.size()) {
    auto u = *st.begin();
    st.erase(st.begin());
    value v = {_abs(u.val - diff), !u.id};
    if (!st.count(v)) return false;
    st.erase(st.find(v));
    if (!u.id)
      t[sizt++] = u.val;
    else
      t[sizt++] = diff - u.val;
  }
  return true;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < n; i++) scanf("%lld", &b[i]);
    sort(a, a + n);
    sort(b, b + n);
    reverse(b, b + n);
    bool flg = true;
    for (int i = 1; i < n; i++)
      if (a[i] + b[i] != a[0] + b[0]) {
        flg = false;
        break;
      }
    if (flg) {
      puts("YES");
      for (int i = 0; i < n; i++) printf("%lld ", a[i]);
      puts("");
      printf("0 %lld\n", a[0] + b[0]);
      continue;
    }
    reverse(a, a + n);
    flg = false;
    for (int i = 0; i < n && !flg; i++) {
      if (!flg && a[0] >= b[i] && check(a, b, n, a[0] - b[i])) {
        flg = true;
        puts("YES");
        ll mnm = 0;
        for (int i = 0; i < n; i++) mnm = min(mnm, t[i]);
        for (int i = 0; i < n; i++) printf("%lld ", t[i] - mnm);
        puts("");
        printf("%lld %lld\n", -mnm, a[0] - b[i] - mnm);
        continue;
      }
      if (!flg && b[0] >= a[i] && check(b, a, n, b[0] - a[i])) {
        flg = true;
        puts("YES");
        ll mnm = 0;
        for (int i = 0; i < n; i++) mnm = min(mnm, t[i]);
        for (int i = 0; i < n; i++) printf("%lld ", t[i] - mnm);
        puts("");
        printf("%lld %lld\n", b[0] - a[i] - mnm, -mnm);
        continue;
      }
    }
    if (flg) continue;
    puts("NO");
  }
  return 0;
}