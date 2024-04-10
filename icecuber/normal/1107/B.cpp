#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll k, x;
    cin >> k >> x;
    cout << (k-1)*9+x << endl;
  }
}