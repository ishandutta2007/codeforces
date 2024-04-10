#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int,int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  vector<int> ind(n);
  for (int i = 0; i < n; i++)
    ind[a[i].second] = i;
  ll ans = 0;
  for (int i = n-m*k; i < n; i++)
    ans += a[i].first;
  cout << ans << endl;
  int len = 0, groups = 0;
  for (int i = 0; i < n; i++) {
    if (ind[i] >= n-m*k)
      len++;
    if (len == m && groups < k-1) {
      cout << i+1 << ' ';
      len = 0;
      groups++;
    }
  }
  cout << endl;
}