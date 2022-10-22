#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, k, a, b;
  cin >> n >> k >> a >> b;
  ll ans = a*(n-1);
  ll used = 0;
  while (k > 1 && n >= k) {
    used += (n%k)*a+b;
    n /= k;
    ans = min(ans, (n-1)*a+used);
  }
  cout << ans << endl;
}