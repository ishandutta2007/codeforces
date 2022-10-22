#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll&v : a) cin >> v;
    n--;
    vector<vector<ll>> sparse(20, vector<ll>(n));
    for (int i = 0; i < n; i++) {
      sparse[0][i] = abs(a[i+1]-a[i]);
    }
    for (int l = 0; l+1 < 20; l++)
      for (int i = 0; i+(2<<l) <= n; i++)
        sparse[l+1][i] = gcd(sparse[l][i], sparse[l][i+(1<<l)]);

    int ans = 1;
    for (int i = 0; i < n; i++) {
      ll g = 0;
      int p = i;
      for (int l = 19; l >= 0; l--) {
        if (p+(1<<l) <= n && gcd(sparse[l][p],g) >= 2) {
          g = gcd(sparse[l][p], g);
          p += 1<<l;
        }
      }
      ans = max(ans, p-i+1);
    }
    cout << ans << endl;
  }
}