#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100000], inv[100000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    inv[a[i]] = i;
  }
  ll ans = 0;
  while (m--) {
    int b;
    cin >> b;
    b--;
    int i = inv[b];
    ans += i/k+1;
    if (i) {
      swap(a[i-1], a[i]);
      swap(inv[a[i-1]], inv[a[i]]);
    }
  }
  cout << ans << endl;
}