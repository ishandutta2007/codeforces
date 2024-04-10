#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll x, y, k;
    cin >> x >> y >> k;
    ll need = k*(y+1)-1;
    cout << (need + x-2)/(x-1)+k << endl;
  }
}