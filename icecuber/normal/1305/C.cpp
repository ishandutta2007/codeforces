#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  if (n > m) {
    cout << 0 << endl;
    return 0;
  }
  vector<int> a(n);
  for (int&v : a) cin >> v;
  int ans = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      (ans *= abs(a[i]-a[j])%m) %= m;
    }
  }
  cout << ans << endl;
}