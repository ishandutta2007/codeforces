#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int t[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> a, b;
    for (int i = 0; i < n; i++) scanf("%d", &t[i]);
    for (int i = 0; i < n; i++) {
      int k;
      scanf("%d", &k);
      (t[i] ? a : b).push_back(k);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    if (a.size() > b.size()) swap(a, b);
    ll ans = 0;
    for (int i = 0; i < a.size(); i++) ans += 2LL * a[i] + 2LL * b[i];
    for (int i = a.size(); i < b.size(); i++) ans += b[i];
    if (a.size() == b.size()) ans -= min(a.back(), b.back());
    printf("%lld\n", ans);
  }
  return 0;
}