#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll x;
    cin >> x;
    cout << (x >= 14 && x%14 >= 1 && x%14 <= 6 ? "YES" : "NO") << endl;
  }
}