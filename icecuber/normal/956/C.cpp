#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> m(n), x(n);
  int ma = 0;
  for (int i = 0; i < n; i++) {
    cin >> m[i];
    ma = max(ma, m[i]);
    x[i] = ma+1;
  }
  ll ans = 0;
  int mi = x[n-1]+1;
  for (int i = n-1; i >= 0; i--) {
    mi = max(mi-1, x[i]);
    ans += mi-m[i]-1;
  }
  cout << ans << endl;
}