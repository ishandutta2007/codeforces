#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define fori(n) for (int i = 0; i < n; i++)

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll b = 3e4;
    ll x = n/b;
    ll z = b-6;
    ll a = n%b;
    ll c = 1;
    assert(x*z+a*c+x*c*6==n);
    fori(x) cout << '1';
    fori(2) cout << '3';
    fori(z) cout << '7';
    fori(a) cout << '1';
    fori(2) cout << '3';
    fori(c) cout << '7';
    cout << endl;
  }
}