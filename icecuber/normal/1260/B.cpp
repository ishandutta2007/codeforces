#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll a, b;
    cin >> a >> b;
    cout << ((a+b)%3 == 0 && a <= 2*b && b <= 2*a ? "YES" : "NO") << endl;
  }
}