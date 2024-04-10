#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n;
  cin >> n;
  ll f = 2;
  for (ll i = 1; i < n; i++) f *= i;
  cout << f/n << endl;
}