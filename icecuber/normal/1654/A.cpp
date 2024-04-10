#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll&v : a) cin >> v;
    sort(a.rbegin(), a.rend());
    cout << a[0]+a[1] << endl;
  }
}