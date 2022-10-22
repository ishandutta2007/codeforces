#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n;
  cin >> n;
  vector<ll> fact;
  for (ll i = 2; i*i <= n; i++) {
    while (n%i == 0) {
      fact.push_back(i);
      n /= i;
    }
  }
  if (n > 1) fact.push_back(n);
  if (fact.size() <= 1) {
    cout << 1 << endl;
    cout << 0 << endl;
  } else if (fact.size() == 2) {
    cout << 2 << endl;
  } else {
    cout << 1 << endl;
    cout << fact[0]*fact[1] << endl;
  }
}