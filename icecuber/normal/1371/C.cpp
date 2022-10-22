#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll a, b, good, bad;
    cin >> a >> b >> good >> bad;
    if (b < a) swap(a, b);
    cout << (good+bad <= a+b && bad <= a ? "Yes" : "No") << endl;
  }
}