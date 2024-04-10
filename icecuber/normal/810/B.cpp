#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;

  vector<ll> d;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    ll x = min(a,b), y = min(a*2,b);
    d.push_back(y-x);
    ans += x;
  }
  sort(d.rbegin(), d.rend());
  for (int i = 0; i < k; i++)
    ans += d[i];
  cout << ans << endl;
}