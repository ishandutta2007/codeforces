#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  ll n;
  cin >> n;
  set<ll> ans;
  for (ll i = 1; i*i <= n; i++) {
    if (n%i == 0) {
      ll r = n/i;
      ans.insert(n*(r-1)/2+r);
      ans.insert(n*(i-1)/2+i);
    }
  }
  for (ll i : ans)
    cout << i << ' ';
  cout << endl;
}