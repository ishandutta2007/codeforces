#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n;
  cin >> n;
  ll ans = 0, m = 1;
  for (int i = 1; i <= 10; i++) {
    if (n >= m)
      ans += n-(m-1);
    m *= 10;
  }
  cout << ans << endl;
}