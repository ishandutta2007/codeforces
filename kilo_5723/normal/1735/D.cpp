#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 5;
ll a[maxn], comb[maxn][maxn];
unordered_map<ll, int> cnt;
ll comb2(ll n) { return n * (n - 1) / 2; }
ll comb3(ll n) { return n * (n - 1) * (n - 2) / 6; }
ll calc(ll a, ll b) {
  if (a == b) return a;
  return calc(a >> 2, b >> 2) << 2 |
         ((a & 3) == (b & 3) ? a & 3 : 3 - (a & 3) - (b & 3));
}
int kk;
void write(int n) {
  for (int i = 0; i < kk; i++) {
    printf("%d ", n & 3);
    n >>= 2;
  }
  puts("");
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  kk = k;
  for (int i = 0; i < n; i++) {
    a[i] = 0;
    for (int j = 0; j < k; j++) {
      int t;
      scanf("%d", &t);
      a[i] = a[i] << 2 | t;
    }
  }
  for (int i = 0; i < n; i++) cnt[a[i]]++;
  ll ans = 0;
  // for (int i = 0; i < n; i++) {
  //   cnt[a[i]]--;
  //   for (int j = i + 1; j < n; j++) {
  //     cnt[a[j]]--;
  //     ans += comb3(n - 2) - comb3(n - 2 - cnt[calc(a[i], a[j])]);
  //     cnt[a[j]]++;
  //   }
  //   cnt[a[i]]++;
  // }
  // printf("%d\n",ans);
  for (int i = 0; i < n; i++) {
    cnt[a[i]]--;
    int val = 0;
    for (int j = 0; j < n; j++) {
      cnt[a[j]]--;
      if (cnt[calc(a[i], a[j])]) val++;
      cnt[a[j]]++;
    }
    cnt[a[i]]++;
    val /= 2;
    // printf("%d\n", val);
    ans += comb2(val);
  }
  printf("%lld\n", ans);
  return 0;
}