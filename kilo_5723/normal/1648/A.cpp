#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
vector<vector<int> > a;
map<int, ll> cnt;
map<int, ll> sum;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  a.resize(n);
  for (int i = 0; i < n; i++) {
    a[i].resize(m);
    for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
  }
  ll ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      ans += cnt[a[i][j]] * i - sum[a[i][j]];
      sum[a[i][j]] += i;
      cnt[a[i][j]]++;
    }
  cnt.clear();
  sum.clear();
  for (int j = 0; j < m; j++)
    for (int i = 0; i < n; i++) {
      ans += cnt[a[i][j]] * j - sum[a[i][j]];
      sum[a[i][j]] += j;
      cnt[a[i][j]]++;
    }
  printf("%lld\n", ans);
  return 0;
}