#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, m;
    cin >> n >> m;
    ll b = (n-m)/(m+1);
    ll r = n-m - b*(m+1);
    cout << n*(n+1)/2 - r*(b+1)*(b+2)/2 - (m+1-r)*(b)*(b+1)/2 << '\n';
  }
}